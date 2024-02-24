#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Базовий клас "Товар"
class Item {
protected:
    string name;
    double price;
    int quantity;

public:
    Item(string name, double price, int quantity) : name(name), price(price), quantity(quantity) {}

    virtual double calculateCost() const {
        return price * quantity;
    }

    virtual void display() const {
        cout << "Name: " << name << ", Price: " << price << ", Quantity: " << quantity << endl;
    }

    virtual ~Item() {}
};

// Підклас "Продукти харчування"
class FoodItem : public Item {
public:
    FoodItem(string name, double price, int quantity) : Item(name, price, quantity) {}

    // Реалізація методу для підрахунку вартості з урахуванням знижки для продуктів харчування
    double calculateCost() const override {
        // Припустимо, що для продуктів харчування знижка - 5%
        return price * quantity * 0.95;
    }
};

// Підклас "Одяг"
class ClothingItem : public Item {
public:
    ClothingItem(string name, double price, int quantity) : Item(name, price, quantity) {}

    // Реалізація методу для підрахунку вартості з урахуванням знижки для одягу
    double calculateCost() const override {
        // Припустимо, що для одягу знижка - 10%
        return price * quantity * 0.9;
    }
};

// Підклас "Електроніка"
class ElectronicsItem : public Item {
public:
    ElectronicsItem(string name, double price, int quantity) : Item(name, price, quantity) {}

    // Реалізація методу для підрахунку вартості з урахуванням знижки для електроніки
    double calculateCost() const override {
        // Припустимо, що для електроніки знижка - 8%
        return price * quantity * 0.92;
    }
};

// Клас для управління магазином
class Store {
private:
    vector<Item*> inventory;

public:
    void addItem(Item* item) {
        inventory.push_back(item);
    }

    void removeItem(int index) {
        if (index >= 0 && index < inventory.size()) {
            delete inventory[index];
            inventory.erase(inventory.begin() + index);
        }
    }

    void displayInventory() const {
        for (const auto& item : inventory) {
            item->display();
        }
    }

    double calculateTotalCost() const {
        double totalCost = 0.0;
        for (const auto& item : inventory) {
            totalCost += item->calculateCost();
        }
        return totalCost;
    }

    ~Store() {
        for (const auto& item : inventory) {
            delete item;
        }
    }
};

int main() {
    Store store;

    // Додавання товарів до магазину
    store.addItem(new FoodItem("Apple", 1.5, 10));
    store.addItem(new ClothingItem("T-Shirt", 10.0, 5));
    store.addItem(new ElectronicsItem("Smartphone", 500.0, 3));

    // Виведення інвентаря магазину
    cout << "Store Inventory:" << endl;
    store.displayInventory();

    // Виведення загальної вартості товарів
    cout << "Total Cost: $" << store.calculateTotalCost() << endl;

    return 0;
}
