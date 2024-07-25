//main program
//Victor Escarcega
//July 7th 2024
//CSC Capstone Project

#include <iostream>
#include <string>

void createItem() {
    std::cout << "You selected add Item.\n";
}

void viewItem() {
    std::cout << "You selected view Item.\n";
}

void updateItem() {
    std::cout << "You selected update Item.\n";
}

void deleteItem() {
    std::cout << "You selected delete Item.\n";
}

int main() {
    int choice;

    std::cout<< "Please select option.\n";
    std::cout << "1.Create Item.\n";
    std::cout << "2.View Item.\n";
    std::cout << "3.Update Item.\n";
    std::cout << "4.Delete Item.\n";
    std::cout << "Enter your choice: ";

    std::cin>> choice

    while (choice <1 || choice > 4 || std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '.\n');
        std::cout << "Invalid input, choose a number between 1 and 4: ";
        std::cin >> choice;
    }

    switch(choice) {
        case 1:
        //functions to create item
        case 2:
        // function to view item
        case 3:
        // function to update item
        case 4:
        // function to delete item
        default:
        std::cout << "An error occrred  .\n";
        break
    }

    return 0;
}