#ifndef STARTFORM_H
#define STARTFORM_H

#include <QDialog>
#include <QFileDialog>

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

private slots:
    void SpecifyFile();
};

#endif // STARTFORM_H
