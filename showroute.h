#ifndef SHOWROUTE_H
#define SHOWROUTE_H

#include <QDialog>
#include "sqlitedbmanager.h"
#include "route.h"
#include <QSqlQueryModel>
namespace Ui {
class ShowRoute;
}

class ShowRoute : public QDialog
{
    Q_OBJECT

public:
    explicit ShowRoute(QWidget *parent = nullptr);
    ~ShowRoute();
    void newRoute();
    void showR();

private slots:
    void on_PBnext_clicked();
    void on_PBback_clicked();
signals:
    void goBackShowRoute();
private:
    Ui::ShowRoute *ui;
    DBManager *sqlDBM;


};

#endif // SHOWROUTE_H
