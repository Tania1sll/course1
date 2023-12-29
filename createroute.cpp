#include "createroute.h"
#include "ui_createroute.h"
#include "route.h"
#include <QSqlTableModel>
#include <QMessageBox>
CreateRoute::CreateRoute(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CreateRoute)
{
    ui->setupUi(this);
    sqlDBM= SQLiteDBManager::getInstance();
}
void CreateRoute::newRoute(){
    check();
    Route route;
    if(ui->CBrouteType->currentIndex()==1){
        route.setRouteType("Печера");
    }
    else
        if(ui->CBrouteType->currentIndex()==2){
            route.setRouteType("Вода");

        }

    if(ui->CBcomplaxity->currentIndex()==1){
        route.setComplaxity("для початківців");

    }
    else
        if(ui->CBcomplaxity->currentIndex()==2){
            route.setComplaxity("для бувалих");

        }
        else
            if(ui->CBcomplaxity->currentIndex()==3){
                route.setComplaxity("для тих хто хоче екстриму");

            }
            else
                 if(ui->CBcomplaxity->currentIndex()==4){
                    route.setComplaxity("для профі");
 }
    route.setRouteName(ui->LErouteName->text().toStdString());
    route.setDistance(ui->LEdistance->text().toDouble());
    route.setPrice(ui->LEprice->text().toDouble());
    route.setRouteDetails(ui->LErouteDetails->text().toStdString());
    sqlDBM->insertIntoTableRoute(route);
}
void CreateRoute:: showR(){
    QSqlQueryModel *modal = sqlDBM->showRoute();
    ui->TVroute->setModel(modal);
}

CreateRoute::~CreateRoute()
{
    delete ui;
}

void CreateRoute::on_PBnext_clicked()
{
    newRoute();
    showR();
}


void CreateRoute::on_PBback_clicked()
{
   emit this->goBackRoute();
}

void CreateRoute::on_PBdelete_clicked()
{
    int deleteR=ui->LEdelete->text().toInt();
    bool deleted =sqlDBM->deleteRoute(deleteR);
    if(deleted){
        showR();
        qDebug()<<"Deleted";
    }else{
        qDebug()<<"Not deleted";
    }
}
void CreateRoute::check() {
    if (ui->CBrouteType->currentIndex() == 0 ||
        ui->CBcomplaxity->currentIndex() == 0 ||
        ui->LErouteName->text().isEmpty() ||
        ui->LEdistance->text().isEmpty() ||
        ui->LEprice->text().isEmpty()) {
        QMessageBox::critical(this, "Error", "Please fill in all required fields.");
    }
}
