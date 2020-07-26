#include "qwidgetdraw.h"
#include "QPainter"
#include <QTimer>
#include <QLabel>
//#include "wave.h"
#include <QDebug>

QWidgetDraw::QWidgetDraw(QWidget *parent) : QWidget(parent)
{
    this->label = new QLabel(this);
    this->label->setGeometry(10,0,100,20);//此处的位置是相对于每个画布的相对位置
    W0=this->width();
    Y0=this->height();
    this->map = new  QPixmap(this->width(),this->height());
    this->map->fill(Qt::black);

}

void QWidgetDraw:: setLabelText(QString labelText)
{
    this->label->setText(labelText);
}

void QWidgetDraw::refresh( int data )
{
    QPainter *painter=new QPainter();
    painter->begin(this->map);       //把笔放置在画布上
    this->draw(painter,data);
    painter->end();
    this->update();
}

void QWidgetDraw::paintEvent(QPaintEvent *event)
{
    QPainter *painter=new QPainter();
    painter->begin(this);
    //this->draw(painter);
    painter->drawPixmap(0,0,*this->map);        //显示画
    painter->end();
}

void QWidgetDraw::draw(QPainter *painter,int data)
{
    QPen *pen= new QPen();        //设置画笔颜色
    pen->setWidth(2);
    pen->setColor(Qt::red);
    painter->setPen(*pen);

    this->drawWaveFromArray(painter,data);

}

void QWidgetDraw::drawWaveFromArray(QPainter *painter,int data)
{
    int datapoint = 0;
    int height=this->map->height();

    datapoint=height-height*data/4096;

    this->drawWave(painter,datapoint);


}

void QWidgetDraw::drawWave(QPainter *painter,int data)
{

    int width =this->width();//当前尺寸
    int height=this->height();
    if(width != W0 || height != Y0)
    {
        W0=width;
        Y0=height;
        this->map = new  QPixmap(width,height);
        this->map->fill(Qt::black);
        X=0;
    }



    QPen *pen= new QPen();
    pen->setWidth(20);
    pen->setColor(Qt::black);  //新的配置
    //保存原来配置
    painter->save();
    //配置新的
    painter->setPen(*pen);



    painter->drawLine(this->X+10,0,this->X+10,height);
    //返回原来的
    painter->restore();
    //painter->drawPoint(this->X,data);
    painter->drawLine(this->X-1,lastdata,this->X,data);
    this->lastdata=data;
    this->X+=1;
    if(this->X>=width)
        this->X=0;

}

