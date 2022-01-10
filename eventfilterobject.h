#ifndef EVENTFILTEROBJECT_H
#define EVENTFILTEROBJECT_H

#include <QObject>
#include <QEvent>
#include <QMouseEvent>
#include <QWidget>

class eventFilterObject : public QObject
{
    Q_OBJECT
public:
    explicit eventFilterObject(QObject *parent = nullptr);
    bool eventFilter(QObject *watched, QEvent *event) override;
signals:

};

#endif // EVENTFILTEROBJECT_H
