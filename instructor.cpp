#include "Instructor.h"
#include <string>
using namespace std;

Instructor::Instructor() {}

Instructor::Instructor(const string& firstName, const string& lastName, const string& middleName,
                       int age, const string& generalInformation)
    : Person(firstName, lastName, middleName, age), generalInformation(generalInformation) {}

string Instructor::getGeneralInformation() const {
    return generalInformation;
}
void Instructor::setGeneralInformation(const string& generalInformation) {
    this->generalInformation = generalInformation;
}
