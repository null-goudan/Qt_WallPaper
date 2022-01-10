#ifndef DESKTOPWIDGET_H
#define DESKTOPWIDGET_H

#include <QLabel>

class DesktopWidget : public QLabel
{
    Q_OBJECT
public:
    explicit DesktopWidget(QWidget *parent = nullptr);
    void setBkPixmap(const QString& filename);
signals:

};

#endif // DESKTOPWIDGET_H
