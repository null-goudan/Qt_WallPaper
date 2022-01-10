#include "settingwidget.h"
#include "ui_settingwidget.h"
#include <QGraphicsDropShadowEffect>
#include "eventfilterobject.h"
#include <QFileDialog>
#include <QButtonGroup>
#include <QRadioButton>

settingwidget::settingwidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::settingwidget)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_TranslucentBackground);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    QGraphicsDropShadowEffect *shadow  = new QGraphicsDropShadowEffect();
    shadow->setColor(QColor(40,40,40,200));
    //设置偏移量
    shadow->setOffset(0, 0);
    ui->centerWidget->setGraphicsEffect(shadow);
    slotAndSignals();
    installEventFilter(new eventFilterObject);
}

settingwidget::~settingwidget()
{
    delete ui;
}

void settingwidget::on_closeBtn_clicked()
{
    this->hide();
}

void settingwidget::on_wall_setting_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void settingwidget::on_model_1_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void settingwidget::on_model_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void settingwidget::on_model_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void settingwidget::slotAndSignals()
{
    QButtonGroup *model_check = new QButtonGroup(this);
    model_check->addButton(ui->checkBox1);
    model_check->addButton(ui->checkBox2);
    model_check->addButton(ui->checkBox3);
    model_check->setExclusive(true);

    connect(model_check, QOverload<QAbstractButton*,bool>::of( &QButtonGroup::buttonToggled),this, [=](QAbstractButton* btn, bool checked){
        if(btn == ui->checkBox1){
            emit roleModelChanged(0);
        }else if(btn == ui->checkBox2){
            emit roleModelChanged(1);
        }else if(btn == ui->checkBox3){
            emit roleModelChanged(2);
        }
    });
    ui->checkBox1->setChecked(1);

    connect(ui->happy, &QRadioButton::toggle, this,[=](){emit roleMoodChanged(0);});
    connect(ui->sad, &QRadioButton::toggle, this,[=](){emit roleMoodChanged(1);});
    connect(ui->pi, &QRadioButton::toggle, this,[=](){emit roleMoodChanged(2);});
    connect(ui->shy, &QRadioButton::toggle, this,[=](){emit roleMoodChanged(3);});
    ui->happy->setChecked(1);
}


void settingwidget::on_selectBtn_clicked()
{
    const QString& filename = QFileDialog::getOpenFileName(this,"选择背景","./","Image (*.jpg *.png)");
    if(filename.isEmpty())
    {
        qWarning("请选择壁纸~");
        return;
    }
    emit bkImageChanged(filename);
}
