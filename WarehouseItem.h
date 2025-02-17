
//WarehouseItem.h
#ifndef WAREHOUSEITEM_H
#define WAREHOUSEITEM_H

#include "Item.h"

#include <string>
#include <iostream>
#include <iomanip>

//create class and variables inside of class 
class WarehouseItem : public Item {
    //declare variables
private:
// attributes that provide a description of the item created
    std::string name;
    double price;
    int quantity;
    std::string description;

public:
//constructor
    WarehouseItem()= default;
//the constructor requires for user to provide the name, price quantity etc.
    WarehouseItem(const std::string& name, double price, int quantity, const std::string& description)
        : name(name), price(price), quantity(quantity), description(description) {}

//functions and getters the return the information stored in this object
    std::string getName() const {
        return name;
    }
//gets price from item
    double getPrice() const {
        return price;
    }

    int getQuantity() const {
        return quantity;
    }

//retrieves a short description of item
    std::string getDescription() const {
        return description;
    }

    void setPrice(double price) override {
        this->price = price;
    }

    void setQuantity(int quantity) override {
        this->quantity = quantity;
    }

    void setDescription(const std::string &description) override {
        this->description = description;
    }

    void display() const  {
        std::cout <<"Name: " << name
                    <<", Price: " <<std::fixed << std::setprecision(2) << price
                    <<", Quantity: " <<quantity
                    <<", Description: " <<description;
    }

    friend std::ostream& operator<<(std::ostream& os, const WarehouseItem& item) {
        os << "Name: " << item.name 
           << ", Price: " << std::fixed << std::setprecision(2) << item.price 
           << ", Quantity: " << item.quantity 
           << ", Description: " << item.description;
        return os;
    }
};

#endif // WAREHOUSEITEM_H
