#############################################################################
# Makefile for building: har5
# Generated by qmake (2.01a) (Qt 4.8.4) on: ?? 8? 26 16:21:51 2019
# Project:  har5.pro
# Template: app
# Command: /home/thomas/Qt4.8.4_arm/bin/qmake -o Makefile har5.pro
#############################################################################

####### Compiler, tools and options

CC            = /home/thomas/linux-devkit/bin/arm-arago-linux-gnueabi-gcc
CXX           = /home/thomas/linux-devkit/bin/arm-arago-linux-gnueabi-g++
DEFINES       = -DQT_NO_DEBUG -DQT_SQL_LIB -DQT_GUI_LIB -DQT_NETWORK_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I../../Qt4.8.4_arm/mkspecs/qws/linux-arm-gnueabi-g++ -I. -I../../Qt4.8.4_arm/include/QtCore -I../../Qt4.8.4_arm/include/QtNetwork -I../../Qt4.8.4_arm/include/QtGui -I../../Qt4.8.4_arm/include/QtSql -I../../Qt4.8.4_arm/include -I. -Iheader -Iui -Imoc -Iui
LINK          = /home/thomas/linux-devkit/bin/arm-arago-linux-gnueabi-g++
LFLAGS        = -Wl,-O1 -Wl,-rpath,/home/thomas/Qt4.8.4_arm/lib
LIBS          = $(SUBLIBS)  -L/home/thomas/Qt4.8.4_arm/lib -lQtSql -L/home/thomas/Qt4.8.4_arm/lib -lQtGui -lQtNetwork -lQtCore -lpthread 
AR            = /home/thomas/linux-devkit/bin/arm-arago-linux-gnueabi-ar cqs
RANLIB        = 
QMAKE         = /home/thomas/Qt4.8.4_arm/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = /home/thomas/linux-devkit/bin/arm-arago-linux-gnueabi-strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = obj/

####### Files

SOURCES       = src/can_recv_send.cpp \
		src/controlsetting.cpp \
		src/cutheight.cpp \
		src/engtach.cpp \
		src/main.cpp \
		src/mqlabel.cpp \
		src/mydashboard.cpp \
		src/mylcdnumber.cpp \
		src/myprogressbar.cpp \
		src/mywidget.cpp \
		src/numkeyboard.cpp \
		src/parametersetting.cpp \
		src/softkeylineedit.cpp \
		src/tachmeter.cpp \
		src/thread.cpp \
		src/INIParser.cpp moc/moc_controlsetting.cpp \
		moc/moc_cutheight.cpp \
		moc/moc_engtach.cpp \
		moc/moc_mqlabel.cpp \
		moc/moc_mydashboard.cpp \
		moc/moc_mylcdnumber.cpp \
		moc/moc_myprogressbar.cpp \
		moc/moc_mywidget.cpp \
		moc/moc_numkeyboard.cpp \
		moc/moc_parametersetting.cpp \
		moc/moc_softkeylineedit.cpp \
		moc/moc_tachmeter.cpp \
		moc/moc_thread.cpp \
		rcc/qrc_image.cpp
OBJECTS       = obj/can_recv_send.o \
		obj/controlsetting.o \
		obj/cutheight.o \
		obj/engtach.o \
		obj/main.o \
		obj/mqlabel.o \
		obj/mydashboard.o \
		obj/mylcdnumber.o \
		obj/myprogressbar.o \
		obj/mywidget.o \
		obj/numkeyboard.o \
		obj/parametersetting.o \
		obj/softkeylineedit.o \
		obj/tachmeter.o \
		obj/thread.o \
		obj/INIParser.o \
		obj/moc_controlsetting.o \
		obj/moc_cutheight.o \
		obj/moc_engtach.o \
		obj/moc_mqlabel.o \
		obj/moc_mydashboard.o \
		obj/moc_mylcdnumber.o \
		obj/moc_myprogressbar.o \
		obj/moc_mywidget.o \
		obj/moc_numkeyboard.o \
		obj/moc_parametersetting.o \
		obj/moc_softkeylineedit.o \
		obj/moc_tachmeter.o \
		obj/moc_thread.o \
		obj/qrc_image.o
DIST          = ../../Qt4.8.4_arm/mkspecs/common/unix.conf \
		../../Qt4.8.4_arm/mkspecs/common/linux.conf \
		../../Qt4.8.4_arm/mkspecs/common/gcc-base.conf \
		../../Qt4.8.4_arm/mkspecs/common/gcc-base-unix.conf \
		../../Qt4.8.4_arm/mkspecs/common/g++-base.conf \
		../../Qt4.8.4_arm/mkspecs/common/g++-unix.conf \
		../../Qt4.8.4_arm/mkspecs/common/qws.conf \
		../../Qt4.8.4_arm/mkspecs/qconfig.pri \
		../../Qt4.8.4_arm/mkspecs/modules/qt_webkit_version.pri \
		../../Qt4.8.4_arm/mkspecs/features/qt_functions.prf \
		../../Qt4.8.4_arm/mkspecs/features/qt_config.prf \
		../../Qt4.8.4_arm/mkspecs/features/exclusive_builds.prf \
		../../Qt4.8.4_arm/mkspecs/features/default_pre.prf \
		../../Qt4.8.4_arm/mkspecs/features/release.prf \
		../../Qt4.8.4_arm/mkspecs/features/default_post.prf \
		../../Qt4.8.4_arm/mkspecs/features/warn_on.prf \
		../../Qt4.8.4_arm/mkspecs/features/qt.prf \
		../../Qt4.8.4_arm/mkspecs/features/unix/thread.prf \
		../../Qt4.8.4_arm/mkspecs/features/moc.prf \
		../../Qt4.8.4_arm/mkspecs/features/resources.prf \
		../../Qt4.8.4_arm/mkspecs/features/uic.prf \
		../../Qt4.8.4_arm/mkspecs/features/yacc.prf \
		../../Qt4.8.4_arm/mkspecs/features/lex.prf \
		har5.pro
QMAKE_TARGET  = har5
DESTDIR       = 
TARGET        = har5

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET): ui/ui_controlsetting.h ui/ui_mywidget.h ui/ui_parametersetting.h $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: har5.pro  ../../Qt4.8.4_arm/mkspecs/qws/linux-arm-gnueabi-g++/qmake.conf ../../Qt4.8.4_arm/mkspecs/common/unix.conf \
		../../Qt4.8.4_arm/mkspecs/common/linux.conf \
		../../Qt4.8.4_arm/mkspecs/common/gcc-base.conf \
		../../Qt4.8.4_arm/mkspecs/common/gcc-base-unix.conf \
		../../Qt4.8.4_arm/mkspecs/common/g++-base.conf \
		../../Qt4.8.4_arm/mkspecs/common/g++-unix.conf \
		../../Qt4.8.4_arm/mkspecs/common/qws.conf \
		../../Qt4.8.4_arm/mkspecs/qconfig.pri \
		../../Qt4.8.4_arm/mkspecs/modules/qt_webkit_version.pri \
		../../Qt4.8.4_arm/mkspecs/features/qt_functions.prf \
		../../Qt4.8.4_arm/mkspecs/features/qt_config.prf \
		../../Qt4.8.4_arm/mkspecs/features/exclusive_builds.prf \
		../../Qt4.8.4_arm/mkspecs/features/default_pre.prf \
		../../Qt4.8.4_arm/mkspecs/features/release.prf \
		../../Qt4.8.4_arm/mkspecs/features/default_post.prf \
		../../Qt4.8.4_arm/mkspecs/features/warn_on.prf \
		../../Qt4.8.4_arm/mkspecs/features/qt.prf \
		../../Qt4.8.4_arm/mkspecs/features/unix/thread.prf \
		../../Qt4.8.4_arm/mkspecs/features/moc.prf \
		../../Qt4.8.4_arm/mkspecs/features/resources.prf \
		../../Qt4.8.4_arm/mkspecs/features/uic.prf \
		../../Qt4.8.4_arm/mkspecs/features/yacc.prf \
		../../Qt4.8.4_arm/mkspecs/features/lex.prf \
		/home/thomas/Qt4.8.4_arm/lib/libQtSql.prl \
		/home/thomas/Qt4.8.4_arm/lib/libQtCore.prl \
		/home/thomas/Qt4.8.4_arm/lib/libQtGui.prl \
		/home/thomas/Qt4.8.4_arm/lib/libQtNetwork.prl
	$(QMAKE) -o Makefile har5.pro
../../Qt4.8.4_arm/mkspecs/common/unix.conf:
../../Qt4.8.4_arm/mkspecs/common/linux.conf:
../../Qt4.8.4_arm/mkspecs/common/gcc-base.conf:
../../Qt4.8.4_arm/mkspecs/common/gcc-base-unix.conf:
../../Qt4.8.4_arm/mkspecs/common/g++-base.conf:
../../Qt4.8.4_arm/mkspecs/common/g++-unix.conf:
../../Qt4.8.4_arm/mkspecs/common/qws.conf:
../../Qt4.8.4_arm/mkspecs/qconfig.pri:
../../Qt4.8.4_arm/mkspecs/modules/qt_webkit_version.pri:
../../Qt4.8.4_arm/mkspecs/features/qt_functions.prf:
../../Qt4.8.4_arm/mkspecs/features/qt_config.prf:
../../Qt4.8.4_arm/mkspecs/features/exclusive_builds.prf:
../../Qt4.8.4_arm/mkspecs/features/default_pre.prf:
../../Qt4.8.4_arm/mkspecs/features/release.prf:
../../Qt4.8.4_arm/mkspecs/features/default_post.prf:
../../Qt4.8.4_arm/mkspecs/features/warn_on.prf:
../../Qt4.8.4_arm/mkspecs/features/qt.prf:
../../Qt4.8.4_arm/mkspecs/features/unix/thread.prf:
../../Qt4.8.4_arm/mkspecs/features/moc.prf:
../../Qt4.8.4_arm/mkspecs/features/resources.prf:
../../Qt4.8.4_arm/mkspecs/features/uic.prf:
../../Qt4.8.4_arm/mkspecs/features/yacc.prf:
../../Qt4.8.4_arm/mkspecs/features/lex.prf:
/home/thomas/Qt4.8.4_arm/lib/libQtSql.prl:
/home/thomas/Qt4.8.4_arm/lib/libQtCore.prl:
/home/thomas/Qt4.8.4_arm/lib/libQtGui.prl:
/home/thomas/Qt4.8.4_arm/lib/libQtNetwork.prl:
qmake:  FORCE
	@$(QMAKE) -o Makefile har5.pro

dist: 
	@$(CHK_DIR_EXISTS) obj/har51.0.0 || $(MKDIR) obj/har51.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) obj/har51.0.0/ && $(COPY_FILE) --parents header/can_recv_send.h header/controlsetting.h header/cutheight.h header/engtach.h header/mqlabel.h header/mydashboard.h header/mylcdnumber.h header/myprogressbar.h header/mywidget.h header/numkeyboard.h header/parametersetting.h header/softkeylineedit.h header/tachmeter.h header/thread.h header/INIParser.h obj/har51.0.0/ && $(COPY_FILE) --parents src/image.qrc obj/har51.0.0/ && $(COPY_FILE) --parents src/can_recv_send.cpp src/controlsetting.cpp src/cutheight.cpp src/engtach.cpp src/main.cpp src/mqlabel.cpp src/mydashboard.cpp src/mylcdnumber.cpp src/myprogressbar.cpp src/mywidget.cpp src/numkeyboard.cpp src/parametersetting.cpp src/softkeylineedit.cpp src/tachmeter.cpp src/thread.cpp src/INIParser.cpp obj/har51.0.0/ && $(COPY_FILE) --parents forms/controlsetting.ui forms/mywidget.ui forms/parametersetting.ui obj/har51.0.0/ && (cd `dirname obj/har51.0.0` && $(TAR) har51.0.0.tar har51.0.0 && $(COMPRESS) har51.0.0.tar) && $(MOVE) `dirname obj/har51.0.0`/har51.0.0.tar.gz . && $(DEL_FILE) -r obj/har51.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc/moc_controlsetting.cpp moc/moc_cutheight.cpp moc/moc_engtach.cpp moc/moc_mqlabel.cpp moc/moc_mydashboard.cpp moc/moc_mylcdnumber.cpp moc/moc_myprogressbar.cpp moc/moc_mywidget.cpp moc/moc_numkeyboard.cpp moc/moc_parametersetting.cpp moc/moc_softkeylineedit.cpp moc/moc_tachmeter.cpp moc/moc_thread.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc/moc_controlsetting.cpp moc/moc_cutheight.cpp moc/moc_engtach.cpp moc/moc_mqlabel.cpp moc/moc_mydashboard.cpp moc/moc_mylcdnumber.cpp moc/moc_myprogressbar.cpp moc/moc_mywidget.cpp moc/moc_numkeyboard.cpp moc/moc_parametersetting.cpp moc/moc_softkeylineedit.cpp moc/moc_tachmeter.cpp moc/moc_thread.cpp
moc/moc_controlsetting.cpp: header/can_recv_send.h \
		header/INIParser.h \
		header/controlsetting.h
	/home/thomas/Qt4.8.4_arm/bin/moc $(DEFINES) $(INCPATH) header/controlsetting.h -o moc/moc_controlsetting.cpp

moc/moc_cutheight.cpp: header/cutheight.h
	/home/thomas/Qt4.8.4_arm/bin/moc $(DEFINES) $(INCPATH) header/cutheight.h -o moc/moc_cutheight.cpp

moc/moc_engtach.cpp: header/engtach.h
	/home/thomas/Qt4.8.4_arm/bin/moc $(DEFINES) $(INCPATH) header/engtach.h -o moc/moc_engtach.cpp

moc/moc_mqlabel.cpp: header/mqlabel.h
	/home/thomas/Qt4.8.4_arm/bin/moc $(DEFINES) $(INCPATH) header/mqlabel.h -o moc/moc_mqlabel.cpp

moc/moc_mydashboard.cpp: header/mydashboard.h
	/home/thomas/Qt4.8.4_arm/bin/moc $(DEFINES) $(INCPATH) header/mydashboard.h -o moc/moc_mydashboard.cpp

moc/moc_mylcdnumber.cpp: header/mylcdnumber.h
	/home/thomas/Qt4.8.4_arm/bin/moc $(DEFINES) $(INCPATH) header/mylcdnumber.h -o moc/moc_mylcdnumber.cpp

moc/moc_myprogressbar.cpp: header/mylcdnumber.h \
		header/myprogressbar.h
	/home/thomas/Qt4.8.4_arm/bin/moc $(DEFINES) $(INCPATH) header/myprogressbar.h -o moc/moc_myprogressbar.cpp

moc/moc_mywidget.cpp: header/mydashboard.h \
		header/mqlabel.h \
		header/can_recv_send.h \
		header/thread.h \
		header/parametersetting.h \
		header/controlsetting.h \
		header/INIParser.h \
		header/mywidget.h
	/home/thomas/Qt4.8.4_arm/bin/moc $(DEFINES) $(INCPATH) header/mywidget.h -o moc/moc_mywidget.cpp

moc/moc_numkeyboard.cpp: header/numkeyboard.h
	/home/thomas/Qt4.8.4_arm/bin/moc $(DEFINES) $(INCPATH) header/numkeyboard.h -o moc/moc_numkeyboard.cpp

moc/moc_parametersetting.cpp: header/thread.h \
		header/parametersetting.h \
		header/can_recv_send.h \
		header/parametersetting.h
	/home/thomas/Qt4.8.4_arm/bin/moc $(DEFINES) $(INCPATH) header/parametersetting.h -o moc/moc_parametersetting.cpp

moc/moc_softkeylineedit.cpp: header/numkeyboard.h \
		header/softkeylineedit.h
	/home/thomas/Qt4.8.4_arm/bin/moc $(DEFINES) $(INCPATH) header/softkeylineedit.h -o moc/moc_softkeylineedit.cpp

moc/moc_tachmeter.cpp: header/tachmeter.h
	/home/thomas/Qt4.8.4_arm/bin/moc $(DEFINES) $(INCPATH) header/tachmeter.h -o moc/moc_tachmeter.cpp

moc/moc_thread.cpp: header/parametersetting.h \
		header/thread.h \
		header/can_recv_send.h \
		header/thread.h
	/home/thomas/Qt4.8.4_arm/bin/moc $(DEFINES) $(INCPATH) header/thread.h -o moc/moc_thread.cpp

compiler_rcc_make_all: rcc/qrc_image.cpp
compiler_rcc_clean:
	-$(DEL_FILE) rcc/qrc_image.cpp
rcc/qrc_image.cpp: src/image.qrc \
		images/help.png \
		images/setdia.png \
		images/bg.png \
		images/GS.png \
		images/ReelReturnOilPressure.png \
		images/CutterFeedingOilPressure.png \
		images/poweroff.png \
		images/main.png \
		images/CutterReturnOilPressure.png \
		images/ReelFeedingOilPressure.png \
		images/on.png \
		images/pressure.png \
		images/white.png \
		images/ReelFlow.png \
		images/out.png \
		images/FeedAugerFeedingOilPressure.png \
		images/FeedAugerFlow.png \
		images/cut_height.png \
		images/GPS_OFF.png \
		images/GPS_ON.png \
		images/FeedAugerReturnOilPressure.png \
		images/harvester.png \
		images/off.png \
		images/psw.png \
		images/para.png \
		images/exit.png \
		images/sys.png \
		images/leiwo.png \
		images/name.png \
		images/CutterFlow.png \
		images/pass.png \
		images/warning/off.png \
		images/warning/alarm.png \
		images/warning/on.png \
		images/warning/normal.png \
		images/con_recong/ReelValveDownOn.png \
		images/con_recong/CutHeiValveUpcl.png \
		images/con_recong/RollerDownOff.png \
		images/con_recong/CutHeiUpOff.png \
		images/con_recong/ReelDownOff.png \
		images/con_recong/CutHeiDownOff.png \
		images/con_recong/UnloaderValveSwingInch.png \
		images/con_recong/ReelValveDownch.png \
		images/con_recong/RollerUpOn.png \
		images/con_recong/ClutchValveOnch.png \
		images/con_recong/CutHeiValveUpOff.png \
		images/con_recong/backupdriverch.png \
		images/con_recong/ClutchValveOffch.png \
		images/con_recong/LoadRegulationAutoOff.png \
		images/con_recong/CutHeiValveDownch.png \
		images/con_recong/ReelValveUpOn.png \
		images/con_recong/s_oncl.png \
		images/con_recong/LoadRegulationAutoOn.png \
		images/con_recong/RollerValveUpOff.png \
		images/con_recong/cut_height.png \
		images/con_recong/backupdriveroff.png \
		images/con_recong/ReelValveDownOff.png \
		images/con_recong/RollerUpOff.png \
		images/con_recong/ReelValveUpch.png \
		images/con_recong/RollerValveDowncl.png \
		images/con_recong/RollerValveUpcl.png \
		images/con_recong/CutHeiUpOn.png \
		images/con_recong/ReelUpOn.png \
		images/con_recong/ClutchValveOncl.png \
		images/con_recong/UnloaderValveSwingOutch.png \
		images/con_recong/ReelValveUpOff.png \
		images/con_recong/backupdrivercl.png \
		images/con_recong/ReelUpOff.png \
		images/con_recong/RollerValveDownOff.png \
		images/con_recong/backupdriveron.png \
		images/con_recong/ProfilingHeightSet.png \
		images/con_recong/CutHeiValveUpch.png \
		images/con_recong/FanDownOff.png \
		images/con_recong/CutHeiValveDowncl.png \
		images/con_recong/FanUpOn.png \
		images/con_recong/UnloaderValveSwingIncl.png \
		images/con_recong/ReelValveDowncl.png \
		images/con_recong/RollerValveDownOn.png \
		images/con_recong/CutHeiValveUpOn.png \
		images/con_recong/RollerValveUpOn.png \
		images/con_recong/CutHeiDownOn.png \
		images/con_recong/FanUpOff.png \
		images/con_recong/CutHeiValveDownOn.png \
		images/con_recong/CutHeiValveDownOff.png \
		images/con_recong/ClutchValveOffcl.png \
		images/con_recong/ReelDownOn.png \
		images/con_recong/ReelValveUpcl.png \
		images/con_recong/RollerValveDownch.png \
		images/con_recong/RollerValveUpch.png \
		images/con_recong/s_onch.png \
		images/con_recong/FanDownOn.png \
		images/con_recong/UnloaderValveSwingOutcl.png \
		images/con_recong/RollerDownOn.png \
		images/parameters/minus_on.png \
		images/parameters/CutLossRate.png \
		images/parameters/RearMotorSpeed.png \
		images/parameters/ClutchValveOffOn.png \
		images/parameters/UnloaderValveSwingOutOff.png \
		images/parameters/WeightWet.png \
		images/parameters/sorting_screen_down.png \
		images/parameters/ProfilingHeight.png \
		images/parameters/CutHeightResetOn.png \
		images/parameters/CutHeightLeft.png \
		images/parameters/ClutchOffOff.png \
		images/parameters/WeightDry.png \
		images/parameters/UnloaderSwingOutOff.png \
		images/parameters/ConcaveClearance.png \
		images/parameters/YieldPerSquare.png \
		images/parameters/WaterRate.png \
		images/parameters/CutHeightRight.png \
		images/parameters/sorting_screen_tail.png \
		images/parameters/ReelShift.png \
		images/parameters/UnloaderSwingInOff.png \
		images/parameters/plus_on.png \
		images/parameters/UnloaderOn.png \
		images/parameters/sorting_screen_up.png \
		images/parameters/s_off.png \
		images/parameters/s_on.png \
		images/parameters/minus_off.png \
		images/parameters/CutHeightResetOff.png \
		images/parameters/ClutchOnOn.png \
		images/parameters/ClutchOffOn.png \
		images/parameters/FanAngle.png \
		images/parameters/UnloaderValveSwingOutOn.png \
		images/parameters/UnloaderValveSwingInOff.png \
		images/parameters/GrainHeight.png \
		images/parameters/UnloaderSwingOutOn.png \
		images/parameters/FrontMotorSpeed.png \
		images/parameters/ClutchOnOff.png \
		images/parameters/FeedQuality.png \
		images/parameters/ReelHeight.png \
		images/parameters/UnloaderSwingInOn.png \
		images/parameters/UnloaderOff.png \
		images/parameters/ClutchValveOffOff.png \
		images/parameters/plus_off.png \
		images/parameters/GrainQualityMonitor.png \
		images/parameters/ClutchValveOnOn.png \
		images/parameters/ThrowMachineAngle.png \
		images/parameters/UnloaderValveSwingInOn.png \
		images/parameters/RollerTorque.png \
		images/parameters/ClutchValveOnOff.png \
		images/source/zSpeed.png \
		images/source/SprinklerWidth.png \
		images/source/ySpeed.png \
		images/source/SprinklerTorque.png \
		images/source/xSpeed.png \
		images/setting/ConcaveClearanceMin.png \
		images/setting/GrainDensity.png \
		images/setting/UnloaderSetting.png \
		images/setting/CutMachineMode.png \
		images/setting/AxialRollerSpeedMin.png \
		images/setting/WeightClearOn.png \
		images/setting/ConcaveClearanceMax.png \
		images/setting/Weight1000.png \
		images/setting/PlantHeight.png \
		images/setting/GrainMoisture.png \
		images/setting/GrassGrainRatio.png \
		images/setting/ConcaveClearanceSetting.png \
		images/setting/cut_height_max.png \
		images/setting/CutHeightAutoOff.png \
		images/setting/AxialRollerSpeedMax.png \
		images/setting/heartbeat.png \
		images/setting/cut_height_min.png \
		images/setting/WeightClearOff.png \
		images/setting/CutHeightAutoOn.png \
		images/setting/RollerSpeedLowSetting.png \
		images/engine/draught_fan.png \
		images/engine/Elevator.png \
		images/engine/clutch_off.png \
		images/engine/eng_oil_prs.png \
		images/engine/warning.png \
		images/engine/fuel.png \
		images/engine/diplight.png \
		images/engine/R.png \
		images/engine/handbrake.png \
		images/engine/clutch_error.png \
		images/engine/turn_left.png \
		images/engine/clutch_on.png \
		images/engine/ReThreshing.png \
		images/engine/F.png \
		images/engine/preheat.png \
		images/engine/RiceKind.png \
		images/engine/air_cleaner.png \
		images/engine/FeedAugerSpeed.png \
		images/engine/CutterHz.png \
		images/engine/N.png \
		images/engine/ZeroOn.png \
		images/engine/DriftLoseRate.png \
		images/engine/Indt_lamp.png \
		images/engine/charging.png \
		images/engine/highbeam.png \
		images/engine/full1.png \
		images/engine/CrushRate.png \
		images/engine/cut_mach.png \
		images/engine/draught_fan_rate.png \
		images/engine/oil_water.png \
		images/engine/draught_fanimpurity_rate.png \
		images/engine/full2.png \
		images/engine/ReelSpeed.png \
		images/engine/RollerSpeed.png \
		images/engine/eng_tem.png \
		images/engine/engine_fault.png \
		images/engine/ZeroOff.png \
		images/engine/turn_right.png
	/home/thomas/Qt4.8.4_arm/bin/rcc -name image src/image.qrc -o rcc/qrc_image.cpp

compiler_image_collection_make_all: ui/qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) ui/qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui/ui_controlsetting.h ui/ui_mywidget.h ui/ui_parametersetting.h
compiler_uic_clean:
	-$(DEL_FILE) ui/ui_controlsetting.h ui/ui_mywidget.h ui/ui_parametersetting.h
ui/ui_controlsetting.h: forms/controlsetting.ui \
		header/softkeylineedit.h \
		header/numkeyboard.h
	/home/thomas/Qt4.8.4_arm/bin/uic forms/controlsetting.ui -o ui/ui_controlsetting.h

ui/ui_mywidget.h: forms/mywidget.ui \
		header/softkeylineedit.h \
		header/myprogressbar.h \
		header/mydashboard.h \
		header/engtach.h \
		header/mqlabel.h \
		header/numkeyboard.h \
		header/mylcdnumber.h
	/home/thomas/Qt4.8.4_arm/bin/uic forms/mywidget.ui -o ui/ui_mywidget.h

ui/ui_parametersetting.h: forms/parametersetting.ui
	/home/thomas/Qt4.8.4_arm/bin/uic forms/parametersetting.ui -o ui/ui_parametersetting.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_rcc_clean compiler_uic_clean 

####### Compile

obj/can_recv_send.o: src/can_recv_send.cpp header/can_recv_send.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/can_recv_send.o src/can_recv_send.cpp

obj/controlsetting.o: src/controlsetting.cpp header/controlsetting.h \
		header/can_recv_send.h \
		header/INIParser.h \
		ui/ui_controlsetting.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/controlsetting.o src/controlsetting.cpp

obj/cutheight.o: src/cutheight.cpp header/cutheight.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/cutheight.o src/cutheight.cpp

obj/engtach.o: src/engtach.cpp header/engtach.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/engtach.o src/engtach.cpp

obj/main.o: src/main.cpp header/mywidget.h \
		header/mydashboard.h \
		header/mqlabel.h \
		header/can_recv_send.h \
		header/thread.h \
		header/parametersetting.h \
		header/controlsetting.h \
		header/INIParser.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/main.o src/main.cpp

obj/mqlabel.o: src/mqlabel.cpp header/mqlabel.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/mqlabel.o src/mqlabel.cpp

obj/mydashboard.o: src/mydashboard.cpp header/mydashboard.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/mydashboard.o src/mydashboard.cpp

obj/mylcdnumber.o: src/mylcdnumber.cpp header/mylcdnumber.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/mylcdnumber.o src/mylcdnumber.cpp

obj/myprogressbar.o: src/myprogressbar.cpp header/myprogressbar.h \
		header/mylcdnumber.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/myprogressbar.o src/myprogressbar.cpp

obj/mywidget.o: src/mywidget.cpp header/mywidget.h \
		header/mydashboard.h \
		header/mqlabel.h \
		header/can_recv_send.h \
		header/thread.h \
		header/parametersetting.h \
		header/controlsetting.h \
		header/INIParser.h \
		ui/ui_mywidget.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/mywidget.o src/mywidget.cpp

obj/numkeyboard.o: src/numkeyboard.cpp header/numkeyboard.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/numkeyboard.o src/numkeyboard.cpp

obj/parametersetting.o: src/parametersetting.cpp header/parametersetting.h \
		header/thread.h \
		header/can_recv_send.h \
		ui/ui_parametersetting.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/parametersetting.o src/parametersetting.cpp

obj/softkeylineedit.o: src/softkeylineedit.cpp header/softkeylineedit.h \
		header/numkeyboard.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/softkeylineedit.o src/softkeylineedit.cpp

obj/tachmeter.o: src/tachmeter.cpp header/tachmeter.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/tachmeter.o src/tachmeter.cpp

obj/thread.o: src/thread.cpp header/thread.h \
		header/parametersetting.h \
		header/can_recv_send.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/thread.o src/thread.cpp

obj/INIParser.o: src/INIParser.cpp header/INIParser.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/INIParser.o src/INIParser.cpp

obj/moc_controlsetting.o: moc/moc_controlsetting.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/moc_controlsetting.o moc/moc_controlsetting.cpp

obj/moc_cutheight.o: moc/moc_cutheight.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/moc_cutheight.o moc/moc_cutheight.cpp

obj/moc_engtach.o: moc/moc_engtach.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/moc_engtach.o moc/moc_engtach.cpp

obj/moc_mqlabel.o: moc/moc_mqlabel.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/moc_mqlabel.o moc/moc_mqlabel.cpp

obj/moc_mydashboard.o: moc/moc_mydashboard.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/moc_mydashboard.o moc/moc_mydashboard.cpp

obj/moc_mylcdnumber.o: moc/moc_mylcdnumber.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/moc_mylcdnumber.o moc/moc_mylcdnumber.cpp

obj/moc_myprogressbar.o: moc/moc_myprogressbar.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/moc_myprogressbar.o moc/moc_myprogressbar.cpp

obj/moc_mywidget.o: moc/moc_mywidget.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/moc_mywidget.o moc/moc_mywidget.cpp

obj/moc_numkeyboard.o: moc/moc_numkeyboard.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/moc_numkeyboard.o moc/moc_numkeyboard.cpp

obj/moc_parametersetting.o: moc/moc_parametersetting.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/moc_parametersetting.o moc/moc_parametersetting.cpp

obj/moc_softkeylineedit.o: moc/moc_softkeylineedit.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/moc_softkeylineedit.o moc/moc_softkeylineedit.cpp

obj/moc_tachmeter.o: moc/moc_tachmeter.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/moc_tachmeter.o moc/moc_tachmeter.cpp

obj/moc_thread.o: moc/moc_thread.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/moc_thread.o moc/moc_thread.cpp

obj/qrc_image.o: rcc/qrc_image.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/qrc_image.o rcc/qrc_image.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

