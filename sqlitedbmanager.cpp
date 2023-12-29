#include "sqlitedbmanager.h"
#include <QObject>
#include <QSqlQuery>
#include <QSqlError>
#include <QFile>
#include <QDate>
#include <QDebug>
#include <QCryptographicHash>
#include <QSqlQueryModel>
#include <QMessageBox>

SQLiteDBManager* SQLiteDBManager::instance = nullptr;

SQLiteDBManager::SQLiteDBManager(){
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName(DATABASE_HOST_NAME);
    db.setDatabaseName(DATABASE_FILE_NAME);
}

SQLiteDBManager* SQLiteDBManager::getInstance() {
    if (instance == nullptr) {
        instance = new SQLiteDBManager();
        instance->connectToDataBase();
    }
    return instance;
}

void SQLiteDBManager::connectToDataBase() {
    if (QFile(DATABASE_FILE_NAME).exists()) {
        this->openDataBase();
    } else {
        this->restoreDataBase();
    }
}

QSqlDatabase SQLiteDBManager::getDB() {
    return db;
}

bool SQLiteDBManager::restoreDataBase() {
    if (this->openDataBase()) {
        if (!this->createTables()) {
            return false;
        } else {
            return true;
        }
    } else {
        qDebug() << "Не вдалось відновити базу даних";
        return false;
    }
}

bool SQLiteDBManager::openDataBase() {
    if (db.open()) {
        return true;
    } else
        return false;
}

void SQLiteDBManager::closeDataBase() {
    db.close();
}

bool SQLiteDBManager::createTables() {
    QSqlQuery query, queryCustomer, queryRoute;

    if (!query.exec("CREATE TABLE " TABLE_USER_REGISTRATION " ("
                    "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                    TABLE_USER_LOGIN " VARCHAR(255) NOT NULL, "
                    TABLE_USER_PASSWORD " VARCHAR(255) NOT NULL, "
                    "userType VARCHAR(20) NOT NULL, "
                    "question VARCHAR(20)"
                    " )"
                    )) {
        qDebug() << "DataBase: error of create " << TABLE_USER_REGISTRATION;
        qDebug() << query.lastError().text();
        return false;
    }
    if (!query.exec("CREATE TABLE "  TABLE_NAME_CUSTOMER  " ("
                    "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                    TABLE_CUSTOMER_LAST_NAME  " TEXT,"
                    TABLE_CUSTOMER_FIRST_NAME  " TEXT,"
                    TABLE_CUSTOMER_MIDDLE_NAME  " TEXT,"
                    TABLE_CUSTOMER_AGE  " INTEGER,"
                    TABLE_CUSTOMER_PHONE_NUMBER  " TEXT,"
                    TABLE_CUSTOMER_EMAIL  " TEXT,"
                    TABLE_CUSTOMER_ROUTE  " TEXT,"
                    TABLE_CUSTOMER_ROUTE_DETAILS  " TEXT,"
                    TABLE_CUSTOMER_INSTRUCTOR  " TEXT, "
                    TABLE_CUSTOMER_PRICE  " INTEGER"
                    " )"
                    )) {
        qDebug() << "DataBase: error of create " << TABLE_USER_REGISTRATION;
        qDebug() << query.lastError().text();
        return false;
    }
    if (!query.exec("CREATE TABLE " TABLE_NAME_ROUTE " ("
                    "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                    "routeType TEXT, "
                    "routeName TEXT UNIQUE, "
                    "complaxity TEXT, "
                    "distance REAL, "
                    "price REAL, "
                    "routeDetails TEXT)")) {
        qDebug() << "DataBase: error of create " << TABLE_NAME_ROUTE;
        qDebug() << query.lastError().text();
        return false;
    }

    if (!query.exec("CREATE TABLE " TABLE_NAME_INSTRUCTOR " ("
                    "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                    "firstName TEXT, "
                    "lastName TEXT, "
                    "middleName TEXT, "
                    "age INTEGER, "
                    "generalInformation TEXT, "
                    "price REAL) "
                    )) {
        qDebug() << "DataBase: error of create " << TABLE_NAME_INSTRUCTOR;
        qDebug() << query.lastError().text();
        return false;
    }

    return true;
}
bool SQLiteDBManager::inserIntoTable(const QString& login, const QString& password, const QString& userType, const QString& question) {
    QSqlQuery query;
    query.prepare("INSERT INTO " TABLE_USER_REGISTRATION "(" TABLE_USER_LOGIN ", "
                  TABLE_USER_PASSWORD ", userType, question) "
                  "VALUES (:login, :password, :userType, :question)");
    query.bindValue(":login", login);
    query.bindValue(":password", password);
    query.bindValue(":userType", userType);
    query.bindValue(":question", question);

    // Після чого виконується запит методом exec()
    if (!query.exec()) {
        qDebug() << "error insert into " << TABLE_USER_REGISTRATION;
        qDebug() << query.lastError().text();
        qDebug() << query.lastQuery();

        return false;
    } else
        return true;
}


bool SQLiteDBManager::loginCheck(const QString& login)
{
    QSqlQuery queryAccount;
    queryAccount.prepare("SELECT * FROM " TABLE_USER_REGISTRATION " WHERE " TABLE_USER_LOGIN " = :login");
    queryAccount.bindValue(":login", login);
    queryAccount.exec();
    if (!queryAccount.exec()) {
        qDebug() << "error insert into " << TABLE_USER_REGISTRATION;
        qDebug() << queryAccount.lastError().text();
        qDebug() << queryAccount.lastQuery();
    }
    int count=0;
    while(queryAccount.next())
    {
        count++;
    }
    if (count > 0) {
        return false;
    } else {
        return true;
    }

}
bool SQLiteDBManager::userLogin(const QString& login, const QString& password)
{
    QSqlQuery queryAccount;
    queryAccount.prepare("SELECT * FROM " TABLE_USER_REGISTRATION " WHERE " TABLE_USER_LOGIN " = :login AND "
                         TABLE_USER_PASSWORD "= :password");
    queryAccount.bindValue(":login", login);
    queryAccount.bindValue(":password", password);
    queryAccount.exec();
    if (!queryAccount.exec()) {
        qDebug() << "error insert into " << TABLE_USER_REGISTRATION;
        qDebug() << queryAccount.lastError().text();
        qDebug() << queryAccount.lastQuery();
    }
    if(queryAccount.next()) { return true;}
    else  {return false;}
}
bool SQLiteDBManager::userAdmin(const QString& login, const QString& password, const QString& userType, const QString& question){
    QSqlQuery queryAccount;
    queryAccount.prepare("SELECT * FROM " TABLE_USER_REGISTRATION " WHERE " TABLE_USER_LOGIN " = :login AND "
                         TABLE_USER_PASSWORD " = :password AND userType = :userType AND question = :question");
    queryAccount.bindValue(":login", login);
    queryAccount.bindValue(":password", password);
    queryAccount.bindValue(":userType", userType);
    queryAccount.bindValue(":question", question);
    queryAccount.exec();
    if (!queryAccount.exec()) {
        qDebug() << "error insert into " << TABLE_USER_REGISTRATION;
        qDebug() << queryAccount.lastError().text();
        qDebug() << queryAccount.lastQuery();
    }
    if(queryAccount.next()) { return true;}
    else  {return false;}}

bool SQLiteDBManager::insertIntoTableCustomer(const Customer& customer) {
    QSqlQuery query;
    query.prepare("INSERT INTO "  TABLE_NAME_CUSTOMER  " ("
                  TABLE_CUSTOMER_LAST_NAME  ", "  TABLE_CUSTOMER_FIRST_NAME  ", "
                  TABLE_CUSTOMER_MIDDLE_NAME  ", "  TABLE_CUSTOMER_AGE  ", "
                  TABLE_CUSTOMER_PHONE_NUMBER  ", "  TABLE_CUSTOMER_EMAIL  ", "
                  TABLE_CUSTOMER_ROUTE  ", " TABLE_CUSTOMER_ROUTE_DETAILS ", " TABLE_CUSTOMER_INSTRUCTOR ", "
                  TABLE_CUSTOMER_PRICE
                  ") VALUES (:last_name, :first_name, :middle_name, :age, :phone_number, "
                  ":email, :route, :route_details, :instructor, :price)");

    query.bindValue(":last_name", QString::fromStdString(customer.getLastName()));
    query.bindValue(":first_name", QString::fromStdString(customer.getFirstName()));
    query.bindValue(":middle_name", QString::fromStdString(customer.getMiddleName()));
    query.bindValue(":age", customer.getAge());
    query.bindValue(":phone_number",  QString::fromStdString(customer.getPhoneNumber()));
    query.bindValue(":email",  QString::fromStdString(customer.getEmail()));
    query.bindValue(":route",  QString::fromStdString(customer.getRoute()));
    query.bindValue(":route_details",  QString::fromStdString(customer.getRouteDetails()));
    query.bindValue(":instructor",  QString::fromStdString(customer.getInstructor()));
     query.bindValue(":price",  QString::fromStdString(customer.getPrice()));

    if (!query.exec()) {
        qDebug() << "Error inserting into " << TABLE_NAME_CUSTOMER;
        qDebug() << query.lastError().text();
        qDebug() << query.lastQuery();
        return false;
    } else {
        return true;
    }
}

bool SQLiteDBManager::insertIntoTableRoute(const Route& route) {
    QSqlQuery query;

    query.prepare("INSERT INTO " TABLE_NAME_ROUTE " ("
                  "routeType, "
                  "routeName, "
                  "complaxity, "
                  "distance, "
                  "price, "
                  "routeDetails) "
                  "VALUES (:routeType, :routeName, :complaxity, :distance, :price, :routeDetails)");

    query.bindValue(":routeType", QString::fromStdString(route.getRouteType()));
    query.bindValue(":routeName", QString::fromStdString(route.getRouteName()));
    query.bindValue(":complaxity", QString::fromStdString(route.getComplaxity()));
    query.bindValue(":distance", route.getDistance());
    query.bindValue(":price", route.getPrice());
    query.bindValue(":routeDetails", QString::fromStdString(route.getRouteDetails()));

    if (!query.exec()) {
        qDebug() << "Error inserting into " << TABLE_NAME_ROUTE;
        qDebug() << query.lastError().text();
        qDebug() << query.lastQuery();
        return false;
    } else {
        return true;
    }
}
bool SQLiteDBManager::insertIntoTableInstructor(const Instructor& instructor) {
    QSqlQuery query;
    query.prepare("INSERT INTO " TABLE_NAME_INSTRUCTOR " ("
                  "firstName, "
                  "lastName, "
                  "middleName, "
                  "age, "
                  "generalInformation, "
                  "price) "
                  "VALUES (:firstName, :lastName, :middleName, :age, :generalInformation, :price)");

    query.bindValue(":firstName", QString::fromStdString(instructor.getFirstName()));
    query.bindValue(":lastName", QString::fromStdString(instructor.getLastName()));
    query.bindValue(":middleName", QString::fromStdString(instructor.getMiddleName()));
    query.bindValue(":age", instructor.getAge());
    query.bindValue(":generalInformation", QString::fromStdString(instructor.getGeneralInformation()));
    query.bindValue(":price", instructor.getPrice());

    if (!query.exec()) {
        qDebug() << "Error inserting into " << TABLE_NAME_INSTRUCTOR;
        qDebug() << query.lastError().text();
        qDebug() << query.lastQuery();
        return false;
    }

    return true;
}
QSqlQueryModel* SQLiteDBManager::showRoute() {
    QSqlQueryModel *modal = new QSqlQueryModel();
    QSqlQuery query(db);
    query.prepare("SELECT * FROM route_information");
    if (query.exec()) {
        modal->setQuery(query);
    }
    return modal;
}
QSqlQueryModel* SQLiteDBManager::showInstructor() {
    QSqlQueryModel *modal = new QSqlQueryModel();
    QSqlQuery query(db);
    query.prepare("SELECT * FROM instructor_information");
    if (query.exec()) {
        modal->setQuery(query);
    }
    return modal;
}

double SQLiteDBManager::getInstructorPrice(const QString& instructorName) {
    QSqlQuery query;
    query.prepare("SELECT price FROM instructor_information WHERE firstName = :firstName");
    query.bindValue(":firstName", instructorName);

    if (query.exec() && query.next()) {
        return query.value(0).toDouble();
    }
    qDebug() << "Error fetching instructor price";
    qDebug()<<query.lastError();
    qDebug()<<query.lastQuery();
    return 0.0;
}


double SQLiteDBManager::getRoutePrice(const QString& routeName) {
    QSqlQuery query;
    query.prepare("SELECT price FROM route_information WHERE routeName = :routeName");
    query.bindValue(":routeName", routeName);

    if (query.exec() && query.next()) {
        return query.value(0).toDouble();
    }
    qDebug() << "Error fetching route price"<<query.lastError();
    qDebug()<<query.lastQuery();
    return 0.0;
}
bool SQLiteDBManager::deleteRoute(int id)
{
    QSqlQuery query;

    query.prepare("DELETE FROM route_information  WHERE id = :id");
    query.bindValue(":id", id);
    if (query.exec()) {
        return true;
    } else {
        qDebug() << "Error updating master: " << query.lastError().text();
        return false;
    }
}
bool SQLiteDBManager::deleteInstructor(int id)
{
    QSqlQuery query;

    query.prepare("DELETE FROM instructor_information  WHERE id = :id");
    query.bindValue(":id", id);
    if (query.exec()) {
        return true;
    } else {
        qDebug() << "Error updating master: " << query.lastError().text();
        return false;
    }
}
