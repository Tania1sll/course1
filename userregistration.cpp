#include "userregistration.h"
#include "ui_userregistration.h"
#include <QMessageBox>
#include <QCryptographicHash>
UserRegistration::UserRegistration(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::UserRegistration), mainWindow(nullptr)
{
    ui->setupUi(this);
    sqlDBM = SQLiteDBManager::getInstance();
    ui->LEquestion->hide();
    connect(ui->CBcheck, SIGNAL(currentTextChanged(const QString&)), this, SLOT(onUserTypeChanged(const QString&)));
}
UserRegistration::~UserRegistration()
{
    delete ui;
}
void UserRegistration::on_PBnext_clicked()
{
    QString login= ui->LElogin->text();
    QString password = ui->LEpassword->text();
    QString userType = ui->CBcheck->currentText();
    QString question = ui->LEquestion->text();

    if(!login.isEmpty()&&!password.isEmpty())
    {
        bool nameExists = sqlDBM->loginCheck(login);
        if (!nameExists) {
            QMessageBox::critical(this, "Problem", "This name already exists");
        } else {
            QCryptographicHash hash(QCryptographicHash::Sha256);
            hash.addData(password.toUtf8());
            QByteArray hashedData = hash.result();
            QString hashedDataString = hashedData.toHex();
            if (userType == "користувач") {
                sqlDBM->inserIntoTable(login, hashedDataString, userType, question);
                QMessageBox::about(this, "Entrance to system", "User registration was successful");
                if (!mainWindow)
                    mainWindow = new MainWindow();
                mainWindow->show();
                close();

            } else if (userType == "адміністратор") {
                ui->LEquestion->show();
                if(question != QUESTION){
                    QMessageBox::about(this, "Entrance to system", "Incorrect answer to system questoin, try again!");
                }else{
                    QCryptographicHash hash2(QCryptographicHash::Sha256);
                    hash.addData(question.toUtf8());
                    QByteArray hashedData2 = hash2.result();
                    QString hashedDataString2 = hashedData2.toHex();
                    sqlDBM->inserIntoTable(login, hashedDataString, userType, hashedDataString2);
                    QMessageBox::about(this, "Entrance to system", "Administrator registration was successful");
                    if(!adminMW)
                        adminMW = new AdminMainWindow();
                    adminMW->show();
                    close();}

            } else {
                QMessageBox::critical(this, "Problem", "Unknown user type");
            }

        }
    }
    else {
        QMessageBox::critical(this, "Problem", "Fill in all the required lines!");
    }
}
void UserRegistration::onUserTypeChanged(const QString& userType)
{
    if (userType == "користувач") {
        ui->LEquestion->hide();
    } else if (userType == "адміністратор") {
        ui->LEquestion->show();
    } else {
        QMessageBox::critical(this, "Problem", "Unknown user type");
    }
}
void UserRegistration::on_PBback_clicked()
{
    emit this->goBackRegistration();
}

