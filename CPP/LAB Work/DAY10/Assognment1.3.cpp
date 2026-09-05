#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    int empId;
    string name;
    string department;
    char grade;
    double basicSalary;
    bool isActive;

    static int employeeCount;

public:

    // Constructor
    Employee() {
        empId = 1001 + employeeCount;
        employeeCount++;

        name = "Unknown";
        department = "Engineering";
        grade = 'D';
        basicSalary = 0;
        isActive = true;
    }

    // Setters
    void setName(string newName) {
        if (newName.empty()) {
            cout << "Invalid name!" << endl;
            return;
        }

        name = newName;
    }

    void setDepartment(string newDepartment) {
        if (newDepartment != "Engineering" &&
            newDepartment != "HR" &&
            newDepartment != "Finance" &&
            newDepartment != "Operations") {

            cout << "Invalid Department!" << endl;
            return;
        }

        department = newDepartment;
    }

    void setGrade(char newGrade) {
        if (newGrade != 'A' &&
            newGrade != 'B' &&
            newGrade != 'C' &&
            newGrade != 'D') {

            cout << "Invalid Grade!" << endl;
            return;
        }

        grade = newGrade;
    }

    void setBasicSalary(double salary) {
        if (salary <= 10000 || salary >= 5000000) {
            cout << "Invalid Salary!" << endl;
            return;
        }

        basicSalary = salary;
    }

    // Getters
    int getEmpId() const {
        return empId;
    }

    string getName() const {
        return name;
    }

    string getDepartment() const {
        return department;
    }

    char getGrade() const {
        return grade;
    }

    double getBasicSalary() const {
        return basicSalary;
    }

    bool getIsActive() const {
        return isActive;
    }

    // Deactivate employee
    void deactivate() {
        isActive = false;
    }

    // Static Employee Count
    static int getEmployeeCount() {
        return employeeCount;
    }

    // Calculate Allowance
    double computeAllowances() const {
        switch (grade) {
            case 'A':
                return basicSalary * 0.40;

            case 'B':
                return basicSalary * 0.30;

            case 'C':
                return basicSalary * 0.20;

            case 'D':
                return basicSalary * 0.10;

            default:
                return 0;
        }
    }

    // Calculate Gross Salary
    double computeGrossSalary() const {
        return basicSalary + computeAllowances();
    }

    // Calculate Tax
    double computeTax() const {
        double gross = computeGrossSalary();

        if (gross <= 50000) {
            return 0;
        }
        else if (gross <= 100000) {
            return (gross - 50000) * 0.10;
        }
        else {
            return 5000 + (gross - 100000) * 0.20;
        }
    }

    // Calculate Net Salary
    double computeNetSalary() const {
        return computeGrossSalary() - computeTax();
    }

    // Print Payslip
    void printPayslip() const {
        cout << "----------------------------" << endl;
        cout << "       EMPLOYEE PAYSLIP     " << endl;
        cout << "----------------------------" << endl;

        cout << "Employee ID   : " << empId << endl;
        cout << "Name          : " << name << endl;
        cout << "Department    : " << department << endl;
        cout << "Grade         : " << grade << endl;
        cout << "Basic Salary  : " << basicSalary << endl;
        cout << "Allowance     : " << computeAllowances() << endl;
        cout << "Gross Salary  : " << computeGrossSalary() << endl;
        cout << "Tax           : " << computeTax() << endl;
        cout << "Net Salary    : " << computeNetSalary() << endl;
        cout << "Status        : "
             << (isActive ? "Active" : "Inactive") << endl;

        cout << "----------------------------" << endl;
    }
};

// Definition of static member
int Employee::employeeCount = 0;


int main() {

    // Stack Object
    Employee e1;

    e1.setName("Alice");
    e1.setDepartment("Engineering");
    e1.setGrade('A');
    e1.setBasicSalary(50000);

    e1.printPayslip();

    cout << endl;


    // Heap Object
    Employee* e2 = new Employee();

    e2->setName("Bob");
    e2->setDepartment("Finance");
    e2->setGrade('C');
    e2->setBasicSalary(60000);

    e2->printPayslip();

    cout << endl;


    // Deactivate Employee
    e2->deactivate();

    cout << "After deactivation:" << endl;

    cout << "Employee 2 active: "
         << (e2->getIsActive() ? "Yes" : "No") << endl;

    cout << endl;


    cout << "Total employees: "
         << Employee::getEmployeeCount() << endl;


    // Release heap memory
    delete e2;

    return 0;
}