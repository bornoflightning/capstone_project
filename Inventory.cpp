#include "Inventory.h"
#include <iostream>
#include <algorithm>
#include <vector>

std::map<std::string, Item*> inventory;

void addItem(const std::string &name, double price, int quantity, const std:: string &description) {
    Item* item = new WarehouseItem(name, price, quantity, description);
    inventory[name] = item;
    std::cout << "Item added successfully. \n";
}

void displayItems() {
    for (const auto &pair : inventory) {
        pair.second->display();
        std::cout<< "\n-----------------------------\n";
    }
}

bool compareByName(Item* a, Item* b) {
    return a->getName() < b->getName();
}

bool compareByPrice(Item* a, Item* b) {
    return a->getPrice() < b->getPrice();
}