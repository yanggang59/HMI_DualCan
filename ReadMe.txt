2019年５月14日使用双can口

０．在can_recv_send.h和can_recv_send.cpp中定义了can初始化函数can_init()，作用是进行波特率设置和打开can口
    在使用前需注意
    (1)替换屏幕的/sbin目录下的ip文件，原ip文件是/bin/busybox的软链接
    (2)注意此时的can口的打开、关闭以及波特率设置均需要使用ip命令来完成
１．can0 和　can1 的接收和发送数据函数的定义在can_recv_send.h和can_recv_send.cpp中定义
２．在thread.h和thraed.cpp中定义了两个线程分别用来负责can0和can1的接收数据
３．发送数据放在主线程中完成，在controlsetting.h和controlsetting.cpp中