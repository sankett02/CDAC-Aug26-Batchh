#include <iostream>
using namespace std;

void inputArr(double arr[][3], int row, int col){
    cout<<"Enter the temperatures: "<<endl;

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cin>>arr[i][j];
        }
    }
}

void displayArr(double arr[][3], int row, int col){
    cout<<"        Room1   Room2   Room3"<<endl;

    for(int i=0; i<row; i++){
        cout<<"Floor "<<i+1<<" : ";

        for(int j=0; j<col; j++){
            cout<<arr[i][j]<<"    ";
        }

        cout<<endl;
    }
}

void findHottestRoom(double arr[][3], int row, int col){
    double max = arr[0][0];
    int floor = 0;
    int room = 0;

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(arr[i][j] > max){
                max = arr[i][j];
                floor = i;
                room = j;
            }
        }
    }

    cout<<"Hottest Room : Floor "<<floor+1<<", Room "<<room+1
        <<" -> "<<max<<"C"<<endl;
}

void findHottestFloor(double arr[][3], int row, int col){
    double maxAvg = 0;
    int hottestFloor = 0;

    for(int i=0; i<row; i++){
        double sum = 0;

        for(int j=0; j<col; j++){
            sum += arr[i][j];
        }

        double avg = sum/col;

        if(avg > maxAvg){
            maxAvg = avg;
            hottestFloor = i;
        }
    }

    cout<<"Hottest Floor : Floor "<<hottestFloor+1
        <<" (avg "<<maxAvg<<"C)"<<endl;
}

void countWarning(double arr[][3], int row, int col){
    int count = 0;

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(arr[i][j] >= 30){
                count++;
            }
        }
    }

    cout<<"Rooms at WARNING or above : "<<count<<endl;
}

int main(){
    double arr[3][3];
    inputArr(arr, 3, 3);
    cout<<endl;
    displayArr(arr, 3, 3);
    cout<<endl;
    findHottestRoom(arr, 3, 3);
    findHottestFloor(arr, 3, 3);
    countWarning(arr, 3, 3);
    
    return 0;
}