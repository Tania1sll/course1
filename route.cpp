#include "Route.h"
Route::Route() : Agency(), routeType(""), routeName(""), complaxity(""), distance(0.0) {}

// Route::Route(double initialPrice, const string& initialCode, const string& initialRouteType,
             // const string& initialRouteName, const string& initialComplaxity, double initialDistance)
    // : Agency(initialPrice, initial), routeType(initialRouteType), routeName(initialRouteName),
    // complaxity(initialComplaxity), distance(initialDistance) {}

string Route::getRouteType() const {
    return routeType;
}

void Route::setRouteType(const string& newRouteType) {
    routeType = newRouteType;
}

string Route::getRouteName() const {
    return routeName;
}

void Route::setRouteName(const string& newRouteName) {
    routeName = newRouteName;
}
string Route::getComplaxity() const {
    return complaxity;
}

void Route::setComplaxity(const string& newComplaxity) {
    complaxity = newComplaxity;
}
double Route::getDistance() const {
    return distance;
}
void Route::setDistance(double newDistance) {
    distance = newDistance;
}
string Route::getRouteDetails() const{
    return routeDetails;
}

void Route::setRouteDetails( const string& newRouteDetails){
    routeDetails = newRouteDetails;
}

