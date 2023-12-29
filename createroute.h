#ifndef CREATEROUTE_H
#define CREATEROUTE_H
#include <QDialog>
#include "sqlitedbmanager.h"
#include "route.h"
#include <QSqlQueryModel>
namespace Ui {
class CreateRoute;
}
class CreateRoute : public QDialog
{
    Q_OBJECT

public:
    explicit CreateRoute(QWidget *parent = nullptr);
    ~CreateRoute();
    void newRoute();
    void showR();
    void check();
private slots:
    void on_PBnext_clicked();
    void on_PBback_clicked();
    void on_PBdelete_clicked();

signals:
    void goBackRoute();

private:
    Ui::CreateRoute *ui;
    DBManager *sqlDBM;
};

#endif // CREATEROUTE_H
