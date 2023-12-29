#ifndef PERSON_H
#define PERSON_H
#include <string>
using namespace std;
class Person {
private:
    string firstName;
    string lastName;
    string middleName;
    int age;
public:
    Person();
    Person(const string& firstName, const string& lastName, const string& middleName, int age);
    string getFirstName() const;
    string getLastName() const;
    string getMiddleName() const;
    int getAge() const;
    void setFirstName(const string& firstName);
    void setLastName(const string& lastName);
    void setMiddleName(const string& middleName);
    void setAge(int age);
};

#endif // PERSON_H

