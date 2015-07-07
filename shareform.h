#ifndef SHAREFORM_H
#define SHAREFORM_H

#include <QDialog>

namespace Ui {
class ShareForm;
}

class ShareForm : public QDialog
{
    Q_OBJECT

public:
    explicit ShareForm(QWidget *parent = 0);
    ~ShareForm();

private:
    Ui::ShareForm *ui;
};

#endif // SHAREFORM_H
