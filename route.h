#ifndef ROUTE_H
#define ROUTE_H
#include <string>
#include "Agency.h"
using namespace std;
class Route : public Agency {
private:
    string routeType;
    string routeName;
    string complaxity;
    double distance;
    string routeDetails;

public:
    Route();
    Route(double initialPrice, const string& initialCode, const string& initialRouteType,
          const string& initialRouteName, const string& initialComplaxity, double initialDistance);
    string getRouteType() const;
    void setRouteType(const string& newRouteType);
    string getRouteName() const;
    void setRouteName(const string& newRouteName);
    string getComplaxity() const;
    void setComplaxity(const string& newComplaxity);
    double getDistance() const;
    void setDistance(double newDistance);
    string getRouteDetails() const;
    void setRouteDetails( const string& newRouteDetails);
};

#endif // ROUTE_H
