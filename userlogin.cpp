#include "userlogin.h"
#include "ui_userlogin.h"
#include <QCryptographicHash>
#include <QMessageBox>
UserLogin::UserLogin(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::UserLogin)
{
    ui->setupUi(this);
    sqlDBM = SQLiteDBManager::getInstance();
    ui->LEquestionLogin->hide();
    connect(ui->CBloginAs, SIGNAL(currentTextChanged(const QString&)), this, SLOT(onUserTypeChanged(const QString&)));
    mainWindow = new MainWindow;
    qDebug() << "UserLogin";
}

UserLogin::~UserLogin()
{
    delete ui;
}

void UserLogin::on_PBnextU_clicked()
{
    QString login = ui->LEloginU->text();
    QString password = ui->LEpasswordU->text();
    QString userType = ui->CBloginAs->currentText();
    QString question = ui->LEquestionLogin->text();

    if(!login.isEmpty()&&!password.isEmpty())
    {
        QCryptographicHash hash(QCryptographicHash::Sha256);
        hash.addData(password.toUtf8());
        QByteArray hashedData = hash.result();
        QString hashedDataString = hashedData.toHex();
        if (userType == "користувач") {
            bool check= sqlDBM->userLogin(login, hashedDataString);
            sqlDBM->inserIntoTable(login, hashedDataString, userType, question);
            QMessageBox::about(this, "Entrance to system", "User login was successful");
            mainWindow->show();
            close();
        } else if (userType == "адміністратор")
        {
            ui->LEquestionLogin->show();
            if(question != QUESTION){
                QMessageBox::about(this, "Entrance to system", "Incorrect answer to system questoin, try again!");
            }else{

                QCryptographicHash hash2(QCryptographicHash::Md5);
                hash.addData(question.toUtf8());
                QByteArray hashedData2 = hash2.result();
                QString hashedDataString2 = hashedData2.toHex();
                bool check = sqlDBM->userAdmin(login,hashedDataString, userType, hashedDataString2);
                sqlDBM->inserIntoTable(login, hashedDataString, userType, hashedDataString2);
                QMessageBox::about(this, "Entrance to system", "Administrator login was successful");
                if(!adminMW)
                    adminMW = new AdminMainWindow();
                adminMW->show();
                close();
            }   } else {
            QMessageBox::critical(this, "Problem", "Unknown user type");
        }

    }
    else  { QMessageBox::critical(this,"Login Failed", "Incorrect login or password. Please try again");}
}
void UserLogin::onUserTypeChanged(const QString& userType)
{
    if (userType == "користувач") {
        ui->LEquestionLogin->hide();
    } else if (userType == "адміністратор") {
        ui->LEquestionLogin->show();
    } else {
        QMessageBox::critical(this, "Problem", "Unknown user type");
    }
}

void UserLogin::on_PBbackU_clicked()
{
     emit this->goBack();

}

