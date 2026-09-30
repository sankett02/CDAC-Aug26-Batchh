#include <iostream>
using namespace std;
//int main(){
//	int a , b , temp;
//	cout<<" Enter two numbers:";
//	cin>> a >> b;
//	temp=a;
//	a = b;
//	b = temp;
//	 cout <<"After Swapping:"<< endl;
//	 cout <<"a =" << a<< endl;
//	 cout << "b =" << b << endl;
//	 return 0;
int main()
{
	  int a, b;

	   cout << "Enter two numbers: ";
	   cin >> a >> b;

	    a = a * b;
	    b = a / b;
	    a = a / b;

	   cout << "After swapping:" << endl;
	   cout << "a = " << a << endl;
	   cout << "b = " << b << endl;

	    return 0;
}



