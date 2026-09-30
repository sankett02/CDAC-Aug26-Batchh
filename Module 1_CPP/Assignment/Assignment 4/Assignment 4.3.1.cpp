#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>
#include <iomanip>
#include <cctype>

using namespace std;

// ============================================================
// PART A: ABSTRACT DATA PROCESSOR
// ============================================================

class DataProcessor {
public:

    // Pure virtual functions
    virtual void loadData() = 0;
    virtual void processData() = 0;
    virtual void exportResult() = 0;

    virtual string processorType() const = 0;
    virtual int recordCount() const = 0;

    // Non-pure virtual function
    virtual void printSummary() const {
        cout << "Processor Type: "
             << processorType() << endl;

        cout << "Record Count: "
             << recordCount() << endl;
    }

    virtual ~DataProcessor() = default;
};


// ============================================================
// CSV PROCESSOR
// ============================================================

class CSVProcessor : public DataProcessor {
private:
    vector<string> data;

public:

    void loadData() override {

        data = {
            "apple",
            "banana",
            "orange",
            "mango",
            "grape"
        };

        cout << "CSV data loaded." << endl;
    }

    void processData() override {

        for (string& value : data) {

            for (char& c : value) {
                c = static_cast<char>(
                    toupper(static_cast<unsigned char>(c))
                );
            }
        }

        cout << "CSV data converted to uppercase."
             << endl;
    }

    void exportResult() override {

        cout << "CSV Export Result:" << endl;

        for (const string& value : data) {
            cout << value << endl;
        }
    }

    string processorType() const override {
        return "CSV Processor";
    }

    int recordCount() const override {
        return static_cast<int>(data.size());
    }

    void printSummary() const override {

        cout << "\nCSV Processor Summary" << endl;
        cout << "Records: "
             << recordCount() << endl;
    }
};


// ============================================================
// SENSOR STREAM PROCESSOR
// ============================================================

class SensorStreamProcessor : public DataProcessor {
private:
    vector<double> data;

    double meanValue = 0;
    double minValue = 0;
    double maxValue = 0;

public:

    void loadData() override {

        data = {
            23.5,
            25.1,
            22.8,
            26.4,
            24.7,
            27.2,
            21.9,
            25.6
        };

        cout << "Sensor data loaded." << endl;
    }

    void processData() override {

        if (data.empty()) {
            return;
        }

        double sum = 0;

        minValue = data[0];
        maxValue = data[0];

        for (double value : data) {

            sum += value;

            if (value < minValue) {
                minValue = value;
            }

            if (value > maxValue) {
                maxValue = value;
            }
        }

        meanValue = sum / data.size();

        cout << "Sensor statistics calculated."
             << endl;
    }

    void exportResult() override {

        cout << fixed << setprecision(2);

        cout << "Sensor Results:" << endl;
        cout << "Mean: " << meanValue << endl;
        cout << "Minimum: " << minValue << endl;
        cout << "Maximum: " << maxValue << endl;
    }

    string processorType() const override {
        return "Sensor Stream Processor";
    }

    int recordCount() const override {
        return static_cast<int>(data.size());
    }

    void printSummary() const override {

        cout << "\nSensor Stream Summary" << endl;

        cout << "Records: "
             << recordCount() << endl;

        cout << fixed << setprecision(2);

        cout << "Mean: "
             << meanValue << endl;

        cout << "Min: "
             << minValue << endl;

        cout << "Max: "
             << maxValue << endl;
    }
};


// ============================================================
// PART B: GENERIC CIRCULAR DATA BUFFER
// ============================================================

template <typename T>
class DataBuffer {

private:
    T* data;
    int capacity;
    int head;
    int tail;
    int count;

public:

    // Constructor
    DataBuffer(int cap)
        : capacity(cap),
          head(0),
          tail(0),
          count(0) {

        if (capacity <= 0) {
            throw invalid_argument(
                "Capacity must be greater than zero."
            );
        }

        data = new T[capacity];
    }

    // Destructor
    ~DataBuffer() {
        delete[] data;
    }

    // Prevent accidental shallow copies
    DataBuffer(const DataBuffer&) = delete;
    DataBuffer& operator=(const DataBuffer&) = delete;


    // --------------------------------------------------------
    // PUSH
    // --------------------------------------------------------

    void push(const T& value) {

        // If full, overwrite the oldest element
        if (isFull()) {

            data[tail] = value;

            tail = (tail + 1) % capacity;
            head = tail;

        }
        else {

            data[tail] = value;

            tail = (tail + 1) % capacity;

            count++;
        }
    }


    // --------------------------------------------------------
    // POP
    // --------------------------------------------------------

    T pop() {

        if (isEmpty()) {
            throw underflow_error(
                "Buffer is empty"
            );
        }

        T value = data[head];

        head = (head + 1) % capacity;

        count--;

        return value;
    }


    // --------------------------------------------------------
    // PEEK
    // --------------------------------------------------------

    const T& peek() const {

        if (isEmpty()) {
            throw underflow_error(
                "Buffer is empty"
            );
        }

        return data[head];
    }


    // --------------------------------------------------------
    // CHECK EMPTY
    // --------------------------------------------------------

    bool isEmpty() const {
        return count == 0;
    }


    // --------------------------------------------------------
    // CHECK FULL
    // --------------------------------------------------------

    bool isFull() const {
        return count == capacity;
    }


    // --------------------------------------------------------
    // SIZE
    // --------------------------------------------------------

    int size() const {
        return count;
    }


    // --------------------------------------------------------
    // STREAM OUTPUT
    // --------------------------------------------------------

    template <typename U>
    friend ostream& operator<<(
        ostream& os,
        const DataBuffer<U>& buffer
    );
};


// ============================================================
// DATA BUFFER OUTPUT OPERATOR
// ============================================================

template <typename T>
ostream& operator<<(
    ostream& os,
    const DataBuffer<T>& buffer
) {

    os << "[";

    for (int i = 0; i < buffer.count; i++) {

        int index =
            (buffer.head + i) % buffer.capacity;

        os << buffer.data[index];

        if (i < buffer.count - 1) {
            os << ", ";
        }
    }

    os << "]";

    return os;
}


// ============================================================
// MAIN
// ============================================================

int main() {

    // ========================================================
    // PART A DEMO
    // ========================================================

    cout << "========================================" << endl;
    cout << "       DATA PROCESSOR DEMO" << endl;
    cout << "========================================" << endl;

    vector<DataProcessor*> processors;

    processors.push_back(new CSVProcessor());
    processors.push_back(new SensorStreamProcessor());

    for (DataProcessor* processor : processors) {

        cout << "\n----------------------------------------"
             << endl;

        cout << "Type: "
             << processor->processorType()
             << endl;

        processor->loadData();
        processor->processData();
        processor->printSummary();
        processor->exportResult();
    }

    // Clean up
    for (DataProcessor* processor : processors) {
        delete processor;
    }

    processors.clear();


    // ========================================================
    // PART B: INTEGER BUFFER
    // ========================================================

    cout << "\n\n========================================" << endl;
    cout << "       INTEGER BUFFER" << endl;
    cout << "========================================" << endl;

    DataBuffer<int> intBuffer(3);

    intBuffer.push(10);
    intBuffer.push(20);
    intBuffer.push(30);

    cout << "Buffer: "
         << intBuffer << endl;

    cout << "Peek: "
         << intBuffer.peek() << endl;

    cout << "Pop: "
         << intBuffer.pop() << endl;

    cout << "Buffer after pop: "
         << intBuffer << endl;


    // Demonstrate overwrite
    intBuffer.push(40);
    intBuffer.push(50);

    cout << "After pushing 40 and 50: "
         << intBuffer << endl;


    // ========================================================
    // DOUBLE BUFFER
    // ========================================================

    cout << "\n\n========================================" << endl;
    cout << "       DOUBLE BUFFER" << endl;
    cout << "========================================" << endl;

    DataBuffer<double> doubleBuffer(3);

    doubleBuffer.push(10.5);
    doubleBuffer.push(20.75);
    doubleBuffer.push(30.25);

    cout << "Buffer: "
         << doubleBuffer << endl;

    cout << "Peek: "
         << doubleBuffer.peek() << endl;

    cout << "Pop: "
         << doubleBuffer.pop() << endl;

    cout << "Buffer after pop: "
         << doubleBuffer << endl;


    // ========================================================
    // STRING BUFFER
    // ========================================================

    cout << "\n\n========================================" << endl;
    cout << "       STRING BUFFER" << endl;
    cout << "========================================" << endl;

    DataBuffer<string> stringBuffer(3);

    stringBuffer.push("Apple");
    stringBuffer.push("Banana");
    stringBuffer.push("Orange");

    cout << "Buffer: "
         << stringBuffer << endl;

    cout << "Peek: "
         << stringBuffer.peek() << endl;

    cout << "Pop: "
         << stringBuffer.pop() << endl;

    cout << "Buffer after pop: "
         << stringBuffer << endl;


    // ========================================================
    // EXCEPTION DEMO
    // ========================================================

    cout << "\n\n========================================" << endl;
    cout << "       EXCEPTION DEMO" << endl;
    cout << "========================================" << endl;

    try {

        DataBuffer<int> emptyBuffer(3);

        cout << emptyBuffer.pop() << endl;

    }
    catch (const underflow_error& e) {

        cout << "Exception caught: "
             << e.what() << endl;
    }


    return 0;
}