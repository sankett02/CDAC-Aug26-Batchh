#include <iostream>
#include <cmath>
using namespace std;

// 1. Compute RMS
double computeRMS(double* signal, int n)
{
    double sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += *(signal + i) * *(signal + i);
    }

    return sqrt(sum / n);
}

// 2. Normalise signal
void normalise(double* signal, int n)
{
    double maxAbs = 0;

    // Find maximum absolute value
    for (int i = 0; i < n; i++)
    {
        if (abs(*(signal + i)) > maxAbs)
        {
            maxAbs = abs(*(signal + i));
        }
    }

    // Avoid division by zero
    if (maxAbs != 0)
    {
        for (int i = 0; i < n; i++)
        {
            *(signal + i) = *(signal + i) / maxAbs;
        }
    }
}

// 3. Count zero crossings
int countZeroCrossings(double* signal, int n)
{
    if (n < 2)
        return 0;

    int count = 0;

    double* previous = signal;
    double* current = signal + 1;

    for (int i = 1; i < n; i++)
    {
        if ((*previous > 0 && *current < 0) ||
            (*previous < 0 && *current > 0))
        {
            count++;
        }

        previous++;
        current++;
    }

    return count;
}

// 4. Apply gain
void applyGain(double* signal, int n, double gainFactor)
{
    for (int i = 0; i < n; i++)
    {
        *(signal + i) = *(signal + i) * gainFactor;
    }
}

int main()
{
    double signal[] = {
        0.5, -1.2, 0.8, -0.3, 1.0, -0.9, 0.1
    };

    int n = 7;

    double rms = computeRMS(signal, n);

    cout << "RMS: " << rms << endl;

    normalise(signal, n);

    cout << "Normalised signal: ";

    for (int i = 0; i < n; i++)
    {
        cout << *(signal + i) << " ";
    }

    cout << endl;

    int crossings = countZeroCrossings(signal, n);

    cout << "Zero crossings: " << crossings << endl;

    applyGain(signal, n, 2.0);

    cout << "After gain: ";

    for (int i = 0; i < n; i++)
    {
        cout << *(signal + i) << " ";
    }

    cout << endl;

    return 0;
}