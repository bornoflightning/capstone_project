#ifndef INVENTORY_H
#define INVENTORY_H

#include <string>
#include <map>
#include <iostream>
#include "Item.h"
#include "WarehouseItem.h"
#include "inventory.h"

extern std::map<std::string, Item*> inventory;


//CRUD functions

void addItem(const std::string &name, double price, int quantity, std::string &description);

void displayItems();

bool updateItem(const std::string &name, double price, int quantity, std::string &description);

bool deleteItem(const std:: string &name);

void sortItemsByName();

void cleanupInventory();


#endif


