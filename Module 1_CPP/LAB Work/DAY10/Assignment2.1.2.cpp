#include <iostream>
#include <string>
using namespace std;

class Patient {
private:
    int patientId;
    string name;
    int age;
    string ward;
    const string bloodGroup;

public:

    // Default constructor
    Patient()
        : patientId(0),
          name("Unknown"),
          age(0),
          ward("General"),
          bloodGroup("O+") {
    }

    // Emergency admission constructor
    Patient(int id, const string& patientName)
        : patientId(id),
          name(patientName),
          age(0),
          ward("Emergency"),
          bloodGroup("O+") {
    }

    // Full admission constructor
    Patient(int id,
            const string& patientName,
            int patientAge,
            const string& patientWard,
            const string& bg)
        : patientId(id),
          name(patientName),
          age(patientAge),
          ward(patientWard),
          bloodGroup(bg) {
    }

    // Display patient details
    void display() const {
        cout << "Patient ID  : " << patientId << endl;
        cout << "Name        : " << name << endl;
        cout << "Age         : " << age << endl;
        cout << "Ward        : " << ward << endl;
        cout << "Blood Group : " << bloodGroup << endl;
    }

    // Destructor
    ~Patient() {
        cout << "Patient " << patientId << " destroyed." << endl;
    }
};

int main() {

    cout << "===== Default Constructor =====" << endl;

    Patient p1;
    p1.display();

    cout << "\n===== Emergency Constructor =====" << endl;

    Patient p2(101, "Rahul");
    p2.display();

    cout << "\n===== Full Constructor =====" << endl;

    Patient p3(102, "Meera", 35, "Cardiology", "B+");
    p3.display();

    cout << "\n===== Dynamic Patient Array =====" << endl;

    Patient* patients = new Patient[3];

    patients[0] = Patient(201, "Amit", 25, "General", "A+");
    patients[1] = Patient(202, "Priya", 40, "Emergency", "O+");
    patients[2] = Patient(203, "John", 50, "Cardiology", "AB+");
    
    for (int i = 0; i < 3; i++) {
        cout << "\nPatient " << i + 1 << endl;
        patients[i].display();
    }

    // Release dynamically allocated array
    delete[] patients;

    return 0;
}