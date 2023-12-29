#ifndef ADMINMAINWINDOW_H
#define ADMINMAINWINDOW_H

#include <QDialog>
#include "createinstructor.h"
#include "dbmanager.h"
#include "showinstructor.h"
#include "createroute.h"
#include "showroute.h"
class ShowRoute;
class CreateRoute;
class CreateInstructor;
class ShowInstructor;

namespace Ui {
class AdminMainWindow;
}

class AdminMainWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AdminMainWindow(QWidget *parent = nullptr);
    ~AdminMainWindow();

private slots:
    void on_PBaddInstructor_clicked();
    void on_PBaddRoute_clicked();
    void on_goBackInstructor();
    void on_goBackRoute();
    void on_PBback_clicked();
private:
    Ui::AdminMainWindow *ui;
    CreateInstructor *createInstructor;
    ShowInstructor *showInstructor;
    DBManager* instance;
    CreateRoute *createRoute;
    ShowRoute *showRoute;
};

#endif // ADMINMAINWINDOW_H
