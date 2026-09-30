#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    float principal, rate, time;
    float amount, ci;

    cout << "Enter principal amount: ";
    cin >> principal;

    cout << "Enter rate of interest: ";
    cin >> rate;

    cout << "Enter time: ";
    cin >> time;

    amount = principal * pow((1 + rate / 100), time);
    ci = amount - principal;

    cout << "Compound Interest = " << ci;

    return 0;
}
