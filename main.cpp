#include <QApplication>
#include <QWidget>
#include <QHBoxLayout>
#include <QPushButton>
#include <QVBoxLayout>
#include <QDebug>
#include <QLabel>
#include <QSizePolicy>
#include "qwidgetdemo.h"
//#include "layoutDraw.h"
#include "qwidgetdraw.h"
#include "cwidgetserialtx.h"
#include "qwidgetserialrx.h"















int main(int argc, char * argv[])
{
    QApplication a(argc, argv);
    QWidget *mainWin =new QWidget();

    mainWin->resize(800,500);
    mainWin->setWindowTitle("实习起飞组");

    /*创建主布局和3个按钮布局，3张波形图布局*/
    QHBoxLayout *layout_main = new QHBoxLayout();
    QVBoxLayout *layout_wave = new QVBoxLayout();
    QVBoxLayout *layout_btn = new QVBoxLayout();

    /*创建3个按钮、3个标签*/
    QPushButton *btnECG = new QPushButton("ECG");
    QPushButton *btnSPO2 = new QPushButton("SPO2");
    QPushButton *btnIBP = new QPushButton("IBP");
    //QLabel *ECG = new QLabel("ECG");
    //QLabel *IBP = new QLabel("IBP");
    //QLabel *SPO2 = new QLabel("SPO2");

    /*放3个按钮到3个按钮布局中*/
    layout_btn->addWidget(btnECG);
    layout_btn->addWidget(btnSPO2);
    layout_btn->addWidget(btnIBP);

    /* 若想改变对象的宽度或距离之比就必须设置其Policy为Preferred*/
    btnECG->setSizePolicy(QSizePolicy::Policy::Preferred,QSizePolicy::Policy::Preferred);
    btnSPO2->setSizePolicy(QSizePolicy::Policy::Preferred,QSizePolicy::Policy::Preferred);
    btnIBP->setSizePolicy(QSizePolicy::Policy::Preferred,QSizePolicy::Policy::Preferred);

    /*没有插入拉伸因子条件下，3个按钮会纵向铺满整个界面，宽度之比就是setStretchFactor内参数之比*/
    layout_btn->setStretchFactor(btnECG,1);
    layout_btn->setStretchFactor(btnSPO2,1);
    layout_btn->setStretchFactor(btnIBP,1);

    /*插入拉伸因子就是插入空隙*/
    /*因为按钮布局中总共有3只按钮，故这3只按钮从上到下的编号(insertStretch中第一个参数)分别为0、1、2*/
    /*insertStretch(i,j)中第二个参数表示在第i个对象“上方”，插入一个比例为j的空隙*/
    /*从下到上插入空隙的宽度之比是(row44):(row45):(row46):(row47)*/
    /*layout_btn->insertStretch(3,1);
    layout_btn->insertStretch(2,1);
    layout_btn->insertStretch(1,1);
    layout_btn->insertStretch(0,1);*/

    /*创建3张画布*/
    QWidgetDraw *drawmap_ecg= new QWidgetDraw();
    QWidgetDraw *drawmap_ibp= new QWidgetDraw();
    QWidgetDraw *drawmap_spo2= new QWidgetDraw();

    /*实例化串口发送和串口接收类*/
    QWidgetSerialTx *serialTx =new QWidgetSerialTx(mainWin);
    QWidgetSerialRx *serialRx =new QWidgetSerialRx(mainWin);

    /*将COM5接收来的数据发射到画布上*/
    mainWin->connect(serialRx,&QWidgetSerialRx::rxDataSignal_ecg,drawmap_ecg,&QWidgetDraw::refresh);
    mainWin->connect(serialRx,&QWidgetSerialRx::rxDataSignal_ibp,drawmap_ibp,&QWidgetDraw::refresh);
    mainWin->connect(serialRx,&QWidgetSerialRx::rxDataSignal_spo2,drawmap_spo2,&QWidgetDraw::refresh);

    /*放3张画布、3个标签到3张波形图布局中*/
    //layout_wave->addWidget(ECG);
    layout_wave->addWidget(drawmap_ecg);
    //layout_wave->addWidget(IBP);
    layout_wave->addWidget(drawmap_ibp);
    //layout_wave->addWidget(SPO2);
    layout_wave->addWidget(drawmap_spo2);

    /* 若想改变对象的宽度或距离之比就必须设置其Policy为Preferred*/
    //ECG->setSizePolicy(QSizePolicy::Policy::Preferred,QSizePolicy::Policy::Preferred);
    drawmap_ecg->setSizePolicy(QSizePolicy::Policy::Preferred,QSizePolicy::Policy::Preferred);
    //IBP->setSizePolicy(QSizePolicy::Policy::Preferred,QSizePolicy::Policy::Preferred);
    drawmap_ibp->setSizePolicy(QSizePolicy::Policy::Preferred,QSizePolicy::Policy::Preferred);
    //SPO2->setSizePolicy(QSizePolicy::Policy::Preferred,QSizePolicy::Policy::Preferred);
    drawmap_spo2->setSizePolicy(QSizePolicy::Policy::Preferred,QSizePolicy::Policy::Preferred);

    /*设置波形图里标签的内容*/
    drawmap_ecg->setLabelText("ECG");
    drawmap_ibp->setLabelText("IBP");
    drawmap_spo2->setLabelText("SPO2");
    drawmap_ecg->setStyleSheet("color : white");
    drawmap_ibp->setStyleSheet("color : white");
    drawmap_spo2->setStyleSheet("color : white");

    /*没有插入拉伸因子条件下，3个按钮会纵向铺满整个界面，宽度之比就是setStretchFactor内参数之比*/
    //layout_wave->setStretchFactor(ECG,1);
    layout_wave->setStretchFactor(drawmap_ecg,5);
    //layout_wave->setStretchFactor(IBP,1);
    layout_wave->setStretchFactor(drawmap_ibp,5);
    //layout_wave->setStretchFactor(SPO2,1);
    layout_wave->setStretchFactor(drawmap_spo2,5);

    /*左右分别放置3只按钮布局和3张波形图布局*/
    layout_main->addLayout(layout_wave);
    layout_main->addLayout(layout_btn);


    /*setStretchFactor用来设置布局之间的长度比例*/
    layout_main->setStretchFactor(layout_btn,1);
    layout_main->setStretchFactor(layout_wave,4);

    /*insertStretch用来设置布局之间空隙的长度比例，从左到右对象编号分别是0、1、2*/
    /*layout_main->insertStretch(2,1);
    layout_main->insertStretch(1,1);
    layout_main->insertStretch(0,1);*/
    mainWin->setLayout(layout_main);
    mainWin->show();
    return a.exec();
}


















#if 0
int main(int argc, char * argv[])
{
    QApplication a(argc, argv);
//layoutDemo2();
//    layoutDemo1();
    QWidget *winmain = new QWidget();
    QVBoxLayout *layout = new QVBoxLayout();

    QWidgetDraw *drawWidget  = new  QWidgetDraw();
    QWidgetDraw *drawWidget1 = new  QWidgetDraw();

    layout->addWidget(drawWidget);
    layout->addWidget(drawWidget1);

    winmain->setLayout(layout);

    winmain->setWindowTitle("实习起飞组");
    winmain->resize(1000,500);

    winmain->show();
    return a.exec();
}
#endif
