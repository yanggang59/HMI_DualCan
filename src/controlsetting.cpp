#include "./header/controlsetting.h"
#include "ui_controlsetting.h"

ControlSetting::ControlSetting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ControlSetting)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::WindowStaysOnTopHint);

    InitValue();

    send_control_setting();

    timer_500ms->start(500);
    timer_1000ms->start(1000);
}

//
ControlSetting::~ControlSetting()
{
    delete ui;
}

void ControlSetting::InitValue()
{

    arrctl5030.resize(8);
    arrctl5130.resize(8);
    arrctl5230.resize(8);
    arrctl5330.resize(8);
    arrctl5430.resize(8);
    arrctl5530.resize(8);

    for(int i = 0 ; i < 8 ; i++){
        arrctl5030[i] = 0;
        arrctl5130[i] = 0;
        arrctl5230[i] = 0;
        arrctl5330[i] = 0;
        arrctl5430[i] = 0;
        arrctl5530[i] = 0;
    }

    timer_500ms=new QTimer(this);
    timer_1000ms=new QTimer(this);

    isSendValid = false;
}

void ControlSetting::send_control_setting()
{
    connect(ui->OK_btn,SIGNAL(clicked()),this,SLOT(setvalid()));
    connect(ui->Cancel_btn,SIGNAL(clicked()),this,SLOT(setinvalid()));

    connect(timer_500ms,SIGNAL(timeout()),this,SLOT(sendPer500ms()));
    connect(timer_1000ms,SIGNAL(timeout()),this,SLOT(sendPer1000ms()));
}

void ControlSetting::setvalid(){

    int clear_meter ;
    int reset_cutheight;
    int control_unloader;
    int auto_loader;
    int auto_cutheight;
    int reset_weight;

    if(ui->cbx_4->currentIndex() == 1)          clear_meter = 1;            //清零
    else                                        clear_meter = 0;            //无动作

    if(ui->cbx_3->currentIndex() == 0)          reset_cutheight = 0;        //脱开
    else if (ui->cbx_3->currentIndex() == 1)    reset_cutheight = 1;        //割台提升
    else if (ui->cbx_3->currentIndex() == 2)    reset_cutheight = 2;        //割台下降
    else                                        reset_cutheight = 3;        //未定义

    if(ui->cbx_1->currentIndex() == 0)          control_unloader = 4;       //停止
    else if (ui->cbx_1->currentIndex() == 1)    control_unloader = 5;       //动态展开
    else if (ui->cbx_1->currentIndex() == 2)    control_unloader = 6;       //静态展开
    else if (ui->cbx_1->currentIndex() == 3)    control_unloader = 7;       //收回
    else                                        control_unloader = 0;       //无动作

    if(ui->cbx_5->currentIndex() == 0)          auto_loader = 0;            //关闭负荷自动调节
    else if (ui->cbx_5->currentIndex() == 1)    auto_loader = 1;            //开启负荷自动调节
    else                                        auto_loader = 2;            //无动作

    if(ui->cbx_6->currentIndex() == 0)          auto_cutheight = 0;         //关闭割台高度自动调节
    else if (ui->cbx_6->currentIndex() == 1)    auto_cutheight = 1;         //开启割台高度自动调节
    else                                        auto_cutheight = 2;         //无动作

    if(ui->cbx_7->currentIndex() == 0)          reset_weight = 0;           //无动作
    else if (ui->cbx_7->currentIndex() == 1)    reset_weight = 1;           //清零
    else                                        reset_weight = 2;           //未定义

    if(ui->cbx_9->currentIndex() == 1)          arrctl5330[0] = 1;          //静音
    else if (ui->cbx_9->currentIndex() == 2)    arrctl5330[0] = 2;          //播放
    else                                        arrctl5330[0] = 0;          //无动作
    /*
     * added on 2019.4.5
    */
    int StalkMoisture = (int)(ui->l_StalkMoisture->text().toFloat()*100);   //茎干含水率设置值
    arrctl5330[1] = StalkMoisture%256;
    arrctl5330[2] = StalkMoisture/256;

    int CroppingIntensity = (int)(ui->l_CroppingIntensity->text().toFloat()*100);
    arrctl5330[3] = CroppingIntensity%256;                                 //作物密度设置值
    arrctl5330[4] = CroppingIntensity/256;

    int GrassGrainRatio = ui->l_GrassrGrainratio->text().toFloat();       //草谷比设置值
    arrctl5330[5] = GrassGrainRatio;

    int PlantHeight = ui->l_PlantHeight->text().toFloat();                //农作物高度设置值
    arrctl5330[6] = PlantHeight%256;
    arrctl5330[7] = PlantHeight/256;


    int AxialRollerSpeedMin = ui->l_AxialRollerSpeedMin->text().toFloat(); //轴流滚筒转速下限设置值
    arrctl5430[0] = AxialRollerSpeedMin%256;
    arrctl5430[1] = AxialRollerSpeedMin/256;

    int AxialRollerSpeedMax = ui->l_AxialRollerSpeedMax->text().toFloat(); //轴流滚筒转速上限设置值
    arrctl5430[2] = AxialRollerSpeedMax%256;
    arrctl5430[3] = AxialRollerSpeedMax/256;

    /*
     * added on 2019.4.3 18FF5530
    */
    if(ui->cbx_heartbeat->currentIndex() == 0) arrctl5530[0] = 1;           //01:仪表在线
    else arrctl5530[0] = 0;                                                 //00:仪表掉线



    /*
     * added on 2019.4.3 18FF5130
    */
    float le = ui->l_weight1000->text().toFloat();  //千粒重设置值
    int pfh = ui->l_pfh->text().toFloat();          //仿形高度设置值
    int cutx = ui->l_cuth_max->text().toFloat();    //割台返回高度上限
    int cutn = ui->l_cuth_min->text().toFloat();    //割台返回高度下限

    /*
     * added on 2019.4.3
    */
    arrctl5130[0] = ((int)(le*100))%256;    //千粒重设置值
    arrctl5130[1] = (int(le*100))/256;
    arrctl5130[2] = pfh%256;                //仿形高度设置值
    arrctl5130[3] = pfh/256;
    arrctl5130[4] = cutx%256;               //割台返回高度上限
    arrctl5130[5] = cutx/256;
    arrctl5130[6] = cutn%256;               //割台返回高度下限
    arrctl5130[7] = cutn/256;

    /*
     * added on 2019.4.3 18FF5230
    */
    int rsls = ui->l_rsls->text().toFloat();                    //轴流滚筒堵塞转速低报警设置值
    int concaveclset = ui->l_concaveclset->text().toFloat();    //凹版间隙调节值
    int cuttermode = 0;                                         //切碎器工作模式
    int grainkd = 0;                                            //当前作物种类

    if(ui->cutterMode->currentIndex() == 1)   cuttermode = 1;          //排草
    else cuttermode = 0;                                               //切碎

    if(ui->grain_kind->currentIndex() == 0)          grainkd = 0;       //"水稻"
    else if (ui->grain_kind->currentIndex() == 1)    grainkd = 1;       //"小麦"
    else if (ui->grain_kind->currentIndex() == 2)    grainkd = 2;       //"玉米"
    else if (ui->grain_kind->currentIndex() == 3)    grainkd = 3;       //"大豆"L
    else if (ui->grain_kind->currentIndex() == 4)    grainkd = 15;      //"其他"

    int ConcaveclClearanceSetMax = ui->l_ConcaveclSetMax->text().toFloat(); //凹板间隙上限
    int ConcaveclClearanceSetMin = ui->l_ConcaveclSetMin->text().toFloat(); //凹板间隙下限

    arrctl5230[1] = rsls % 256;
    arrctl5230[2] = rsls / 256;
    arrctl5230[3] = concaveclset;
    arrctl5230[6] = (cuttermode << 4) | grainkd;
    arrctl5230[4] = ConcaveclClearanceSetMax;
    arrctl5230[5] = ConcaveclClearanceSetMin;
    arrctl5230[0]  = arrctl5230[7] = 0;

    arrctl5030[0] = (clear_meter << 2) | (reset_cutheight << 4);
    arrctl5030[1] = control_unloader | (auto_loader << 3) | (auto_cutheight << 5);
    arrctl5030[2] = reset_weight;

    /*
    *18FF5030是按需发送
    *18FF5130、18FF5230、18FF5330是每隔500ms发送一次
    *18FF5430、18FF5530是每隔1000ms发送一次
    */
    can0_send(arrctl5030,0x18FF5030);
    isSendValid = true;
    this->hide();
}

void ControlSetting::setinvalid()
{
    this->hide();
}

void ControlSetting::sendPer500ms()
{
    if(isSendValid)
    {
        can0_send(arrctl5130,0x18FF5130);
        can1_send(arrctl5230,0x18FF5230);
        can1_send(arrctl5330,0x18FF5330);
    }
}

void ControlSetting::sendPer1000ms()
{
    if(isSendValid)
    {
        can1_send(arrctl5430,0x18FF5430);
        /*
         * added on 2019.6.19 18FF5530
        */
        QTime current_time=QTime::currentTime();
        int hour=current_time.hour();
        int minute=current_time.minute();
        int second=current_time.second();

        QDate current_date=QDate::currentDate();
        int year=current_date.year();
        int month=current_date.month();
        int day=current_date.day();

        arrctl5530[1] = year%256;
        arrctl5530[2] = year/256;
        arrctl5530[3] = month;
        arrctl5530[4] = day;
        arrctl5530[5] = hour;
        arrctl5530[6] = minute;
        arrctl5530[7] = second;

        can1_send(arrctl5530,0x18FF5530);
    }
}

void ControlSetting::saveConfig()
{


}

void ControlSetting::resumeConfig()
{


}
