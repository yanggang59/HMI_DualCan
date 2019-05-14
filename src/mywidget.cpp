#include "mywidget.h"
#include "ui_mywidget.h"

#define WDT "/dev/watchdog"



myWidget::myWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::myWidget)
{

    SensordataInit();   //传感器数据初始化
    StatedataInit();    //警告表初始化

    ui->setupUi(this);
    cs = new ControlSetting;        //不加cs和ps实例化会出现段错误
    ps = new ParameterSetting;

    variable_init();

    this->setWindowIcon(QIcon(":/images/leiwo.png"));         //设置应用窗口图标
//    this->setWindowFlags(Qt::FramelessWindowHint);          //去掉标题栏"QT"字样
//    setWindowFlags(windowFlags() &~ (Qt::WindowMinMaxButtonsHint | Qt::WindowCloseButtonHint));

    //LCD时间显示的定时器
    timer=new QTimer(this);
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(updateTime()));
    timer->start(1000);
//    set_watchdog();              //20170911,看门狗，卡死之后自动重启系统

    //更新界面的定时器
    tmpara = new QTimer(this);
    QObject::connect(tmpara,SIGNAL(timeout()),this,SLOT(show_parameter()));
    tmpara->start(1000);

    //防止QT界面假死
    QElapsedTimer et;
    et.start();
    while(et.elapsed()<300)
        QCoreApplication::processEvents();

    setWindowTitle(tr("    收获机械智能监测系统"));
    ui->lcdNumber->setDigitCount(20);
    ui->lcdNumber->setPalette(Qt::white); //设置QLCDNumber字体颜色，背景色可以直接stylesheet中设置

    //要显示登录界面，需要将下面三行注释取消，或者点击exit按钮进入登录界面
//    ui->tabWidget->hide();
//    ui->lcdNumber->hide();
//    ui->exit->hide();
    ui->syssw->hide();


    ui->upassword->setEchoMode(QLineEdit::Password);            //设置为密码输入方式
    connect(ui->sbtn,SIGNAL(clicked()),this,SLOT(show_sys()));  //进入主界面
    connect(ui->out_btn,SIGNAL(clicked()),this,SLOT(close_sys()));  //退出系统按钮
    connect(ui->exit,SIGNAL(clicked()),this,SLOT(hide_sys()));  //退出主界面，返回登录

    connect(ui->control_set,SIGNAL(clicked()),cs,SLOT(show()));
    connect(ui->parameter_set,SIGNAL(clicked()),ps,SLOT(show()));

    ui->label_7->setStyleSheet("background-image: url(:/images/engine/fuel.png);");

    connect(this,SIGNAL(sendTime(QString)),ui->lcdNumber,SLOT(display(QString)));

    conflag = ui->tabWidget->currentIndex();

    can0_set_bitrate();

    can1_set_bitrate();

    //开启接收数据的线程
    can0RecvThread = new Thread0;
    can0RecvThread->start();

    can1RecvThread = new Thread1;
    can1RecvThread->start();

    //开启返回数据的线程
    reThreadBack = new ThreadBack;
    reThreadBack->start();

}

myWidget::~myWidget()
{
    delete ui;
}

void myWidget::variable_init(){

    wdt_fd = -1;

    //主界面
    ui->l_full->setStyleSheet("");                  //粮满报警
    ui->l_oil_water->setStyleSheet("");             //油水分离
    ui->l_eng_fault->setStyleSheet("");             //发动机故障
    ui->l_indt_lm->setStyleSheet("");               //位置灯
    ui->l_turn_lf->setStyleSheet("");               //左转向
    ui->l_turn_rt->setStyleSheet("");               //右转向
    ui->l_highlight->setStyleSheet("");             //远光灯
    ui->l_diplight->setStyleSheet("");              //近光灯
    ui->l_air_cln->setStyleSheet("");               //空滤堵塞报警
    ui->l_clutch_st->setStyleSheet("");             //主离合状态
    ui->eng_hb->setStyleSheet("");                  //手刹
    ui->l_preheat->setStyleSheet("");               //预热
    ui->eng_chg->setStyleSheet("");                 //充电
    ui->eng_gear->setStyleSheet("");                //档位
    ui->impr_rate->setStyleSheet("");               //含杂率等级
    ui->w_reed_speed->setStyleSheet("");            //拨禾轮转速三角形报警提示
    ui->w_cut_mach->setStyleSheet("");              //切碎器转速三角形报警提示
    ui->w_dtfan_sp->setStyleSheet("");              //风机转速三角形报警提示
    ui->w_fdaugersp->setStyleSheet("");             //喂入绞龙转速三角形报警提示
    ui->w_rollerspeed->setStyleSheet("");           //轴流滚筒转速三角形报警提示
    ui->w_re_thr_sp->setStyleSheet("");             //复脱器转速三角形报警提示
    ui->w_elevator->setStyleSheet("");              //升运器转速三角形报警提示

    //参数界面
    cs->hide();
    ui->w_front_motor_sp->setStyleSheet("");        //前马达转速三角形报警
    ui->w_rear_motor_sp->setStyleSheet("");         //后马达转速三角形报警

    //诊断报警界面
    ui->l_fcm_1->setStyleSheet("border-image:url(:/images/warning/normal.png)");
    ui->l_fcm_2->setStyleSheet("border-image:url(:/images/warning/normal.png)");
    ui->l_fcm_3->setStyleSheet("border-image:url(:/images/warning/normal.png)");
    ui->l_es_1->setStyleSheet("border-image:url(:/images/warning/normal.png)");
    ui->l_es_2->setStyleSheet("border-image:url(:/images/warning/normal.png)");
    ui->l_es_3->setStyleSheet("border-image:url(:/images/warning/normal.png)");
    ui->l_fas_1->setStyleSheet("border-image:url(:/images/warning/normal.png)");
    ui->l_fas_2->setStyleSheet("border-image:url(:/images/warning/normal.png)");
    ui->l_fas_3->setStyleSheet("border-image:url(:/images/warning/normal.png)");
    ui->l_fd_1->setStyleSheet("border-image:url(:/images/warning/normal.png)");
    ui->l_fd_2->setStyleSheet("border-image:url(:/images/warning/normal.png)");
    ui->l_fd_3->setStyleSheet("border-image:url(:/images/warning/normal.png)");
    ui->l_rls_1->setStyleSheet("border-image:url(:/images/warning/normal.png)");
    ui->l_rls_2->setStyleSheet("border-image:url(:/images/warning/normal.png)");
    ui->l_rls_3->setStyleSheet("border-image:url(:/images/warning/normal.png)");
    ui->l_cm_1->setStyleSheet("border-image:url(:/images/warning/normal.png)");
    ui->l_cm_2->setStyleSheet("border-image:url(:/images/warning/normal.png)");
    ui->l_cm_3->setStyleSheet("border-image:url(:/images/warning/normal.png)");
    ui->l_df_1->setStyleSheet("border-image:url(:/images/warning/normal.png)");
    ui->l_df_2->setStyleSheet("border-image:url(:/images/warning/normal.png)");
    ui->l_df_3->setStyleSheet("border-image:url(:/images/warning/normal.png)");
    ui->l_fm_1->setStyleSheet("border-image:url(:/images/warning/normal.png)");
    ui->l_fm_2->setStyleSheet("border-image:url(:/images/warning/normal.png)");
    ui->l_fm_3->setStyleSheet("border-image:url(:/images/warning/normal.png)");
    ui->l_rm_1->setStyleSheet("border-image:url(:/images/warning/normal.png)");
    ui->l_rm_2->setStyleSheet("border-image:url(:/images/warning/normal.png)");
    ui->l_rm_3->setStyleSheet("border-image:url(:/images/warning/normal.png)");

    ui->l_cluster_on->setStyleSheet("border-image:url(:/images/parameters/ClutchOnOff.png)");
    ui->l_cluster_off->setStyleSheet("border-image:url(:/images/parameters/ClutchOffOff.png)");
    ui->l_clusterval_on->setStyleSheet("border-image:url(:/images/parameters/ClutchValveOnOff.png)");
    ui->l_clusterval_off->setStyleSheet("border-image:url(:/images/parameters/ClutchValveOffOff.png)");
    ui->l_cuthei_up->setStyleSheet("border-image: url(:/images/con_recong/CutHeiUpOff.png);");
    ui->l_cuthei_down->setStyleSheet("border-image: url(:/images/con_recong/CutHeiDownOff.png)");
    ui->l_cutheival_up->setStyleSheet("border-image: url(:/images/con_recong/CutHeiValveUpOff.png);");
    ui->l_cutheival_down->setStyleSheet("border-image: url(:/images/con_recong/CutHeiValveDownOff.png);");
    ui->l_rol_up->setStyleSheet("border-image: url(:/images/con_recong/RollerUpOff.png);");
    ui->l_rol_down->setStyleSheet("border-image: url(:/images/con_recong/RollerDownOff.png);");
    ui->l_rolval_up->setStyleSheet("border-image: url(:/images/con_recong/RollerValveUpOff.png);");
    ui->l_rolval_down->setStyleSheet("border-image: url(:/images/con_recong/RollerValveDownOff.png);");
    ui->l_reel_up->setStyleSheet("border-image: url(:/images/con_recong/ReelUpOff.png);");
    ui->l_reel_down->setStyleSheet("border-image: url(:/images/con_recong/ReelDownOff.png);");
    ui->l_reelval_up->setStyleSheet("border-image: url(:/images/con_recong/RollerValveUpOff.png);");
    ui->l_reelval_down->setStyleSheet("border-image: url(:/images/con_recong/ReelValveDownOff.png);");
    ui->l_unswout->setStyleSheet("border-image: url(:/images/parameters/UnloaderSwingOutOff.png);");
    ui->l_unswin->setStyleSheet("border-image: url(:/images/parameters/UnloaderSwingInOff.png);");
    ui->l_unswoutval->setStyleSheet("border-image: url(:/images/parameters/UnloaderValveSwingOutOff.png);");
    ui->l_unswinval->setStyleSheet("border-image: url(:/images/parameters/UnloaderValveSwingInOff.png);");
    ui->l_unloader->setStyleSheet("border-image: url(:/images/parameters/UnloaderOff.png);");
    ui->s_fan->setStyleSheet("border-image: url(:/images/parameters/s_off.png);");
    ui->s_plus->setStyleSheet("border-image: url(:/images/con_recong/FanUpOff.png);");
    ui->s_minus->setStyleSheet("border-image: url(:/images/con_recong/FanDownOff.png);");
    ui->l_backupdri->setStyleSheet("border-image: url(:/images/con_recong/backupdriveroff.png);");

}

void myWidget::show_sys(){

    if(ui->uname->text() == "5555"){
        if(ui->upassword->text() == "5555"){
            ui->syssw->hide();
            ui->tabWidget->show();
            ui->lcdNumber->show();
            ui->exit->show();
        }else  QMessageBox::information(this, QString::fromLocal8Bit("警告"),QString::fromLocal8Bit("密码错误，请重新输入！"));
    }else   QMessageBox::information(this, QString::fromLocal8Bit("警告"),QString::fromLocal8Bit("用户名错误，请重新输入！"));

}

void myWidget::hide_sys(){
    //自定义警告框内容和按钮
    QMessageBox::StandardButton ret  = QMessageBox::question(this,
                          QString::fromLocal8Bit("警告"),QString::fromLocal8Bit("确定退出吗？"),
                          QMessageBox::Yes|QMessageBox::No,QMessageBox::No);
    if(ret == QMessageBox::Yes){
        ui->syssw->show();
        ui->tabWidget->hide();
        ui->lcdNumber->hide();
        ui->exit->hide();
    }
}

void myWidget::close_sys(){
    QMessageBox::StandardButton ret  = QMessageBox::question(this,
                          QString::fromLocal8Bit("警告"),QString::fromLocal8Bit("确定退出本系统吗？"),
                          QMessageBox::Yes|QMessageBox::No,QMessageBox::No);

    if(ret == QMessageBox::Yes){
        can0RecvThread->terminate();
        can1RecvThread->terminate();
        reThreadBack->terminate();
        this->close();
    }
}


//显示数据
void myWidget::show_parameter()
{
        get_eng_ti_dis(num_mon[0]);          //18FFFEF0
        get_speed_data(num_mon[1]);          //18FFFDF0
        get_meter_distance(num_mon[2]);      //18FF0803
        get_motor_speed(num_mon[3]);         //18FF0903  前后马达转速
        get_unload_btn(num_mon[4]);          //18FF1003
        get_valve_state(num_mon[5]);         //18FF1103
        get_redischarge_machine(num_mon[6]); //18FF1203  复脱器转速
        get_clean_fan(num_mon[7]);           //18FF1305  清选风扇

        get_water_rate(num_mon[9]);          //18FF1507
        get_weight_dry(num_mon[10]);         //18FF1607
        get_elevator_speed(num_mon[11]);     //18FF1707  升运器
        get_lose_rate(num_mon[12]);          //18FF1809
        get_gear_state(num_mon[13]);         //18FF1909
        get_throw_angle(num_mon[14]);        //18FF2011  切碎器
        //get_2111(num_mon[15]);               //18FF2111---备用
        getGPS(num_mon[16]);                 //18FF2213----导航
        get_detect_value(num_mon[17]);       //18FF2313
        get_cut_width(num_mon[18]);          //18FF2413
        //get_real_speed(num_mon[19]);         //18FF2913----备用
        get_cutter_freq(num_mon[20]);        //18FF2515 拨禾轮、搅龙转速

        /*
        1405 2615 2715 2815 2817 5个ID均在参数设置界面显示
        2615的前几个参数在主界面有显示
        */

        get_feed(num_mon[21]);               //18FF2615 喂入量、割台损失率、割刀频率

        get_drum_speed(num_mon[22]);           //18FF2717 轴流滚筒

        //get2817(num_mon[23]);
        //getF700(num_mon[24]);              //系统电压，实际在18FFFDF0中已经定义

        get_eng_rev(num_mon[25]);            //0CF00400  发送机转速



        get_eng_thm(num_mon[28]);            //18FEEE00  发动机冷却水温

        get_eng_oilpres(num_mon[29]);        //18FEEF00  发动机油压
}


//显示当前时间
void myWidget::updateTime(){

    QDateTime dt;
    QTime currTime;
    QDate currDate;
    dt.setTime(currTime.currentTime());
    dt.setDate(currDate.currentDate());
    QString current=dt.toString("yyyy-MM-dd hh:mm:ss");
    emit sendTime(current);
}

void myWidget::set_watchdog(){
    int timeoutw;
    timerwdt=new QTimer(this);
    QObject::connect(timerwdt,SIGNAL(timeout()),this,SLOT(FeedDog()));
    timerwdt->start(10000);

    wdt_fd = open(WDT,O_WRONLY);
    if(wdt_fd == -1){
        qDebug() << "fail to open \"WDT\" ! " ;
    }else{
        printf("WDT is opend !\n");
    }

    timeoutw = 12;
    ioctl(wdt_fd,WDIOC_SETTIMEOUT,&timeoutw);

    ioctl(wdt_fd,WDIOC_GETTIMEOUT,&timeoutw);

    printf("The timeout was is %d seconds\n", timeoutw);
}

void myWidget::FeedDog(){

    write(wdt_fd,"\0",1);

}

//发动机工作小时和总里程----18FFFEF0
void myWidget::get_eng_ti_dis(int array[8]){
    /* 0x18FFFEF0,字节0-7
     * 字节0-3，发动机工作小时
     * 字节4-7，总里程
     */
    EngineerWorktime = array[0]+array[1]*256+array[2]*256*256+array[3]*256*256*256;
    TotalMileage  = array[4]+array[5]*256+array[6]*256*256+array[7]*256*256*256;

    ui->totle_tm->setText(tr("%1").arg(EngineerWorktime/10));
    ui->totle_km->setText(tr("%1").arg(TotalMileage/10));
}


//燃油位---18FFFDF0
void myWidget::get_speed_data(int array[8]){
    /* 0x18FFFDF0,字节0-7
     * 取消：燃油位L，字节1，燃油位H，0.1L/bit，0.0-1000L
     * 字节2，系统电压L，字节3，系统电压H，0.1V/bit，0.0-36V
     * 取消：字节4，行驶速度L，字节5，行驶速度H，0.1km/h/bit，0.0-30km/h
     * 字节6，燃油位百分比，1%/bit，0-100%
     * 字节7，0-1位，粮满报警：00，不报警，01，低报警，10，高报警，11，error
     *       2-3位，主离合状态：00，脱开，01，结合，10，error，11，不可用
     * */

    SystemVoltage = (array[2]+array[3]*256);           //系统电压
    Fuel = array[6];                                   //燃油位百分比
    qreal valsm = array[7]&0x3;                        //取字节7的第0-1位,高位在左边，低位在右边
    qreal valst = (array[7]&0xc)>>2;                   //取字节7的第2-3位

    if(Fuel >= 100)
        Fuel = 100;
    ui->l_eng_sm->setText(tr("%1").arg(Fuel));

    if(SystemVoltage >= 360)
        SystemVoltage = 360;
    ui->l_voltage->setText(tr("%1V").arg(SystemVoltage/10));


    if(valsm == 0){
        ui->l_full->setStyleSheet("");
        GrainWarning = "正常";
    }else if(valsm == 1){
        ui->l_full->setStyleSheet("border-image:url(:/images/engine/full1.png)");
        GrainWarning = "粮满低警告";
    }else if(valsm == 2){
        ui->l_full->setStyleSheet("border-image:url(:/images/engine/full2.png)");
        GrainWarning = "粮满高警告";
    }else{
        GrainWarning = "异常";
    }

    if(valst == 0){
        ui->l_clutch_st->setStyleSheet("border-image:url(:/images/engine/clutch_off.png)");
    }else if(valst == 1){
        ui->l_clutch_st->setStyleSheet("border-image:url(:/images/engine/clutch_on.png)");
    }else if(valst == 2){
        ui->l_clutch_st->setStyleSheet("border-image:url(:/images/engine/clutch_error.png)");
    }
}

//米计里程
void myWidget::get_meter_distance(int array[8]){
    /* 0x18FF0803,字节0-7
     * 字节0-3，单次行驶里程LL-HH,这里不显示
     * 字节4-7，米计里程LL-HH
     * */
    MetericMileage  = array[4]+array[5]*256+array[6]*256*256+array[7]*256*256*256;
    ui->totle_m->setText(tr("%1").arg(MetericMileage));

}

//马达转速----18FF0903
void myWidget::get_motor_speed(int array[8]){
    /* 0x18FF0903,字节0-7
     * 字节0-1，前马达转速rpm
     * 字节2-3，后马达转速rpm
     * bit16：1=堵塞报警，0=无报警
     * bit15：1=转速过高报警，0=无报警
     * bit14：1=转速过低报警，0=无报警
     * bit13-1:1rpm/bit，  0xFF表示无效
     * */

    FormotorSpeed      = array[0]+(array[1] & 0x1f)*256;      //取第0字节和第1字节的低5位
    BehmotorSpeed      = array[2]+(array[3] & 0x1f)*256;
    qreal warning1  = (array[1] & 0xe0) >> 5;   //判断是否有报警
    qreal warning2  = (array[3] & 0xe0) >> 5;
    qreal warningf1 = (array[1] & 0x20) >> 5;   //转速过低报警13
    qreal warningf2 = (array[1] & 0x40) >> 6;   //转速过高报警14
    qreal warningf3 = (array[1] & 0x80) >> 7;   //堵塞报警15
    qreal warningr1 = (array[3] & 0x20) >> 5;   //转速过低报警13
    qreal warningr2 = (array[3] & 0x40) >> 6;   //转速过高报警14
    qreal warningr3 = (array[3] & 0x80) >> 7;   //堵塞报警15

    if((array[0] == (qreal)(0xff) && array[1] == (qreal)(0xff))||(array[2] == (qreal)(0xff) && array[3] == (qreal)(0xff))){

        if(array[0] == (qreal)(0xff) && array[1] == (qreal)(0xff))            FormotorSpeed = warning1 = warningf1 = warningf2 = warningf3 = 0;
        if (array[2] == (qreal)(0xff) && array[3] == (qreal)(0xff))        BehmotorSpeed = warning2 = warningr1 = warningr2 = warningr3 = 0;
    }

    ui->front_motor_sp->setText(tr("%1").arg(FormotorSpeed));
    ui->rear_motor_sp->setText(tr("%1").arg(BehmotorSpeed));

    if(warning1){
        ui->w_front_motor_sp->setStyleSheet("border-image:url(:/images/engine/warning.png)");
        ui->w_front_motor_sp->glitter();
    }else{
        ui->w_front_motor_sp->setStyleSheet(" ");
        FormotorWarningD = "正常";
        FormotorWarningHL = "正常";
    }

    if(warning2){
        ui->w_rear_motor_sp->setStyleSheet("border-image:url(:/images/engine/warning.png)");
        ui->w_rear_motor_sp->glitter();
    }else{
        ui->w_rear_motor_sp->setStyleSheet(" ");
        BehmotorWarningHL = "正常";
        BehmotorWarningD = "正常";
    }

    if(warningf1){
        ui->l_fm_1->setStyleSheet("border-image:url(:/images/warning/alarm.png)");
        FormotorWarningHL = "低警告";
    }else             ui->l_fm_1->setStyleSheet("border-image:url(:/images/warning/normal.png)");
    if(warningf2){
        ui->l_fm_2->setStyleSheet("border-image:url(:/images/warning/alarm.png)");
        FormotorWarningHL = "高警告";
    }else             ui->l_fm_2->setStyleSheet("border-image:url(:/images/warning/normal.png)");
    if(!warningf1&&!warningf2){
        FormotorWarningHL = "正常";
    }
    if(warningf3){
        ui->l_fm_3->setStyleSheet("border-image:url(:/images/warning/alarm.png)");
        FormotorWarningD = "堵塞警告";
    }else{
        ui->l_fm_3->setStyleSheet("border-image:url(:/images/warning/normal.png)");
        FormotorWarningD = "正常";
    }

    if(warningr1){
        ui->l_rm_1->setStyleSheet("border-image:url(:/images/warning/alarm.png)");
        BehmotorWarningHL = "低警告";
    }else             ui->l_rm_1->setStyleSheet("border-image:url(:/images/warning/normal.png)");
    if(warningr2){
        ui->l_rm_2->setStyleSheet("border-image:url(:/images/warning/alarm.png)");
        BehmotorWarningHL = "高警告";
    }else             ui->l_rm_2->setStyleSheet("border-image:url(:/images/warning/normal.png)");
    if(!warningr1&&!warningr2)
    {
        BehmotorWarningHL = "正常";
    }
    if(warningr3){
        ui->l_rm_3->setStyleSheet("border-image:url(:/images/warning/alarm.png)");
        BehmotorWarningD = "堵塞警告";
    }else{
        ui->l_rm_3->setStyleSheet("border-image:url(:/images/warning/normal.png)");
        BehmotorWarningD = "正常";
    }
}

//卸粮筒等-----18FF1003
void myWidget::get_unload_btn(int array[8]){
    /* 0x18FF1003,字节0-7
     * 两位一个参数，00表示开关未闭合，信号未触发；01表示开关闭合，信号触发；10未定义；11未定义
     * */
    qreal val1 = (array[0] & 0x3);           //取第0字节的0-1位，表示充电指示
    qreal val2 = (array[0] & 0xc) >> 2;      //取第0字节的2-3位，表示位置灯
    qreal val3 = (array[0] & 0x30) >> 4;     //取第0字节的4-5位，表示右转向
    qreal val4 = (array[0] & 0xc0) >> 6;     //取第0字节的6-7位，表示左转向

    qreal val5 = (array[1] & 0x3) ;          //取第1字节的0-1位，表示远光
    qreal val6 = (array[1] & 0xc) >> 2;      //取第1字节的2-3位，表示近光
    qreal val7 = (array[1] & 0x30) >> 4;     //取第1字节的4-5位，表示空滤堵塞报警
    qreal val8 = (array[1] & 0xc0) >> 6;     //取第1字节的6-7位，表示预热

    qreal val9 = (array[2] & 0xc) >> 2;      //取第2字节的2-3位，表示手刹

    qreal val10 = (array[3] & 0xc) >> 2;     //取第3字节的2-3位，表示油水分离
    qreal val11 = (array[3] & 0x30) >> 4;    //取第3字节的4-5位，表示发动机故障
    qreal val12 = (array[3] & 0xc0) >> 6;    //取第3字节的6-7位，表示卸粮安全开关

    qreal val14 = (array[4] & 0xc0) >> 6;    //取第4字节的6-7位，表示风机减速按钮

    qreal val15 = (array[5] & 0x3) ;         //取第5字节的0-1位，表示拨禾轮提升按钮
    qreal val16 = (array[5] & 0xc) >> 2;     //取第5字节的2-3位，表示拨禾轮下降按钮
    qreal val17 = (array[5] & 0x30) >> 4;    //取第5字节的4-5位，表示轴流滚筒提升按钮
    qreal val18 = (array[5] & 0xc0) >> 6;    //取第5字节的6-7位，表示轴流滚筒下降按钮

    qreal val19 = (array[6] & 0x3) ;         //取第6字节的0-1位，表示主离合啮合按钮
    qreal val20 = (array[6] & 0xc) >> 2;     //取第6字节的2-3位，表示主离合分离按钮

    qreal val21 = (array[7] & 0x3);          //取第7字节的0-1位，表示卸粮筒展开按钮
    qreal val22 = (array[7] & 0xc) >> 2;     //取第7字节的2-3位，表示卸粮筒收回按钮
    qreal val23 = (array[7] & 0x30) >> 4;    //取第7字节的4-5位，表示割台上升按钮
    qreal val24 = (array[7] & 0xc0) >> 6;    //取第7字节的6-7位，表示割台下降按钮



    if(val1 == 1)   ui->eng_chg->setStyleSheet("background-image: url(:/images/engine/charging.png);");
    else        ui->eng_chg->setStyleSheet("");

    if(val2 == 1)   ui->l_indt_lm->setStyleSheet("border-image: url(:/images/engine/Indt_lamp.png);");
    else        ui->l_indt_lm->setStyleSheet("");

    if(val3 == 1) {  ui->l_turn_rt->setStyleSheet("border-image: url(:/images/engine/turn_right.png);"); ui->l_turn_rt->glitter(); }
    else        ui->l_turn_rt->setStyleSheet("");

    if(val4 == 1) {  ui->l_turn_lf->setStyleSheet("border-image: url(:/images/engine/turn_left.png);"); ui->l_turn_lf->glitter(); }
    else        ui->l_turn_lf->setStyleSheet("");

    if(val5 == 1)   ui->l_highlight->setStyleSheet("border-image: url(:/images/engine/highbeam.png);");
    else        ui->l_highlight->setStyleSheet("");

    //近光灯不需要显示
    if(val6 == 10)   ui->l_diplight->setStyleSheet("border-image: url(:/images/engine/diplight.png);");
    else        ui->l_diplight->setStyleSheet("");

    if(val7 == 1) {  ui->l_air_cln->setStyleSheet("border-image: url(:/images/engine/air_cleaner.png);");
    }
    else        ui->l_air_cln->setStyleSheet("");

    if(val8 == 1) {  ui->l_preheat->setStyleSheet("border-image: url(:/images/engine/preheat.png);");
    }
    else        ui->l_preheat->setStyleSheet("");

    if(val9 == 1)   ui->eng_hb->setStyleSheet("border-image: url(:/images/engine/handbrake.png);");
    else        ui->eng_hb->setStyleSheet("");

    if(val10 == 1) {  ui->l_oil_water->setStyleSheet("border-image: url(:/images/engine/oil_water.png);");
    }
    else        ui->l_oil_water->setStyleSheet("");

    if(val11 == 1) {  ui->l_eng_fault->setStyleSheet("border-image: url(:/images/engine/engine_fault.png);");
    }
    else        ui->l_eng_fault->setStyleSheet("");

    if(val12 == 1)   ui->l_unloader->setStyleSheet("border-image: url(:/images/parameters/UnloaderOn.png);");
    else        ui->l_unloader->setStyleSheet("border-image: url(:/images/parameters/UnloaderOff.png);");

    if(val14 == 1)   ui->s_minus->setStyleSheet("border-image: url(:/images/con_recong/FanDownOn.png);");
    else        ui->s_minus->setStyleSheet("border-image: url(:/images/con_recong/FanDownOff.png);");

    if(val15 == 1)   ui->l_reel_up->setStyleSheet("border-image: url(:/images/con_recong/ReelUpOn.png);");
    else        ui->l_reel_up->setStyleSheet("border-image: url(:/images/con_recong/ReelUpOff.png);");

    if(val16 == 1)   ui->l_reel_down->setStyleSheet("border-image: url(:/images/con_recong/ReelDownOn.png);");
    else        ui->l_reel_down->setStyleSheet("border-image: url(:/images/con_recong/ReelDownOff.png);");

    if(val17 == 1)   ui->l_rol_up->setStyleSheet("border-image: url(:/images/con_recong/RollerUpOn.png);");
    else        ui->l_rol_up->setStyleSheet("border-image: url(:/images/con_recong/RollerUpOff.png);");

    if(val18 == 1)   ui->l_rol_down->setStyleSheet("border-image: url(:/images/con_recong/RollerDownOn.png);");
    else        ui->l_rol_down->setStyleSheet("border-image: url(:/images/con_recong/RollerDownOff.png);");

    if(val19 == 1)   ui->l_cluster_on->setStyleSheet("border-image: url(:/images/parameters/ClutchOnOn.png);");
    else        ui->l_cluster_on->setStyleSheet("border-image: url(:/images/parameters/ClutchOnOff.png);");

    if(val20 == 1)   ui->l_cluster_off->setStyleSheet("border-image: url(:/images/parameters/ClutchOffOn.png);");
    else        ui->l_cluster_off->setStyleSheet("border-image: url(:/images/parameters/ClutchOffOff.png);");

    if(val21 == 1)   ui->l_unswout->setStyleSheet("border-image: url(:/images/parameters/UnloaderSwingOutOn.png);");
    else        ui->l_unswout->setStyleSheet("border-image: url(:/images/parameters/UnloaderSwingOutOff.png);");

    if(val22 == 1)   ui->l_unswin->setStyleSheet("border-image: url(:/images/parameters/UnloaderSwingInOn.png);");
    else        ui->l_unswin->setStyleSheet("border-image: url(:/images/parameters/UnloaderSwingInOff.png);");

    if(val23 == 1)   ui->l_cuthei_up->setStyleSheet("border-image: url(:/images/con_recong/CutHeiUpOn.png);");
    else        ui->l_cuthei_up->setStyleSheet("border-image: url(:/images/con_recong/CutHeiUpOff.png);");

    if(val24 == 1)   ui->l_cuthei_down->setStyleSheet("border-image: url(:/images/con_recong/CutHeiDownOn.png);");
    else        ui->l_cuthei_down->setStyleSheet("border-image: url(:/images/con_recong/CutHeiDownOff.png);");

}

//电磁阀等----18FF1103
void myWidget::get_valve_state(int array[8]){
    /* 0x18FF1103,字节0-7
     * 两位一个参数，表示电磁阀状态，00未驱动输出状态；01驱动输出状态；10输出电流过高；11输出电流过低（被驱动设备未连接）
     * */

    qreal val6 = (array[1] & 0xc) >> 2;          //取第1字节的2-3位，表示割台提升电磁阀
    qreal val7 = (array[1] & 0x30) >> 4;         //取第1字节的4-5位，表示割台下降电磁阀
    qreal val8 = (array[1] & 0xc0) >> 6;         //取第1字节的6-7位，表示拨禾轮提升电磁阀

    qreal val9  = (array[2] & 0x3) ;             //取第2字节的0-1位，表示拨禾轮下降电磁阀
    qreal val10 = (array[2] & 0xc) >> 2;         //取第2字节的2-3位，表示轴流滚筒速度提升电磁阀
    qreal val11 = (array[2] & 0x30) >> 4;        //取第2字节的4-5位，表示轴流滚筒速度下降电磁阀
    qreal val12 = (array[2] & 0xc0) >> 6;        //取第2字节的6-7位，表示主离合啮合电磁阀

    qreal val13 = (array[3] & 0x3);              //取第3字节的0-1位，表示主离合分离电磁阀
    qreal val16 = (array[3] & 0xc0) >> 6;        //取第3字节的6-7位，表示卸粮筒展开电磁阀

    qreal val17 = (array[4] & 0x3);              //取第4字节的0-1位，表示卸粮筒收回电磁阀
    qreal val19 = (array[4] & 0x30) >> 4;        //取第4字节的4-5位，表示备用驱动输出
    qreal val20 = (array[4] & 0xc0) >> 6;        //取第4字节的6-7位，表示风机调速电磁阀


    if(val6 == 1)       ui->l_cutheival_up->setStyleSheet("border-image: url(:/images/con_recong/CutHeiValveUpOn.png);");
    else if(val6 == 2)  ui->l_cutheival_up->setStyleSheet("border-image: url(:/images/con_recong/CutHeiValveUpch.png);");
    else if(val6 == 3)  ui->l_cutheival_up->setStyleSheet("border-image: url(:/images/con_recong/CutHeiValveUpcl.png);");
    else                ui->l_cutheival_up->setStyleSheet("border-image: url(:/images/con_recong/CutHeiValveUpOff.png);");

    if(val7 == 1)       ui->l_cutheival_down->setStyleSheet("border-image: url(:/images/con_recong/CutHeiValveDownOn.png);");
    else if(val7 == 2)  ui->l_cutheival_down->setStyleSheet("border-image: url(:/images/con_recong/CutHeiValveDownch.png);");
    else if(val7 == 3)  ui->l_cutheival_down->setStyleSheet("border-image: url(:/images/con_recong/CutHeiValveDowncl.png);");
    else                ui->l_cutheival_down->setStyleSheet("border-image: url(:/images/con_recong/CutHeiValveDownOff.png);");

    if(val8 == 1)       ui->l_reelval_up->setStyleSheet("border-image: url(:/images/con_recong/ReelValveUpOn.png);");
    else if(val8 == 2)  ui->l_reelval_up->setStyleSheet("border-image: url(:/images/con_recong/ReelValveUpch.png);");
    else if(val8 == 3)  ui->l_reelval_up->setStyleSheet("border-image: url(:/images/con_recong/ReelValveUpcl.png);");
    else                ui->l_reelval_up->setStyleSheet("border-image: url(:/images/con_recong/ReelValveUpOff.png);");

    if(val9 == 1)       ui->l_reelval_down->setStyleSheet("border-image: url(:/images/con_recong/ReelValveDownOn.png);");
    else if(val9 == 2)  ui->l_reelval_down->setStyleSheet("border-image: url(:/images/con_recong/ReelValveDownch.png);");
    else if(val9 == 3)  ui->l_reelval_down->setStyleSheet("border-image: url(:/images/con_recong/ReelValveDowncl.png);");
    else                ui->l_reelval_down->setStyleSheet("border-image: url(:/images/con_recong/ReelValveDownOff.png);");

    if(val10 == 1)       ui->l_rolval_up->setStyleSheet("border-image: url(:/images/con_recong/RollerValveUpOn.png);");
    else if(val10 == 2)  ui->l_rolval_up->setStyleSheet("border-image: url(:/images/con_recong/RollerValveUpch.png);");
    else if(val10 == 3)  ui->l_rolval_up->setStyleSheet("border-image: url(:/images/con_recong/RollerValveUpcl.png);");
    else                 ui->l_rolval_up->setStyleSheet("border-image: url(:/images/con_recong/RollerValveUpOff.png);");

    if(val11 == 1)       ui->l_rolval_down->setStyleSheet("border-image: url(:/images/con_recong/RollerValveDownOn.png);");
    else if(val11 == 2)  ui->l_rolval_down->setStyleSheet("border-image: url(:/images/con_recong/RollerValveDownch.png);");
    else if(val11 == 3)  ui->l_rolval_down->setStyleSheet("border-image: url(:/images/con_recong/RollerValveDowncl.png);");
    else                 ui->l_rolval_down->setStyleSheet("border-image: url(:/images/con_recong/RollerValveDownOff.png);");

    if(val12 == 1)       ui->l_clusterval_on->setStyleSheet("border-image: url(:/images/parameters/ClutchValveOnOn.png);");
    else if(val12 == 2)  ui->l_clusterval_on->setStyleSheet("border-image: url(:/images/con_recong/ClutchValveOnch.png);");
    else if(val12 == 3)  ui->l_clusterval_on->setStyleSheet("border-image: url(:/images/con_recong/ClutchValveOncl.png);");
    else                 ui->l_clusterval_on->setStyleSheet("border-image: url(:/images/parameters/ClutchValveOnOff.png);");

    if(val13 == 1)       ui->l_clusterval_off->setStyleSheet("border-image: url(:/images/parameters/ClutchValveOffOn.png);");
    else if(val13 == 2)  ui->l_clusterval_off->setStyleSheet("border-image: url(:/images/con_recong/ClutchValveOffch.png);");
    else if(val13 == 3)  ui->l_clusterval_off->setStyleSheet("border-image: url(:/images/con_recong/ClutchValveOffcl.png);");
    else                 ui->l_clusterval_off->setStyleSheet("border-image: url(:/images/parameters/ClutchValveOffOff.png);");

    if(val16 == 1)       ui->l_unswoutval->setStyleSheet("border-image: url(:/images/parameters/UnloaderValveSwingOutOn.png);");
    else if(val16 == 2)  ui->l_unswoutval->setStyleSheet("border-image: url(:/images/con_recong/UnloaderValveSwingOutch.png);");
    else if(val16 == 3)  ui->l_unswoutval->setStyleSheet("border-image: url(:/images/con_recong/UnloaderValveSwingOutcl.png);");
    else                 ui->l_unswoutval->setStyleSheet("border-image: url(:/images/parameters/UnloaderValveSwingOutOff.png);");

    if(val17 == 1)       ui->l_unswinval->setStyleSheet("border-image: url(:/images/parameters/UnloaderValveSwingInOn.png);");
    else if(val17 == 2)  ui->l_unswinval->setStyleSheet("border-image: url(:/images/con_recong/UnloaderValveSwingInch.png);");
    else if(val17 == 3)  ui->l_unswinval->setStyleSheet("border-image: url(:/images/con_recong/UnloaderValveSwingIncl.png);");
    else                 ui->l_unswinval->setStyleSheet("border-image: url(:/images/parameters/UnloaderValveSwingInOff.png);");

    if(val19 == 1)       ui->l_backupdri->setStyleSheet("border-image: url(:/images/con_recong/backupdriveron.png);");
    else if(val19 == 2)  ui->l_backupdri->setStyleSheet("border-image: url(:/images/con_recong/backupdriverch.png);");
    else if(val19 == 3)  ui->l_backupdri->setStyleSheet("border-image: url(:/images/con_recong/backupdrivercl.png);");
    else                 ui->l_backupdri->setStyleSheet("border-image: url(:/images/con_recong/backupdriveroff.png);");

    if(val20 == 1)       ui->s_fan->setStyleSheet("border-image: url(:/images/parameters/s_on.png);");
    else if(val20 == 2)  ui->s_fan->setStyleSheet("border-image: url(:/images/con_recong/s_onch.png);");
    else if(val20 == 3)  ui->s_fan->setStyleSheet("border-image: url(:/images/con_recong/s_oncl.png);");
    else                 ui->s_fan->setStyleSheet("border-image: url(:/images/parameters/s_off.png);");


}

//复脱器转速---18FF1203
void myWidget::get_redischarge_machine(int array[8]){
    /* 0x18FF1203,字节0-7
     * 第0字节表示复脱器转速低位，第1字节表示复脱器转速高位，13位转速低报警，14位转速高报警，15位堵塞报警
     * */
    Retractor = array[0] + array[1]*256;

    ui->re_thr_sp->setText(tr("%1").arg(Retractor));

//**********************************
    qreal warning1  = (array[1] & 0xe0) >> 5;   //判断是否有报警
    qreal warninge1 = (array[1] & 0x20) >> 5;   //转速过低报警13
    qreal warninge2 = (array[1] & 0x40) >> 6;   //转速过高报警14
    qreal warninge3 = (array[1] & 0x80) >> 7;   //堵塞报警15


    if((array[0] == (qreal)(0xff) && array[1] == (qreal)(0xff))){

            Retractor = warning1 = warninge1 = warninge2 = warninge3 = 0;
    }

    if(warning1){
        ui->w_re_thr_sp->setStyleSheet("border-image:url(:/images/engine/warning.png)");
        ui->w_re_thr_sp->glitter();
    }else{
        ui->w_re_thr_sp->setStyleSheet(" ");
        RetractorWarningHL = "正常";
        RetractorWarningD = "正常";
    }


    if(warninge1){
        ui->l_cm_1->setStyleSheet("border-image:url(:/images/warning/alarm.png)");
        RetractorWarningHL = "低警告";
    }else             ui->l_cm_1->setStyleSheet("border-image:url(:/images/warning/normal.png)");
    if(warninge2){
        ui->l_cm_2->setStyleSheet("border-image:url(:/images/warning/alarm.png)");
        RetractorWarningHL = "高警告";
    }else             ui->l_cm_2->setStyleSheet("border-image:url(:/images/warning/normal.png)");
    if(!warninge1&&!warninge2){
        RetractorWarningHL = "正常";
    }
    if(warninge3){
        ui->l_cm_3->setStyleSheet("border-image:url(:/images/warning/alarm.png)");
        RetractorWarningD = "堵塞警告";
    }else{
        ui->l_cm_3->setStyleSheet("border-image:url(:/images/warning/normal.png)");
        RetractorWarningD = "正常";
    }
}

//清选风扇等 18FF1305
void myWidget::get_clean_fan(int array[8]){
    /* 0x18FF1305,字节0-7
     * 第0字节表示清选风扇转速低位，第1字节表示清选风扇转速高位，13位转速低报警，14位转速高报警，15位堵塞报警
     * 第2字节表示风机分风板角度低位，第3字节表示风机风板角度高位
     * 第4字节表示上筛开度
     * 第5字节表示下筛开度
     * 第6字节表示尾筛开度
     * */

    FunSpeed = array[0] + array[1]*256;
    PartwindBoard = array[2] + array[3]*256;
    UpsieveOpendegree = array[4];
    DownsieveOpendegree = array[5];
    LastsieveOpendegree = array[6];


    ui->l_dtfan_sp->setText(tr("%1").arg(FunSpeed));
    ui->l_fan_angle->setText(tr("%1").arg(PartwindBoard/10));
    ui->label_58->setText(tr("%1").arg(UpsieveOpendegree));
    ui->label_60->setText(tr("%1").arg(DownsieveOpendegree));
    ui->label_61->setText(tr("%1").arg(LastsieveOpendegree));

//***************************************
    qreal warning1  = (array[1] & 0xe0) >> 5;   //判断是否有报警
    qreal warninge1 = (array[1] & 0x20) >> 5;   //转速过低报警13
    qreal warninge2 = (array[1] & 0x40) >> 6;   //转速过高报警14
    qreal warninge3 = (array[1] & 0x80) >> 7;   //堵塞报警15


    if((array[0] == (qreal)(0xff) && array[1] == (qreal)(0xff))){

            FunSpeed = warning1 = warninge1 = warninge2 = warninge3 = 0;
    }


    if(warning1){
        ui->w_dtfan_sp->setStyleSheet("border-image:url(:/images/engine/warning.png)");
        ui->w_dtfan_sp->glitter();
    }else{
        FunSpeedWarningHL = "正常";
        FunSpeedWarningD = "正常";
        ui->w_dtfan_sp->setStyleSheet(" ");
    }

    if(warninge1){
        ui->l_fas_1->setStyleSheet("border-image:url(:/images/warning/alarm.png)");
        FunSpeedWarningHL = "低警告";
    }else             ui->l_fas_1->setStyleSheet("border-image:url(:/images/warning/normal.png)");
    if(warninge2){
        ui->l_fas_2->setStyleSheet("border-image:url(:/images/warning/alarm.png)");
        FunSpeedWarningHL = "高警告";
    }else             ui->l_fas_2->setStyleSheet("border-image:url(:/images/warning/normal.png)");
    if(!warninge1&&!warninge2){
        FunSpeedWarningHL = "正常";
    }
    if(warninge3){
        ui->l_fas_3->setStyleSheet("border-image:url(:/images/warning/alarm.png)");
        FunSpeedWarningD = "堵塞警告";
    }else{
        ui->l_fas_3->setStyleSheet("border-image:url(:/images/warning/normal.png)");
        FunSpeedWarningD = "正常";
    }

}

//含水率等----18FF1507
void myWidget::get_water_rate(int array[8]){
    /* 0x18FF1507,字节0-7
     * 第0字节表示含水率低位，第1字节表示含水率高位
     * 第2字节表示谷物流量检测质量低位，第3字节表示谷物流量检测质量高位
     * 第4字节表示平方米产量低位，第5字节表示平方米产量高位
     * 第6字节表示粮食湿重低位，第7字节表示粮食湿重高位
     * */

    WaterRate = (array[0] + array[1]*256);
    GrainflowQuality = array[2] + array[3]*256;
    ProductionSquaremeter = (array[4] + array[5]*256);
    GrainWetweight = array[6] + array[7]*256;

    ui->water_rate->setText(tr("%1").arg(WaterRate/100));
    ui->grain_quality_monitor->setText(tr("%1").arg(GrainflowQuality));
    ui->label_85->setText(tr("%1").arg(ProductionSquaremeter/1000));
    ui->weight_wet->setText(tr("%1").arg(GrainWetweight));
}

//粮食干重-----18FF1607
void myWidget::get_weight_dry(int array[8]){
    /* 0x18FF1607,字节0-7
     * 第0字节表示粮食干重低位，第1字节表示粮食干重高位
     * */

    GrainDryweight = (array[0] + array[1]*256);

    ui->weight_dry->setText(tr("%1").arg(GrainDryweight));

}

//升运器转速-----18FF1707
void myWidget::get_elevator_speed(int array[8]){
    /* 0x18FF1707,字节0-7
     * 更改到0x18ff1607：第0字节表示粮食干重低位，第1字节表示粮食干重高位
     * 第2字节表示升运器转速低位，第3字节表示升运器转速高位和报警信息
     * */

    //qreal val1 = (array[0) + array[1)*256);
    LiftdeviceSpeed = array[2]+(array[3] & 0x1f)*256;
    qreal warning1  = (array[3] & 0xe0) >> 5;   //判断是否有报警
    qreal warninge1 = (array[3] & 0x20) >> 5;   //转速过低报警13
    qreal warninge2 = (array[3] & 0x40) >> 6;   //转速过高报警14
    qreal warninge3 = (array[3] & 0x80) >> 7;   //堵塞报警15

    if((array[2] == (qreal)(0xff) && array[3] == (qreal)(0xff))){
            LiftdeviceSpeed = warning1 = warninge1 = warninge2 = warninge3 = 0;
    }

    ui->l_elevator->setText(tr("%1").arg(LiftdeviceSpeed));

    if(warning1){
        ui->w_elevator->setStyleSheet("border-image:url(:/images/engine/warning.png)");
        ui->w_elevator->glitter();
    }else{
        ui->w_elevator->setStyleSheet(" ");
        LiftdeviceWarningD = "正常";
        LiftdeviceWarningHL = "正常";
    }

    if(warninge1){
        ui->l_df_1->setStyleSheet("border-image:url(:/images/warning/alarm.png)");
        LiftdeviceWarningHL = "低警告";
    }else             ui->l_df_1->setStyleSheet("border-image:url(:/images/warning/normal.png)");
    if(warninge2){
        ui->l_df_2->setStyleSheet("border-image:url(:/images/warning/alarm.png)");
        LiftdeviceWarningHL = "高警告";
    }else             ui->l_df_2->setStyleSheet("border-image:url(:/images/warning/normal.png)");
    if(!warninge1&&!warninge2){
        LiftdeviceWarningHL = "正常";
    }
    if(warninge3){
        ui->l_df_3->setStyleSheet("border-image:url(:/images/warning/alarm.png)");
        LiftdeviceWarningD = "堵塞警告";
    }else{
        ui->l_df_3->setStyleSheet("border-image:url(:/images/warning/normal.png)");
        LiftdeviceWarningD = "正常";
    }
}


//损失率和含杂率-----18FF1809
void myWidget::get_lose_rate(int array[8]){
    /* 0x18FF1809,字节0-7
     * 第0字节表示清选损失率
     * 第1字节表示夹带损失率
     * ***************第2字节表示割台损失率,已取消
     * 第3字节表示清选含杂率低位,第4字节表示清选含杂率高位，最高三位表示含杂率等级0-7
     * 第5字节表示破碎率
     * */

    CheckLossrate = array[0];          //清选损失率
    EntrainmentLossrate = array[1];    //夹带损失率
    ClearInclusionrate = array[3] + (array[4]&0x3)*256;   //清选含杂率
    HanZaLevel = (array[4] & 0xe0 ) >> 5;                 //含杂率等级
    BrokenRate = array[5];                                //破碎率


    ui->dr_fan_rate->setText(tr("%1").arg(CheckLossrate/10));
    ui->drift_lose_rate->setText(tr("%1").arg(EntrainmentLossrate/10));
    ui->dr_fan_impr_rate->setText(tr("%1").arg(ClearInclusionrate/10));
    ui->impr_rate->setText(tr("%1").arg(HanZaLevel));
    ui->l_crushrate->setText(tr("%1").arg(BrokenRate/10));
}


//空、前进、倒档-----18FF1909
void myWidget::get_gear_state(int array[8]){
    /* 0x18FF1909,字节0-7，11、10未定义；01开关闭合，信号触发；00开关未闭合，信号未触发
     * 第0字节第0-1位表示空挡N
     * 第0字节第2-3位表示倒挡R
     * 第0字节第4-5位表示前进挡F
     * */
    qreal val1 = (array[0] & 0x3) ;
    qreal val2 = (array[0] & 0xc) >> 2;
    qreal val3 = (array[0] & 0x30) >> 4;

    if(val1 == 1)       ui->eng_gear->setStyleSheet("border-image:url(:/images/engine/N.png)");
    else if(val2 == 1)  ui->eng_gear->setStyleSheet("border-image:url(:/images/engine/R.png)");
    else if(val3 == 1)  ui->eng_gear->setStyleSheet("border-image:url(:/images/engine/F.png)");
    else                ui->eng_gear->setStyleSheet("");
}


//18FF2111----备用
void myWidget::get_2111(int array[8])
{


}


//抛撒器角度和切碎器转速-----18FF2011
void myWidget::get_throw_angle(int array[8]){
    /* 0x18FF2011,字节0-7
     * 第0字节表示抛撒器幅宽低位，第1字节表示抛撒器幅宽高位
     * 第2字节表示抛撒器扭矩低位，第3字节表示抛撒器扭矩高位
     * 第4字节表示切碎器转速低位，第5字节表示切碎器转速高位
     * */

    SprinklerWidth = array[0] + array[1]*256;
    SprinklerTorque = array[4] + (array[5] & 0x1f)*256;

    qreal warning1  = (array[5] & 0xe0) >> 5;   //判断是否有报警
    qreal warninge1 = (array[5] & 0x20) >> 5;   //转速过低报警13
    qreal warninge2 = (array[5] & 0x40) >> 6;   //转速过高报警14
    qreal warninge3 = (array[5] & 0x80) >> 7;   //堵塞报警15

    if((array[0] == (qreal)(0xff) && array[1] == (qreal)(0xff)) || (array[4] == (qreal)(0xff) && array[5] == (qreal)(0xff))){

        if(array[0] == (qreal)(0xff) && array[1] == (qreal)(0xff))
            SprinklerAngle = 0;
        if(array[4] == (qreal)(0xff) && array[5] == (qreal)(0xff))
            ChopperSpeed = warning1 = warninge1 = warninge2 = warninge3 = 0;
    }

    ui->SprinklerWidth->setText(tr("%1").arg(SprinklerWidth));
    ui->SprinklerTorque->setText(tr("%1").arg(SprinklerTorque));

    if(warning1){
        ui->w_cut_mach->setStyleSheet("border-image:url(:/images/engine/warning.png)");
        ui->w_cut_mach->glitter();
    }else{
        ui->w_cut_mach->setStyleSheet(" ");
        ChopperWarningHL = "正常";
        ChopperWarningD = "正常";
    }

    if(warninge1){
        ui->l_es_1->setStyleSheet("border-image:url(:/images/warning/alarm.png)");
        ChopperWarningHL = "低警告";
    }else       ui->l_es_1->setStyleSheet("border-image:url(:/images/warning/normal.png)");
    if(warninge2){
        ui->l_es_2->setStyleSheet("border-image:url(:/images/warning/alarm.png)");
        ChopperWarningHL = "高警告";
    }else       ui->l_es_2->setStyleSheet("border-image:url(:/images/warning/normal.png)");
    if(!warninge1&&!warninge2){
        ChopperWarningHL = "正常";
    }
    if(warninge3){
        ui->l_es_3->setStyleSheet("border-image:url(:/images/warning/alarm.png)");
        ChopperWarningD = "堵塞警告";
    }else{
        ChopperWarningD = "正常";
        ui->l_es_3->setStyleSheet("border-image:url(:/images/warning/normal.png)");
    }
}


//导航----18FF2213
//XYZ speed
void myWidget::getGPS(int array[8])
{
    isGuidingSytemOn = array[0]&1;

    if(isGuidingSytemOn)
        ui->l_isGuidingSystemOn->setStyleSheet("border-image:url(:/images/GPS_ON.png)");
    else
        ui->l_isGuidingSystemOn->setStyleSheet("border-image:url(:/images/GPS_OFF.png)");

    xSpeed = array[1] + array[2]*256;
    ySpeed = array[3] + array[4]*256;
    zSpeed = array[5] + array[6]*256;

    ui->xSpeed->setText(tr("%1").arg(xSpeed));
    ui->ySpeed->setText(tr("%1").arg(ySpeed));
    ui->zSpeed->setText(tr("%1").arg(zSpeed));

}

//仿形高度等
void myWidget::get_detect_value(int array[8]){
    /* 0x18FF2313,字节0-7
     * 第0字节表示仿形高度检测值低位，第1字节表示仿形高度检测值高位
     *
     * 第4字节表示农作物高度检测值低位，第5字节表示农作物高度检测值高位
     * */

    ProfilingHeightvalue = array[0] + array[1]*256;
    CropHeightvalue = array[4] + array[5]*256;

    if((array[0] == (qreal)(0xff) && array[1] == (qreal)(0xff)) ||
            (array[2] == (qreal)(0xff) && array[3] == (qreal)(0xff)) ||
            (array[4] == (qreal)(0xff) && array[5] == (qreal)(0xff))){

        if(array[0] == (qreal)(0xff) && array[1] == (qreal)(0xff))
            ProfilingHeightvalue = 0;
        if(array[4] == (qreal)(0xff) && array[5] == (qreal)(0xff))
            CropHeightvalue = 0;
    }
    ui->profiling_height->setText(tr("%1").arg(ProfilingHeightvalue));
    ui->cropHeight->setText(tr("%1").arg(CropHeightvalue));
}



//割宽----18FF2413
void myWidget::get_cut_width(int array[8]){
    /* 0x18FF2413,字节0-7
     * 第0字节表示割宽（左）检测值
     * 第1字节割宽（右）检测值
     * */
    CutwidthLeftvalue = array[0]+array[1]*256;
    CutwidthRightvalue = array[2]+array[3]*256;

    if(CutwidthLeftvalue > 255) CutwidthLeftvalue = 0;
    if(CutwidthRightvalue > 255) CutwidthRightvalue = 0;

    CarSpeed = array[4] + array[5]*256 ;

    if(CarSpeed >= 600)
        CarSpeed = 600;
    ui->widget_eng->setValue(CarSpeed/10);

    ui->label_95->setText(tr("%1").arg(CutwidthLeftvalue));
    ui->label_96->setText(tr("%1").arg(CutwidthRightvalue));
}

//18FF2913 ---备用
void myWidget::get_real_speed(int array[8])
{


}

//拨禾轮转速等
void myWidget::get_cutter_freq(int array[8]){
    /* 0x18FF2515,字节0-7
     * 第0字节表示拨禾轮转速低位,第1字节表示拨禾轮转速高位，14-16位报警
     * 第2字节表示拨禾轮高度，0xFF表示无效
     * 第3字节表示拨禾轮前后位移，0xFF表示无效
     * 第4字节表示喂入搅龙转速低位，第5字节表示喂入搅龙转速高位，14-16位报警
     * 第6字节表示喂入搅龙转矩低位，第7字节表示喂入搅龙转矩高位，0xFF表示无效
     * */
    BohelunSpeed = array[0] + (array[1] & 0x1f)*256;
    BohelunHeightvalue = array[2];
    BohelunDisplacement = array[3];
    FeedSpeed = array[4] + (array[5] & 0x1f)*256;

    qreal warning1  = (array[1] & 0xe0) >> 5;   //判断是否有报警
    qreal warninge1 = (array[1] & 0x20) >> 5;   //转速过低报警13
    qreal warninge2 = (array[1] & 0x40) >> 6;   //转速过高报警14
    qreal warninge3 = (array[1] & 0x80) >> 7;   //堵塞报警15

    qreal warning2  = (array[5] & 0xe0) >> 5;   //判断是否有报警
    qreal warningg1 = (array[5] & 0x20) >> 5;   //转速过低报警13
    qreal warningg2 = (array[5] & 0x40) >> 6;   //转速过高报警14
    qreal warningg3 = (array[5] & 0x80) >> 7;   //堵塞报警15

    if((array[2] == (qreal)(0xff) || array[3] == (qreal)(0xff))){

        if(array[2] == (qreal)(0xff))
            BohelunHeightvalue = 0;
        if(array[3] == (qreal)(0xff))
            BohelunDisplacement = 0;
    }

    ui->l_reedspeed->setText(tr("%1").arg(BohelunSpeed));
    ui->reel_height->setText(tr("%1").arg(BohelunHeightvalue));
    ui->reel_shift->setText(tr("%1").arg(BohelunDisplacement));
    ui->l_fdaugersp->setText(tr("%1").arg(FeedSpeed));

    if(warning1){
        ui->w_reed_speed->setStyleSheet("border-image:url(:/images/engine/warning.png)");
        ui->w_reed_speed->glitter();
    }else{
        BohelunWarningHL = "正常";
        BohelunWarningD = "正常";
        ui->w_reed_speed->setStyleSheet(" ");
    }
    if(warninge1){
        ui->l_fcm_1->setStyleSheet("border-image:url(:/images/warning/alarm.png)");
        BohelunWarningHL = "低警告";
    }else             ui->l_fcm_1->setStyleSheet("border-image:url(:/images/warning/normal.png)");
    if(warninge2){
        ui->l_fcm_2->setStyleSheet("border-image:url(:/images/warning/alarm.png)");
        BohelunWarningHL = "高警告";
    }else             ui->l_fcm_2->setStyleSheet("border-image:url(:/images/warning/normal.png)");
    if(!warninge1&&!warninge2)
    {
        BohelunWarningHL = "正常";
    }
    if(warninge3){
        ui->l_fcm_3->setStyleSheet("border-image:url(:/images/warning/alarm.png)");
        BohelunWarningD = "堵塞警告";
    }else{
        BohelunWarningD = "正常";
        ui->l_fcm_3->setStyleSheet("border-image:url(:/images/warning/normal.png)");
    }
    if(warning2){
        ui->w_fdaugersp->setStyleSheet("border-image:url(:/images/engine/warning.png)");
        ui->w_fdaugersp->glitter();
    }else{
        FeedWarningD = "正常";
        FeedWarningHL = "正常";
        ui->w_fdaugersp->setStyleSheet(" ");
    }
    if(warningg1){
        ui->l_fd_1->setStyleSheet("border-image:url(:/images/warning/alarm.png)");
        FeedWarningHL = "低警告";
    }else       ui->l_fd_1->setStyleSheet("border-image:url(:/images/warning/normal.png)");
    if(warningg2){
        ui->l_fd_2->setStyleSheet("border-image:url(:/images/warning/alarm.png)");
        FeedWarningHL = "高警告";
    }else       ui->l_fd_2->setStyleSheet("border-image:url(:/images/warning/normal.png)");
    if(!warningg1&&!warningg2)
    {
        FeedWarningHL = "正常";
    }
    if(warningg3){
        ui->l_fd_3->setStyleSheet("border-image:url(:/images/warning/alarm.png)");
        FeedWarningD = "堵塞警告";
    }else{
        FeedWarningD = "正常";
        ui->l_fd_3->setStyleSheet("border-image:url(:/images/warning/normal.png)");
    }
}

//喂入量---18FF2615
void myWidget::get_feed(int array[8]){
    /* 0x18FF2615,字节0-7
     * 第0字节表示喂入量
     * 第1字节表示割台损失率
     * 第2字节表示割刀频率低位,第3字节表示割刀频率高位
     * */
    FeedQuantity = array[0];
    CutterLossrate = array[1];
    CutterFrequency = array[2] + array[3]*256;

    if(array[0] == (qreal)(0xff)){
        FeedQuantity = 0;
    }

    ui->label_99->setText(tr("%1").arg(FeedQuantity/10));
    ui->label_88->setText(tr("%1").arg(CutterLossrate));
    ui->label_47->setText(tr("%1").arg(CutterFrequency));
}


//滚筒转速和转矩
void myWidget::get_drum_speed(int array[8]){
    /* 0x18FF2717,字节0-7
     * 第0字节表示轴流(切流)滚筒转速低位,第1字节表示轴流(切流)滚筒转速高位，14-16位报警
     * 第2字节表示轴流(切流)滚筒转矩低位,第3字节表示轴流(切流)滚筒转矩高位
     * 第4字节表示凹板间隙检测值
     * */
    AxialflowRollerSpeed = array[0] + (array[1] & 0x1f)*256;
    AxialflowRollerTorque = array[2] + array[3] * 256;
    GravureGapvalue = array[4];

    qreal warning1  = (array[1] & 0xe0) >> 5;   //判断是否有报警
    qreal warningr1 = (array[1] & 0x20) >> 5;   //转速过低报警13
    qreal warningr2 = (array[1] & 0x40) >> 6;   //转速过高报警14
    qreal warningr3 = (array[1] & 0x80) >> 7;   //堵塞报警15


    ui->l_rollerspeed->setText(tr("%1").arg(AxialflowRollerSpeed));
    ui->roller_torque->setText(tr("%1").arg(AxialflowRollerTorque));
    ui->l_concavecl->setText(tr("%1").arg(GravureGapvalue));

    if(warning1){
        ui->w_rollerspeed->setStyleSheet("border-image:url(:/images/engine/warning.png)");
        ui->w_rollerspeed->glitter();
    }else{
        AxialflowWarningHL = "正常";
        AxialflowWarningD = "正常";
        ui->w_rollerspeed->setStyleSheet(" ");
    }
    if(warningr1){
        ui->l_rls_1->setStyleSheet("border-image:url(:/images/warning/alarm.png)");
        AxialflowWarningHL = "低警告";
    }else       ui->l_rls_1->setStyleSheet("border-image:url(:/images/warning/normal.png)");
    if(warningr2){
        ui->l_rls_2->setStyleSheet("border-image:url(:/images/warning/alarm.png)");
        AxialflowWarningHL = "高警告";
    }else       ui->l_rls_2->setStyleSheet("border-image:url(:/images/warning/normal.png)");
    if(!warningr1&&!warningr2)
    {
        AxialflowWarningHL = "正常";
    }
    if(warningr3){
        ui->l_rls_3->setStyleSheet("border-image:url(:/images/warning/alarm.png)");
        AxialflowWarningD = "堵塞警告";
    }else{
        AxialflowWarningD = "正常";
        ui->l_rls_3->setStyleSheet("border-image:url(:/images/warning/normal.png)");
    }

}

//18FEEE00
//发动机冷却水温
void myWidget::get_eng_thm(int array[8]){
    EngineerTemperature = array[0]-40;
    if(EngineerTemperature >= 120)
        EngineerTemperature = 120;
    ui->l_eng_them->setText(QString::fromUtf8("%1", -1).arg(EngineerTemperature));     //设置l_eng_them的值,转换格式，使能够正常显示单位
}


//18FEEF00
//发动机油压力
void myWidget::get_eng_oilpres(int array[8]){
    OilPressure = array[3]*4;
    ui->w_eopres->setValue(OilPressure);
}

//0CF00400
//发动机转速
void myWidget::get_eng_rev(int array[8])
{
    EngineerSpeed = (array[3]+array[4]*256);
    if(EngineerSpeed >= 3000)
        EngineerSpeed = 3000;
    ui->widget_Tach->setValue(EngineerSpeed);
}


//传感器数据初始化
void myWidget::SensordataInit()
{
    EngineerWorktime = 0;
    TotalMileage = 0;
    CarSpeed = 0;
    Fuel = 0;
    SystemVoltage = 0;
    OilPressure = 0;
    MetericMileage = 0;
    CheckLossrate = 0;
    EntrainmentLossrate = 0;
    ClearInclusionrate = 0;
    BrokenRate = 0;
    HanZaLevel = 0;
    EngineerSpeed = 0;
    EngineerTemperature = 0;
    ChopperSpeed = 0;
    FunSpeed = 0;
    CutterFrequency = 0;
    BohelunSpeed = 0;
    AxialflowRollerSpeed = 0;
    Retractor = 0;
    LiftdeviceSpeed = 0;
    FeedSpeed = 0;
    WaterRate = 0;
    ProductionSquaremeter = 0;
    GrainDryweight = 0;
    GrainWetweight = 0;
    GravureGapvalue = 0;
    UpsieveOpendegree = 0;
    DownsieveOpendegree = 0;
    LastsieveOpendegree = 0;
    ProfilingHeightvalue = 0;
    CutterHeightvalue = 0;
    CropHeightvalue = 0;
    BohelunHeightvalue = 0;
    BohelunDisplacement = 0;
    FormotorSpeed = 0;
    BehmotorSpeed = 0;
    AxialflowRollerTorque = 0;
    CutterLossrate = 0;
    GrainflowQuality = 0;
    PartwindBoard = 0;
    SprinklerAngle = 0;
    SprinklerWidth = 0;
    SprinklerTorque =0;
    CutwidthLeftvalue = 0;
    CutwidthRightvalue = 0;
    FeedQuantity = 0;
}

//警告数据初始化
void myWidget::StatedataInit()
{
    GrainWarning = "正常";
    FormotorWarningHL = "正常";
    FormotorWarningD = "正常";
    BehmotorWarningHL = "正常";
    BehmotorWarningD = "正常";
    RetractorWarningHL = "正常";
    RetractorWarningD = "正常";
    LiftdeviceWarningHL = "正常";
    LiftdeviceWarningD = "正常";
    ChopperWarningHL = "正常";
    ChopperWarningD = "正常";
    FunSpeedWarningHL = "正常";
    FunSpeedWarningD = "正常";
    FeedWarningHL = "正常";
    FeedWarningD = "正常";
    BohelunWarningHL = "正常";
    BohelunWarningD = "正常";
    AxialflowWarningHL = "正常";
    AxialflowWarningD = "正常";
}



