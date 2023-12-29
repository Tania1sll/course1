#include "showinstructor.h"
#include "ui_showinstructor.h"
#include "instructor.h"
#include <QSqlTableModel>
ShowInstructor::ShowInstructor(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ShowInstructor)
{
    ui->setupUi(this);
    sqlDBM= SQLiteDBManager::getInstance();
}
ShowInstructor::~ShowInstructor()
{
    delete ui;
}

void ShowInstructor::on_PBnext_clicked()
{
    showI();
}

void ShowInstructor:: showI(){
    QSqlQueryModel *modal = sqlDBM->showInstructor();
    ui->TVinstuctor->setModel(modal);
}

void ShowInstructor::on_PBback_clicked()
{
    emit this->goBackShowInstructor();
}

