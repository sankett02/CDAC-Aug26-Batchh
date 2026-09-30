#include <iostream>
#include <memory>
class Array
{
private:
    int* data;
    int size;

public:

    // Constructor
    Array(int s)
    {
        size = s;
        data = new int[size];
    }

    // Copy Constructor
    Array(const Array& other)
    {
        size = other.size;

        data = new int[size];

        for (int i = 0; i < size; i++)
        {
            data[i] = other.data[i];
        }
    }

    // Copy Assignment
    Array& operator=(const Array& other)
    {
        if (this != &other)
        {
            delete[] data;

            size = other.size;
            data = new int[size];

            for (int i = 0; i < size; i++)
            {
                data[i] = other.data[i];
            }
        }

        return *this;
    }

    // Destructor
    ~Array()
    {
        delete[] data;
    }
};