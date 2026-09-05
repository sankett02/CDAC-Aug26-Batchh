#include <iostream>
#include <iomanip>
using namespace std;

int main() {

    int N;
    double readings[100];

    int skipped = 0;
    int count = 0;

    double sum = 0;
    double min;
    double max;

    bool firstValid = true;

    // 1. Get number of readings
    cout << "Enter the number of readings: ";
    cin >> N;

    // 2. Read N temperature values
    for (int i = 0; i < N; i++) {
        cin >> readings[i];
    }

    // 3. Print valid readings
    cout << "Valid readings : ";

    for (int i = 0; i < N; i++) {

        if (readings[i] < 0) {
            skipped++;
            continue;
        }

        cout << readings[i] << " ";
    }

    cout << endl;

    // 4. Calculate min, max, sum and count
    for (int i = 0; i < N; i++) {

        // Skip sensor errors
        if (readings[i] < 0) {
            continue;
        }

        // Count valid readings
        count++;

        // Add current reading to sum
        sum += readings[i];

        // First valid reading initializes min and max
        if (firstValid) {
            min = readings[i];
            max = readings[i];
            firstValid = false;
        }
        else {

            // Update minimum
            if (readings[i] < min) {
                min = readings[i];
            }

            // Update maximum
            if (readings[i] > max) {
                max = readings[i];
            }
        }
    }

    // 5. Calculate average
    double average = 0;

    if (count > 0) {
        average = sum / count;
    }

    // 6. Find first reading >= 45
    for (int i = 0; i < N; i++) {

        if (readings[i] >= 45) {

            cout << "First CRITICAL : Index "
                 << i << " → "
                 << readings[i] << "°C" << endl;

            break;
        }
    }

    // 7. Print analysis
    cout << fixed << setprecision(2);

    cout << "Skipped (errors) : " << skipped << endl;

    if (count > 0) {
        cout << "Min : " << min
             << "°C Max : " << max
             << "°C Avg : " << average << "°C" << endl;
    }

    return 0;
}