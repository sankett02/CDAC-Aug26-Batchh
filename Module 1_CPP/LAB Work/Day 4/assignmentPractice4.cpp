#include <iostream>
#include <cstdlib>
using namespace std;

int main(int argc, char* argv[]) {

    // Check if all required arguments are provided
    if (argc < 4) {
        cout << "Usage: ./sensor_monitor <warn_threshold> "
             << "<critical_threshold> <num_readings>" << endl;
        return 1;
    }

    // Convert command-line arguments from strings to integers
    int warnThreshold = atoi(argv[1]);
    int criticalThreshold = atoi(argv[2]);
    int numReadings = atoi(argv[3]);

    // Validate thresholds and number of readings
    if (warnThreshold >= criticalThreshold) {
        cout << "Invalid thresholds" << endl;
        return 1;
    }

    if (numReadings < 1 || numReadings > 500) {
        cout << "Invalid number of readings" << endl;
        return 1;
    }

    // Category counters
    int normalCount = 0;
    int warningCount = 0;
    int criticalCount = 0;

    // Generate and classify readings
    for (int i = 0; i < numReadings; i++) {

        int reading = rand() % 70;

        if (reading < warnThreshold) {
            normalCount++;
        }
        else if (reading < criticalThreshold) {
            warningCount++;
        }
        else {
            criticalCount++;
        }
    }

    // Display summary
    cout << "\nSensor Summary" << endl;
    cout << "Normal   : " << normalCount << endl;
    cout << "Warning  : " << warningCount << endl;
    cout << "Critical : " << criticalCount << endl;

    return 0;
}