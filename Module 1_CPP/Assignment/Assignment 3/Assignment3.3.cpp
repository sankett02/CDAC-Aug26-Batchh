#include <iostream>
#include <cstring>

using namespace std;

class LogBuffer
{
private:
    char* buffer;
    int capacity;
    int size;

    static int instanceCount;

public:

    // Constructor
    LogBuffer(int capacity)
    {
        this->capacity = capacity;
        buffer = new char[capacity];
        size = 0;

        instanceCount++;

        cout << "[LogBuffer Created] capacity=" << capacity << endl;
    }

    // Copy Constructor - Deep Copy
    LogBuffer(const LogBuffer& other)
    {
        capacity = other.capacity;
        size = other.size;

        buffer = new char[capacity];

        memcpy(buffer, other.buffer, size);

        instanceCount++;

        cout << "[LogBuffer Deep Copied] capacity=" << capacity << endl;
    }

    // Copy Assignment Operator
    LogBuffer& operator=(const LogBuffer& other)
    {
        // Self-assignment check
        if (this == &other)
        {
            cout << "[Self-assignment detected - no operation]" << endl;
            return *this;
        }

        // Release old memory
        delete[] buffer;

        // Copy capacity and size
        capacity = other.capacity;
        size = other.size;

        // Allocate new memory
        buffer = new char[capacity];

        // Deep copy
        memcpy(buffer, other.buffer, size);

        cout << "[LogBuffer Assigned]" << endl;

        return *this;
    }

    // Destructor
    ~LogBuffer()
    {
        delete[] buffer;
        instanceCount--;

        cout << "[LogBuffer Destroyed]" << endl;
    }

    // Append message
    void append(const char* msg)
    {
        int msgLength = strlen(msg);

        // Determine how much can be copied
        int available = capacity - size;

        int copyLength;

        if (msgLength < available)
            copyLength = msgLength;
        else
            copyLength = available;

        memcpy(buffer + size, msg, copyLength);

        size += copyLength;
    }

    // Print current buffer
    void print() const
    {
        cout.write(buffer, size);
        cout << endl;
    }

    // Clear buffer
    void clear()
    {
        size = 0;
    }

    // Static getter
    static int getInstanceCount()
    {
        return instanceCount;
    }
};


// Initialize static member
int LogBuffer::instanceCount = 0;


int main()
{
    // Object 1: Basic usage
    LogBuffer log1(256);

    log1.append("Server started on port 8080");
    log1.append(" | Request received from 192.168.1.10");
    log1.print();


    // Object 2: Deep copy via copy constructor
    LogBuffer log2 = log1;

    log2.append(" | Cached response sent");

    cout << "log1: ";
    log1.print();

    cout << "log2: ";
    log2.print();


    // Object 3: Copy assignment
    LogBuffer log3(128);

    log3 = log1;

    log3.print();


    // Object 4: Self-assignment
    log1 = log1;

    log1.print();


    // Static member
    cout << "Live LogBuffer objects: "
         << LogBuffer::getInstanceCount()
         << endl;

    return 0;
}