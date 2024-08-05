# Warehouse Management Project

This is a warehouse management project for my computer science class. It allows you to keep track of inventory for different items to ensure that a retail store and/or warehouse stays well organized.

## Table of Contents
- [Introduction](#introduction)
- [Features](#features)
- [Getting Started](#getting-started)
- [Usage](#usage)
- [License](#license)
- [Project details](#requirements-checklist)

## Introduction
The Warehouse Management Project helps in managing inventory for a retail store or warehouse. It provides functionality to add, remove, and retrieve items, ensuring the inventory stays well organized.

## Features
- Add items to the warehouse.
- Remove items from the warehouse.
- Retrieve information about specific items.
- Display all items in the warehouse.

## Getting Started

### Prerequisites
- C++ Compiler (e.g., GCC, Clang, MSVC)

# Capstone Project: Inventory Management System

## Author
Victor Escarcega

## Date
July 7th, 2024

## Project Description
This capstone project is an Inventory Management System developed in C++. The system allows users to create, view, update, and delete items in a warehouse. The project demonstrates key concepts such as abstract classes, inheritance, polymorphism, sorting, and the use of data structures.

## Requirements Checklist

- **Abstract Classes:**
  - Implemented `Item` class as an abstract class with pure virtual functions.
- **Inheritance:**
  - `WarehouseItem` class inherits from the abstract `Item` class.
- **Polymorphism:**
  - Virtual functions in the `Item` class are overridden in the `WarehouseItem` class.
- **Sorting:**
  - Implemented functions to sort items by name and by price.
- **Data Structures:**
  - Utilized `std::map` to store and manage inventory items.
- **Recursion:**
  - Not explicitly required for this project.

## Project Structure

The project is organized into the following files:

1. **Header Files:**
   - `Item.h`: Defines the abstract `Item` class.
   - `WarehouseItem.h`: Defines the `WarehouseItem` class inheriting from `Item`.
   - `Inventory.h`: Declares functions for managing inventory.

2. **Source Files:**
   - `main.cpp`: Contains the main program logic.
   - `Inventory.cpp`: Implements the functions declared in `Inventory.h`.

## Compilation Instructions

To compile the project, navigate to the project directory and run the following command:

```sh
g++ main.cpp Inventory.cpp -o capstone_project


