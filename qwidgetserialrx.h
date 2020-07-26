#ifndef QWIDGETSERIALRX_H
#define QWIDGETSERIALRX_H
#include <QtSerialPort/QSerialPort>
#include <QWidget>
#include <QTimer>
#include <QWidget>

class QWidgetSerialRx : public QWidget
{
    Q_OBJECT
public:
    explicit QWidgetSerialRx(QWidget *parent = nullptr);
    QSerialPort *com;
    char status=0;
    unsigned int num=0;
    unsigned int num_ibp=0;
    unsigned int num_spo2=0;
    int ecg1,ecg2,ecg3;
    int ibp;
    int spo2;
    int ecg_enable = 0;
    int ibp_enable = 0;
    int spo2_enable = 0;
    unsigned char pkgDataCnt;
    unsigned char pkgDataHead;
    unsigned char pkgDataCrc;
    unsigned char pkgData[7];
    void serialRx(void) ;
    void rxDataHandle(unsigned char data);
    int serialInit();

signals:
    void rxDataSignal_ecg(int data);
    void rxDataSignal_ibp(int data);
    void rxDataSignal_spo2(int data);
};

#endif // QWIDGETSERIALRX_H
