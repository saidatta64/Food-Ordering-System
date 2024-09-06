// server.cpp
#include "server.h"

// Order class constructor
Order::Order() : total(0.0) {}

// Adds item to the order
void Order::addItem(const MenuItem& item, int quantity) {
    items[item.name] += quantity;
    total += item.price * quantity;
}

// Displays the order
void Order::display(const std::vector<MenuItem>& menu) const {
    std::cout << "Order Summary:" << std::endl;
    for (const auto& pair : items) {
        double itemPrice = 0.0;
        for (const auto& menuItem : menu) {
            if (menuItem.name == pair.first) {
                itemPrice = menuItem.price;
                break;
            }
        }
        std::cout << pair.first << ": " << pair.second << " x $" 
                  << itemPrice << " = $" << pair.second * itemPrice << std::endl;
    }
    std::cout << "Total: $" << total << std::endl;
}

// Adds a menu item
void Server::addMenuItem(const MenuItem& item) {
    menu.push_back(item);
}

// Adds item to the order by name
void Server::addItemToOrder(const std::string& itemName, int quantity) {
    for (const auto& menuItem : menu) {
        if (menuItem.name == itemName) {
            order.addItem(menuItem, quantity);
            return;
        }
    }
    std::cout << "Item " << itemName << " not found on the menu." << std::endl;
}

// Processes the order
void Server::processOrder() {
    std::cout << "Processing order..." << std::endl;
    order.display(menu);
}

// Gets the total order cost
double Server::getOrderTotal() const {
    return order.total;
}
