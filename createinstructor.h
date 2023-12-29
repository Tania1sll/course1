#ifndef SHOWINSTRUCTOR_H
#define SHOWINSTRUCTOR_H
#include <QDialog>
#include "sqlitedbmanager.h"
#include "instructor.h"
#include <QSqlQueryModel>
 #include <QSortFilterProxyModel>
namespace Ui {
class CreateInstructor;
}

class CreateInstructor : public QDialog
{
    Q_OBJECT

public:
    explicit CreateInstructor(QWidget *parent = nullptr);
    ~CreateInstructor();
    void newInstructor();
    void showI();
    void checkI();
private slots:
    void on_PBnext_clicked();
    void on_PBback_clicked();
    void on_PBdeleteInstructor_clicked();

signals:
    void goBackInstructor();
private:
    Ui::CreateInstructor *ui;
    DBManager *sqlDBM;
};

#endif // SHOWINSTRUCTOR_H


