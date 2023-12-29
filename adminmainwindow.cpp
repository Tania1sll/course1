#include "adminmainwindow.h"
#include "ui_adminmainwindow.h"
AdminMainWindow::AdminMainWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AdminMainWindow), createInstructor(nullptr), createRoute(nullptr)
{
    ui->setupUi(this);
    this->instance = SQLiteDBManager::getInstance();
}

AdminMainWindow::~AdminMainWindow()
{
    delete ui;
}
void AdminMainWindow::on_goBackInstructor()
{
    createInstructor->hide();
    this->show();
}
void AdminMainWindow::on_goBackRoute(){
    createRoute->hide();
    this->show();
}
void AdminMainWindow::on_PBaddInstructor_clicked()
{
    if (!this->createInstructor) {
        this->createInstructor = new CreateInstructor(this);
        connect(createInstructor, &CreateInstructor::goBackInstructor, this, &AdminMainWindow::on_goBackInstructor);
    }
    createInstructor->show();
    hide();
}
void AdminMainWindow::on_PBaddRoute_clicked()
{
    if (!this->createRoute) {
        this->createRoute = new CreateRoute(this);
         connect(createRoute, &CreateRoute::goBackRoute, this, &AdminMainWindow::on_goBackRoute);
    }
    createRoute->show();
    hide();
}


void AdminMainWindow::on_PBback_clicked()
{
     // emit this->goBackAdminMW();
    QApplication::quit();
}

