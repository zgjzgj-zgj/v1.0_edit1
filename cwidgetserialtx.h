#ifndef CWIDGETSERIALTX_H
#define CWIDGETSERIALTX_H
#include <QtSerialPort/QSerialPort>
#include <QWidget>
#include <QTimer>

class QWidgetSerialTx : public QWidget
{
    Q_OBJECT
public:
    QSerialPort *com;
    QTimer *timer;

    int index= 0;
    int index_IBP = 0;
    int index_SPO2 = 0;
    unsigned int getEcg2Data();
    unsigned int getEcg2Data_IBP();
    unsigned int getEcg2Data_SPO2();
    explicit QWidgetSerialTx(QWidget *parent = nullptr);
    int serialInit(void);
void sendEcgPkg();
void sendEcgPkg_IBP();
void sendEcgPkg_SPO2();
signals:

};

#endif // CWIDGETSERIALTX_H
