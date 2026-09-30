#include <iostream>
using namespace std;

namespace Physics{
    double clamp(double val, double min, double max){
        if(val < min){
            return min;
        }
        else if(val > max){
            return max;
        }
        else{
            return val;
        }
    }

    double lerp(double a, double b, double t){
        return a + (b - a) * t;
    }
}

namespace GameMath{
    int clamp(int val, int min, int max){
        if(val < min){
            return min;
        }
        else if(val > max){
            return max;
        }
        else{
            return val;
        }
    }

    double lerp(double a, double b, double t){
        return a + (b - a) * t;
    }
}

int main(){
    double velocity;
    double startPosition;
    double endPosition;
    double time;
    int health;
    cout<<"Enter velocity: ";
    cin>>velocity;
    cout<<"Enter health: ";
    cin>>health;
    cout<<"Enter start position, end position and time: ";
    cin>>startPosition >> endPosition >> time;

    cout<<"\nPhysics Clamp: "<<Physics::clamp(velocity, 0.0, 100.0);

    cout<<"\nGameMath Clamp: "<<GameMath::clamp(health, 0, 100);

    cout<<"\nPhysics Lerp: "<<Physics::lerp(startPosition, endPosition, time);

    {
        using namespace GameMath;
        cout<<"\nGameMath Lerp using limited block scope: "<<lerp(startPosition, endPosition, time);
    }

    return 0;
}