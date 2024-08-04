//Inventory.cpp
#include "Inventory.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>

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

void sortItemsByName() {
    std::vector<Item*> items;
    for (const auto &pair : inventory) {
        items.push_back(pair.second);
    }
    std::sort(items.begin(), items.end(), compareByName);
    std::cout << "Items sorted by name: \n";
    for (Item* item : items) {
        item->display();
        std::cout << "\n------------------------------\n";
    }
}

void sortItemsByPrice() {
    std::vector<Item*> items;
    for (const auto &pair : inventory){
        items.push_back(pair.second);
    }
    std::sort(items.begin(), items.end(), compareByPrice);
    std::cout << "Items sorted by price:\n";
    for(Item* item : items) {
        item->display();
        std::cout << "\n--------------------------------\n";
    }
}


void createItem() {
    std::cout << "You selected add Item.\n";
    std::string name, description;
    double price;
    int quantity;

    //creating the name
    std::cout <<"Enter item name: ";
    std::cin.ignore();
    std::getline(std::cin, name);

    //creating the price
    // use a do while loop to ensure input is numeric and no negative numbers are provided
    do {
        std::cout << "Enter item price: ";
        std::cin >> price;
        if (std::cin.fail() || price <= 0) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a valid item price using numbers above 0.\n";
        }
    } while (std::cin.fail() || price <= 0);
    

    //creating the quantity
    //use a do while loop to ensure input is numeric. Zero is accepted as the quantity, just cannot be negative
    do {
        std::cout << "Enter item quantity";
        std::cin >> quantity;
        if (std::cin.fail() || quantity < 0) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a valid quantity using numbers. 0 is okay, just cannot be negative.\n";
        } 

  

    } while (std::cin.fail() || quantity <0);

    std::cout << "Enter item description: ";
    std::cin.ignore();
    std::getline(std::cin, description);

    

    addItem(name, price, quantity, description);

}

void cleanupInventory() {
    for (auto &pair : inventory) {
        delete pair.second;
    }
    inventory.clear();

}