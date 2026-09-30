#include <iostream>
using namespace std;

int main() {
    double temperature[3][3];

    // Input
    cout << "Room1 Room2 Room3" << endl;

    for (int i = 0; i < 3; i++) {
        cout << "Floor " << i + 1 << " : ";

        for (int j = 0; j < 3; j++) {
            cin >> temperature[i][j];
        }
    }

    // Display table
    cout << "\nTemperature Table:" << endl;

    for (int i = 0; i < 3; i++) {
        cout << "Floor " << i + 1 << " : ";

        for (int j = 0; j < 3; j++) {
            cout << temperature[i][j] << " ";
        }

        cout << endl;
    }

    // Find hottest room
    double hottest = temperature[0][0];
    int hottestFloor = 0;
    int hottestRoom = 0;

    // Find highest floor average
    double highestAverage = 0;
    int highestFloor = 0;

    // Count rooms >= 30
    int warningCount = 0;

    for (int i = 0; i < 3; i++) {

        double floorSum = 0;

        for (int j = 0; j < 3; j++) {

            // Add temperature to floor sum
            floorSum += temperature[i][j];

            // Find hottest room
            if (temperature[i][j] > hottest) {
                hottest = temperature[i][j];
                hottestFloor = i;
                hottestRoom = j;
            }

            // Count rooms >= 30
            if (temperature[i][j] >= 30) {
                warningCount++;
            }
        }

        // Calculate this floor's average
        double floorAverage = floorSum / 3;

        // Check whether this is the highest floor average
        if (i == 0 || floorAverage > highestAverage) {
            highestAverage = floorAverage;
            highestFloor = i;
        }
    }

    // Output results
    cout << "\nHottest Room : Floor "
         << hottestFloor + 1
         << ", Room "
         << hottestRoom + 1
         << " -> "
         << hottest
         << " C" << endl;

    cout << "Hottest Floor : Floor "
         << highestFloor + 1
         << " -> Average = "
         << highestAverage
         << " C" << endl;

    cout << "Rooms >= 30 C : "
         << warningCount
         << endl;

    return 0;
}