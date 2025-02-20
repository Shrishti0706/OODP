#include <iostream>

class Warehouse {
public:
    // Static variable to track total items across all warehouses
    static int totalItemsStored;
    
    Warehouse() : items(0) {}
    
    void addItem(int count) {
        if (count > 0) {
            items += count;
            totalItemsStored += count;
        }
    }
    
    void removeItem(int count) {
        if (count > 0 && count <= items) {
            items -= count;
            totalItemsStored -= count;
        } else {
            std::cout << "Invalid operation: Not enough items to remove." << std::endl;
        }
    }
    
    static int getTotalItemsStored() {
        return totalItemsStored;
    }

private:
    int items;
};

// Initialize static variable
int Warehouse::totalItemsStored = 0;

// Example Usage
int main() {
    Warehouse warehouse1, warehouse2;

    warehouse1.addItem(50);
    warehouse2.addItem(30);
    std::cout << Warehouse::getTotalItemsStored() << std::endl;  // Output: 80

    warehouse1.removeItem(10);
    std::cout << Warehouse::getTotalItemsStored() << std::endl;  // Output: 70
    
    return 0;
}
