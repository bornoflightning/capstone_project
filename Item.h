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
    virtual std::string getDescription() const = 0;
    virtual void display() cosnt = 0;
};

#endif