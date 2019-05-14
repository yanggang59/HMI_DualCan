#include "can_recv_send.h"

#include <QMutex>       //线程加锁保护

#define CAN0_BITRATE "/sbin/ip link set can0 up type can bitrate 250000"
#define CAN0_OPEN "/sbin/ip link set can0 up"
#define CAN0_CLOSE "/sbin/ip link set can0 down"

#define CAN1_BITRATE "/sbin/ip link set can1 up type can bitrate 250000"
#define CAN1_OPEN "/sbin/ip link set can1 up"
#define CAN1_CLOSE "/sbin/ip link set can1 down"



QMutex mutex;

int j = 0;              //返回数据
int sum = 1;
int sum_right = 1;

void can0_set_bitrate(void)
{     //设置波特率
    system(CAN0_CLOSE);
    system(CAN0_BITRATE);
    system(CAN0_OPEN);
}

void can1_set_bitrate(void)
{     //设置波特率
    system(CAN1_CLOSE);
    system(CAN1_BITRATE);
    system(CAN1_OPEN);
}



//can0 ----12
int can0_recv(struct can_frame frame[])
{
    /* can通信的初始化 */
    int s=0;
    //int loopback = 0;	//本地回环，现在还不明白
    unsigned long nbytes = 0;
    struct sockaddr_can addr;	//canl
    struct ifreq ifr;	//
    struct can_filter rfilter[12];	//过滤规则的结构体

    if((s = socket(PF_CAN, SOCK_RAW, CAN_RAW)) < 0)	//创建套接字
    {
     perror("Error while opening socket");
     return -1;
    }
    strncpy(ifr.ifr_name, "can0", sizeof(ifr.ifr_name)-1);
    ifr.ifr_name[sizeof(ifr.ifr_name)-1] = '\0';
    ioctl(s, SIOCGIFINDEX, &ifr);	//指定can0设备

    addr.can_family = AF_CAN;	//这两行必须有
    addr.can_ifindex = ifr.ifr_ifindex;

    if((bind(s, (struct sockaddr *)&addr, sizeof(addr))) < 0)       //绑定
    {
     perror("Error in socket bind");
     return -1;
    }
    /*只有扩展帧能通过，CAN_SFF_MASK 是标准帧，
    * CAN_SFF_MASK & CAN_EFF_MASK, 都能通过。
    */
    rfilter[0].can_id = 0x18FFFEF0;                      //发动机工作时间和总里程----0
    rfilter[0].can_mask = CAN_EFF_MASK;
    rfilter[1].can_id = 0x18FFFDF0;                      //系统电压等----1
    rfilter[1].can_mask = CAN_EFF_MASK;
    rfilter[2].can_id = 0x18FF0803;                      //米计里程----2
    rfilter[2].can_mask = CAN_EFF_MASK;
    rfilter[3].can_id = 0x18FF0903;                     //前后马达转速----3
    rfilter[3].can_mask = CAN_EFF_MASK;
    rfilter[4].can_id = 0x18FF1003;                      //卸粮筒等----4
    rfilter[4].can_mask = CAN_EFF_MASK;
    rfilter[5].can_id = 0x18FF1103;                      //电磁阀等----5
    rfilter[5].can_mask = CAN_EFF_MASK;
    rfilter[6].can_id = 0x18FF1203;                     //复脱器转速,割刀频率等----6
    rfilter[6].can_mask = CAN_EFF_MASK;
    rfilter[7].can_id = 0x18FF1909;                      //空、前进、倒档----13
    rfilter[7].can_mask = CAN_EFF_MASK;
    rfilter[8].can_id = 0x18FEF700;                     //系统电压----24
    rfilter[8].can_mask = CAN_EFF_MASK;
    rfilter[9].can_id = 0x0CF00400 | CAN_EFF_FLAG;     //扩展帧，发动机转速----25
    rfilter[9].can_mask = 0xFFF;
    rfilter[10].can_id = 0x18FEEE00;                     //发动机冷却水温----28
    rfilter[10].can_mask = CAN_EFF_MASK;
    rfilter[11].can_id = 0x18FEEF00;                     //发动机油压力----29
    rfilter[11].can_mask = CAN_EFF_MASK;

    setsockopt(s, SOL_CAN_RAW, CAN_RAW_FILTER, &rfilter, sizeof(rfilter));	//设置过滤规则


    //nbytes = read(s, frame, sizeof(*frame));

    socklen_t len = sizeof(addr);

    nbytes = recvfrom(s,frame,sizeof(struct can_frame),0,(struct sockaddr*)&addr,&len);

    close(s);

    return(nbytes);
}


//can1 ---18
int can1_recv(struct can_frame frame[])
{
    /* can 通信的初始化 */
    int s=0;
    //int loopback = 0;	//本地回环，现在还不明白
    unsigned long nbytes = 0;
    struct sockaddr_can addr;	//can1
    struct ifreq ifr;	//
    struct can_filter rfilter[18];	//过滤规则的结构体

    if((s = socket(PF_CAN, SOCK_RAW, CAN_RAW)) < 0)	//创建套接字
    {
     perror("Error while opening socket");
     return -1;
    }
    strncpy(ifr.ifr_name, "can1", sizeof(ifr.ifr_name)-1);

    ifr.ifr_name[sizeof(ifr.ifr_name)-1] = '\0';

    ioctl(s, SIOCGIFINDEX, &ifr);	//指定can1设备

    addr.can_family = AF_CAN;	//这两行必须有
    addr.can_ifindex = ifr.ifr_ifindex;

    if((bind(s, (struct sockaddr *)&addr, sizeof(addr))) < 0)       //绑定
    {
     perror("Error in socket bind");
     return -1;
    }

    /*只有扩展帧能通过，CAN_SFF_MASK 是标准帧，
    * CAN_SFF_MASK & CAN_EFF_MASK, 都能通过。
    */
    rfilter[0].can_id = 0x18FF1305;                     //清选风扇----7
    rfilter[0].can_mask = CAN_EFF_MASK;
    rfilter[1].can_id = 0x18FF1405;                      //清选风机设置值----8
    rfilter[1].can_mask = CAN_EFF_MASK;
    rfilter[2].can_id = 0x18FF1507;                    //含水率等----9
    rfilter[2].can_mask = CAN_EFF_MASK;
    rfilter[3].can_id = 0x18FF1607;                      //粮食干重----10
    rfilter[3].can_mask = CAN_EFF_MASK;
    rfilter[4].can_id = 0x18FF1707;                      //升运器转速----11
    rfilter[4].can_mask = CAN_EFF_MASK;
    rfilter[5].can_id = 0x18FF1809;                     //损失率和含杂率----12
    rfilter[5].can_mask = CAN_EFF_MASK;
    rfilter[6].can_id = 0x18FF2011;                      //抛撒器角度和切碎器转速----14
    rfilter[6].can_mask = CAN_EFF_MASK;
    rfilter[7].can_id = 0x18FF2111;                     //备用----15
    rfilter[7].can_mask = CAN_EFF_MASK;
    rfilter[8].can_id = 0x18FF2213;                    //导航辅助驾驶调节----16
    rfilter[8].can_mask = CAN_EFF_MASK;
    rfilter[9].can_id = 0x18FF2313;                     //仿形高度等----17
    rfilter[9].can_mask = CAN_EFF_MASK;
    rfilter[10].can_id = 0x18FF2413;                     //割宽----18
    rfilter[10].can_mask = CAN_EFF_MASK;
    rfilter[11].can_id = 0x18FF2913;                     //备用----19
    rfilter[11].can_mask = CAN_EFF_MASK;
    rfilter[12].can_id = 0x18FF2515;                     //拨禾轮转速----20
    rfilter[12].can_mask = CAN_EFF_MASK;
    rfilter[13].can_id = 0x18FF2615;                    //喂入量----21
    rfilter[13].can_mask = CAN_EFF_MASK;
    rfilter[14].can_id = 0x18FF2717;                     //轴流滚筒转矩----22
    rfilter[14].can_mask = CAN_EFF_MASK;
    rfilter[15].can_id = 0x18FF2817;                     //备用----23
    rfilter[15].can_mask = CAN_EFF_MASK;
    rfilter[16].can_id = 0x18FF2715;                    //拨禾轮液压马达流量的低高值----26
    rfilter[16].can_mask = CAN_EFF_MASK;
    rfilter[17].can_id = 0x18FF2815;                    //拨禾轮液压马达进油压力的低高值----27
    rfilter[17].can_mask = CAN_EFF_MASK;

    setsockopt(s, SOL_CAN_RAW, CAN_RAW_FILTER, &rfilter, sizeof(rfilter));	//设置过滤规则

    //nbytes = read(s, frame, sizeof(*frame));

    socklen_t len = sizeof(addr);

    nbytes = recvfrom(s,frame,sizeof(struct can_frame),0,(struct sockaddr*)&addr,&len);

    close(s);

    return(nbytes);
}


//can0 send
void can0_send(QByteArray data ,int id)
{
    QMutexLocker lock(&mutex);		//加锁，防止竞争

    int s = 0, nbytes= 0;
    struct sockaddr_can addr;
    struct ifreq ifr;		//s,addr,ifr都是为了将嵌套字和can接口连接
    struct can_frame frame;	//存储数据信息

    s = socket(PF_CAN,SOCK_RAW,CAN_RAW);	//创建一个套接字

    strncpy(ifr.ifr_name,"can0", sizeof(ifr.ifr_name)-1);
    ifr.ifr_name[sizeof(ifr.ifr_name)-1] = '\0';

    ioctl(s,SIOCGIFINDEX,&ifr);			//指定CAN1设备,得到索引

    addr.can_family = AF_CAN;
    addr.can_ifindex = ifr.ifr_ifindex;
    bind(s,(struct sockaddr*)&addr,sizeof(addr));//将套接字与can0设备连接在一起

    frame.can_id = CAN_EFF_FLAG| id;
    frame.can_dlc = 8;

    for(int i = 0; i<8; i++)
    {
      frame.data[i] = data.at(i);
    }

    setsockopt(s, SOL_CAN_RAW, CAN_RAW_FILTER, NULL, 0);
    nbytes = write(s, &frame, sizeof(frame));
    close(s);

}

//can1 send
void can1_send(QByteArray data ,int id)
{
    QMutexLocker lock(&mutex);		//加锁，防止竞争

    int s = 0, nbytes= 0;
    struct sockaddr_can addr;
    struct ifreq ifr;		//s,addr,ifr都是为了将嵌套字和can接口连接
    struct can_frame frame;	//存储数据信息
    //struct can_filter rfilter;	//过滤规则

    s = socket(PF_CAN,SOCK_RAW,CAN_RAW);	//创建一个套接字

    strncpy(ifr.ifr_name,"can1", sizeof(ifr.ifr_name)-1);
    ifr.ifr_name[sizeof(ifr.ifr_name)-1] = '\0';

    ioctl(s,SIOCGIFINDEX,&ifr);			//指定CAN1设备,得到索引

    addr.can_family = AF_CAN;
    addr.can_ifindex = ifr.ifr_ifindex;
    bind(s,(struct sockaddr*)&addr,sizeof(addr));//将套接字与can0设备连接在一起

    frame.can_id = CAN_EFF_FLAG| id;
    frame.can_dlc = 8;

    for(int i = 0; i<8; i++)
    {
      frame.data[i] = data.at(i);
    }

    setsockopt(s, SOL_CAN_RAW, CAN_RAW_FILTER, NULL, 0);


    nbytes = write(s, &frame, sizeof(frame));


    close(s);

}



