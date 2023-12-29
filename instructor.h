#pragma once
#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H
#include "Person.h"
#include "agency.h"
#include <string>
using namespace std;
class Instructor : public Person, public Agency {
private:
    string generalInformation;

public:
    Instructor();
    Instructor(const string& firstName, const string& lastName, const string& middleName,
               int age, const string& generalInformation);
    string getGeneralInformation() const;
    void setGeneralInformation(const string& generalInformation);
};

#endif // INSTRUCTOR_H
