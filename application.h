#ifndef APPLICATION_H
#define APPLICATION_H

#include <QApplication>
#include <QSettings>


class Q_WIDGETS_EXPORT Application:public QApplication
{
    Q_OBJECT
public:
    Application(int&, char**, QSettings *);
    virtual ~Application();

    QSettings*              getSettings() const;

private:
    QSettings*              m_settings;
};

QSettings*                  getApplicationSettings();

#endif // APPLICATION_H
