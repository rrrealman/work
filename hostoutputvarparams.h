#ifndef HOSTOUTPUTVARPARAMS_H
#define HOSTOUTPUTVARPARAMS_H

#include <QWidget>
#include <QFileDialog>

namespace Ui {
class HostOutputVarParams;
}

class HostOutputVarParams : public QWidget
{
    Q_OBJECT

public:
    explicit HostOutputVarParams(QWidget *parent = 0);
    ~HostOutputVarParams();

    void SpecifyFile();

private:
    Ui::HostOutputVarParams *ui;
};

#endif // HOSTOUTPUTVARPARAMS_H
