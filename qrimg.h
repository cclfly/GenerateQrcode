#ifndef QRIMG_H
#define QRIMG_H

#include <QObject>
#include <QQuickPaintedItem>
#include <QPainter>
#include <QImage>
#include <QPixmap>
#include <qrencode.h>

class QrImg : public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(QString qrstr READ getQrstr WRITE setQrstr NOTIFY qrstrChanged)

public:
    explicit QrImg(QQuickItem *parent = nullptr);
    QString getQrstr();

protected:
    void paint(QPainter *painter) override;

protected:
    QImage qrimg;
    QString qrstr;

signals:
    void qrstrChanged();

public slots:
    void setQrstr(QString str);
    void qrUpdate();
};

#endif // QRIMG_H
