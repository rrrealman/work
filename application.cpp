#include "application.h"
#include <QDebug>

#define APP_STGS "appSettings"

Application::Application(int &argc, char** argv, QSettings *settings)
    :QApplication(argc, argv),  m_settings(settings)
{
    //this->arguments();
}

Application::~Application()
{
    if (m_settings) delete m_settings;
}

QSettings* Application::getSettings() const
{
    return m_settings;
}

QSettings* getApplicationSettings()
{
    Application *app = static_cast<Application *>(qApp);
    return app->getSettings();
}
