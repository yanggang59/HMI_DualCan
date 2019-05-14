#ifndef THREAD_H
#define THREAD_H

#include <QThread>
#include <QMetaType>
#include <QVariant>
#include <iostream>
#include <QTimer>
#include <QMessageBox>
#include "parametersetting.h"

extern int get_flag;

extern "C"{
//#include "led_header.h"			//Led的头文件
}

extern int num_mon[30][8];          //所有id接收的数据综合


/* can0接收数据的线程 */
class Thread0: public QThread
{
	Q_OBJECT
public:
    Thread0();
	
	void stop();
		
public slots:
	
signals:
	void warn_signal();

protected:
	void run();
	
private:
	volatile bool stopped;
	QTimer *warn_timer;


private slots:
	void warnFun_slot();
	
};



/* can1接收数据的线程 */
class Thread1: public QThread
{
    Q_OBJECT
public:
    Thread1();
    void stop();

public slots:

signals:
    void warn_signal();

protected:
    void run();

private:
    volatile bool stopped;
    QTimer *warn_timer;

private slots:
    void warnFun_slot();

};
#endif // THREAD
