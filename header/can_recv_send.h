#ifndef CAN_RECV_SEND
#define CAN_RECV_SEND

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/ioctl.h>	//这四条是can通信的头文件
#include <net/if.h>
#include <arpa/inet.h>
#include <linux/socket.h>
#include <linux/can/error.h>
#include <linux/can.h>
#include <linux/can/raw.h>

#include <signal.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>

/* linux 文件的读写头文件 */
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <QByteArray>

#ifndef PF_CAN			//条件编译
    #define PF_CAN 29
#endif

#ifndef AF_CAN
    #define AF_CAN PF_CAN
    #define CAN_EFF_FLAG 0x80000000U	//扩展帧的标识
#endif

#define CAN0_BITRATE "/sbin/ip link set can0 up type can bitrate 250000"
#define CAN0_OPEN "/sbin/ip link set can0 up"
#define CAN0_CLOSE "/sbin/ip link set can0 down"

#define CAN1_BITRATE "/sbin/ip link set can1 up type can bitrate 250000"
#define CAN1_OPEN "/sbin/ip link set can1 up"
#define CAN1_CLOSE "/sbin/ip link set can1 down"


extern void can_init();

extern int can0_recv(can_frame frame[]);
extern int can1_recv(can_frame frame[]);

extern void can0_send(QByteArray data,int id);    //can0 send
extern void can1_send(QByteArray data ,int id);  //can1 send



#endif // CAN_RECV_SEND

