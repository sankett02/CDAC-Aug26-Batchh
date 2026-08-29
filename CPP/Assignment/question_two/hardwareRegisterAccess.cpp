#include <iostream>
using namespace std;

int main(){
    int statusReg = 0b10110001;
    int controlReg = 0b00000000;
    int dataReg = 0b11001010;

    const int* regPtr1 = &statusReg;

    cout<<"Status Register : "<<*regPtr1<<endl;

    // *regPtr1 = 10;
    // Error: regPtr1 is a pointer to const, so the value cannot be changed through the pointer.

    // regPtr1 = &dataReg;
    // This is allowed because regPtr1 itself is not const.
    // It can point to another address, but the value cannot be changed through it.

    int* const regPtr2 = &controlReg;

    *regPtr2 = 15;

    cout<<"Control Register : "<<*regPtr2<<endl;

    // regPtr2 = &dataReg;
    // Error: regPtr2 is a const pointer, so it cannot point to another address.

    const int* const regPtr3 = &statusReg;

    cout<<"ROM Config : "<<*regPtr3<<endl;

    // *regPtr3 = 20;
    // Error: regPtr3 points to const data, so the value cannot be changed.

    // regPtr3 = &dataReg;
    // Error: regPtr3 is a const pointer, so it cannot point to another address.

    return 0;
}