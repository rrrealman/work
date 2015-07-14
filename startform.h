#ifndef STARTFORM_H
#define STARTFORM_H

#include <QDialog>
#include <QFileDialog>
#include "QSignalMapper"

#define HOST 0
#define YT   1
#define US   2

namespace Ui {
class StartForm;
}

class StartForm : public QDialog
{
    Q_OBJECT

public:
    explicit StartForm(QWidget *parent = 0);
    ~StartForm();
    char GetMode() const;
    QString GetParams() const;

private:
    Ui::StartForm *ui;
    QString Params;
    QSignalMapper *RadioButtons;

private slots:
    void SpecifyFile();
    void RBClicked(int RB);
//    void HideAllParams();
//    void VisibleHostParams(bool visible);
};

#endif // STARTFORM_H
