#include<iostream>
using namespace std;

int main(){
	float principal, rate , time, si;
	cout<<"Enter Principal amount:";
	cin>> principal;
	cout<<"Enter rate of interest:";
	cin>>rate;

	cout<<" Enter time:";
	cin>> time;

	si = ( principal* rate*time)/100;
	cout<<"Simple interest="<<si;
	return 0;
}



