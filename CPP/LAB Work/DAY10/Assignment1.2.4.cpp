#include <iostream>
using namespace std;

bool parsePacket(const int* rawData, int size,
                 int** outMin, int** outMax)
{
    // Check for invalid/empty packet
    if (size <= 0)
    {
        return false;
    }

    // Start both pointers at the first element
    const int* min = rawData;
    const int* max = rawData;

    // Find minimum and maximum
    for (int i = 1; i < size; i++)
    {
        if (*(rawData + i) < *min)
        {
            min = rawData + i;
        }

        if (*(rawData + i) > *max)
        {
            max = rawData + i;
        }
    }

    // Give the addresses back to the caller
    *outMin = min;
    *outMax = max;

    return true;
}

int main()
{
    int packet[] = {-45, 12, 67, 8, 55, 31};
    int size = 6;

    int* minPtr = nullptr;
    int* maxPtr = nullptr;

    bool success = parsePacket(packet, size, &minPtr, &maxPtr);

    if (success)
    {
        cout << "Minimum: " << *minPtr << endl;
        cout << "Maximum: " << *maxPtr << endl;

        cout << "Minimum address: " << minPtr << endl;
        cout << "Maximum address: " << maxPtr << endl;
    }
    else
    {
        cout << "Invalid packet" << endl;
    }

    return 0;
}