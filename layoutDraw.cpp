
#include "qwidgetdemo.h"
#include "layoutDraw.h"

void layoutDemo2(void)
{
    QWidget *demowidgetmain =new QWidget();
    demowidgetmain->resize(150,400);

    QWidgetDemo *demowidget1 =new QWidgetDemo();
    QWidgetDemo *demowidget2=new QWidgetDemo();
    QWidgetDemo *demowidget3 =new QWidgetDemo();

    QVBoxLayout *layout =new QVBoxLayout();
    layout->addWidget(demowidget1);
    layout->addWidget(demowidget2);
    layout->addWidget(demowidget3);

    demowidgetmain->setLayout(layout);
    demowidgetmain->show();
}




void layoutDemo1(void)
{
    //创建界面
    QWidget *winMain=new QWidget();

    //设计界面尺寸
    winMain->resize(800,480);

    QPushButton *btnRelay=new QPushButton("Replay");
    QPushButton *btnConfig=new QPushButton("Config");
    QPushButton *btnLogin=new QPushButton("Login");
#if 0
    qDebug()<<btnRelay->sizeHint();
    qDebug()<<btnRelay->size();
    qDebug()<<btnRelay->minimumSizeHint();
    qDebug()<<btnRelay->minimumSize();

    //设置参数
//    btnRelay->setMinimumSize(50,50);
  //  btnRelay->setMaximumSize(100,100);
    //btnConfig->setMinimumSize(50,50);
   // btnConfig->setMaximumSize(100,100);
 //   btnLogin->setMinimumSize(50,50);
 //   btnLogin->setMaximumSize(100,100);
#endif


    //配置策略参数
    btnRelay->setSizePolicy(QSizePolicy::Policy::Minimum,QSizePolicy::Policy::Minimum);
    btnConfig->setSizePolicy(QSizePolicy::Policy::Minimum,QSizePolicy::Policy::Minimum);
    btnLogin->setSizePolicy(QSizePolicy::Policy::Minimum,QSizePolicy::Policy::Minimum);

    //拉伸因子


    //创建水平箱式子Layout
    QHBoxLayout *hlayoutMain =new QHBoxLayout();
    //布局添加按钮
    hlayoutMain->addWidget(btnRelay);
    hlayoutMain->addWidget(btnConfig);
    hlayoutMain->addWidget(btnLogin);

    //拉伸因子
    hlayoutMain->setStretchFactor(btnRelay,2);
    hlayoutMain->setStretchFactor(btnConfig,2);

   // hlayoutMain->setStretch(1,2);
    hlayoutMain->setStretchFactor(btnLogin,2);
    hlayoutMain->insertStretch(3,1);
    hlayoutMain->insertStretch(2,1);
    hlayoutMain->insertStretch(1,1);
    hlayoutMain->insertStretch(0,1);

    //创建垂直
    QVBoxLayout *layout=new QVBoxLayout();
    //配置拉伸因子
    layout->addLayout(hlayoutMain);
    layout->setStretchFactor(hlayoutMain,1);
    layout->insertStretch(1,1);
    layout->insertStretch(0,1);



    //把布局器应用到窗口
    winMain->setLayout(layout);
    winMain->show();
}

void layoutDemo0(void)
{
    //创建界面
    QWidget *winMain=new QWidget();

    //设计界面尺寸
    winMain->resize(800,480);

    //创建水平箱式子Layout
    QHBoxLayout *hlayoutMain =new QHBoxLayout();
    //布局添加按钮
    hlayoutMain->addWidget(new QPushButton("Replay"));
    hlayoutMain->addWidget(new QPushButton("Config"));
    hlayoutMain->addWidget(new QPushButton("Login"));


    //创建垂直箱子布局
    QVBoxLayout *vlayoutMain =new QVBoxLayout();
    //布局添加按钮
    vlayoutMain->addWidget(new QPushButton("Replay"));
    vlayoutMain->addWidget(new QPushButton("Config"));
    vlayoutMain->addWidget(new QPushButton("Login"));


    //两个布局添加到一个布局
    QVBoxLayout *layoutMain =new QVBoxLayout();
      layoutMain->addLayout(vlayoutMain);
    layoutMain->addLayout(hlayoutMain);


    //把布局器应用到窗口
    winMain->setLayout(layoutMain);
    winMain->show();

}
