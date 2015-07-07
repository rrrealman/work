#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "startform.h"
#include "shareform.h"
#include "optionsform.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    bool Playing;
    QString params;

private slots:
    void StartClicked();
    void ShareClicked();
    void OptionsClicked();
};

#endif // MAINWINDOW_H
