/********************************************************************************
** Form generated from reading UI file 'parametersetting.ui'
**
** Created: Sat Jul 27 10:36:28 2019
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PARAMETERSETTING_H
#define UI_PARAMETERSETTING_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QScrollArea>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ParameterSetting
{
public:
    QPushButton *OK_btn;
    QPushButton *Cancel_btn;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QLabel *l_cutterFrequencyTarget;
    QLabel *label_106;
    QLabel *label_9;
    QLabel *label_107;
    QLabel *l_augerSpeedTarget;
    QLabel *label_11;
    QLabel *label_109;
    QLabel *l_cleanFanSpeedTarget;
    QLabel *label_13;
    QLabel *label_108;
    QLabel *label_12;
    QLabel *l_rollerSpeedTarget;
    QLabel *label_104;
    QLabel *label_14;
    QLabel *l_winderSpeedTarget;
    QLabel *label;
    QLabel *l_winderHydraulicMotorFlow;
    QLabel *label_3;
    QLabel *label_6;
    QLabel *l_feedingAugerHydraulicMotorFlow;
    QLabel *label_4;
    QLabel *labe_7;
    QLabel *l_cutterHydraulicMotorFlow;
    QLabel *label_10;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_4;
    QLabel *label_7;
    QLabel *label_15;
    QLabel *label_2;
    QLabel *l_winderHydraulicMotorReturnOilPressure;
    QLabel *label_17;
    QLabel *l_winderHydraulicMotorTakeOilPressure;
    QLabel *l_feedingAugerHydraulicMotorReturnOilPressure;
    QLabel *label_26;
    QLabel *label_23;
    QLabel *label_22;
    QLabel *label_29;
    QLabel *l_cutterHydraulicMotorTakeOilPressure;
    QLabel *label_27;
    QLabel *label_18;
    QLabel *label_21;
    QLabel *l_cuttingPlatformHeight;
    QLabel *l_cutterHydraulicMotorReturnOilPressure;
    QLabel *l_feedingAugerHydraulicMotorTakeOilPressure;
    QLabel *label_28;
    QLabel *label_24;
    QLabel *label_25;

    void setupUi(QDialog *ParameterSetting)
    {
        if (ParameterSetting->objectName().isEmpty())
            ParameterSetting->setObjectName(QString::fromUtf8("ParameterSetting"));
        ParameterSetting->resize(457, 392);
        QFont font;
        font.setFamily(QString::fromUtf8("AR PL UKai CN"));
        font.setPointSize(17);
        ParameterSetting->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/leiwo.png"), QSize(), QIcon::Normal, QIcon::Off);
        ParameterSetting->setWindowIcon(icon);
        OK_btn = new QPushButton(ParameterSetting);
        OK_btn->setObjectName(QString::fromUtf8("OK_btn"));
        OK_btn->setGeometry(QRect(250, 350, 81, 35));
        OK_btn->setStyleSheet(QString::fromUtf8("background-color: rgb(58, 111, 249);"));
        Cancel_btn = new QPushButton(ParameterSetting);
        Cancel_btn->setObjectName(QString::fromUtf8("Cancel_btn"));
        Cancel_btn->setGeometry(QRect(340, 350, 81, 35));
        Cancel_btn->setStyleSheet(QString::fromUtf8("background-color: rgb(249, 88, 88);"));
        scrollArea = new QScrollArea(ParameterSetting);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(10, 10, 211, 371));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 209, 369));
        l_cutterFrequencyTarget = new QLabel(scrollAreaWidgetContents);
        l_cutterFrequencyTarget->setObjectName(QString::fromUtf8("l_cutterFrequencyTarget"));
        l_cutterFrequencyTarget->setGeometry(QRect(60, 10, 61, 20));
        l_cutterFrequencyTarget->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_106 = new QLabel(scrollAreaWidgetContents);
        label_106->setObjectName(QString::fromUtf8("label_106"));
        label_106->setGeometry(QRect(10, 0, 39, 40));
        label_106->setStyleSheet(QString::fromUtf8("border-image: url(:/images/engine/CutterHz.png)"));
        label_9 = new QLabel(scrollAreaWidgetContents);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(140, 0, 21, 30));
        label_107 = new QLabel(scrollAreaWidgetContents);
        label_107->setObjectName(QString::fromUtf8("label_107"));
        label_107->setGeometry(QRect(10, 50, 39, 40));
        label_107->setStyleSheet(QString::fromUtf8("border-image: url(:/images/engine/FeedAugerSpeed.png)"));
        l_augerSpeedTarget = new QLabel(scrollAreaWidgetContents);
        l_augerSpeedTarget->setObjectName(QString::fromUtf8("l_augerSpeedTarget"));
        l_augerSpeedTarget->setGeometry(QRect(60, 50, 61, 17));
        l_augerSpeedTarget->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_11 = new QLabel(scrollAreaWidgetContents);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(140, 40, 40, 30));
        label_109 = new QLabel(scrollAreaWidgetContents);
        label_109->setObjectName(QString::fromUtf8("label_109"));
        label_109->setGeometry(QRect(10, 90, 39, 40));
        label_109->setStyleSheet(QString::fromUtf8("border-image: url(:/images/engine/draught_fan.png)"));
        l_cleanFanSpeedTarget = new QLabel(scrollAreaWidgetContents);
        l_cleanFanSpeedTarget->setObjectName(QString::fromUtf8("l_cleanFanSpeedTarget"));
        l_cleanFanSpeedTarget->setGeometry(QRect(60, 100, 61, 17));
        l_cleanFanSpeedTarget->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_13 = new QLabel(scrollAreaWidgetContents);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(140, 90, 40, 30));
        label_108 = new QLabel(scrollAreaWidgetContents);
        label_108->setObjectName(QString::fromUtf8("label_108"));
        label_108->setGeometry(QRect(10, 130, 39, 40));
        label_108->setStyleSheet(QString::fromUtf8("border-image: url(:/images/engine/RollerSpeed.png)"));
        label_12 = new QLabel(scrollAreaWidgetContents);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(140, 140, 40, 30));
        l_rollerSpeedTarget = new QLabel(scrollAreaWidgetContents);
        l_rollerSpeedTarget->setObjectName(QString::fromUtf8("l_rollerSpeedTarget"));
        l_rollerSpeedTarget->setGeometry(QRect(60, 140, 61, 21));
        l_rollerSpeedTarget->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_104 = new QLabel(scrollAreaWidgetContents);
        label_104->setObjectName(QString::fromUtf8("label_104"));
        label_104->setGeometry(QRect(10, 180, 39, 40));
        label_104->setStyleSheet(QString::fromUtf8("border-image: url(:/images/engine/ReelSpeed.png)"));
        label_14 = new QLabel(scrollAreaWidgetContents);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(150, 180, 40, 30));
        l_winderSpeedTarget = new QLabel(scrollAreaWidgetContents);
        l_winderSpeedTarget->setObjectName(QString::fromUtf8("l_winderSpeedTarget"));
        l_winderSpeedTarget->setGeometry(QRect(60, 190, 61, 21));
        l_winderSpeedTarget->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label = new QLabel(scrollAreaWidgetContents);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 220, 40, 40));
        QFont font1;
        font1.setPointSize(12);
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8("border-image: url(:/images/ReelFlow.png)"));
        l_winderHydraulicMotorFlow = new QLabel(scrollAreaWidgetContents);
        l_winderHydraulicMotorFlow->setObjectName(QString::fromUtf8("l_winderHydraulicMotorFlow"));
        l_winderHydraulicMotorFlow->setGeometry(QRect(60, 230, 61, 20));
        l_winderHydraulicMotorFlow->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_3 = new QLabel(scrollAreaWidgetContents);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(140, 230, 67, 21));
        label_6 = new QLabel(scrollAreaWidgetContents);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 260, 40, 40));
        label_6->setFont(font1);
        label_6->setStyleSheet(QString::fromUtf8("border-image: url(:/images/FeedAugerFlow.png)"));
        l_feedingAugerHydraulicMotorFlow = new QLabel(scrollAreaWidgetContents);
        l_feedingAugerHydraulicMotorFlow->setObjectName(QString::fromUtf8("l_feedingAugerHydraulicMotorFlow"));
        l_feedingAugerHydraulicMotorFlow->setGeometry(QRect(60, 270, 61, 20));
        l_feedingAugerHydraulicMotorFlow->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_4 = new QLabel(scrollAreaWidgetContents);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(140, 270, 67, 21));
        labe_7 = new QLabel(scrollAreaWidgetContents);
        labe_7->setObjectName(QString::fromUtf8("labe_7"));
        labe_7->setGeometry(QRect(10, 310, 40, 40));
        labe_7->setFont(font1);
        labe_7->setStyleSheet(QString::fromUtf8("border-image: url(:/images/CutterFlow.png)"));
        l_cutterHydraulicMotorFlow = new QLabel(scrollAreaWidgetContents);
        l_cutterHydraulicMotorFlow->setObjectName(QString::fromUtf8("l_cutterHydraulicMotorFlow"));
        l_cutterHydraulicMotorFlow->setGeometry(QRect(60, 320, 61, 20));
        l_cutterHydraulicMotorFlow->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_10 = new QLabel(scrollAreaWidgetContents);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(140, 320, 67, 17));
        scrollArea->setWidget(scrollAreaWidgetContents);
        scrollArea_2 = new QScrollArea(ParameterSetting);
        scrollArea_2->setObjectName(QString::fromUtf8("scrollArea_2"));
        scrollArea_2->setGeometry(QRect(250, 10, 191, 331));
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_4 = new QWidget();
        scrollAreaWidgetContents_4->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_4"));
        scrollAreaWidgetContents_4->setGeometry(QRect(0, 0, 189, 329));
        label_7 = new QLabel(scrollAreaWidgetContents_4);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(150, 10, 41, 21));
        label_15 = new QLabel(scrollAreaWidgetContents_4);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(150, 60, 67, 21));
        label_2 = new QLabel(scrollAreaWidgetContents_4);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 0, 40, 40));
        label_2->setFont(font1);
        label_2->setStyleSheet(QString::fromUtf8("border-image: url(:/images/ReelFeedingOilPressure.png)"));
        l_winderHydraulicMotorReturnOilPressure = new QLabel(scrollAreaWidgetContents_4);
        l_winderHydraulicMotorReturnOilPressure->setObjectName(QString::fromUtf8("l_winderHydraulicMotorReturnOilPressure"));
        l_winderHydraulicMotorReturnOilPressure->setGeometry(QRect(50, 60, 91, 20));
        l_winderHydraulicMotorReturnOilPressure->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_17 = new QLabel(scrollAreaWidgetContents_4);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(10, 50, 40, 40));
        label_17->setFont(font1);
        label_17->setStyleSheet(QString::fromUtf8("border-image: url(:/images/ReelReturnOilPressure.png)"));
        l_winderHydraulicMotorTakeOilPressure = new QLabel(scrollAreaWidgetContents_4);
        l_winderHydraulicMotorTakeOilPressure->setObjectName(QString::fromUtf8("l_winderHydraulicMotorTakeOilPressure"));
        l_winderHydraulicMotorTakeOilPressure->setGeometry(QRect(50, 10, 91, 20));
        l_winderHydraulicMotorTakeOilPressure->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        l_feedingAugerHydraulicMotorReturnOilPressure = new QLabel(scrollAreaWidgetContents_4);
        l_feedingAugerHydraulicMotorReturnOilPressure->setObjectName(QString::fromUtf8("l_feedingAugerHydraulicMotorReturnOilPressure"));
        l_feedingAugerHydraulicMotorReturnOilPressure->setGeometry(QRect(60, 150, 81, 20));
        l_feedingAugerHydraulicMotorReturnOilPressure->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_26 = new QLabel(scrollAreaWidgetContents_4);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setGeometry(QRect(10, 240, 40, 40));
        label_26->setFont(font1);
        label_26->setStyleSheet(QString::fromUtf8("border-image: url(:/images/CutterReturnOilPressure.png)"));
        label_23 = new QLabel(scrollAreaWidgetContents_4);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(150, 150, 67, 17));
        label_22 = new QLabel(scrollAreaWidgetContents_4);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(150, 100, 67, 17));
        label_29 = new QLabel(scrollAreaWidgetContents_4);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setGeometry(QRect(150, 200, 67, 17));
        l_cutterHydraulicMotorTakeOilPressure = new QLabel(scrollAreaWidgetContents_4);
        l_cutterHydraulicMotorTakeOilPressure->setObjectName(QString::fromUtf8("l_cutterHydraulicMotorTakeOilPressure"));
        l_cutterHydraulicMotorTakeOilPressure->setGeometry(QRect(50, 200, 91, 20));
        l_cutterHydraulicMotorTakeOilPressure->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_27 = new QLabel(scrollAreaWidgetContents_4);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setGeometry(QRect(10, 280, 40, 40));
        label_27->setFont(font1);
        label_27->setStyleSheet(QString::fromUtf8("border-image: url(:/images/cut_height.png)"));
        label_18 = new QLabel(scrollAreaWidgetContents_4);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(10, 140, 40, 40));
        label_18->setFont(font1);
        label_18->setStyleSheet(QString::fromUtf8("border-image: url(:/images/FeedAugerReturnOilPressure.png)"));
        label_21 = new QLabel(scrollAreaWidgetContents_4);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(10, 90, 40, 40));
        label_21->setFont(font1);
        label_21->setStyleSheet(QString::fromUtf8("border-image: url(:/images/FeedAugerFeedingOilPressure.png)"));
        l_cuttingPlatformHeight = new QLabel(scrollAreaWidgetContents_4);
        l_cuttingPlatformHeight->setObjectName(QString::fromUtf8("l_cuttingPlatformHeight"));
        l_cuttingPlatformHeight->setGeometry(QRect(50, 290, 91, 21));
        l_cuttingPlatformHeight->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        l_cutterHydraulicMotorReturnOilPressure = new QLabel(scrollAreaWidgetContents_4);
        l_cutterHydraulicMotorReturnOilPressure->setObjectName(QString::fromUtf8("l_cutterHydraulicMotorReturnOilPressure"));
        l_cutterHydraulicMotorReturnOilPressure->setGeometry(QRect(50, 250, 91, 20));
        l_cutterHydraulicMotorReturnOilPressure->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        l_feedingAugerHydraulicMotorTakeOilPressure = new QLabel(scrollAreaWidgetContents_4);
        l_feedingAugerHydraulicMotorTakeOilPressure->setObjectName(QString::fromUtf8("l_feedingAugerHydraulicMotorTakeOilPressure"));
        l_feedingAugerHydraulicMotorTakeOilPressure->setGeometry(QRect(50, 100, 91, 20));
        l_feedingAugerHydraulicMotorTakeOilPressure->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_28 = new QLabel(scrollAreaWidgetContents_4);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setGeometry(QRect(10, 190, 40, 40));
        label_28->setFont(font1);
        label_28->setStyleSheet(QString::fromUtf8("border-image: url(:/images/CutterFeedingOilPressure.png)"));
        label_24 = new QLabel(scrollAreaWidgetContents_4);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(150, 250, 67, 17));
        label_25 = new QLabel(scrollAreaWidgetContents_4);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(150, 290, 67, 17));
        scrollArea_2->setWidget(scrollAreaWidgetContents_4);

        retranslateUi(ParameterSetting);

        QMetaObject::connectSlotsByName(ParameterSetting);
    } // setupUi

    void retranslateUi(QDialog *ParameterSetting)
    {
        ParameterSetting->setWindowTitle(QApplication::translate("ParameterSetting", "\345\217\202\346\225\260\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        OK_btn->setText(QApplication::translate("ParameterSetting", "OK", 0, QApplication::UnicodeUTF8));
        Cancel_btn->setText(QApplication::translate("ParameterSetting", "Cancel", 0, QApplication::UnicodeUTF8));
        l_cutterFrequencyTarget->setText(QApplication::translate("ParameterSetting", "0", 0, QApplication::UnicodeUTF8));
        label_106->setText(QString());
        label_9->setText(QApplication::translate("ParameterSetting", "Hz", 0, QApplication::UnicodeUTF8));
        label_107->setText(QString());
        l_augerSpeedTarget->setText(QApplication::translate("ParameterSetting", "0", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("ParameterSetting", "rpm", 0, QApplication::UnicodeUTF8));
        label_109->setText(QString());
        l_cleanFanSpeedTarget->setText(QApplication::translate("ParameterSetting", "0", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("ParameterSetting", "rpm", 0, QApplication::UnicodeUTF8));
        label_108->setText(QString());
        label_12->setText(QApplication::translate("ParameterSetting", "rpm", 0, QApplication::UnicodeUTF8));
        l_rollerSpeedTarget->setText(QApplication::translate("ParameterSetting", "0", 0, QApplication::UnicodeUTF8));
        label_104->setText(QString());
        label_14->setText(QApplication::translate("ParameterSetting", "rpm", 0, QApplication::UnicodeUTF8));
        l_winderSpeedTarget->setText(QApplication::translate("ParameterSetting", "0", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        l_winderHydraulicMotorFlow->setText(QApplication::translate("ParameterSetting", "0", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ParameterSetting", "L/min", 0, QApplication::UnicodeUTF8));
        label_6->setText(QString());
        l_feedingAugerHydraulicMotorFlow->setText(QApplication::translate("ParameterSetting", "0", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("ParameterSetting", "L/min", 0, QApplication::UnicodeUTF8));
        labe_7->setText(QString());
        l_cutterHydraulicMotorFlow->setText(QApplication::translate("ParameterSetting", "0", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("ParameterSetting", "L/min", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("ParameterSetting", "bar", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("ParameterSetting", "bar", 0, QApplication::UnicodeUTF8));
        label_2->setText(QString());
        l_winderHydraulicMotorReturnOilPressure->setText(QApplication::translate("ParameterSetting", "0", 0, QApplication::UnicodeUTF8));
        label_17->setText(QString());
        l_winderHydraulicMotorTakeOilPressure->setText(QApplication::translate("ParameterSetting", "0", 0, QApplication::UnicodeUTF8));
        l_feedingAugerHydraulicMotorReturnOilPressure->setText(QApplication::translate("ParameterSetting", "0", 0, QApplication::UnicodeUTF8));
        label_26->setText(QString());
        label_23->setText(QApplication::translate("ParameterSetting", "bar", 0, QApplication::UnicodeUTF8));
        label_22->setText(QApplication::translate("ParameterSetting", "bar", 0, QApplication::UnicodeUTF8));
        label_29->setText(QApplication::translate("ParameterSetting", "bar", 0, QApplication::UnicodeUTF8));
        l_cutterHydraulicMotorTakeOilPressure->setText(QApplication::translate("ParameterSetting", "0", 0, QApplication::UnicodeUTF8));
        label_27->setText(QString());
        label_18->setText(QString());
        label_21->setText(QString());
        l_cuttingPlatformHeight->setText(QApplication::translate("ParameterSetting", "0", 0, QApplication::UnicodeUTF8));
        l_cutterHydraulicMotorReturnOilPressure->setText(QApplication::translate("ParameterSetting", "0", 0, QApplication::UnicodeUTF8));
        l_feedingAugerHydraulicMotorTakeOilPressure->setText(QApplication::translate("ParameterSetting", "0", 0, QApplication::UnicodeUTF8));
        label_28->setText(QString());
        label_24->setText(QApplication::translate("ParameterSetting", "bar", 0, QApplication::UnicodeUTF8));
        label_25->setText(QApplication::translate("ParameterSetting", "mm", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ParameterSetting: public Ui_ParameterSetting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PARAMETERSETTING_H
