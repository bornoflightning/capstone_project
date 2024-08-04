//main program
//Victor Escarcega
//July 7th 2024
//CSC Capstone Project

#include <iostream>
#include <string>
#include <limits>
#include "Inventory.h"


int main() {
    int choice;

  

    do {
        std::cout<< "Please select option.\n";
        std::cout << "1.Create Item.\n";
        std::cout << "2.View Item.\n";
        std::cout << "3.Sort Items by Name.\n";
        std::cout << "4.Sort Items by Price.\n";
        std::cout << "5. Exit.\n";
        std::cout << "Enter your choice: ";

        std::cin>> choice;

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
                sortItemsByName();
                break;
            case 4:
                sortItemsByName();
                break;
            case 5:
                cleanupInventory();
                break;
            default:
            std::cout << "An error occrred  .\n";
                break; 
        }
    } while (choice != 5);

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