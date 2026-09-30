#include <iostream>
#include <string>
using namespace std;

class Product {
private:
    int productId;
    string name;
    double price;
    int quantity;

public:
    void acceptDetails() {
        cout << "Enter ProductId: ";
        cin >> productId;

        cout << "Enter name: ";
        cin >> name;

        cout << "Enter price: ";
        cin >> price;

        cout << "Enter quantity: ";
        cin >> quantity;
    }

    void displayDetails() const {
        cout << productId << "  "
             << name << "  "
             << price << "  "
             << quantity << "  "
             << totalValue() << endl;
    }

    double totalValue() const {
        return price * quantity;
    }

    bool isLowStock(int threshold) const {
        return quantity < threshold;
    }

    string getName() const {
        return name;
    }
};

int main() {
    Product arr[5];

    for (int i = 0; i < 5; i++) {
        arr[i].acceptDetails();
    }

    int threshold;
    cout << "Enter the threshold: ";
    cin >> threshold;

    cout << "===== INVENTORY REPORT =====" << endl;
    cout << "ID    Name    Price    Qty    Total Value" << endl;

    for (int i = 0; i < 5; i++) {
        arr[i].displayDetails();
    }

    double highest = arr[0].totalValue();
    int index = 0;

    for (int i = 1; i < 5; i++) {
        if (arr[i].totalValue() > highest) {
            highest = arr[i].totalValue();
            index = i;
        }
    }

    cout << "Highest Value Product : "
         << arr[index].getName()
         << " (Rs. "
         << arr[index].totalValue()
         << ")" << endl;

    bool found = false;

    cout << "Low Stock (threshold: " << threshold << ") : ";

    for (int i = 0; i < 5; i++) {
        if (arr[i].isLowStock(threshold)) {

            if (found) {
                cout << ", ";
            }

            cout << arr[i].getName();
            found = true;
        }
    }

    if (!found) {
        cout << "None";
    }

    cout << endl;

    return 0;
}