#include<iostream>
using namespace std;

int main(){
    double temperature;
        int status;
        double fahrenheit;
    cout<<"Enter temperature: ";
    cin>>temperature;
    if(temperature<0){   
        status=-1;
    }
    else if(temperature<30){
      
        status=0;
    }
    else if(temperature<45){
        status=1;
    }
    else if(temperature<60){
        status=2;
    }
    else{
        status=3;
        
    }

switch(status){
    case -1:
    cout<<"Status:SENSOR_ERROR"<<endl;
    cout<<"Action:Sensor fault — check wiring";
    break;
     case 0:
    cout<<"Status:NORMAL"<<endl;
    cout<<"Action:No action required";
    break;
     case 1:
    cout<<"Status:WARNING"<<endl;
    cout<<"Action:Alert sent to supervisor";
    break;
     case 2:
    cout<<"Status:CRITICAL"<<endl;
    cout<<"Action:Cooling system triggered";
    break;
     case 3:
    cout<<"Status:SHUTDOWN"<<endl;
    cout<<"Action:Emergency shutdown initiated";
    break;
 }


   cout << "Reading : "
     << (temperature > 25 ? "Above Average" : "Below Average")
     << endl;

    fahrenheit = (temperature * 9 / 5) + 32;
    cout << "Temperature : " << temperature << "°C / "
     << fahrenheit << "°F" << endl;
 
 return 0;

    
}