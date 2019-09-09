/********************************************************************************
** Form generated from reading UI file 'controlsetting.ui'
**
** Created: Mon Aug 26 16:21:54 2019
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTROLSETTING_H
#define UI_CONTROLSETTING_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include "softkeylineedit.h"

QT_BEGIN_NAMESPACE

class Ui_ControlSetting
{
public:
    QComboBox *cbx_1;
    QLabel *label;
    QLabel *l_chrs;
    QComboBox *cbx_3;
    QLabel *m_reset;
    QComboBox *cbx_4;
    QLabel *auto_load_regu;
    QComboBox *cbx_5;
    QLabel *auto_height;
    QComboBox *cbx_6;
    QLabel *l_rw_cl;
    QComboBox *cbx_7;
    QComboBox *cbx_9;
    QLabel *m_reset_2;
    QPushButton *Cancel_btn;
    QPushButton *OK_btn;
    QLabel *label_103;
    QLabel *label_4;
    SoftKeyLineEdit *l_pfh;
    QLabel *label_3;
    QLabel *label_102;
    SoftKeyLineEdit *l_weight1000;
    QLabel *label_5;
    QLabel *label_2;
    QLabel *label_7;
    QLabel *label_10;
    QLabel *label_23;
    QLabel *label_22;
    SoftKeyLineEdit *l_rsls;
    SoftKeyLineEdit *l_cuth_max;
    SoftKeyLineEdit *l_cuth_min;
    QLabel *label_19;
    SoftKeyLineEdit *l_concaveclset;
    QLabel *label_6;
    QLabel *label_8;
    QLabel *label_105;
    QComboBox *grain_kind;
    QComboBox *cutterMode;
    QLabel *label_9;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QComboBox *cbx_heartbeat;
    QLabel *label_14;
    QLabel *label_15;
    SoftKeyLineEdit *l_ConcaveclSetMin;
    SoftKeyLineEdit *l_ConcaveclSetMax;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_20;
    SoftKeyLineEdit *l_GrassrGrainratio;
    QLabel *label_21;
    QLabel *label_24;
    SoftKeyLineEdit *l_PlantHeight;
    QLabel *label_25;
    QLabel *label_26;
    SoftKeyLineEdit *l_AxialRollerSpeedMin;
    QLabel *label_27;
    QLabel *label_28;
    QLabel *label_29;
    SoftKeyLineEdit *l_AxialRollerSpeedMax;
    SoftKeyLineEdit *l_StalkMoisture;
    SoftKeyLineEdit *l_CroppingIntensity;

    void setupUi(QDialog *ControlSetting)
    {
        if (ControlSetting->objectName().isEmpty())
            ControlSetting->setObjectName(QString::fromUtf8("ControlSetting"));
        ControlSetting->resize(780, 312);
        QFont font;
        font.setFamily(QString::fromUtf8("AR PL UKai CN"));
        font.setPointSize(16);
        ControlSetting->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/leiwo.png"), QSize(), QIcon::Normal, QIcon::Off);
        ControlSetting->setWindowIcon(icon);
        cbx_1 = new QComboBox(ControlSetting);
        cbx_1->setObjectName(QString::fromUtf8("cbx_1"));
        cbx_1->setGeometry(QRect(60, 210, 91, 41));
        label = new QLabel(ControlSetting);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 210, 39, 41));
        label->setStyleSheet(QString::fromUtf8("border-image: url(:/images/setting/UnloaderSetting.png);"));
        label->setLineWidth(1);
        l_chrs = new QLabel(ControlSetting);
        l_chrs->setObjectName(QString::fromUtf8("l_chrs"));
        l_chrs->setGeometry(QRect(10, 260, 40, 40));
        l_chrs->setMinimumSize(QSize(40, 0));
        l_chrs->setStyleSheet(QString::fromUtf8("border-image: url(:/images/parameters/CutHeightResetOn.png);"));
        cbx_3 = new QComboBox(ControlSetting);
        cbx_3->setObjectName(QString::fromUtf8("cbx_3"));
        cbx_3->setGeometry(QRect(60, 260, 91, 41));
        m_reset = new QLabel(ControlSetting);
        m_reset->setObjectName(QString::fromUtf8("m_reset"));
        m_reset->setGeometry(QRect(10, 110, 40, 40));
        m_reset->setStyleSheet(QString::fromUtf8("border-image: url(:/images/engine/ZeroOn.png);"));
        cbx_4 = new QComboBox(ControlSetting);
        cbx_4->setObjectName(QString::fromUtf8("cbx_4"));
        cbx_4->setGeometry(QRect(60, 110, 91, 41));
        cbx_4->setStyleSheet(QString::fromUtf8("font: 16pt \"AR PL UKai CN\";"));
        auto_load_regu = new QLabel(ControlSetting);
        auto_load_regu->setObjectName(QString::fromUtf8("auto_load_regu"));
        auto_load_regu->setGeometry(QRect(10, 60, 40, 40));
        auto_load_regu->setStyleSheet(QString::fromUtf8("border-image: url(:/images/con_recong/LoadRegulationAutoOn.png);"));
        cbx_5 = new QComboBox(ControlSetting);
        cbx_5->setObjectName(QString::fromUtf8("cbx_5"));
        cbx_5->setGeometry(QRect(60, 60, 261, 41));
        auto_height = new QLabel(ControlSetting);
        auto_height->setObjectName(QString::fromUtf8("auto_height"));
        auto_height->setGeometry(QRect(10, 10, 40, 40));
        auto_height->setStyleSheet(QString::fromUtf8("border-image: url(:/images/setting/CutHeightAutoOn.png);"));
        cbx_6 = new QComboBox(ControlSetting);
        cbx_6->setObjectName(QString::fromUtf8("cbx_6"));
        cbx_6->setGeometry(QRect(60, 10, 261, 41));
        l_rw_cl = new QLabel(ControlSetting);
        l_rw_cl->setObjectName(QString::fromUtf8("l_rw_cl"));
        l_rw_cl->setGeometry(QRect(10, 160, 40, 40));
        l_rw_cl->setStyleSheet(QString::fromUtf8("border-image: url(:/images/setting/WeightClearOn.png);"));
        cbx_7 = new QComboBox(ControlSetting);
        cbx_7->setObjectName(QString::fromUtf8("cbx_7"));
        cbx_7->setGeometry(QRect(60, 160, 91, 41));
        cbx_9 = new QComboBox(ControlSetting);
        cbx_9->setObjectName(QString::fromUtf8("cbx_9"));
        cbx_9->setGeometry(QRect(210, 210, 111, 41));
        m_reset_2 = new QLabel(ControlSetting);
        m_reset_2->setObjectName(QString::fromUtf8("m_reset_2"));
        m_reset_2->setGeometry(QRect(160, 210, 40, 40));
        m_reset_2->setStyleSheet(QString::fromUtf8("border-image: url(:/images/warning/on.png);"));
        Cancel_btn = new QPushButton(ControlSetting);
        Cancel_btn->setObjectName(QString::fromUtf8("Cancel_btn"));
        Cancel_btn->setGeometry(QRect(650, 220, 121, 50));
        Cancel_btn->setStyleSheet(QString::fromUtf8("background-color: rgb(249, 88, 88);"));
        OK_btn = new QPushButton(ControlSetting);
        OK_btn->setObjectName(QString::fromUtf8("OK_btn"));
        OK_btn->setGeometry(QRect(650, 150, 121, 50));
        OK_btn->setStyleSheet(QString::fromUtf8("background-color: rgb(58, 111, 249);"));
        label_103 = new QLabel(ControlSetting);
        label_103->setObjectName(QString::fromUtf8("label_103"));
        label_103->setGeometry(QRect(330, 59, 39, 40));
        label_103->setStyleSheet(QString::fromUtf8("border-image: url(:/images/con_recong/ProfilingHeightSet.png);"));
        label_4 = new QLabel(ControlSetting);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(450, 70, 40, 30));
        l_pfh = new SoftKeyLineEdit(ControlSetting);
        l_pfh->setObjectName(QString::fromUtf8("l_pfh"));
        l_pfh->setGeometry(QRect(380, 60, 70, 40));
        l_pfh->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_3 = new QLabel(ControlSetting);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(450, 20, 40, 30));
        label_102 = new QLabel(ControlSetting);
        label_102->setObjectName(QString::fromUtf8("label_102"));
        label_102->setGeometry(QRect(330, 10, 39, 39));
        label_102->setStyleSheet(QString::fromUtf8("border-image: url(:/images/setting/Weight1000.png);"));
        l_weight1000 = new SoftKeyLineEdit(ControlSetting);
        l_weight1000->setObjectName(QString::fromUtf8("l_weight1000"));
        l_weight1000->setGeometry(QRect(380, 10, 70, 40));
        l_weight1000->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_5 = new QLabel(ControlSetting);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(450, 170, 40, 30));
        label_2 = new QLabel(ControlSetting);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(450, 220, 40, 30));
        label_7 = new QLabel(ControlSetting);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(450, 119, 40, 30));
        label_10 = new QLabel(ControlSetting);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(330, 210, 39, 40));
        label_10->setStyleSheet(QString::fromUtf8("border-image: url(:/images/setting/RollerSpeedLowSetting.png);"));
        label_23 = new QLabel(ControlSetting);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(330, 109, 39, 40));
        label_23->setStyleSheet(QString::fromUtf8("border-image: url(:/images/setting/cut_height_min.png);"));
        label_22 = new QLabel(ControlSetting);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(330, 160, 39, 40));
        label_22->setStyleSheet(QString::fromUtf8("border-image: url(:/images/setting/cut_height_max.png);"));
        l_rsls = new SoftKeyLineEdit(ControlSetting);
        l_rsls->setObjectName(QString::fromUtf8("l_rsls"));
        l_rsls->setGeometry(QRect(380, 210, 70, 40));
        l_rsls->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        l_cuth_max = new SoftKeyLineEdit(ControlSetting);
        l_cuth_max->setObjectName(QString::fromUtf8("l_cuth_max"));
        l_cuth_max->setGeometry(QRect(380, 160, 70, 40));
        l_cuth_max->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        l_cuth_min = new SoftKeyLineEdit(ControlSetting);
        l_cuth_min->setObjectName(QString::fromUtf8("l_cuth_min"));
        l_cuth_min->setGeometry(QRect(380, 110, 70, 39));
        l_cuth_min->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_19 = new QLabel(ControlSetting);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(330, 260, 39, 40));
        label_19->setStyleSheet(QString::fromUtf8("border-image: url(:/images/setting/ConcaveClearanceSetting.png);"));
        l_concaveclset = new SoftKeyLineEdit(ControlSetting);
        l_concaveclset->setObjectName(QString::fromUtf8("l_concaveclset"));
        l_concaveclset->setGeometry(QRect(380, 260, 70, 40));
        l_concaveclset->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_6 = new QLabel(ControlSetting);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(450, 270, 40, 30));
        label_8 = new QLabel(ControlSetting);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(160, 110, 39, 41));
        label_8->setStyleSheet(QString::fromUtf8("border-image: url(:/images/setting/CutMachineMode.png);"));
        label_105 = new QLabel(ControlSetting);
        label_105->setObjectName(QString::fromUtf8("label_105"));
        label_105->setGeometry(QRect(160, 170, 30, 30));
        label_105->setStyleSheet(QString::fromUtf8("border-image: url(:/images/engine/RiceKind.png);"));
        grain_kind = new QComboBox(ControlSetting);
        grain_kind->setObjectName(QString::fromUtf8("grain_kind"));
        grain_kind->setGeometry(QRect(210, 160, 111, 41));
        cutterMode = new QComboBox(ControlSetting);
        cutterMode->setObjectName(QString::fromUtf8("cutterMode"));
        cutterMode->setGeometry(QRect(210, 110, 111, 41));
        label_9 = new QLabel(ControlSetting);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(480, 20, 41, 40));
        label_9->setMinimumSize(QSize(41, 0));
        label_9->setStyleSheet(QString::fromUtf8("border-image: url(:/images/setting/ConcaveClearanceMax.png);"));
        label_11 = new QLabel(ControlSetting);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(600, 20, 40, 30));
        label_12 = new QLabel(ControlSetting);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(600, 70, 40, 30));
        label_13 = new QLabel(ControlSetting);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(480, 70, 40, 40));
        label_13->setStyleSheet(QString::fromUtf8("border-image: url(:/images/setting/ConcaveClearanceMin.png);"));
        cbx_heartbeat = new QComboBox(ControlSetting);
        cbx_heartbeat->setObjectName(QString::fromUtf8("cbx_heartbeat"));
        cbx_heartbeat->setGeometry(QRect(210, 260, 111, 41));
        label_14 = new QLabel(ControlSetting);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(160, 260, 41, 41));
        label_14->setStyleSheet(QString::fromUtf8("border-image: url(:/images/setting/heartbeat.png);"));
        label_15 = new QLabel(ControlSetting);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(480, 110, 40, 40));
        label_15->setStyleSheet(QString::fromUtf8("border-image: url(:/images/setting/GrainMoisture.png);"));
        l_ConcaveclSetMin = new SoftKeyLineEdit(ControlSetting);
        l_ConcaveclSetMin->setObjectName(QString::fromUtf8("l_ConcaveclSetMin"));
        l_ConcaveclSetMin->setGeometry(QRect(520, 60, 70, 40));
        l_ConcaveclSetMin->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        l_ConcaveclSetMax = new SoftKeyLineEdit(ControlSetting);
        l_ConcaveclSetMax->setObjectName(QString::fromUtf8("l_ConcaveclSetMax"));
        l_ConcaveclSetMax->setGeometry(QRect(520, 10, 70, 40));
        l_ConcaveclSetMax->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_16 = new QLabel(ControlSetting);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(600, 120, 21, 30));
        QFont font1;
        font1.setPointSize(15);
        label_16->setFont(font1);
        label_17 = new QLabel(ControlSetting);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(480, 160, 40, 40));
        label_17->setStyleSheet(QString::fromUtf8("border-image: url(:/images/setting/GrainDensity.png);"));
        label_18 = new QLabel(ControlSetting);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(590, 170, 61, 30));
        label_20 = new QLabel(ControlSetting);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(480, 210, 40, 40));
        label_20->setStyleSheet(QString::fromUtf8("border-image: url(:/images/setting/GrassGrainRatio.png);"));
        l_GrassrGrainratio = new SoftKeyLineEdit(ControlSetting);
        l_GrassrGrainratio->setObjectName(QString::fromUtf8("l_GrassrGrainratio"));
        l_GrassrGrainratio->setGeometry(QRect(520, 210, 70, 40));
        l_GrassrGrainratio->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_21 = new QLabel(ControlSetting);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(600, 220, 21, 30));
        label_24 = new QLabel(ControlSetting);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(600, 270, 21, 30));
        l_PlantHeight = new SoftKeyLineEdit(ControlSetting);
        l_PlantHeight->setObjectName(QString::fromUtf8("l_PlantHeight"));
        l_PlantHeight->setGeometry(QRect(520, 260, 70, 40));
        l_PlantHeight->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_25 = new QLabel(ControlSetting);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(480, 260, 40, 40));
        label_25->setStyleSheet(QString::fromUtf8("border-image: url(:/images/setting/PlantHeight.png);"));
        label_26 = new QLabel(ControlSetting);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setGeometry(QRect(630, 10, 40, 40));
        label_26->setStyleSheet(QString::fromUtf8("border-image: url(:/images/setting/AxialRollerSpeedMin.png);"));
        l_AxialRollerSpeedMin = new SoftKeyLineEdit(ControlSetting);
        l_AxialRollerSpeedMin->setObjectName(QString::fromUtf8("l_AxialRollerSpeedMin"));
        l_AxialRollerSpeedMin->setGeometry(QRect(670, 10, 70, 40));
        l_AxialRollerSpeedMin->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_27 = new QLabel(ControlSetting);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setGeometry(QRect(740, 10, 31, 30));
        label_28 = new QLabel(ControlSetting);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setGeometry(QRect(740, 60, 31, 30));
        label_29 = new QLabel(ControlSetting);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setGeometry(QRect(630, 60, 40, 40));
        label_29->setStyleSheet(QString::fromUtf8("border-image: url(:/images/setting/AxialRollerSpeedMax.png);"));
        l_AxialRollerSpeedMax = new SoftKeyLineEdit(ControlSetting);
        l_AxialRollerSpeedMax->setObjectName(QString::fromUtf8("l_AxialRollerSpeedMax"));
        l_AxialRollerSpeedMax->setGeometry(QRect(670, 60, 70, 40));
        l_AxialRollerSpeedMax->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        l_StalkMoisture = new SoftKeyLineEdit(ControlSetting);
        l_StalkMoisture->setObjectName(QString::fromUtf8("l_StalkMoisture"));
        l_StalkMoisture->setGeometry(QRect(520, 110, 70, 40));
        l_StalkMoisture->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        l_CroppingIntensity = new SoftKeyLineEdit(ControlSetting);
        l_CroppingIntensity->setObjectName(QString::fromUtf8("l_CroppingIntensity"));
        l_CroppingIntensity->setGeometry(QRect(520, 160, 70, 40));
        l_CroppingIntensity->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        retranslateUi(ControlSetting);

        QMetaObject::connectSlotsByName(ControlSetting);
    } // setupUi

    void retranslateUi(QDialog *ControlSetting)
    {
        ControlSetting->setWindowTitle(QApplication::translate("ControlSetting", "\344\273\252\350\241\250\346\216\247\345\210\266", 0, QApplication::UnicodeUTF8));
        cbx_1->clear();
        cbx_1->insertItems(0, QStringList()
         << QApplication::translate("ControlSetting", "\345\201\234\346\255\242", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ControlSetting", "\345\212\250\346\200\201\345\261\225\345\274\200", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ControlSetting", "\351\235\231\346\200\201\345\261\225\345\274\200", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ControlSetting", "\346\224\266\345\233\236", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ControlSetting", "\346\227\240\345\212\250\344\275\234", 0, QApplication::UnicodeUTF8)
        );
        label->setText(QString());
        l_chrs->setText(QString());
        cbx_3->clear();
        cbx_3->insertItems(0, QStringList()
         << QApplication::translate("ControlSetting", "\350\204\261\345\274\200", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ControlSetting", "\345\211\262\345\217\260\346\217\220\345\215\207", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ControlSetting", "\345\211\262\345\217\260\344\270\213\351\231\215", 0, QApplication::UnicodeUTF8)
        );
        m_reset->setText(QString());
        cbx_4->clear();
        cbx_4->insertItems(0, QStringList()
         << QApplication::translate("ControlSetting", "\346\227\240\345\212\250\344\275\234", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ControlSetting", "\346\270\205\351\233\266", 0, QApplication::UnicodeUTF8)
        );
        auto_load_regu->setText(QString());
        cbx_5->clear();
        cbx_5->insertItems(0, QStringList()
         << QApplication::translate("ControlSetting", "\345\205\263\351\227\255\350\264\237\350\215\267\350\207\252\345\212\250\350\260\203\350\212\202", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ControlSetting", "\345\274\200\345\220\257\350\264\237\350\215\267\350\207\252\345\212\250\350\260\203\350\212\202", 0, QApplication::UnicodeUTF8)
        );
        auto_height->setText(QString());
        cbx_6->clear();
        cbx_6->insertItems(0, QStringList()
         << QApplication::translate("ControlSetting", "\345\205\263\351\227\255\345\211\262\345\217\260\351\253\230\345\272\246\350\207\252\345\212\250\350\260\203\350\212\202", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ControlSetting", "\345\274\200\345\220\257\345\211\262\345\217\260\351\253\230\345\272\246\350\207\252\345\212\250\350\260\203\350\212\202", 0, QApplication::UnicodeUTF8)
        );
        l_rw_cl->setText(QString());
        cbx_7->clear();
        cbx_7->insertItems(0, QStringList()
         << QApplication::translate("ControlSetting", "\346\227\240\345\212\250\344\275\234", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ControlSetting", "\346\270\205\351\233\266", 0, QApplication::UnicodeUTF8)
        );
        cbx_9->clear();
        cbx_9->insertItems(0, QStringList()
         << QApplication::translate("ControlSetting", "\346\227\240\345\212\250\344\275\234", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ControlSetting", "\351\235\231\351\237\263", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ControlSetting", "\346\222\255\346\224\276", 0, QApplication::UnicodeUTF8)
        );
        m_reset_2->setText(QString());
        Cancel_btn->setText(QApplication::translate("ControlSetting", "Cancel", 0, QApplication::UnicodeUTF8));
        OK_btn->setText(QApplication::translate("ControlSetting", "OK", 0, QApplication::UnicodeUTF8));
        label_103->setText(QString());
        label_4->setText(QApplication::translate("ControlSetting", "mm", 0, QApplication::UnicodeUTF8));
        l_pfh->setText(QApplication::translate("ControlSetting", "0", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ControlSetting", "g", 0, QApplication::UnicodeUTF8));
        label_102->setText(QString());
        l_weight1000->setText(QApplication::translate("ControlSetting", "0.00", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("ControlSetting", "mm", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ControlSetting", "rpm", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("ControlSetting", "mm", 0, QApplication::UnicodeUTF8));
        label_10->setText(QString());
        label_23->setText(QString());
        label_22->setText(QString());
        l_rsls->setText(QApplication::translate("ControlSetting", "0", 0, QApplication::UnicodeUTF8));
        l_cuth_max->setText(QApplication::translate("ControlSetting", "0", 0, QApplication::UnicodeUTF8));
        l_cuth_min->setText(QApplication::translate("ControlSetting", "0", 0, QApplication::UnicodeUTF8));
        label_19->setText(QString());
        l_concaveclset->setText(QApplication::translate("ControlSetting", "0", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("ControlSetting", "mm", 0, QApplication::UnicodeUTF8));
        label_8->setText(QString());
        label_105->setText(QString());
        grain_kind->clear();
        grain_kind->insertItems(0, QStringList()
         << QApplication::translate("ControlSetting", "\346\260\264\347\250\273", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ControlSetting", "\345\260\217\351\272\246", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ControlSetting", "\347\216\211\347\261\263", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ControlSetting", "\345\244\247\350\261\206", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ControlSetting", "\345\205\266\344\273\226", 0, QApplication::UnicodeUTF8)
        );
        cutterMode->clear();
        cutterMode->insertItems(0, QStringList()
         << QApplication::translate("ControlSetting", "\345\210\207\347\242\216", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ControlSetting", "\346\216\222\350\215\211", 0, QApplication::UnicodeUTF8)
        );
        label_9->setText(QString());
        label_11->setText(QApplication::translate("ControlSetting", "mm", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("ControlSetting", "mm", 0, QApplication::UnicodeUTF8));
        label_13->setText(QString());
        cbx_heartbeat->clear();
        cbx_heartbeat->insertItems(0, QStringList()
         << QApplication::translate("ControlSetting", "\344\273\252\350\241\250\345\234\250\347\272\277", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ControlSetting", "\344\273\252\350\241\250\346\216\211\347\272\277", 0, QApplication::UnicodeUTF8)
        );
        label_14->setText(QString());
        label_15->setText(QString());
        l_ConcaveclSetMin->setText(QApplication::translate("ControlSetting", "0", 0, QApplication::UnicodeUTF8));
        l_ConcaveclSetMax->setText(QApplication::translate("ControlSetting", "0", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("ControlSetting", "%", 0, QApplication::UnicodeUTF8));
        label_17->setText(QString());
        label_18->setText(QApplication::translate("ControlSetting", "Kg/m3", 0, QApplication::UnicodeUTF8));
        label_20->setText(QString());
        l_GrassrGrainratio->setText(QApplication::translate("ControlSetting", "0", 0, QApplication::UnicodeUTF8));
        label_21->setText(QApplication::translate("ControlSetting", "%", 0, QApplication::UnicodeUTF8));
        label_24->setText(QApplication::translate("ControlSetting", "mm", 0, QApplication::UnicodeUTF8));
        l_PlantHeight->setText(QApplication::translate("ControlSetting", "0", 0, QApplication::UnicodeUTF8));
        label_25->setText(QString());
        label_26->setText(QString());
        l_AxialRollerSpeedMin->setText(QApplication::translate("ControlSetting", "0", 0, QApplication::UnicodeUTF8));
        label_27->setText(QApplication::translate("ControlSetting", "rpm", 0, QApplication::UnicodeUTF8));
        label_28->setText(QApplication::translate("ControlSetting", "rpm", 0, QApplication::UnicodeUTF8));
        label_29->setText(QString());
        l_AxialRollerSpeedMax->setText(QApplication::translate("ControlSetting", "0", 0, QApplication::UnicodeUTF8));
        l_StalkMoisture->setText(QApplication::translate("ControlSetting", "0.00", 0, QApplication::UnicodeUTF8));
        l_CroppingIntensity->setText(QApplication::translate("ControlSetting", "0.00", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ControlSetting: public Ui_ControlSetting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTROLSETTING_H
