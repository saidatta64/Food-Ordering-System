const menuList = document.getElementById('menu-list');
const totalDisplay = document.getElementById('total');
const placeOrderButton = document.getElementById('place-order');

let menuItems = [];
let orderTotal = 0;

// Simulating data from backend
menuItems = [
    { name: "Pizza", price: 15.00 },
    { name: "Salad", price: 12.50 },
    { name: "Burger", price: 18.75 }
];

function renderMenu() {
    menuList.innerHTML = '';
    menuItems.forEach(item => {
        const menuItem = document.createElement('li');
        menuItem.className = 'menu-item';
        menuItem.textContent = `${item.name} ($${item.price.toFixed(2)})`;
        menuItem.addEventListener('click', () => addItem(item));
        menuList.appendChild(menuItem);
    });
}

function addItem(item) {
    const quantityInput = prompt(`How many ${item.name}s would you like?`);
    if (quantityInput !== null && !isNaN(quantityInput) && quantityInput > 0) {
        const quantity = parseInt(quantityInput);
        updateOrderSummary(item, quantity);
    }
}

function updateOrderSummary(item, quantity) {
    const subtotal = item.price * quantity;
    orderTotal += subtotal;
    totalDisplay.textContent = `$${orderTotal.toFixed(2)}`;
    
    const summaryItem = document.createElement('div');
    summaryItem.textContent = `${item.name}: ${quantity} x $${subtotal.toFixed(2)}`;
    document.body.appendChild(summaryItem);
}

renderMenu();

placeOrderButton.addEventListener('click', () => {
    alert(`Your order has been placed! Total: $${orderTotal.toFixed(2)}`);
});
