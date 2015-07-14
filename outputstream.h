#ifndef OUTPUTSTREAM_H
#define OUTPUTSTREAM_H

#include <QObject>
#include <QWidget>

class OutputStream : public QObject
{
    Q_OBJECT
public:
    explicit OutputStream(QObject *parent = 0);
protected:
    QWidget* getConstParamsWidget();
    QWidget* getVarParamsWidget();
    QString getShortName();
    QString getFullName();
    QString getIntName();
    QPixmap getLogo();
//    void getGSTPipeline(GstElement *Pipeline, GstElement *appsrc);
signals:

public slots:

};

#endif // OUTPUTSTREAM_H
