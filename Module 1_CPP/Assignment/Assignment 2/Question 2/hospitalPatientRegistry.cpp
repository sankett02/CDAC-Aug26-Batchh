#include <iostream>
#include <string>
using namespace std;

class Patient{
    private:
        int patientId;
        string name;
        int age;
        string ward;
        const string bloodGroup;

    public:
        Patient():bloodGroup("O+"){
            patientId = 0;
            name = "Unknown";
            age = 0;
            ward = "General";
            cout<<"[Constructor] Default patient registered."<<endl;
        }
        Patient(int id, const string &name):bloodGroup("O+"){
            patientId = id;
            this->name = name;
            age = 0;
            ward = "General";
            cout<<"[Constructor] Emergency: "<<name<<endl;
        }
        Patient(int id, const string &name, int age, const string &ward, const string &bg):bloodGroup(bg){
            patientId = id;
            this->name = name;
            this->age = age;
            this->ward = ward;
            cout<<"[Constructor] Full admission: "<<name<<endl;
        }
        ~Patient(){
            cout<<"[Destructor] Patient "<<name<<" discharged."<<endl;
        }
        void displayRecord() const{
            cout<<"Patient Record:"<<endl;
            cout<<"  ID         : "<<patientId<<endl;
            cout<<"  Name       : "<<name<<endl;
            cout<<"  Age        : "<<age<<endl;
            cout<<"  Ward       : "<<ward<<endl;
            cout<<"  Blood Grp  : "<<bloodGroup<<endl;
        }
        void transferWard(const string& newWard){
            ward = newWard;
            cout<<"Ward Transfer: "<<name<<" -> "<<ward<<endl;
        }
        void inputRecord(){
            cout << "\nEnter Patient ID: ";
            cin >> patientId;

            cout << "Enter Name: ";
            cin.ignore();
            getline(cin, name);

            cout << "Enter Age: ";
            cin >> age;

            cout << "Enter Ward: ";
            cin.ignore();
            getline(cin, ward);
        }
};

int main(){
    Patient p1(1001, "Meera Joshi", 34, "Cardiology", "B+");
    Patient p2(1002, "Raj Patel");
    Patient p3;

    Patient *arr = new Patient[4];

    for(int i=0; i<4; i++){
        cout<<"\nEnter details for Patient "<<i + 1<<":";
        arr[i].inputRecord();
    }

    for(int i=0; i<4; i++){
        arr[i].displayRecord();
    }
    p2.transferWard("ICU");

    delete[] arr;
    return 0;
}