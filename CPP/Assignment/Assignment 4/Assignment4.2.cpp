#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <typeinfo>

using namespace std;

// ============================================================
// BASE CLASS: Vehicle
// ============================================================

class Vehicle {
protected:
    string registrationNo;
    string ownerName;
    int yearOfManufacture;
    double kmDriven;

public:
    Vehicle(const string& reg, const string& owner,
            int year, double km)
        : registrationNo(reg),
          ownerName(owner),
          yearOfManufacture(year),
          kmDriven(km) {
        cout << "Vehicle constructor called for "
             << registrationNo << endl;
    }

    // Pure virtual functions
    virtual double fuelCost(double kmToTravel) const = 0;

    virtual void describe() const {
        cout << "Registration No: " << registrationNo << endl;
        cout << "Owner: " << ownerName << endl;
        cout << "Year: " << yearOfManufacture << endl;
        cout << "KM Driven: " << kmDriven << endl;
    }

    virtual string vehicleType() const = 0;

    // Virtual destructor
    virtual ~Vehicle() {
        cout << "Vehicle destructor called for "
             << registrationNo << endl;
    }

    double getKmDriven() const {
        return kmDriven;
    }

    string getRegNo() const {
        return registrationNo;
    }
};


// ============================================================
// CAR
// ============================================================

class Car : public Vehicle {
private:
    string fuelType;
    double mileageKmpl;

public:
    Car(const string& reg, const string& owner,
        int year, double km,
        const string& fuel, double mileage)
        : Vehicle(reg, owner, year, km),
          fuelType(fuel),
          mileageKmpl(mileage) {

        cout << "Car constructor called for "
             << registrationNo << endl;
    }

    double fuelCost(double kmToTravel) const override {
        double fuelPrice;

        if (fuelType == "Petrol") {
            fuelPrice = 106.0;
        }
        else {
            fuelPrice = 93.0;
        }

        double litres = kmToTravel / mileageKmpl;

        return litres * fuelPrice;
    }

    string vehicleType() const override {
        return "Car";
    }

    void describe() const override {
        Vehicle::describe();

        cout << "Fuel Type: " << fuelType << endl;
        cout << "Mileage: " << mileageKmpl << " km/l" << endl;
    }
};


// ============================================================
// TRUCK
// ============================================================

class Truck : public Vehicle {
protected:
    double payloadCapacityTons;
    double fuelEfficiencyKmpl;

public:
    Truck(const string& reg, const string& owner,
          int year, double km,
          double payload, double efficiency)
        : Vehicle(reg, owner, year, km),
          payloadCapacityTons(payload),
          fuelEfficiencyKmpl(efficiency) {

        cout << "Truck constructor called for "
             << registrationNo << endl;
    }

    double fuelCost(double kmToTravel) const override {
        // Efficiency drops by 5% for every ton of payload
        double efficiency =
            fuelEfficiencyKmpl *
            (1.0 - 0.05 * payloadCapacityTons);

        // Prevent invalid/zero efficiency
        if (efficiency <= 0) {
            return 0;
        }

        double litres = kmToTravel / efficiency;

        // Diesel price
        return litres * 93.0;
    }

    string vehicleType() const override {
        return "Truck";
    }

    void describe() const override {
        Vehicle::describe();

        cout << "Payload Capacity: "
             << payloadCapacityTons << " tons" << endl;

        cout << "Fuel Efficiency: "
             << fuelEfficiencyKmpl << " km/l" << endl;
    }

    virtual ~Truck() {
        cout << "Truck destructor called for "
             << registrationNo << endl;
    }
};


// ============================================================
// ELECTRIC TRUCK
// ============================================================

class ElectricTruck : public Truck {
private:
    double batteryCapacityKWh;
    double rangePerChargeKm;

public:
    ElectricTruck(const string& reg, const string& owner,
                  int year, double km,
                  double payload, double efficiency,
                  double battery, double range)
        : Truck(reg, owner, year, km, payload, efficiency),
          batteryCapacityKWh(battery),
          rangePerChargeKm(range) {

        cout << "ElectricTruck constructor called for "
             << registrationNo << endl;
    }

    double fuelCost(double kmToTravel) const override {
        double charges = kmToTravel / rangePerChargeKm;

        // Electricity cost = energy used × Rs. 9.50
        double energyUsed = charges * batteryCapacityKWh;

        return energyUsed * 9.50;
    }

    string vehicleType() const override {
        return "Electric Truck";
    }

    void describe() const override {
        Vehicle::describe();

        cout << "Payload Capacity: "
             << payloadCapacityTons << " tons" << endl;

        cout << "Battery Capacity: "
             << batteryCapacityKWh << " kWh" << endl;

        cout << "Range Per Charge: "
             << rangePerChargeKm << " km" << endl;
    }

    ~ElectricTruck() {
        cout << "ElectricTruck destructor called for "
             << registrationNo << endl;
    }
};


// ============================================================
// VAN
// ============================================================

class Van : public Vehicle {
private:
    int seatingCapacity;
    double mileageKmpl;

public:
    Van(const string& reg, const string& owner,
        int year, double km,
        int seats, double mileage)
        : Vehicle(reg, owner, year, km),
          seatingCapacity(seats),
          mileageKmpl(mileage) {

        cout << "Van constructor called for "
             << registrationNo << endl;
    }

    double fuelCost(double kmToTravel) const override {
        double litres = kmToTravel / mileageKmpl;

        // Petrol price
        return litres * 106.0;
    }

    string vehicleType() const override {
        return "Van";
    }

    void describe() const override {
        Vehicle::describe();

        cout << "Seating Capacity: "
             << seatingCapacity << endl;

        cout << "Mileage: "
             << mileageKmpl << " km/l" << endl;
    }

    ~Van() {
        cout << "Van destructor called for "
             << registrationNo << endl;
    }
};


// ============================================================
// FLEET REPORT
// ============================================================

void printFleetReport(const vector<Vehicle*>& fleet,
                      double tripKm) {

    cout << "\n";
    cout << "============================================================\n";
    cout << "                    VEHICLE FLEET REPORT\n";
    cout << "============================================================\n";

    cout << left
         << setw(15) << "Registration"
         << setw(20) << "Type"
         << setw(20) << "Owner"
         << setw(15) << "KM Driven"
         << setw(15) << "Trip Cost"
         << endl;

    cout << "------------------------------------------------------------\n";

    double lowestCost = 0;
    Vehicle* mostEfficient = nullptr;

    for (Vehicle* vehicle : fleet) {

        double cost = vehicle->fuelCost(tripKm);

        cout << left
             << setw(15) << vehicle->getRegNo()
             << setw(20) << vehicle->vehicleType()
             << setw(20) << "N/A"
             << setw(15) << fixed << setprecision(2)
             << vehicle->getKmDriven()
             << setw(15) << cost
             << endl;

        // Find most efficient vehicle
        if (mostEfficient == nullptr ||
            cost < lowestCost) {

            lowestCost = cost;
            mostEfficient = vehicle;
        }

        // Check whether vehicle is an ElectricTruck
        ElectricTruck* electricTruck =
            dynamic_cast<ElectricTruck*>(vehicle);

        if (electricTruck != nullptr) {
            cout << "  -> Electric Truck detected: "
                 << vehicle->getRegNo() << endl;

            cout << "     Battery/range information available."
                 << endl;
        }
    }

    cout << "------------------------------------------------------------\n";

    if (mostEfficient != nullptr) {
        cout << "Most Efficient Vehicle: "
             << mostEfficient->getRegNo()
             << " (" << mostEfficient->vehicleType()
             << ")" << endl;

        cout << "Lowest Trip Cost: Rs. "
             << fixed << setprecision(2)
             << lowestCost << endl;
    }

    cout << "============================================================\n";
}


// ============================================================
// MAIN
// ============================================================

int main() {

    cout << "========== CONSTRUCTOR / DESTRUCTOR DEMO ==========\n\n";

    {
        cout << "Creating ElectricTruck on stack...\n\n";

        ElectricTruck electricTruck(
            "ET-101",
            "Ali",
            2024,
            15000,
            5.0,
            8.0,
            500.0,
            400.0
        );

        cout << "\nElectricTruck created successfully.\n";
    }

    cout << "\nStack object destroyed.\n";

    // ========================================================
    // POLYMORPHIC FLEET
    // ========================================================

    cout << "\n\n========== POLYMORPHIC FLEET ==========\n";

    vector<Vehicle*> fleet;

    fleet.push_back(
        new Car(
            "CAR-101",
            "Ahmed",
            2022,
            25000,
            "Petrol",
            15.0
        )
    );

    fleet.push_back(
        new Car(
            "CAR-102",
            "Sara",
            2021,
            32000,
            "Diesel",
            18.0
        )
    );

    fleet.push_back(
        new Truck(
            "TRK-101",
            "Usman",
            2020,
            70000,
            4.0,
            7.0
        )
    );

    fleet.push_back(
        new ElectricTruck(
            "ET-101",
            "Ali",
            2024,
            15000,
            5.0,
            8.0,
            500.0,
            400.0
        )
    );

    fleet.push_back(
        new Van(
            "VAN-101",
            "Fatima",
            2023,
            18000,
            8,
            12.0
        )
    );

    // ========================================================
    // DESCRIBE EACH VEHICLE
    // ========================================================

    cout << "\n\n========== VEHICLE DESCRIPTIONS ==========\n";

    for (Vehicle* vehicle : fleet) {

        cout << "\n------------------------------\n";

        vehicle->describe();

        cout << "Vehicle Type: "
             << vehicle->vehicleType()
             << endl;
    }

    // ========================================================
    // FLEET REPORT
    // ========================================================

    double tripKm = 500.0;

    printFleetReport(fleet, tripKm);

    // ========================================================
    // DELETE ALL HEAP OBJECTS
    // ========================================================

    cout << "\n\n========== CLEANING FLEET ==========\n";

    for (Vehicle* vehicle : fleet) {
        delete vehicle;
    }

    fleet.clear();

    cout << "\nAll vehicles deleted successfully.\n";

    return 0;
}