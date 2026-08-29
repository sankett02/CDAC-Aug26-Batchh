// #include <iostream>
// using namespace std;
// int main() {
// // int a = 10;
// // int *ptr = &a; // pointer variable ptr stores the address of a
// int a = 10;
// int b = 20;
// int *ptr = &a; // ptr points to a
// ptr = &b; // ptr now points to b
// cout << a << endl;
// cout << ptr << endl;
// cout << &a << endl;
// cout << &ptr << endl;
// cout << *ptr << endl;
// return 0;
// }

#include <iostream>
using namespace std;
void swap(int *a, int *b){
int temp = *a;
*a = *b;
*b = temp;
}
int main() {
int b = 10,a = 20;
cout << "Before swap: a = " << a << ", b = " << b << endl;
swap(&a, &b);
// passing addresses of a and b
cout << "After swap: a = " << a << ", b = " << b << endl;
return 0;
}
