#ifndef STARTFORM_H
#define STARTFORM_H

#include <QDialog>
#include <QLayout>
#include <QRadioButton>
#include <QSignalMapper>
#include "output.h"

namespace Ui {
class StartForm;
}

class StartForm : public QDialog
{
    Q_OBJECT

public:
    explicit StartForm(QWidget *parent = 0);
    ~StartForm();
//    char GetMode() const;
//    QString GetParams() const;

private:
    Ui::StartForm *ui;
    Output* output;
//    QString Params;

private slots:
    void RBClicked(int RB);
    void HideAll();
//    void VisibleHostParams(bool visible);
};

#endif // STARTFORM_H
