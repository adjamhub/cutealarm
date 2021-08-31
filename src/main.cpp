/*
 * Copyright (C) Andrea Diamantini 2021 <adjam@protonmail.com>
 *
 * cutealarm Project
 *
 * @license GPL-3.0 <https://www.gnu.org/licenses/gpl-3.0.txt>
 */


#include "config.h"

#include "cutealarmtray.h"

#include <QApplication>
#include <QIcon>

#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication app(argc,argv);
    
    app.setApplicationName(PROJECT_NAME);
    app.setApplicationVersion(PROJECT_VERSION);
    app.setOrganizationName("adjam");
    app.setOrganizationDomain("adjam.org");

    app.setQuitOnLastWindowClosed(false);
    app.setWindowIcon( QIcon::fromTheme("alarm-clock-panel") );

    CuteAlarmTray cat;
    cat.show();

    return app.exec();
}
