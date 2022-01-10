#include "mainwindow.h"
#include<QApplication>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),centetLabel(new QLabel),
      model_num(0), model_mood(0), model_frame(0),settingWidget(new settingwidget)
    ,desktopWidget(new DesktopWidget)
{
    this->setWindowFlags(windowFlags()|Qt::FramelessWindowHint| Qt::Tool);
    this->setAttribute(Qt::WA_TranslucentBackground);
    this->setCentralWidget(centetLabel);
    this->setFixedSize(340, 410);

    QTimer* updateTimer = new QTimer(this);
    updateTimer->callOnTimeout(this, &MainWindow::update_model_frame);
    updateTimer->start(500);
    installEventFilter(new eventFilterObject(this));
    this->init_button();
    this->init_taryIcon();

    connect(settingWidget,&settingwidget::roleModelChanged,this,[=](int rmodel){model_num= rmodel;});
    connect(settingWidget,&settingwidget::roleMoodChanged,this,[=](int rmood){model_mood= rmood;});
    connect(settingWidget,&settingwidget::bkImageChanged,desktopWidget,&DesktopWidget::setBkPixmap);
}

MainWindow::~MainWindow()
{
}

void MainWindow::update_model_frame(){
    if(this->model_num==0){
        centetLabel->setStyleSheet(QString("image:url(://resource/desktopRole/summerGril/%1.png);").arg(model_frame));
    }
    else if(this->model_num==1){
        centetLabel->setStyleSheet(QString("image:url(://resource/desktopRole/littleBoy/%1.png);").arg(model_frame));
    }else if(this->model_num==2){
        if(this->model_mood==0){
            centetLabel->setStyleSheet(QString("image:url(://resource/desktopRole/blackGril/action1-happy/%1.png);").arg(model_frame));
        }
        if(this->model_mood==1){
            centetLabel->setStyleSheet(QString("image:url(://resource/desktopRole/blackGril/action1-sad/%1.png);").arg(model_frame));
        }
        if(this->model_mood==2){
            centetLabel->setStyleSheet(QString("image:url(://resource/desktopRole/blackGril/action1-naughty/%1.png);").arg(model_frame));
        }
        if(this->model_mood==3){
            centetLabel->setStyleSheet(QString("image:url(://resource/desktopRole/blackGril/action1-shy/%1.png);").arg(model_frame));
        }
    }
    model_frame = (model_frame + 1) % 6;
}

void MainWindow::init_button()
{
    this->closeBtn = new QPushButton(this);
    this->settingBtn = new QPushButton(this);

    this->closeBtn->setFixedSize(35, 35);
    this->settingBtn->setFixedSize(35, 35);
    this->closeBtn->move(this->width()-45,50);
    this->settingBtn->move(this->width()-45,90);
    this->closeBtn->setObjectName("closeBtn");
    this->settingBtn->setObjectName("settingBtn");

    this->setStyleSheet(
                "QPushButton{"
                    "border: none;"
                    "background-color:rgba(205,205,205,200);"
                "}"
                "QPushButton#closeBtn{"
                    "image:url(://resource/button/shut.png);"
                "}"
                "QPushButton#closeBtn:hover{"
                    "background-color:rgba(232,17,35,200);"
                "}"
                "QPushButton#settingBtn{"
                    "image:url(://resource/button/setting.png);"
                "}"
                "QPushButton#settingBtn:hover{"
                    "background-color:rgba(53,169,240,200);}"
                "}"
                );

    connect(this->closeBtn, &QPushButton::released, this, &MainWindow::close);
    connect(this->settingBtn, &QPushButton::released, this, [=]{
        this->settingWidget->show();
    });
}

void MainWindow::init_taryIcon(){
    this->trayIcon = new  QSystemTrayIcon(QIcon("://resource/logo.png"),this);
    QMenu* trayMenu = new QMenu(this);

    trayMenu->addAction("打开人物面板",this, &QMainWindow::showNormal);
    trayMenu->addSeparator();
    trayMenu->addAction("最小化到托盘",this,&QMainWindow::showMinimized);
    trayMenu->addAction("退出程序",qApp,&QApplication::quit);

    trayIcon->setContextMenu(trayMenu);
    trayIcon->show();

    connect(trayIcon, &QSystemTrayIcon::activated, this, [=](QSystemTrayIcon::ActivationReason reason){
        if(reason == QSystemTrayIcon::ActivationReason::DoubleClick){
            if(this->windowState() & Qt::WindowState::WindowMinimized)
            {
                this->showNormal();
            }else
            {
                this->showMinimized();
            }
        }
    });
}
