/*
 * Copyright (C) Andrea Diamantini 2021 <adjam@protonmail.com>
 *
 * cutealarm Project
 *
 * @license GPL-3.0+ <https://spdx.org/licenses/GPL-3.0+.html>
 */


#ifndef CUTEALARM_TRAY_H
#define CUTEALARM_TRAY_H



#include <QSystemTrayIcon>
#include <QMenu>


class CuteAlarmTray : public QSystemTrayIcon
{
    Q_OBJECT

public:
    CuteAlarmTray(QObject *parent = nullptr);
    ~CuteAlarmTray();

private:
    void setupContextMenu();

private Q_SLOTS:
    void showSettings();
    void aboutApp();

private:
    QMenu* _contextMenu;
};


#endif // CUTEALARM_TRAY_H
