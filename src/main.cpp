// main.cpp
#include "server.h"

int main() {
    Server server;

    MenuItem pizza("Pizza", 15.00);
    MenuItem salad("Salad", 12.50);
    MenuItem burger("Burger", 18.75);

    server.addMenuItem(pizza);
    server.addMenuItem(salad);
    server.addMenuItem(burger);

    // Adding items to the order
    server.addItemToOrder("Pizza", 2);
    server.addItemToOrder("Salad", 1);
    server.addItemToOrder("Burger", 3);

    server.processOrder();

    std::cout << "Order Total: $" << server.getOrderTotal() << std::endl;

    return 0;
}
