#ifndef INVENTORY_H
#define INVENTORY_H

#include <string>
#include <map>
#include <iostream>
#include "WarehouseItem.h" //include Warehouse item
#include "inventory.h"

std::map<std::string, WarehouseItem> inventory;


//function to add item to map
void addItem(const std::string &name, double price, int quantity, std::string &description);
//under construction

//function to display the items
void displayItems();
//under construction

//function to update items
bool updateITem(const std::string &name, double price, int quantity, std::string &description);
//under construction

// function to delete item
bool deleteItem(const std:: string &name);
//under construction


#endif


