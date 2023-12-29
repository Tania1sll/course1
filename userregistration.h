#ifndef USERREGISTRATION_H
#define USERREGISTRATION_H
#include "sqlitedbmanager.h"
#include <QDialog>
#include "mainwindow.h"
#include "openwindow.h"
#include "showinstructor.h"
#include "adminmainwindow.h"
#define QUESTION "happy"
class MainWindow;
class OpenWindow;
class ShowInstructor;
namespace Ui {
class UserRegistration;

}

class UserRegistration : public QDialog
{
    Q_OBJECT

public:
    explicit UserRegistration(QWidget *parent = nullptr);
    ~UserRegistration();
private slots:
    void on_PBnext_clicked();
    void onUserTypeChanged(const QString& userType);
    void on_PBback_clicked();

signals:
    void goBackRegistration();

private:
    Ui::UserRegistration *ui;
    MainWindow *mainWindow;
    DBManager *sqlDBM;
    AdminMainWindow *adminMW;
};
#endif // USERREGISTRATION_H
