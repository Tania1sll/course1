#ifndef USERTYPE_H
#define USERTYPE_H

#include <QString>
#include <QCryptographicHash>
#include "sqlitedbmanager.h"
class SQLiteDBManager;

class UserType {
public:
    enum UserType {
        USER,
        ADMIN
    };
    UserType(SQLiteDBManager* dbManager);

    bool authenticateUser(const QString &login, const QString &password, UserType &type);
    UserType getCurrentUserType() const;
    SQLiteDBManager* getSqlDBManager() const;
    void setCurrentUserType(UserType type);
    QString getCurrentUserName() const;
private:
    QString hashPassword(const QString &password);

    SQLiteDBManager *sqlDBM;
    UserType currentUserType;
};
