#ifndef USERLOGIN_H
#define USERLOGIN_H
#include "sqlitedbmanager.h"
#include <QDialog>
#include "mainwindow.h"
#include "openwindow.h"
#include "adminmainwindow.h"
#define QUESTION "happy"
class MainWindow;
class OpenWindow;
namespace Ui {
class UserLogin;
}

class UserLogin : public QDialog
{
    Q_OBJECT

public:
    explicit UserLogin(QWidget *parent = nullptr);
    ~UserLogin();

private slots:
    void on_PBnextU_clicked();
    void onUserTypeChanged(const QString& userType);
    void on_PBbackU_clicked();

signals:
     void goBack();

private:
    Ui::UserLogin *ui;
    MainWindow *mainWindow; //todo
    DBManager *sqlDBM;
    AdminMainWindow *adminMW; //todo
};

#endif // USERLOGIN_H
