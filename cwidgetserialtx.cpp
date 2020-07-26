#include "cwidgetserialtx.h"
#include <QtSerialPort/QSerialPortInfo>
#include <QtSerialPort/QSerialPort>
#include <QDebug>
#include <QTimer>

int ecgWaveData[]=
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

int Ibp2_DemoData[] =
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
int  Spo2_DemoData[248] =
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

QWidgetSerialTx::QWidgetSerialTx(QWidget *parent) : QWidget(parent)
{
    this->serialInit();

    this->timer = new QTimer();
    connect(this->timer,&QTimer::timeout,this,&QWidgetSerialTx::sendEcgPkg);
    connect(this->timer,&QTimer::timeout,this,&QWidgetSerialTx::sendEcgPkg_IBP);
    connect(this->timer,&QTimer::timeout,this,&QWidgetSerialTx::sendEcgPkg_SPO2);
    this->timer->start(1);
}






/*串口COM4发送心电数据*/
void QWidgetSerialTx::sendEcgPkg()
{

   // this->com->write("Hello");
    char dataBuf[10];
    unsigned int ecgData[3]={2048,2048,2048};
    int i;
    char byteH,byteL;

    /*ADC取心电数据*/
    ecgData[1]=this->getEcg2Data();
    ecgData[0]=ecgData[1];
    ecgData[2]=ecgData[1];

    /*数据格式 ID+数据头+数据+校验*/
    dataBuf[0]=0x08;
    dataBuf[1]=0x80;
    for(i=0;i<3;i++)
    {
        byteH=(char)((ecgData[i])>> 8);
        byteL=(char)(ecgData[i]&0xFF);
        //字节的最高位存入数据头
        dataBuf[1] = dataBuf[1] | ((byteH&0x80) >> (7-i*2));
        dataBuf[1] = dataBuf[1] | ((byteL&0x80) >>(7-i*2-1));

        //添加数据

        dataBuf[2+i*2] = 0x80 | byteH;
        dataBuf[2+i*2+1]=0x80 |byteL;


    }
    dataBuf[8] = 0xFF;//数据状态字段暂时不用
    dataBuf[9] = 0xFF;//暂时不用
    this->com->write(dataBuf,sizeof(dataBuf));
}

/*串口COM4发送血氧数据*/
void QWidgetSerialTx::sendEcgPkg_SPO2()
{
    char dataBuf[4];
    unsigned int spo2Data;
    char byteH;
    spo2Data = (char)(this->getEcg2Data_SPO2());
    dataBuf[0]=0x09;
    dataBuf[1]=0x80;
    byteH=(char)((spo2Data)>> 7);

    /*给一个数据包的每一位赋值*/
    dataBuf[0] = 0x09;
    dataBuf[1] = dataBuf[1] + byteH;
    dataBuf[2] = (char)(0xff&spo2Data) | 0x80;
    dataBuf[3] = 0xFF;//校验位暂时不用

    this->com->write(dataBuf,sizeof(dataBuf));
}


/*串口COM4发送血压数据*/
void QWidgetSerialTx::sendEcgPkg_IBP()
{
    char dataBuf[4];
    unsigned int ibpData;
    char byteH;
    ibpData = (char)(this->getEcg2Data_IBP());
    dataBuf[0]=0x0a;
    dataBuf[1]=0x80;
    byteH=(char)((ibpData)>> 7);

    /*给一个数据包的每一位赋值*/
    dataBuf[0] = 0x0a;
    dataBuf[1] = dataBuf[1] + byteH;
    dataBuf[2] = (char)(0xff&ibpData) | 0x80;
    dataBuf[3] = 0xFF;//校验位暂时不用

    this->com->write(dataBuf,sizeof(dataBuf));
}










/*程序内发送心电数据*/
unsigned int QWidgetSerialTx::getEcg2Data()
{

    this->index+=3;

    if(this->index >= sizeof(ecgWaveData)/sizeof(int))
    {
        this->index=0;
    }

    //return index;   //用index测试
    return ecgWaveData[this->index];
}

/*程序内发送血压数据*/
unsigned int QWidgetSerialTx::getEcg2Data_IBP()
{

    this->index_IBP+=1;

    if(this->index_IBP >= sizeof(Ibp2_DemoData)/sizeof(int))
    {
        this->index_IBP=0;
    }

    //return index;   //用index测试
    return Ibp2_DemoData[this->index_IBP];
}

/*程序内发送血氧数据*/
unsigned int QWidgetSerialTx::getEcg2Data_SPO2()
{
    this->index_SPO2+=1;

    if(this->index_SPO2 >= sizeof(Spo2_DemoData)/sizeof(int))
    {
        this->index_SPO2=0;
    }

    //return index;   //用index测试
    return Spo2_DemoData[this->index_SPO2];
}











/*串口COM4初始化*/
int QWidgetSerialTx::serialInit(void)
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

    this->com->setPortName("COM4");

    //this->com->open(QIODevice::ReadWrite);

    if(!this->com->open(QIODevice::ReadWrite))//会同时打开COM1
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
