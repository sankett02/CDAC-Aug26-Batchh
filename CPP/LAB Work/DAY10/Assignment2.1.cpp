#include<iostream>
#include<string>
using namespace std;

class Product {
    private:
        int productId;
        string name;
        double price;
        int quantity;

    public:
        void acceptDetails(){
            cout<<"Enter the ProductID:"<<endl;
            cin>> productId;

            cout<<"Enter Name:";
            cin>> name;

            cout<<"Enter price:";
            cin>>price;

            cout<<"Enter the Quantity:";
            cin>>quantity;

        }    

        void display()const{
            cout<<productId<<"\t"
                << name<<"\t"
                << price <<"\t"
                << quantity<<"\t"
                << totalValue() <<endl;
        }

        double totalValue() const{
            return price * quantity;
        }

        bool isLowStock(int threshold) const{
            return quantity < threshold;
        }
};

int main(){

    //Array of 5 products objects on the stack
    Product products[5];

    //Accept details fpr all 5 products

    for (int i = 0; i<5; i++){
        cout << "\n Enter details for product"<< i+1<<endl;
        products[i].acceptDetails();

    }

    //Display Inventroy report 
    cout << "\n==========Inventory Report =========="<<endl;
    cout << "ID\tName\tPrice\tTotal Value "<< endl;

    for (int i  = 0; i<5; i++){
    products[i].display();
    }

    //Find Highest Value Product
    int highestIndex =0;

    for(int i =1; i<5;i++){
        if (products[i].totalValue()>products[highestIndex].totalValue()){
            highestIndex = i;
        }

    }

    cout <<"\nHighest Value Product:"
         <<products[highestIndex].totalValue()
         <<endl;
    
     //Low stock threshold 
     int threshold;
     
     cout <<"\nEnter Low Stock Threshodl:";
     cin >> threshold;

     cout <<"\nLow Stock Products:" << endl;

      for (int i = 0; i < 5; i++) {
        if (products[i].isLowStock(threshold)) {
            products[i].display();
            cout << " <-- LOW STOCK" << endl;
        }
    }

    return 0;

}