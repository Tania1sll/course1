#include "showroute.h"
#include "ui_showroute.h"
#include "route.h"
#include <QSqlQueryModel>
ShowRoute::ShowRoute(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ShowRoute)
{
    ui->setupUi(this);
    sqlDBM= SQLiteDBManager::getInstance();
}
ShowRoute::~ShowRoute()
{
    delete ui;
}
void ShowRoute::on_PBnext_clicked()
{
    showR();
}
void ShowRoute:: showR(){
    QSqlQueryModel *modal = sqlDBM->showRoute();
    ui->TVroute->setModel(modal);
}
void ShowRoute::on_PBback_clicked()
{
    emit this->goBackShowRoute();
}

