#ifndef SHOWINSTRUCTOR_H
#define SHOWINSTRUCTOR_H

#include <QDialog>
#include "sqlitedbmanager.h"
#include "instructor.h"
#include <QSqlQueryModel>

namespace Ui {
class ShowInstructor;
}

class ShowInstructor : public QDialog
{
    Q_OBJECT

public:
    explicit ShowInstructor(QWidget *parent = nullptr);
    ~ShowInstructor();
    void newInstructor();
    void showI();
signals:
    void goBackShowInstructor();
private slots:
    void on_PBnext_clicked();

    void on_PBback_clicked();

private:
    Ui::ShowInstructor *ui;
    DBManager *sqlDBM;
};

#endif // SHOWINSTRUCTOR_H
