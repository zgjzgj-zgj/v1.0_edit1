#include "qwidgetserialrx.h"
#include <QtSerialPort/QSerialPortInfo>
#include <QtSerialPort/QSerialPort>
#include <QDebug>
#include <QTimer>

int ecgWave[]=
{
            2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
            2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
            2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
            2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
            2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
            2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
            2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
            2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
            2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
            2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
            2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
            2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
            2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
            2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
            2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
            2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
            2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
            2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
            2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
            2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
            2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
            2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
            2000, 2000, 2000, 2008, 2016, 2016, 2016, 2024, 2032, 2048,
            2064, 2064, 2064, 2072, 2080, 2080, 2080, 2088, 2096, 2104,
            2112, 2112, 2112, 2112, 2112, 2112, 2104, 2096, 2088,
            2080, 2080, 2080, 2072, 2064, 2064, 2064, 2048, 2032, 2032,
            2032, 2016, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
            2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
            2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
            2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
            2000, 2000, 2000, 2000, 2000, 2000, 2000, 1992, 1984, 1976,
            1968, 1960, 1952, 1944, 1936, 1944, 1952, 2016, 2080, 2136,
            2192, 2256, 2320, 2376, 2432, 2488, 2544, 2568, 2592, 2536,
            2480, 2424, 2368, 2304, 2240, 2184, 2128, 2072, 2016, 1968,
            1920, 1928, 1936, 1944, 1952, 1960, 1968, 1984, 2000,
            2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
            2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
            2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
            2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
            2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
            2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
            2000, 2000, 2000, 2000, 2000, 2008, 2016, 2024, 2032, 2032,
            2032, 2048, 2064, 2064, 2064, 2072, 2080, 2088, 2096, 2104,
            2112, 2112, 2112, 2120, 2128, 2136, 2144, 2152, 2160, 2160,
            2160, 2160, 2160, 2168, 2176, 2176, 2176, 2184, 2192,
            2192, 2192, 2192, 2200, 2208, 2208, 2208, 2208, 2208, 2208,
            2208, 2200, 2192, 2192, 2192, 2184, 2176, 2176, 2176, 2168,
            2160, 2160, 2160, 2144, 2128, 2128, 2128, 2128, 2128, 2112,
            2096, 2088, 2080, 2072, 2064, 2064, 2064, 2048, 2032, 2024,
            2016, 2016, 2016, 2008, 2000, 2000, 2000, 2000, 2000,
            2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000
};
int Ibp2_DemoData1[] =
{
  0x0f, 0x10, 0x10, 0x11, 0x12, 0x12, 0x12, 0x13, 0x13,
  0x14, 0x14, 0x14, 0x14, 0x15, 0x17, 0x17, 0x17, 0x18,
  0x18, 0x19, 0x19, 0x19, 0x19, 0x1a, 0x19, 0x1a, 0x1a,
  0x1b, 0x1b, 0x1b, 0x1c, 0x1c, 0x1b, 0x1b, 0x1a, 0x1a,
  0x1a, 0x19, 0x19, 0x18, 0x18, 0x18, 0x17, 0x17, 0x15,
  0x15, 0x15, 0x14, 0x15, 0x14, 0x14, 0x14, 0x15, 0x15,
  0x14, 0x14, 0x15, 0x14, 0x14, 0x14, 0x15, 0x17, 0x17,
  0x17, 0x17, 0x18, 0x18, 0x19, 0x19, 0x19, 0x1a, 0x1b,
  0x1c, 0x1d, 0x1f, 0x20, 0x21, 0x22, 0x23, 0x24, 0x24,
  0x24, 0x26, 0x26, 0x26, 0x26, 0x24, 0x23, 0x23, 0x23,
  0x23, 0x22, 0x21, 0x20, 0x1d, 0x1d, 0x1c, 0x1c, 0x1c,
  0x1c, 0x1c, 0x1c, 0x1c, 0x1b, 0x1c, 0x1b, 0x1a, 0x1a,
  0x19, 0x18, 0x17, 0x15, 0x14, 0x12, 0x12, 0x11, 0x10,
  0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f
};
int  Spo2_DemoData1[248] =
{
    0x21, 0x21, 0x22, 0x22, 0x23, 0x22, 0x22, 0x21, 0x21,
    0x20, 0x20, 0x1f, 0x1e, 0x1d, 0x1c, 0x1b, 0x1b, 0x1a,
    0x19, 0x18, 0x18, 0x17, 0x16, 0x15, 0x14, 0x13, 0x12,
    0x11, 0x11, 0x10, 0x10, 0x0f, 0x0f, 0x0e, 0x0d, 0x0c,
    0x0c, 0x0b, 0x0a, 0x09, 0x09, 0x08, 0x07, 0x06, 0x06,
    0x05, 0x05, 0x04, 0x04, 0x03, 0x03, 0x02, 0x02, 0x01,
    0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x01, 0x03, 0x06, 0x0a, 0x0e, 0x13, 0x18, 0x1d,
    0x23, 0x28, 0x2d, 0x32, 0x37, 0x3b, 0x40, 0x44, 0x49,
    0x4d, 0x51, 0x54, 0x57, 0x58, 0x5a, 0x5a, 0x5a, 0x59,
    0x59, 0x57, 0x55, 0x52, 0x50, 0x4c, 0x49, 0x45, 0x42,
    0x3e, 0x3b, 0x37, 0x34, 0x31, 0x2f, 0x2c, 0x29, 0x26,
    0x24, 0x22, 0x20, 0x1f, 0x1f, 0x1e, 0x1e, 0x1d, 0x1d,
    0x1e, 0x1f, 0x20, 0x21, 0x21, 0x22, 0x22, 0x23, 0x22,
    0x22, 0x21, 0x21, 0x20, 0x20, 0x1f, 0x1e, 0x1d, 0x1c,
    0x1b, 0x1b, 0x1a, 0x19, 0x18, 0x18, 0x17, 0x16, 0x15,
    0x14, 0x13, 0x12, 0x11, 0x11, 0x10, 0x10, 0x0f, 0x0f,
    0x0e, 0x0d, 0x0c, 0x0c, 0x0b, 0x0a, 0x09, 0x09, 0x08,
    0x07, 0x06, 0x06, 0x05, 0x05, 0x04, 0x04, 0x03, 0x03,
    0x02, 0x02, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x06, 0x0a, 0x0e,
    0x13, 0x18, 0x1d, 0x23, 0x28, 0x2d, 0x32, 0x37, 0x3b,
    0x40, 0x44, 0x49, 0x4d, 0x51, 0x54, 0x57, 0x58, 0x5a,
    0x5a, 0x5a, 0x59, 0x59, 0x57, 0x55, 0x52, 0x50, 0x4c,
    0x49, 0x45, 0x42, 0x3e, 0x3b, 0x37, 0x34, 0x31, 0x2f,
    0x2c, 0x29, 0x26, 0x24, 0x22, 0x20, 0x1f, 0x1f, 0x1e,
    0x1e, 0x1d, 0x1d, 0x1e, 0x1f, 0x20, 0x21, 0x21, 0x22,
    0x22, 0x23, 0x22, 0x22, 0x21,
};

QWidgetSerialRx::QWidgetSerialRx(QWidget *parent) : QWidget(parent)
{
    if(-1==this->serialInit())
    {
        return;
    }

    connect(this->com,&QSerialPort::readyRead,this,&QWidgetSerialRx::serialRx);

}

void QWidgetSerialRx::serialRx()
{

    //qDebug()<<"rx:"<<com->readAll();
    //从串口取数据
    //循环读数
    while(!com->atEnd())
    {
        QByteArray data = this->com->read(1);
        this->rxDataHandle(data[0]);
    }

    //接收数据

}

void QWidgetSerialRx::rxDataHandle(unsigned char data)
{
    unsigned char tmpData;
    //数据处理，把有效数据提取出来
    //0.空闲状态，判断数据是不是ID
    //1.接收数据头
    //2.接收数据，并还原数据，达到指定数据长度时进入下一步
    //3.数据校验，如果校验正确，进入下一步？

    //如果最高位非0，复位状态机
    if( data < 0x80 )//不是if(data < 0x80 || data = 0xff)
        this->status = 0;

    //状态机数据处理
    switch (this->status)
    {
    case 0 :  //发送顺序：心电、血氧、血压
    {
        this->ecg_enable = 1;
        this->ibp_enable = 0;
        this->spo2_enable = 0;
            if(0x08 == data)
            {
                this->ecg_enable = 1;
                this->status=1;
                this->pkgDataCnt=0;
            }
            else
                if(0x0a == data)
                {
                    this->ecg_enable = 0;
                    this->status=4;
                    this->pkgDataCnt=0;
                }
            else
                    if(0x09 == data)
                    {
                        this->ecg_enable = 0;
                        this->status=5;
                        this->pkgDataCnt=0;
                    }
                    else
                    {this->status = 0;}
    }break;
    case 1:
    {
        this->pkgDataHead = data;
        this->status=2;
    }break;
    case 2:
    {
        this->ecg_enable = 1;
        tmpData=data&0x7F;
        tmpData = tmpData | (((this->pkgDataHead>>(this->pkgDataCnt)) & 0x01) << 7 );
        this->pkgData[this->pkgDataCnt] = tmpData;
        this->pkgDataCnt+=1;

        if(this->pkgDataCnt >= 7)
            this->status = 3;
            this->ecg_enable = 1;

    }break;
    case 3://发送顺序：心电、血氧、血压
    {
        qDebug()<<"***ecg_enable***="<<ecg_enable<<"***ibp_enable***"<<ibp_enable<<"***spo2_enable***="<<spo2_enable;
/*如果ecg_enable=1，进行心电数据处理；如果ibp_enable=1，进行血压数据处理；如果spo2_enable=1，进行血氧数据处理*/
        if(1 == ecg_enable)
        {
            if(num>sizeof(ecgWave)/sizeof(int)-3)
                num = 0;
            else
            {num += 3;}
            ecg1 = this->pkgData[0];
            ecg1 =ecg1 << 8;
            ecg1 = ecg1 + this->pkgData[1];

            ecg2 = this->pkgData[2];
            ecg2 =ecg2 << 8;
            ecg2 = ecg2 + this->pkgData[3];

            ecg3 = this->pkgData[4];
            ecg3 =ecg3 << 8;
            ecg3 = ecg3 + this->pkgData[5];
            this->ecg_enable = 0;
            /*发送数据到画布*/
            emit rxDataSignal_ecg(ecg2);
            /*心电数据打印*/
            this->status = 0;
            qDebug()<<"num="<<num;
            qDebug()<<"tx:ecg1:"<<ecgWave[num]<<"ecg2:"<<ecgWave[num]<<"ecg3:"<<ecgWave[num];
            qDebug()<<"rx:ecg1:"<<ecg1<<"ecg2:"<<ecg2<<"ecg3:"<<ecg3;
        }
        else
        {
            if(1 == spo2_enable)
            {
                /*pkgDataHead就是数据头，如果数据头是0x81，则原始数据的最高位就是1；如果数据头是0x80，则原始数据的最高位就是0*/

                if(0x81 == pkgDataHead)
                {
                    spo2 =  data;
                }
                else
                {
                    spo2 = data - 0x80;
                }
                this->spo2_enable = 0;
                num_spo2 += 1;
                /*血氧数据打印*/
                qDebug()<<"num_spo2="<<num_spo2;
                qDebug()<<"tx:spo2[num_spo2]:"<<Spo2_DemoData1[num_spo2];
                qDebug()<<"rx:spo2:"<<spo2;
                this->status = 0;
                this->ecg_enable = 1;
                emit rxDataSignal_spo2(spo2*16+1500);
                if(num_spo2>sizeof(Spo2_DemoData1)/sizeof(int))
                {num_spo2 = 0;}
                else
                {}

            }
            else
                if(1 == ibp_enable)
                {
                    if(0x81 == pkgDataHead)
                    {
                        ibp = data;
                    }
                    else
                    {
                        ibp = data - 0x80;
                    }
                    this->ibp_enable = 0;
                    num_ibp += 1;
                    /*血压数据打印*/
                    qDebug()<<"num_ibp="<<num_ibp;
                    qDebug()<<"tx:ibp[num_ibp]:"<<Ibp2_DemoData1[num_ibp];
                    qDebug()<<"rx:ibp:"<<ibp;
                    this->status = 0;
                    this->ecg_enable = 1;
                    emit rxDataSignal_ibp(ibp*50+1000);
                    if(num_ibp>sizeof(Ibp2_DemoData1)/sizeof(int))
                    {num_ibp = 0;}
                    else
                    {}

                }
    }

    }break;
    case 4:
    {
        this->pkgDataHead = data;
        this->status=3;
        this->ibp_enable = 1;
    }break;
    case 5:
    {
        this->pkgDataHead = data;
        this->status=3;
        this->spo2_enable = 1;
    }break;
    }

}

int QWidgetSerialRx::serialInit(void)
{
    //查看设备串口信息
    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        qDebug() << "Name : " << info.portName();
        qDebug() << "Description : " << info.description();
        qDebug() << "Manufacturer: " << info.manufacturer();
        qDebug() << "Serial Number: " << info.serialNumber();

    }

    //创建串口对象
    this->com = new QSerialPort();

    this->com->setPortName("COM5");

    //this->com->open(QIODevice::ReadWrite);

    if(!this->com->open(QIODevice::ReadWrite))
    {
        qDebug()<<"open serial port error"<<this->com->portName();
                  return -1;

    }

    qDebug()<<"open serial port ok";
    this->com->setBaudRate(QSerialPort::Baud115200);
    this->com->setDataBits(QSerialPort::Data8);
    this->com->setFlowControl(QSerialPort::NoFlowControl);
    this->com->setParity(QSerialPort::NoParity);
    this->com->setStopBits(QSerialPort::OneStop);
    return 0;
}
