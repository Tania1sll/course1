#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QSqlQueryModel>
#include <QSqlDatabase>
#include <QString>
#include "customer.h"
#include "route.h"
#include "instructor.h"

class DBManager
{
public:
    virtual QSqlDatabase getDB() = 0;
    virtual bool inserIntoTable(const QString& login, const QString& password, const QString& userType, const QString& question) = 0;
    virtual bool userLogin(const QString& login, const QString& password)=0;
    virtual bool userAdmin(const QString& login, const QString& password, const QString& userType, const QString& question) = 0;
    virtual bool insertIntoTableCustomer(const Customer& customer) =0;
    virtual bool insertIntoTableRoute(const Route& route)=0;
    virtual bool insertIntoTableInstructor(const Instructor& instructor)=0;
    virtual QSqlQueryModel *showInstructor()=0;
    virtual QSqlQueryModel *showRoute()=0;
    virtual bool loginCheck(const QString& login) =0;
   virtual double getInstructorPrice(const QString& instructorName) =0;
   virtual double getRoutePrice(const QString& routeName) =0;
   virtual bool deleteRoute(int id) =0;
   virtual bool deleteInstructor(int id)=0;
};

#endif // DBMANAGER_H
