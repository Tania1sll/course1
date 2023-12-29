#include "Agency.h"
Agency::Agency() : price(0.0), id(0.0) {}
Agency::Agency(int initialPrice, int initialId) : price(initialPrice), id(initialId) {}

int Agency::getPrice() const {
    return price;
}
void Agency::setPrice(int newPrice) {
    price = newPrice;
}
int Agency::getId() const {
    return id;
}
void Agency::setId(int newId) {
    id = newId;
}
