#include <string>
#include <iostream>
#include <iomanip>

class WarehouseItem {
    //declare variables
private:
    std::string name;
    double price;
    int quantity;
    std::string description;

public:
//constructor
    WarehouseItem(const std::string& name, double price, int quantity, const std::string& description)
        : name(name), price(price), quantity(quantity), description(description) {}

//functions and getters the return the information stored in this object
    std::string getName() const {
        return name;
    }

    double getPrice() const {
        return price;
    }

    int getQuantity() const {
        return quantity;
    }

    std::string getDescription() const {
        return description;
    }

    friend std::ostream& operator<<(std::ostream& os, const WarehouseItem& item) {
        os << "Name: " << item.name 
           << ", Price: " << std::fixed << std::setprecision(2) << item.price 
           << ", Quantity: " << item.quantity 
           << ", Description: " << item.description;
        return os;
    }
};
