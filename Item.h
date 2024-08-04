//Item.h
#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <iostream>
#include <iomanip>

class Item {
public:
    virtual ~Item() = default;
    virtual std::string getName() const = 0;
    virtual double getPrice() const = 0;
    virtual int getQuantity() const = 0;
    virtual std::string getDescription() const = 0;
    virtual void setPrice(double price) = 0;
    virtual void setQuantity(int quantity) = 0;
    virtual void setDescription(const std::string &description) = 0;
    virtual void display() const = 0;
};

#endif //ITEM_H