#ifndef OPENWINDOW_H
#define OPENWINDOW_H
#include <QDialog>
#include "mainwindow.h"
#include "adminmainwindow.h"
class UserRegistration;
class UserLogin;
namespace Ui {
class OpenWindow;
}
class OpenWindow : public QDialog
{
    Q_OBJECT

public:
    explicit OpenWindow(QWidget *parent = nullptr);
    ~OpenWindow();

private slots:
   void on_goBackRegistration();
   void on_goBack();
    void on_PBlogin_clicked();
    void on_PBregistration_clicked();
private:
    Ui::OpenWindow *ui;
    UserRegistration *registration;
    UserLogin *userLogin;
};

#endif // OPENWINDOW_H

