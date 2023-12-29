#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "createcustomer.h"
#include "showroute.h"
#include "showinstructor.h"
QT_BEGIN_NAMESPACE
class ShowInstructor;
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_PBcustomer_clicked();
    void on_PBrouter_clicked();
    void on_PBinstructor_clicked();
    void on_goBackCustomer();
    void on_goBackShowInstructor();
    void on_goBackShowRoute();
    void on_PBback_clicked();
private:
    Ui::MainWindow *ui;
    CreateCustomer *customers;
    ShowRoute *route;
    ShowInstructor *instructor;
};
#endif // MAINWINDOW_H
