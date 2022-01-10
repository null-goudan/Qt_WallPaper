#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QString>
#include <QTimer>
#include <QPushButton>
#include "eventfilterobject.h"
#include "settingwidget.h"
#include <QSystemTrayIcon>
#include "desktopwidget.h"
#include <QMenu>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void update_model_frame();
    void init_button();
    void init_taryIcon();
private:
    QLabel* centetLabel;
    qint8 model_num;
    qint8 model_mood;
    qint8 model_frame;

    QPushButton* closeBtn;
    QPushButton* settingBtn;

    settingwidget* settingWidget;
    DesktopWidget* desktopWidget;

    QSystemTrayIcon* trayIcon;
};
#endif // MAINWINDOW_H
