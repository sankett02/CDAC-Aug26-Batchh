#include<iostream>
using namespace std;

int main(){
    int statusReg  = 0b10110001;
    int controlReg = 0;
    const int romConfig = 1234;

    //status:Read only through pointers
    const int* regPtr1 = &statusReg;

    cout<<"status: "<< *regPtr1 <<endl;
     // *regPtr1 = 10;       // ERROR: cannot modify


    //Control:write only through pointers
    int* const regPtr2 = &controlReg;
     *regPtr2 = 42;
    cout<<"control:" <<*regPtr2 <<endl;
     // regPtr2 = &statusReg; // ERROR: pointer is const

    //ROM Config:
    const int* const regPtr3 = &romConfig;
    cout << "ROM Config: " << *regPtr3 << endl;

        // *regPtr3 = 99;       // ERROR
    // regPtr3 = &controlReg; // ERROR




}