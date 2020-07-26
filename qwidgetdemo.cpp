#include "qwidgetdemo.h"
#include <QLabel>
#include <QHBoxLayout>

QWidgetDemo::QWidgetDemo(QWidget *parent) : QWidget(parent)
{
    //创建界面
   // QWidget *winMain=new QWidget();



    //布局
    QHBoxLayout *layout =new QHBoxLayout();
    layout->addWidget(new QLabel("T-"));
    layout->addWidget(new QLabel("36.5"));
    layout->addWidget(new QLabel("℃"));

    //拉伸因子
    layout->setStretch(0,1);
    layout->setStretch(1,2);
    layout->setStretch(2,1);

    this->setLayout(layout);
  //  winMain->show();
}
