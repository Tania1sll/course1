#include "Person.h"
#include <string>
using namespace std;

Person::Person() : age(0) {}

Person::Person(const string &firstName, const string &lastName, const string &middleName, int age)
    : firstName(firstName), lastName(lastName), middleName(middleName), age(age) {}

string Person::getFirstName() const {
    return firstName;
}
string Person::getLastName() const {
    return lastName;
}
string Person::getMiddleName() const {
    return middleName;
}
int Person::getAge() const {
    return age;
}
void Person::setFirstName(const string& firstName) {
    this->firstName = firstName;
}
void Person::setLastName(const string& lastName) {
    this->lastName = lastName;
}
void Person::setMiddleName(const string& middleName) {
    this->middleName = middleName;
}
void Person::setAge(int age) {
    this->age = age;
}

