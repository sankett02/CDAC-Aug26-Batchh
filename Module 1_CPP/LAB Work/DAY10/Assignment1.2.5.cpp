#include <iostream>
#include <cmath>
using namespace std;

// 1. Calculate distance between two points
inline double distanceBetween(double x1, double y1,
                              double x2, double y2)
{
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

// 2. Convert degrees to radians
inline double toRadians(double degrees)
{
    return degrees * (M_PI / 180.0);
}

// 3. Restrict a value to a given range
inline double clamp(double value, double minVal, double maxVal)
{
    if (value < minVal)
        return minVal;
    else if (value > maxVal)
        return maxVal;
    else
        return value;
}

// 4. Check whether a point is inside the safe zone
inline bool isInSafeZone(double x, double y,
                         double cx, double cy, double radius)
{
    return distanceBetween(x, y, cx, cy) <= radius;
}

int main()
{
    // Home position
    double homeX = 0.0;
    double homeY = 0.0;

    // Safe-zone radius
    double radius = 50.0;

    // Test waypoints
    double x1 = 30.0;
    double y1 = 40.0;

    double x2 = 60.0;
    double y2 = 0.0;

    double x3 = -20.0;
    double y3 = -20.0;

    // Test distance
    cout << "Distance to waypoint 1: "
         << distanceBetween(homeX, homeY, x1, y1)
         << endl;

    // Test radians
    cout << "90 degrees in radians: "
         << toRadians(90.0)
         << endl;

    // Test clamp
    cout << "Clamp 75 to [0, 50]: "
         << clamp(75.0, 0.0, 50.0)
         << endl;

    // Test safe zones
    cout << "Waypoint 1 safe: "
         << (isInSafeZone(x1, y1, homeX, homeY, radius) ? "YES" : "NO")
         << endl;

    cout << "Waypoint 2 safe: "
         << (isInSafeZone(x2, y2, homeX, homeY, radius) ? "YES" : "NO")
         << endl;

    cout << "Waypoint 3 safe: "
         << (isInSafeZone(x3, y3, homeX, homeY, radius) ? "YES" : "NO")
         << endl;

    return 0;
}