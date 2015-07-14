#ifndef FILESETTINGS_H
#define FILESETTINGS_H

#include <QDialog>

namespace Ui {
class FileSettings;
}

class FileSettings : public QDialog
{
    Q_OBJECT

public:
    explicit FileSettings(QWidget *parent = 0);
    ~FileSettings();

private:
    Ui::FileSettings *ui;
};

#endif // FILESETTINGS_H
