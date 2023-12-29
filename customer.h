#pragma once
#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "Person.h"
#include <string>
using namespace std;
class Customer : public Person
{
private:
    string phoneNumber;
    string email;
    string route;
    string routeDetails;
    string instructor;
    string price;

public:
    Customer();
    Customer(const string &firstName,
             const string &lastName,
             const string &middleName,
             int age,
             const string &phoneNumber,
             const string &email);
    string getPhoneNumber() const;
    string getEmail() const;
    string getRoute() const;
    string getRouteDetails() const;
    string getInstructor() const;
    string getPrice() const;
    void setPhoneNumber(const string &phoneNumber);
    void setEmail(const string &email);
    void setRoute(const string &route);
    void setRouteDetails(const string &routeDetails);
    void setInstructor(const string &instructor);
    void setPrice(const string &price);
};
#endif // CUSTOMER_H
