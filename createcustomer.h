#ifndef CREATECUSTOMER_H
#define CREATECUSTOMER_H
#include <QDialog>
#include "sqlitedbmanager.h"
#include "customer.h"
namespace Ui {
class CreateCustomer;
}
class CreateCustomer : public QDialog
{
    Q_OBJECT
public:
    explicit CreateCustomer(QWidget *parent = nullptr);
    ~CreateCustomer();
    void newCustomer();
private slots:
    void routeChanged(int index);
    void on_PBback_clicked();

signals:
    void goBackCustomer();

private:
    Ui::CreateCustomer *ui;
    DBManager *sqlDBM;
};
#endif // CREATECUSTOMER_H
