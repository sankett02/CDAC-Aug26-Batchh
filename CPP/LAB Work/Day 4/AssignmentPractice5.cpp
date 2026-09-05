#include <iostream>
using namespace std;

// Pass by value
void swapValue(int a, int b) {

    int temp = a;
    a = b;
    b = temp;
}

// Pass by reference
void swapReference(int &a, int &b) {

    int temp = a;
    a = b;
    b = temp;
}

// Pass by pointer
void swapPointer(int *a, int *b) {

    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {

    int a = 12;
    int b = 13;

    cout << "Before swap: "
         << a << " " << b << endl;

    swapValue(a, b);

    cout << "After swapValue: "
         << a << " " << b << endl;

    swapReference(a, b);

    cout << "After swapReference: "
         << a << " " << b << endl;

    swapPointer(&a, &b);

    cout << "After swapPointer: "
         << a << " " << b << endl;

    return 0;
}