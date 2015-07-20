#ifndef OUTPUTSTREAMOBJECT_H
#define OUTPUTSTREAMOBJECT_H

#include <QObject>
#include <QSettings>
#include "application.h"

class OutputStreamObject : public QObject
{
    Q_OBJECT

protected:
    QString URL;
    QString objName;
    QWidget *constParamsWidget;
    QWidget *varParamsWidget;

public:
    explicit OutputStreamObject(QObject *parent = 0);
    virtual ~OutputStreamObject();

    virtual QWidget* createConstParamsWidget();
    virtual QWidget* createVarParamsWidget();
            QWidget* getConstParamsWidget();
            QWidget* getVarParamsWidget();
            QString  getShortName() const;
            QString  getFullName() const;
            QString  getIntName() const;
    virtual QPixmap* getLogo();
//    virtual void getGSTPipeline(GstElement *Pipeline, GstElement *appsrc);

    bool storeVarParams();
    void resetVarParams();
    void storeConstParams();
    void resetConstParams();
    void initPipeline();
    bool isPipelineDone();

    virtual void readSettings();
    virtual void writeSettings();
protected:
//    QSettings* getSettings();
};

#endif // OUTPUTSTREAMOBJECT_H
