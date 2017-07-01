#include "qrimg.h"

QrImg::QrImg(QQuickItem *parent) : QQuickPaintedItem(parent),qrimg(":/img/aa.jpg")
{
    connect(this,&QrImg::qrstrChanged,this,&QrImg::qrUpdate);
    QRcode *qr = QRcode_encodeString8bit("asdf",0,QR_ECLEVEL_H);
    int w = qr->width;
    qrimg = qrimg.scaled(w,w);
    for(int i=0;i<w;i++)
        for(int j=0;j<w;j++)
            qr->data[i+qr->width*j]&1?qrimg.setPixelColor(i,j,QColor(0,0,0)):qrimg.setPixelColor(i,j,QColor(255,255,255));
}

void QrImg::paint(QPainter *painter)
{
    int len = height() > width() ? width() : height();
    painter->drawPixmap(0,0,QPixmap::fromImage(qrimg).scaled(len,len));
//    painter->drawRect(10,10,100,100);
}

QString QrImg::getQrstr()
{
    return qrstr;
}

void QrImg::setQrstr(QString str)
{
    qrstr = str;
    if(qrstr.length()==0)
        qrstr = "NULL";
    emit qrstrChanged();
}

void QrImg::qrUpdate()
{
    QRcode *qr = QRcode_encodeString8bit(this->qrstr.toStdString().c_str(),0,QR_ECLEVEL_H);
    int w = qr->width;
    qrimg = qrimg.scaled(w,w);
    for(int i=0;i<w;i++)
        for(int j=0;j<w;j++)
            qr->data[i+qr->width*j]&1?qrimg.setPixelColor(i,j,QColor(0,0,0)):qrimg.setPixelColor(i,j,QColor(255,255,255));
    emit update();
}
