#ifndef QWIDGETDRAW_H
#define QWIDGETDRAW_H

#include <QWidget>
#include <QObject>
#include <QLabel>

class QWidgetDraw : public QWidget
{
    Q_OBJECT
public:
    QLabel *label;
    QTimer *timer;
    explicit QWidgetDraw(QWidget *parent = nullptr);
    QPixmap *map;
    int index = 0;
    int W0=0;
    int Y0=0;
    int X = 0;
    int Y = 0;
    int dir = 0;
    int cnt = 0;
    int lastdata=0;
     void NewdrawTriangle(QPainter *painter);
    void draw(QPainter *painter,int data);
    void drawDemo(QPainter *painter);
    void drawTriangle(QPainter *painter);
    void refresh(int data);
    void drawWaveFromArray(QPainter *painter,int data);
    void drawWave(QPainter *painter,int data);
    void sendData();
    void refreshFromData(int data);
    void testRx(int data);
    void setLabelText(QString labelText);

private:
    void paintEvent(QPaintEvent *event) override;

signals:
    void rxDataSignal(int data);

};

#endif // QWIDGETDRAW_H
