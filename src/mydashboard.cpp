//行进系统仪表盘显示源代码,0-60km/h
#include "mydashboard.h"

#include <QDebug>

myDashboard::myDashboard(QWidget *parent) :
    QWidget(parent){
    this->initVariables();
}

void myDashboard::initVariables(){
    m_outerRadius=width()>height() ? height()/2 : width()/2;
    m_innerRadius=m_outerRadius/8*3;
    m_coverCircleRadius=m_outerRadius/8*4+10;
    m_colorCircleRadius=m_outerRadius/8*5;
    m_center=rect().center();
    m_value=0;
    m_currentValue=0;
    updateTimer=new QTimer(this);
    updateTimer->setInterval(10);
    connect(updateTimer,SIGNAL(timeout()),this,SLOT(UpdateGraph()));
    singleTimer=new QTimer(this);
    singleTimer->setInterval(100);
    connect(singleTimer,SIGNAL(timeout()),this,SLOT(update()));
    singleTimer->start();
}

void myDashboard::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing|QPainter::TextAntialiasing);
    resetVariables(&painter);
    drawOuterCircle(&painter);       //最外面浅灰色的圆
    drawInnerCircle(&painter);

    //显示绿黄红色条纹
    drawColorPie(&painter);
    drawCoverCircle(&painter);

    drawMark(&painter);
    drawIndicator(&painter);
    drawCoverBall(&painter);
    drawTextRect(&painter);
    painter.end();
}

void myDashboard::drawOuterCircle(QPainter *painter)
{
    painter->save();

    QRadialGradient outerGradient(m_center,m_outerRadius,m_center);
    outerGradient.setColorAt(0.0,QColor(200,200,200));
    outerGradient.setColorAt(0.9,QColor(80,80,80));
    outerGradient.setColorAt(0.95,QColor(180,180,180));
    outerGradient.setColorAt(1.0,QColor(80,80,80));

    painter->setPen(Qt::NoPen);
    painter->setBrush(outerGradient);
    painter->drawEllipse(m_center,m_outerRadius,m_outerRadius);
    painter->restore();
}

void myDashboard::drawInnerCircle(QPainter *painter)
{
    painter->save();
    QRadialGradient innerGradient(m_center,m_innerRadius,m_center);
    innerGradient.setColorAt(0.0,QColor(130,130,130));
    innerGradient.setColorAt(0.7,QColor(130,130,130));
    innerGradient.setColorAt(1.0,QColor(80,80,80));
    painter->setPen(Qt::NoPen);
    painter->setBrush(innerGradient);
    painter->drawEllipse(m_center,m_innerRadius,m_innerRadius);

    painter->restore();
}

//仪表盘的刻度线和数字显示
void myDashboard::drawMark(QPainter *painter)
{
    painter->save();
    painter->setPen(Qt::white);
    painter->translate(m_center);

    qreal dAngle=(qreal)270/30;
    qreal startAngle=45;
    int value=0;
    QString strValue;

    strValue=tr("km/h");      //设置刻度线的单位
    qreal textWidth=fontMetrics().width(strValue);
 //   qreal textHeight=fontMetrics().height()/10;
    QFont font;

    font.setPointSize(8);
    painter->setFont(font);                 //设置字体的大小
    QPointF textPot(0-textWidth/6,0-m_colorCircleRadius/3);
 //   painter->setPen(QColor(Qt::white));       //设置"单位"字体的颜色
    painter->drawText(textPot,strValue);
 //   painter->setPen(QColor(Qt::white));       //设置“刻度值”字体的颜色为白色

    font.setPointSize(8);
    painter->setFont(font);
    for(int i=0;i<=30;i++)
    {
        painter->save();
        painter->rotate(startAngle);


        if(i%5==0)
        {
            //仪表盘上的整数的指针
            strValue=tr("%1").arg(value);
            qreal textWidth=fontMetrics().width(strValue);
            qreal textHeight=fontMetrics().height()/10;
            value+=10;
            //仪表盘上5的倍数的刻度
            QPointF bottomPot(0,m_colorCircleRadius/8*7+SPACE);
            QPointF topPot(0,m_colorCircleRadius/8*7+SPACE+OK);
            painter->drawLine(bottomPot,topPot);

            //仪表盘上的数字显示
            painter->save();
            QPointF textPot(0-textWidth*2/3,m_colorCircleRadius/8*7+LONG+textHeight);
            painter->translate(textPot);
            painter->rotate(180);
            painter->drawText(QPointF(-textWidth,textHeight/2),strValue);
            painter->restore();

        }
        else
        {
            QPointF bottomPot(0,m_colorCircleRadius/8*7+SPACE);
            QPointF topPot(0,m_colorCircleRadius/8*7+SPACE+SHORT);
            painter->drawLine(bottomPot,topPot);
        }
        painter->restore();
        startAngle+=dAngle;
    }
    painter->restore();
}

void myDashboard::drawCoverBall(QPainter *painter)
{
    painter->save();

    qreal ballRadius=m_outerRadius/7;
    m_coverBallRadius=ballRadius;
    QRadialGradient ballGradient(m_center,ballRadius,m_center);
    ballGradient.setColorAt(0.0,QColor(140,140,140));
    ballGradient.setColorAt(0.7,QColor(140,140,140));
    ballGradient.setColorAt(1.0,QColor(60,60,60));
    painter->setBrush(ballGradient);
    painter->setPen(Qt::NoPen);
    painter->drawEllipse(m_center,ballRadius,ballRadius);

    painter->restore();
}

//仪表盘中间当前数值显示
void myDashboard::drawTextRect(QPainter *painter)
{
    painter->save();
    qreal rectWidth=m_coverCircleRadius/5;

    QPointF topLeftPot(m_center.x()-rectWidth*5/2,m_center.y()+rectWidth*3);
    QPointF bottomRightPot(topLeftPot.x()+5*rectWidth,topLeftPot.y()+rectWidth*3);
    QRectF textRect(topLeftPot,bottomRightPot);

    painter->setPen(Qt::NoPen);
    painter->setBrush(QColor(0,170,255));
    painter->setOpacity(0.6);
    painter->drawRoundRect(textRect,ANGLE,ANGLE);

    qreal fontSize=textRect.height()/2;
    QFont font;
    font.setPointSize(fontSize);
    painter->setFont(font);

    painter->setOpacity(1.0);
    painter->setPen(Qt::black);
    QString strValue;
    strValue=tr("%1").arg(m_value);

    painter->drawText(textRect,Qt::AlignHCenter|Qt::AlignVCenter,strValue);
    painter->restore();
}

void myDashboard::drawCoverCircle(QPainter *painter)
{
    painter->save();
    painter->setBrush(QColor(130,130,130));
    painter->setPen(Qt::NoPen);

    //显示绿黄红条的宽度
    painter->drawEllipse(m_center,m_coverCircleRadius/8*5,m_coverCircleRadius/8*5);

    painter->restore();
}

void myDashboard::drawColorPie(QPainter  *painter)
{
    painter->save();

    QPointF topLeftPot(m_center.x()-m_colorCircleRadius/8*7,m_center.y()-m_colorCircleRadius/8*7);
    QPointF bottomRightPot(m_center.x()+m_colorCircleRadius/8*7,m_center.y()+m_colorCircleRadius/8*7);
    m_colorCircleRect=QRectF(topLeftPot,bottomRightPot);
    painter->setPen(Qt::NoPen);

    QConicalGradient greenGradient(m_center,m_innerRadius);
    greenGradient.setColorAt(0.0,QColor(0,30,0));
    greenGradient.setColorAt(0.25,QColor(0,230,0));
    greenGradient.setColorAt(1.0,QColor(0,230,0));
    painter->setBrush(Qt::green);
    painter->drawPie(m_colorCircleRect,45*16,180*16);

    painter->setBrush(QColor(218,218,0));
    painter->drawPie(m_colorCircleRect,0*16,45*16);

    painter->setBrush(QColor(240,50,50));
    painter->drawPie(m_colorCircleRect,0,-45*16);

    painter->restore();
}

void myDashboard::drawIndicator(QPainter *painter)
{
    painter->save();

    painter->translate(m_center);
    qreal increment=(qreal)270/60;
    qreal changedAngle=45+increment*m_currentValue;
    painter->rotate(changedAngle);

    QPointF topPot(0,m_colorCircleRadius+LONG);
    QPointF bottomLeftPot(-m_coverBallRadius/3,0);
    QPointF bottomRightPot(m_coverBallRadius/3,0);
    painter->setPen(Qt::NoPen);

    QLinearGradient indicatorGradient(topPot,bottomLeftPot);
    indicatorGradient.setColorAt(0.0,QColor(236,187,62));
    indicatorGradient.setColorAt(0.5,QColor(220,147,0));
    indicatorGradient.setColorAt(1.0,QColor(236,187,62));

    painter->setBrush(indicatorGradient);
    QVector<QPointF> potVec;
    potVec.push_back(topPot);
    potVec.push_back(bottomLeftPot);
    potVec.push_back(bottomRightPot);

    painter->drawPolygon(potVec);
    painter->restore();
}

void myDashboard::resetVariables(QPainter *)
{
    m_outerRadius=width()>height() ? height()/2: width()/2;
    m_innerRadius=m_outerRadius/8*7;
    m_coverCircleRadius=m_outerRadius/8*4+10;
    m_colorCircleRadius=m_outerRadius/8*5;

    m_center=rect().center();
}

void myDashboard::setValue(qreal value)
{
    if(value>m_value)
    {
        m_bReverse=false;
        m_value=value;

        if(!m_bAnimating)
        {
            m_currentValue=m_value;
        }
    }
    else if(value<m_value)
    {
        m_bReverse=true;
        m_value=value;
        if(!m_bAnimating)
        {
            m_currentValue=m_value;
        }
    }
    else
    {
        return ;
    }
    updateTimer->start();
}

void myDashboard::UpdateGraph()
{
    if(!m_bReverse)
    {
        m_currentValue+=1;        //分辨率为1

        if(m_currentValue=m_value)    //>
        {
            updateTimer->stop();
        }
    }
    else
    {
        m_currentValue-=1;
        if(m_currentValue=m_value)    //<
        {
            updateTimer->stop();
        }
    }
    update();
}

void myDashboard::debug_a(){
    qDebug()<<"******************";
}
