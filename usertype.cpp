#include "usertype.h"
#include "sqlitedbmanager.h"
// UserType::UserType() {}

bool UserType::authenticateUser(const QString &login, const QString &password, UserType &type) {
    // Перевірка в базі даних або іншим способом
    bool nameExists = sqlDBM->loginCheck(login);

    if (!nameExists) {
        return false; // Користувача не існує
    }

    QString storedPasswordHash = sqlDBM->getStoredPasswordHash(login);
    QString enteredPasswordHash = hashPassword(password);

    if (storedPasswordHash == enteredPasswordHash) {
        type = sqlDBM->getUserType(login);
        currentUserType = type; // Оновлення ролі поточного користувача
        return true; // Успішна автентифікація
    }

    return false; // Невірний пароль
}
 UserType::getCurrentUserType() const {
    return currentUserType;
}

SQLiteDBManager* UserType::getSqlDBManager() const {
    return sqlDBM;
}

void UserType::setCurrentUserType(UserType type) {
    currentUserType = type;
}

QString UserType::getCurrentUserName() const {
    // Реалізуйте отримання ім'я користувача з бази даних або іншим способом
    return ""; // Замініть на вашу реалізацію
}

QString UserType::hashPassword(const QString &password) {
    QCryptographicHash hash(QCryptographicHash::Sha256);
    hash.addData(password.toUtf8());
    return hash.result().toHex();
}
