#!/bin/sh

#HMIUI_BIN_PATH=/tmp/run
HMIUI_BIN_PATH=/root
HMIUI_BIN_PATH=/mnt/wecon/app/usr/bin
HMIUI_ROT_FILE="/mnt/wecon/app/usr/bin/HMIUIRot"


#链接工程中的img目录
rm -rf $HMIUI_BIN_PATH/img
#ln -s /wecon/run/project1/img $HMIUI_BIN_PATH/img
#做字体链接
rm -rf /mnt/wecon/wecon/run/qtfonts/*.qpf2
#ln -s /wecon/run/project1/qpf2/*      /mnt/wecon/wecon/run/qtfonts/

#拷贝HMIUI到内存
#cp /mnt/wecon/app/usr/bin/HMIUI $HMIUI_BIN_PATH
chmod 777 $HMIUI_BIN_PATH/HMIUI


#运行HMIui
cd $HMIUI_BIN_PATH

if [ ! -f "$HMIUI_ROT_FILE" ]; then
 touch "$HMIUI_ROT_FILE"
 echo "0" > $HMIUI_ROT_FILE
fi

#add by yanggang on 2019.7.27
cp $HMIUI_ROT_FILE $HMIUI_BIN_PATH

cat $HMIUI_ROT_FILE | while read LINE
do
	#echo $LINE
	if [ "$LINE" == '90' ]; then 
		echo "Starting HMIUI Rot90.."
		$HMIUI_BIN_PATH/HMIUI -qws -display "Transformed:Rot90" &
	elif [ "$LINE" == '180' ]; then  
		echo "Starting HMIUI Rot180.."
		$HMIUI_BIN_PATH/HMIUI -qws -display "Transformed:Rot180" &
	elif [ "$LINE" == '270' ]; then  
		echo "Starting HMIUI Rot270.."
		$HMIUI_BIN_PATH/HMIUI -qws -display "Transformed:Rot270" &
	else
		echo "Starting HMIUI Rot0.."
		$HMIUI_BIN_PATH/HMIUI -qws &
		#$HMIUI_BIN_PATH/HMIUI -qws -nomouse &
		#$HMIUI_BIN_PATH/HMIUI -qws  > /dev/console 2>&1 &
	fi
done

echo "exit_psplash" > /tmp/psplash
#echo "QUIT" > /tmp/psplash_fifo            #通知开机画面退出



