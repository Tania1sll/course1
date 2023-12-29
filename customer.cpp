#include "Customer.h"
#include <string>
using namespace std;

Customer::Customer() {}

Customer::Customer(const string& firstName,
                   const string& lastName,
                   const string& middleName,
                   int age,
                   const string& phoneNumber,
                   const string& email)
    : Person(firstName, lastName, middleName, age)  // Notice the change here
    , phoneNumber(phoneNumber)
    , email(email)
{}


string Customer::getPhoneNumber() const
{
    return phoneNumber;
}
string Customer::getEmail() const
{
    return email;
}
string Customer::getRoute() const
{
    return route;
}
string Customer::getRouteDetails() const
{
    return routeDetails;
}
string Customer::getInstructor() const
{
    return instructor;
}
string Customer::getPrice() const
{
    return price;
}
void Customer::setPhoneNumber(const string &phoneNumber)
{
    this->phoneNumber = phoneNumber;
}
void Customer::setEmail(const string &email)
{
    this->email = email;
}
void Customer::setRoute(const string &route)
{
    this->route = route;
}
void Customer::setRouteDetails(const string &routeDetails)
{
    this->routeDetails = routeDetails;
}
void Customer::setInstructor(const string &instructor)
{
    this->instructor = instructor;
}
void Customer::setPrice(const string &price)
{
    this->price = price;
}

