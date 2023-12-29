#include "openwindow.h"
#include "ui_openwindow.h"
#include "userlogin.h"
#include "userregistration.h"
#include "adminmainwindow.h"
OpenWindow::OpenWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::OpenWindow), userLogin(nullptr), registration(nullptr)
{
    ui->setupUi(this);

}

OpenWindow::~OpenWindow()
{
    delete ui;
}

void OpenWindow::on_goBack()
{
    userLogin->hide();
    this->show();
}
void OpenWindow::on_goBackRegistration(){
    registration->hide();
    this->show();
}

void OpenWindow::on_PBlogin_clicked()
{
    if (!this->userLogin) {
        this->userLogin = new UserLogin(this);
        connect(userLogin, &UserLogin::goBack, this, &OpenWindow::on_goBack);
    }
    userLogin->show();
    hide();
}

void OpenWindow::on_PBregistration_clicked()
{
    if (!this->registration) {
        this->registration = new UserRegistration(this);
         connect(registration, &UserRegistration::goBackRegistration, this, &OpenWindow::on_goBackRegistration);
    }
    registration->show();
    hide();
}


