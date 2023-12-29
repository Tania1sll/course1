#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    customers = new CreateCustomer();
    route = new ShowRoute();
    instructor = new ShowInstructor();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_goBackCustomer()
{
    customers->hide();
    this->show();
}
void MainWindow::on_goBackShowRoute(){
    route->hide();
    this->show();
}
void MainWindow::on_goBackShowInstructor(){
    instructor->hide();
    this->show();
}
void MainWindow::on_PBcustomer_clicked()
{
     connect(customers, &CreateCustomer::goBackCustomer, this, &MainWindow::on_goBackCustomer);
    customers->show();
    hide();
}


void MainWindow::on_PBrouter_clicked()
{
     connect(route, &ShowRoute::goBackShowRoute, this, &MainWindow::on_goBackShowRoute);
    route->show();
    route->showR();
    hide();
}


void MainWindow::on_PBinstructor_clicked()
{
     connect(instructor, &ShowInstructor::goBackShowInstructor, this, &MainWindow::on_goBackShowInstructor);
    instructor->show();
    instructor->showI();
    hide();
}

void MainWindow::on_PBback_clicked()
{
     QApplication::quit();
}

