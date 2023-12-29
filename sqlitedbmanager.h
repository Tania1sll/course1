#ifndef SQLITEDBMANAGER_H
#define SQLITEDBMANAGER_H
#include "dbmanager.h"
#include <QSqlDatabase>
#include <QString>
#include "customer.h"
#include "route.h"
#include "instructor.h"
#include "createcustomer.h"
#include <QSqlQueryModel>
#include <QSqlQuery>
#define DATABASE_HOST_NAME   "ExampleDataBase"
#define DATABASE_FILE_NAME   "DataBase.sqlite"
#define TABLE_USER_REGISTRATION   "user_registration"
#define TABLE_USER_LOGIN           "login"
#define TABLE_USER_PASSWORD        "password"
#define TABLE_NAME_CUSTOMER         "customer_information"
#define TABLE_CUSTOMER_LAST_NAME           "last_name"
#define TABLE_CUSTOMER_FIRST_NAME          "first_name"
#define TABLE_CUSTOMER_MIDDLE_NAME         "middle_name"
#define TABLE_CUSTOMER_AGE                 "age"
#define TABLE_CUSTOMER_PHONE_NUMBER        "phone_number"
#define TABLE_CUSTOMER_EMAIL               "email"
#define TABLE_CUSTOMER_ROUTE               "route"
#define TABLE_CUSTOMER_ROUTE_DETAILS       "route_details"
#define TABLE_CUSTOMER_INSTRUCTOR          "instructor"
#define TABLE_CUSTOMER_PRICE               "price"
#define TABLE_NAME_ROUTE                  "route_information"
#define TABLE_NAME_INSTRUCTOR             "instructor_information"
class SQLiteDBManager : public DBManager
{
public:
    static SQLiteDBManager* getInstance();
    QSqlDatabase getDB() override;
    SQLiteDBManager();
    bool loginCheck(const QString& login) override;
    bool inserIntoTable(const QString& login, const QString& password, const QString& userType, const QString& question) override;
    bool userLogin(const QString& login, const QString& password) override;
    bool userAdmin(const QString& login, const QString& password, const QString& userType, const QString& question) override;
    bool openDataBase();
    bool restoreDataBase();
    void closeDataBase();
    bool createTables();
    bool insertIntoTableCustomer(const Customer& customer) override;
    bool insertIntoTableRoute(const Route& route) override;
    bool insertIntoTableInstructor(const Instructor& instructor) override;
    QSqlQueryModel *showInstructor() override;
    QSqlQueryModel *showRoute() override;
    double getInstructorPrice(const QString& instructorName) override;
    double getRoutePrice(const QString& routeName) override;
    bool deleteRoute(int id) override;
    bool deleteInstructor(int id) override;
private:
    QSqlDatabase db;
    static SQLiteDBManager* instance;
    void connectToDataBase();
};

#endif // SQLITEDBMANAGER_H
