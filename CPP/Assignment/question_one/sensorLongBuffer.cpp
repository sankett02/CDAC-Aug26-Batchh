#include <iostream>
using namespace std;

int inputEleOfArr(double arr[], int size){
    int countValid = 0;
    double temp;
    cout<<"Enter the elements of the array: "<<endl;
    int i = 0;
    while(i < size){
        cin>>temp;
        if(temp < 0){
            i++;
            continue;
        }
        arr[countValid] = temp;
        countValid++;
        i++;
    }
    return countValid;
}

void displayArr(double arr[], int size){
    cout<<"Valid readings   : ";
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int findEle(double arr[], int size){
    for(int i=0; i<size; i++){
        if(arr[i] >= 45){
            return i;
        }
    }
    return -1;
}

void findMinMaxAvg(double arr[], int size){
    double min = arr[0], max = arr[0], avg, sum = arr[0];
    for(int i=1; i<size; i++){
        if(arr[i] > max){
            max = arr[i];
        }
        if(arr[i] < min){
            min = arr[i];
        }
        sum += arr[i];
    }
    avg = sum/size;
    cout<<"Min : "<<min<<"C  Max : "<<max<<"C  Avg : "<<avg<<"C"<<endl<<endl;
}

void countCategories(double arr[], int size){
    int normal = 0;
    int warning = 0;
    int critical = 0;
    int shutdown = 0;

    for(int i = 0; i < size; i++){
        if(arr[i] >= 0 && arr[i] <= 29){
            normal++;
        }
        else if(arr[i] >= 30 && arr[i] <= 44){
            warning++;
        }
        else if(arr[i] >= 45 && arr[i] <= 59){
            critical++;
        }
        else if(arr[i] >= 60){
            shutdown++;
        }
    }

    cout <<"Normal:"<<normal<<"   ";
    cout <<"Warning:"<< warning<<"   ";
    cout <<"Critical:"<< critical<<"   ";
    cout <<"Shutdown:"<< shutdown<<"   "<<endl;
}

int main(){
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    if(n < 1 || n > 100){
        cout<<"Invalid size of array"<<endl;
        return 0;
    }
    double arr[n];
    int countValid = inputEleOfArr(arr, n);
    cout<<"Readings entered : "<<n<<endl;
    displayArr(arr, countValid);
    int skipped = n-countValid;
    cout<<"Skipped (errors) : "<<skipped<<endl<<endl;
    int indx = findEle(arr,countValid);
    if(indx == -1){
        return 0;
    }
    cout<<"First CRITICAL   : Index "<<indx<<" -> "<<arr[indx]<<"C"<<endl<<endl;
    findMinMaxAvg(arr, countValid);  
    countCategories(arr, countValid);  

    return 0;
}