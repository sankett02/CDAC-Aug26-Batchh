#include <iostream>
using namespace std;

double reorderCost(int qty, double unitPrice){
    return qty * unitPrice;
}
double reorderCost(double qty, double unitPrice){
    return qty * unitPrice;
}
double reorderCost(int qty, double unitPrice, double taxRate){
    double cost = qty*unitPrice;
    return cost + ((cost*taxRate) / 100);
}

double applyDiscount(double price, double discountPercent = 10.0){
    return price - ((price*discountPercent) / 100);
}

int main(){
    int qtyI;
    double price;
    double qtyB;
    double tax;
    double discount;

    cout<<"Enter qtyI: ";
    cin>>qtyI;
    cout<<"Enter price: ";
    cin>>price;
    cout<<"Enter qtyB: ";
    cin>>qtyB;
    cout<<"Enter tax rate: ";
    cin>>tax;
    cout<<"Enter discount: ";
    cin>>discount;

    cout<<"Reorder Cost (Integer Quantity): "<<reorderCost(qtyI, price)<<endl;

    cout<<"Reorder Cost (Fractional Quantity): "<<reorderCost(qtyB, price)<<endl;

    cout<<"Reorder Cost(With Tax): "<<reorderCost(qtyI, price, tax)<<endl;

    cout<<"Price after "<<discount<<"% Discount: "<<applyDiscount(price, discount)<<endl;

    cout<<"Price after "<<discount<<"% Discount: "<<applyDiscount(price, discount)<<endl;
    
    return 0;
}