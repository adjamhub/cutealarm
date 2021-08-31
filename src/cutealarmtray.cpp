/*
 * Copyright (C) Andrea Diamantini 2021 <adjam@protonmail.com>
 *
 * cutealarm Project
 *
 * @license GPL-3.0+ <https://spdx.org/licenses/GPL-3.0+.html>
 */


#include "cutealarmtray.h"
#include "settingsdialog.h"

#include <QApplication>
#include <QAction>
#include <QIcon>
#include <QMessageBox>


CuteAlarmTray::CuteAlarmTray (QObject *parent)
    : QSystemTrayIcon (parent)
    , _contextMenu( new QMenu )
{
    setIcon( QIcon::fromTheme("") );
    
    setToolTip("Alarm");
    
    setupContextMenu();
}


CuteAlarmTray::~CuteAlarmTray()
{
    delete _contextMenu;
}


void CuteAlarmTray::setupContextMenu()
{
    QAction* actionShowSettings = new QAction( QIcon::fromTheme("settings-configure"), "Settings", this);
    connect(actionShowSettings, &QAction::triggered, this, &CuteAlarmTray::showSettings);
    _contextMenu->addAction(actionShowSettings);

    QAction* actionAboutApp = new QAction( QIcon::fromTheme("help-about"), "About", this );
    connect(actionAboutApp, &QAction::triggered, this, &CuteAlarmTray::aboutApp);
    _contextMenu->addAction(actionAboutApp);

    QAction* actionQuit = new QAction( QIcon::fromTheme("application-exit"), "Quit", this );
    connect(actionQuit, &QAction::triggered, qApp, &QApplication::quit, Qt::QueuedConnection);
    _contextMenu->addAction(actionQuit);

    setContextMenu(_contextMenu);
}


void CuteAlarmTray::showSettings()
{
    SettingsDialog* dialog = new SettingsDialog;
    dialog->exec();
    dialog->deleteLater();

//    loadSettings();
}


void CuteAlarmTray::aboutApp()
{
    QString version = qApp->applicationVersion();

    QMessageBox::about(nullptr,
                       "About cutealarm",
                        "CuteAlarm " + version + "\n\nMinimal Alarm GUI application, based on Qt libraries");
}
