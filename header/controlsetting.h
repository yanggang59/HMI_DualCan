#ifndef CONTROLSETTING_H
#define CONTROLSETTING_H

#include <QDialog>
#include <QDebug>
#include <QTimer>
#include "can_recv_send.h"
#include <QTime>
#include <QDate>
#include <QDateTime>
#include "header/INIParser.h"
#include <QSettings>


namespace Ui {
class ControlSetting;
}

//
class ControlSetting : public QDialog
{
    Q_OBJECT

public:
    explicit ControlSetting(QWidget *parent = 0);
    ~ControlSetting();

private:
    Ui::ControlSetting *ui;

    QByteArray arrctl5030;
    QByteArray arrctl5130;
    QByteArray arrctl5230;
    QByteArray arrctl5330;
    QByteArray arrctl5430;
    QByteArray arrctl5530;

    QTimer *timer_500ms;      //500 ms timer
    QTimer *timer_1000ms;     //1000 ms timer

    //QSettings* testConfig;

    bool isSendValid;

    void send_control_setting();
    void InitValue();

    //save config and resume config using INI file
    void saveConfig();
    void resumeConfig();

private slots:
    void setvalid();
    void setinvalid();

    void sendPer500ms();
    void sendPer1000ms();
};

#endif // CONTROLSETTING_H
