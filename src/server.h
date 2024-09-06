// server.h
#ifndef SERVER_H
#define SERVER_H

#include <iostream>
#include <string>
#include <vector>
#include <map>

// MenuItem class definition
class MenuItem {
public:
    std::string name;
    double price;

    MenuItem(std::string n, double p) : name(n), price(p) {}
};

// Order class definition
class Order {
public:
    std::map<std::string, int> items;
    double total;

    Order();  // Constructor

    void addItem(const MenuItem& item, int quantity);
    void display(const std::vector<MenuItem>& menu) const;
};

// Server class definition
class Server {
private:
    std::vector<MenuItem> menu;
    Order order;

public:
    void addMenuItem(const MenuItem& item);
    void addItemToOrder(const std::string& itemName, int quantity);
    void processOrder();
    double getOrderTotal() const;
};

#endif  // SERVER_H
