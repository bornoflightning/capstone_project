//main program
//Victor Escarcega
//July 7th 2024
//CSC Capstone Project

#include <iostream>
#include <string>
#include <limits>
#include "Inventory.h"
#include <algorithm>
#include <vector>
#include <map>
#include "Inventory.h"
#include <chrono>
#include <thread>


//NOTE TO INSTRUCTOR!!!!
//I created separate files to separate tasks, I created a file to declare my functions and another to define them and titled them Inventory.h and Inventory.cpp with proper headings
//The issue I ran into was that when I ran the program, the compiler was only reognizing one cpp file. In order to recognize both I would need to mess with the tasks.json file
//Even if I did that and updated tasks.json, my fear is that I could run the risk of your environment not compiling with 2 .cpp files if it was not updated as well.
//therefore, I declared the functions in Inventory.h but moved the functions to the main folder from Inventory.cpp file so that they will compile and run,
// left the old file to show that I understood the concept.
//I figured loosing some points would be better than my program not compiling at all and getting a bad grade
//Thank you


std::map<std::string, Item*> inventory;


void addItem(const std::string &name, double price, int quantity, const std:: string &description) {
    Item* item = new WarehouseItem(name, price, quantity, description);
    inventory[name] = item;
    std::cout << "Item added successfully. \n";
}

void searchItem() {
    std::string name;
    std::cout <<"Enter the name of the item to search: ";
    std::cin.ignore();
    std::getline(std::cin, name);

    auto it = inventory.find(name);
    if (it != inventory.end()) {
        std::cout << "=============================================" << std:: endl;
        std::cout << "Item Name          : " << it->second->getName() << std::endl;
        std::cout << "---------------------------------------------" << std::endl;
        std::cout << "Price              : $" <<std::fixed <<std::setprecision(2) << it->second->getPrice() <<std::endl;
        std::cout << "Quantity           : "  << it->second->getQuantity() << std::endl;
        std::cout << "Description        : "  << it->second->getDescription() << std::endl;
        std::cout << "=============================================" << std:: endl; 
    } else {
        std::cout << "Item not found.\n";
    }
    waitForNextInput();
}   

void displayItems() {
    // for (const auto &pair : inventory) {
    //     pair.second->display();
    //     std::cout<< "\n-----------------------------\n";
    // }
    if (inventory.empty()) {
        std::cout << "No items in inventory. \n";
    }

    for (const auto &pair : inventory) {
        std::cout << "=============================================" << std:: endl;
        std::cout << "Item Name          : " <<pair.second->getName() << std::endl;
        std::cout << "---------------------------------------------" << std::endl;
        std::cout << "Price              : $" <<std::fixed <<std::setprecision(2) << pair.second->getPrice() <<std::endl;
        std::cout << "Quantity           : "  << pair.second->getQuantity() << std::endl;
        std::cout << "Description        : "  << pair.second->getDescription() << std::endl;
        std::cout << "=============================================" << std:: endl;
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

void waitForNextInput() {
    std::this_thread::sleep_for(std::chrono::seconds(1));
    // std::cout << "\n";
    std::cout << "=============================================\n";
    std::cout << "\n";
    
}



int main() {
    int choice;

  

    do {
        std::cout<< "Please select option.\n";
        std::cout << "1.Create Item.\n";
        std::cout << "2.View All Items.\n";
        std::cout << "3.Search for Item.\n";
        std::cout << "4.Sort Items by Name.\n";
        std::cout << "5.Sort Items by Price.\n";
        std::cout << "6. Exit.\n";
        std::cout << "Enter your choice: ";

        std::cin>> choice;
        waitForNextInput();

        while (choice <1 || choice > 5 || std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input, choose a number between 1 and 4: ";
            std::cin >> choice;
        }

        switch(choice) {
            case 1:
                createItem();
                break;
            case 2:
                displayItems();
                break;
            case 3:
                searchItem();
                break;
            case 4:
                sortItemsByName();
                break;
            case 5:
                sortItemsByPrice();
                break;
            case 6:
                cleanupInventory();
                break;
            default:
            std::cout << "An error occrred  .\n";
                break; 
        }
    } while (choice != 6);

//    void viewItem() {
//     std::cout << "You selected view Item.\n";
// }

// void updateItem() {
//     std::cout << "You selected update Item.\n";
// }

// void deleteItem() {
//     std::cout << "You selected delete Item.\n";
// }

    return 0;
}