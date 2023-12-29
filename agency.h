#ifndef AGENCY_H
#define AGENCY_H
#include <string>
using namespace std;
class Agency {
private:
    int id;
    int price;

public:
    Agency();
    Agency(int initialPrice, int initialId);
    int getPrice() const;
    void setPrice(int newPrice);
    int getId() const;
    void setId(int newId);
};
#endif // AGENCY_H
