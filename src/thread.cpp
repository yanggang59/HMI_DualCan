#include "thread.h"
#include <QTimer>
#include <QDateTime>
#include <QDebug>
#include "can_recv_send.h"		// CAN 数据的头文件

#define SLEEP msleep(0)

/**********************************************************************
 * Name: num_mon[30][8]
 * Description: used to define 8 bytes of data in 30 CAN id
 *       num_mon[0]  represents 18FFFEF0; num_mon[1]  represents 18FFFDF0;num_mon[2]  represents 18FF0803;
 *       num_mon[3]  represents 18FF0903; num_mon[4]  represents 18FF1003;num_mon[5]  represents 18FF1103;
 *       num_mon[6]  represents 18FF1203; num_mon[7]  represents 18FF1305;num_mon[8]  represents 18FF1405;
 *       num_mon[9]  represents 18FF1507; num_mon[10] represents 18FF1607;num_mon[11] represents 18FF1707;
 *       num_mon[12] represents 18FF1809; num_mon[13] represents 18FF1909;num_mon[14] represents 18FF2011;
 *       num_mon[15] represents 18FF2111; num_mon[16] represents 18FF2213;num_mon[17] represents 18FF2313;
 *       num_mon[18] represents 18FF2413; num_mon[19] represents 18FF2913;num_mon[20] represents 18FF2515;
 *       num_mon[21] represents 18FF2615; num_mon[22] represents 18FF2717;num_mon[23] represents 18FF2817;
 *       num_mon[24] represents 18FEF700; num_mon[25] represents 0CF00400;num_mon[26] represents 18FF2715;
 *       num_mon[27] represents 18FF2815; num_mon[28] represents 18FEEE00;num_mon[29] represents 18FEEF00;
 * Date: 2017-9-30
 * Author: shone
 **********************************************************************/

int num_mon[30][8];
int can0_recv_flag = 0;
int can1_recv_flag = 0;
//int get_flag = -1;     //区分是第几页页面

Thread0::Thread0()
{
    stopped = false;	//析构函数的初始化
    warn_timer = new QTimer(this);
}

//can0接收数据线程----12个ID
void Thread0::run()
{
    struct can_frame frame_temp;
    QObject::connect(warn_timer, SIGNAL(timeout()), this, SLOT(warnFun_slot()));
    warn_timer->start(5000);
    while(!stopped)
    {
        warn_timer->stop();		//连续的关闭和开启定时器，这样就不会每隔五秒timeout了
        warn_timer->start(5000);

        can0_recv_flag = can0_recv(&frame_temp);	//得到CAN数据，储蓄在frame_temp里,can0_recv return received bytes

        /* CAN的结构体数据转换成一般数组 */
        QByteArray bArray;
        bArray.resize(8);

        /* 根据不同ID向主线程（即界面线程）发送数据信号 */

             switch (frame_temp.can_id)
            {
                case 0x98FFFEF0://发动机工作时间和总里程,注意，这里是0x18FFFEF0+0x80000000
                    for(int j = 0; j < 8; j++)
                    {
                        num_mon[0][j] = (int)frame_temp.data[j];
                    }
                    SLEEP;
                    break;
               case 0x98FFFDF0://系统电压等,注意，这里是0x18FFFDF0+0x80000000
                   for(int j = 0; j < 8; j++)
                   {
                       num_mon[1][j] = (int)frame_temp.data[j];
                   }
                   SLEEP;
                   break;
               case 0x98FF0803://单次行驶里程
                   for(int j = 0; j < 8; j++)
                   {
                       num_mon[2][j] = (int)frame_temp.data[j];
                   }
                   SLEEP;
                   break;
               case 0x98FF0903://前后马达转速
                  for(int j = 0; j < 8; j++)
                  {
                      num_mon[3][j] = (int)frame_temp.data[j];
                  }
                  SLEEP;
                  break;
               case 0x98FF1003://
                   for(int j = 0; j < 8; j++)
                   {
                       num_mon[4][j] = (int)frame_temp.data[j];
                   }
                   SLEEP;
                   break;
              case 0x98FF1103://
                  for(int j = 0; j < 8; j++)
                  {
                      num_mon[5][j] = (int)frame_temp.data[j];
                  }
                  SLEEP;
                  break;
              case 0x98FF1203://复脱器转速
                  for(int j = 0; j < 8; j++)
                  {
                      num_mon[6][j] = (int)frame_temp.data[j];
                  }
                  SLEEP;
                  break;
            case 0x98FF1909://空、前进、倒档
               for(int j = 0; j < 8; j++)
               {
                   num_mon[13][j] = (int)frame_temp.data[j];
               }
               SLEEP;
               break;
             case 0x98FEF700://系统电压
                 for(int j = 0; j < 8; j++)
                 {
                     num_mon[24][j] = (int)frame_temp.data[j];
                 }
                 SLEEP;
                 break;
            case 0x8CF00400://发送机转速
                for(int j = 0; j < 8; j++)
                {
                    num_mon[25][j] = (int)frame_temp.data[j];
                }
                SLEEP;
                break;
            case 0x98FEEE00://发送机冷却水温
                for(int j = 0; j < 8; j++)
                {
                    num_mon[28][j] = (int)frame_temp.data[j];
                }
                SLEEP;
                break;
            case 0x98FEEF00://发动机油压力
               for(int j = 0; j < 8; j++)
               {
                   num_mon[29][j] = (int)frame_temp.data[j];
               }
               SLEEP;
               break;
                  default:
                    qDebug() << "Not received by can0";
            }
    }

    stopped = false;
    exec();
}


void Thread0::warnFun_slot()
{
    if(can0_recv_flag == 0)
    {
        /* 通信故障的警告信号 */
        emit warn_signal();
    }
}

//can1接收数据线程---18个ID
Thread1::Thread1()
{
    stopped = false;	//析构函数的初始化
    warn_timer = new QTimer(this);
}

void Thread1::run()
{
    struct can_frame frame_temp;
    QObject::connect(warn_timer, SIGNAL(timeout()), this, SLOT(warnFun_slot()));
    warn_timer->start(5000);
    while(!stopped)
    {
        warn_timer->stop();		//连续的关闭和开启定时器，这样就不会每隔五秒timeout了
        warn_timer->start(5000);
        can1_recv_flag = can1_recv(&frame_temp);	//得到CAN数据，储蓄在frame_temp里
        /* CAN的结构体数据转换成一般数组 */
        QByteArray bArray;
        bArray.resize(8);
        /* 根据不同ID向主线程（即界面线程）发送数据信号 */
        switch (frame_temp.can_id)
       {
           case 0x98FF1305://清选风扇等
               for(int j = 0; j < 8; j++)
               {
                   num_mon[7][j] = (int)frame_temp.data[j];
               }
               SLEEP;
               break;
          case 0x98FF1405://清选风机目标值
              for(int j = 0; j < 8; j++)
              {
                  num_mon[8][j] = (int)frame_temp.data[j];
              }
              SLEEP;
              break;
          case 0x98FF1507://含水率、流量、平方米产量,粮食湿重
              for(int j = 0; j < 8; j++)
              {
                  num_mon[9][j] = (int)frame_temp.data[j];
              }
              SLEEP;
              break;
          case 0x98FF1607://粮食干重
             for(int j = 0; j < 8; j++)
             {
                 num_mon[10][j] = (int)frame_temp.data[j];
             }
             SLEEP;
             break;
          case 0x98FF1707://升运器转速
              for(int j = 0; j < 8; j++)
              {
                  num_mon[11][j] = (int)frame_temp.data[j];
              }
              SLEEP;
              break;
         case 0x98FF1809://清选损失率、清选含杂率、破碎率
             for(int j = 0; j < 8; j++)
             {
                 num_mon[12][j] = (int)frame_temp.data[j];
             }
             SLEEP;
             break;
         case 0x98FF2011://抛撒器幅宽、抛撒器扭矩、切碎器转速
             for(int j = 0; j < 8; j++)
             {
                 num_mon[14][j] = (int)frame_temp.data[j];
             }
             SLEEP;
             break;
       case 0x98FF2111://备用
          for(int j = 0; j < 8; j++)
          {
              num_mon[15][j] = (int)frame_temp.data[j];
          }
          SLEEP;
          break;
        case 0x98FF2213://导航辅助驾驶调节、xyz轴的速度
            for(int j = 0; j < 8; j++)
            {
                num_mon[16][j] = (int)frame_temp.data[j];
            }
            SLEEP;
            break;
       case 0x98FF2313://仿形高度检测值、农作物高度检测值
           for(int j = 0; j < 8; j++)
           {
               num_mon[17][j] = (int)frame_temp.data[j];
           }
           SLEEP;
           break;
       case 0x98FF2413://左、右侧割宽检测值、行驶速度
           for(int j = 0; j < 8; j++)
           {
               num_mon[18][j] = (int)frame_temp.data[j];
           }
           SLEEP;
           break;
       case 0x98FF2913://备用
          for(int j = 0; j < 8; j++)
          {
              num_mon[19][j] = (int)frame_temp.data[j];
          }
          SLEEP;
          break;
        case 0x98FF2515://拨禾轮转速、拨禾轮高度、拨禾轮前后位移、喂入搅龙转速、喂入搅龙扭矩
            for(int j = 0; j < 8; j++)
            {
                num_mon[20][j] = (int)frame_temp.data[j];
            }
            SLEEP;
            break;
       case 0x98FF2615://喂入量、割台损失率、割刀频率、割刀转速目标值、搅龙转速目标值
           for(int j = 0; j < 8; j++)
           {
               num_mon[21][j] = (int)frame_temp.data[j];
           }
           SLEEP;
           break;
       case 0x98FF2717://轴流(切流)滚筒转速、轴流(切流)滚筒扭矩、凹板间隙检测值、凹版处称重传感器
           for(int j = 0; j < 8; j++)
           {
               num_mon[22][j] = (int)frame_temp.data[j];
           }
           SLEEP;
           break;
       case 0x98FF2817://滚筒转速目标值
          for(int j = 0; j < 8; j++)
          {
              num_mon[23][j] = (int)frame_temp.data[j];
          }
          SLEEP;
          break;
       case 0x98FF2715://拨禾轮液压马达流量、喂入搅龙液压马达流量、割刀液压马达流量、拨禾轮转速设置值
           for(int j = 0; j < 8; j++)
           {
               num_mon[26][j] = (int)frame_temp.data[j];
           }
           SLEEP;
           break;
      case 0x98FF2815://拨禾轮液压马达进油压力。。。割刀高度检测值
          for(int j = 0; j < 8; j++)
          {
              num_mon[27][j] = (int)frame_temp.data[j];
          }
          SLEEP;
          break;
             default:
               qDebug() << "Not received by can0";
       }
    }
    stopped = false;
    exec();
}

void Thread1::warnFun_slot()
{
    if(can1_recv_flag == 0)
    {
        /* 通信故障的警告信号 */
        emit warn_signal();
    }
}

void Thread1::stop()
{
    stopped = true;
}


/* 返回can数据的线程 */
ThreadBack::ThreadBack()
{
    stopped = false;
    send_timer = new QTimer(this);
}


/* 返回数据的线程 */
void ThreadBack::run()
{
    QObject::connect(send_timer, SIGNAL(timeout()), this, SLOT(can_return()));
    send_timer->start(100);

    QByteArray array;
    array.resize(8);

    if(flag_send_setting)
    {
        emit settingpara1(dataArray130);
        emit settingpara2(dataArray230);

        array = arr12;
        emit set_arr(array);
        flag_send_setting = 0;
    }
}

void ThreadBack::can_return()
{

}

void ThreadBack::canTest(QByteArray bArray)
{

}


void ThreadBack::stop()
{
    stopped = true;
}
