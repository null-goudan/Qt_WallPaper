#include "desktopwidget.h"
#include"finddektophwnd.h"
DesktopWidget::DesktopWidget(QWidget *parent) : QLabel(parent)
{
    setWindowFlags(windowFlags()|Qt::WindowType::WindowStaysOnTopHint);
    showFullScreen();
    setBkPixmap(":/resource/wallpaper/1.jpg");

    FindDektopHwnd::SetParent(this,nullptr);
}

void DesktopWidget::setBkPixmap(const QString &filename)
{
    if(QPixmap(filename).isNull())
    {
        return;
    }
    this->setPixmap(QPixmap(filename));
}


