#include <iostream>
using namespace std;

int findStatusCode(double temp){
    int statusCode;
    if(temp < 0){
        statusCode = -1;
    }
    else if(temp >= 0 && temp <= 29){
        statusCode = 0;
    }
    else if(temp >= 30 && temp <= 44){
        statusCode = 1;
    }
    else if(temp >= 45 && temp <= 59){
        statusCode = 2;
    }
    else{
        statusCode = 3;
    }

    return statusCode;
}

void findStatus(int statusCode){
    switch (statusCode){
        case -1:
            cout<<"Status      : SENSOR_ERROR "<<endl;
            cout<<"Action      : Sensor fault - check wiring"<<endl;
            break;
        case 0:
            cout<<"Status      : NORMAL"<<endl;
            cout<<"Action      : No action required"<<endl;
            break;
        case 1:
            cout<<"Status      : WARNING"<<endl;
            cout<<"Action      : Alert sent to supervisor"<<endl;
            break;
        case 2:
            cout<<"Status      : CRITICAL"<<endl;
            cout<<"Action      : Cooling system trigered"<<endl;
            break;
        default:
            cout<<"Status      : SHUTDOWN"<<endl;
            cout<<"Action      : Emergency shutdown initiated"<<endl;
    }
}

int main(){
    double tempC, tempF;
    cout<<"Enter the temperature: ";
    cin>>tempC;
    tempF = (tempC * 9/5) + 32;
    cout<<"Temperature : "<<tempC<<"C / "<<tempF<<"F"<<endl;
    int statusCode = findStatusCode(tempC);
    findStatus(statusCode);
    cout<<"Reading     : ";
    (tempC <= 25)? cout<<"Below Average"<<endl : cout<<"Above Average"<<endl; 
    
    return 0;
}
