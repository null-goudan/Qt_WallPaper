#ifndef SETTINGWIDGET_H
#define SETTINGWIDGET_H

#include <QWidget>

namespace Ui {
class settingwidget;
}

class settingwidget : public QWidget
{
    Q_OBJECT

public:
    explicit settingwidget(QWidget *parent = nullptr);
    ~settingwidget();
    void slotAndSignals();
signals:
    void roleModelChanged(int rmodel);
    void roleMoodChanged(int rmood);
    void bkImageChanged(const QString& filename);
private slots:
    void on_closeBtn_clicked();

    void on_wall_setting_clicked();

    void on_model_1_clicked();

    void on_model_2_clicked();

    void on_model_3_clicked();

    void on_selectBtn_clicked();

private:
    Ui::settingwidget *ui;
};

#endif // SETTINGWIDGET_H
