#include "createinstructor.h"
#include "ui_createinstructor.h"
#include "instructor.h"
#include <QSqlTableModel>
#include <QMessageBox>
CreateInstructor::CreateInstructor(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CreateInstructor)
{
    ui->setupUi(this);
    sqlDBM= SQLiteDBManager::getInstance();
}

void CreateInstructor::newInstructor(){
    checkI();
    Instructor instructor;
    instructor.setFirstName(ui->LEfirstName->text().toStdString());
    instructor.setLastName(ui->LElastName->text().toStdString());
    instructor.setMiddleName(ui->LEmiddleName->text().toStdString());
    instructor.setAge(ui->LEage->text().toInt());
    instructor.setGeneralInformation(ui->LEgeneralInformation->text().toStdString());
    instructor.setPrice(ui->LEprice->text().toDouble());
    sqlDBM->insertIntoTableInstructor(instructor);
}

CreateInstructor::~CreateInstructor()
{
    delete ui;
}
void CreateInstructor:: showI(){
    QSqlQueryModel *modal = sqlDBM->showInstructor();
    ui->TVinstuctor->setModel(modal);
}

void CreateInstructor::on_PBnext_clicked()
{
    newInstructor();
    showI();
}


void CreateInstructor::on_PBback_clicked()
{
    emit this->goBackInstructor();
}



void CreateInstructor::on_PBdeleteInstructor_clicked()
{
    int deleteInstructor=ui->LEdeleteIns->text().toInt();
    bool deleted =sqlDBM->deleteInstructor(deleteInstructor);
    if(deleted){
        showI();
        qDebug()<<"Deleted";
    }else{
        qDebug()<<"Not deleted";
    }
}
void CreateInstructor::checkI() {
    if (ui->LEfirstName->text().isEmpty() ||
        ui->LElastName->text().isEmpty() ||
        ui->LEmiddleName->text().isEmpty() ||
        ui->LEage->text().isEmpty() ||
        ui->LEprice->text().isEmpty()) {
        QMessageBox::critical(this, "Error", "Please fill in all required fields.");
    }
}
