#include<iostream>
#include<string>
using namespace std;

class class LedgerEntry{
    private:
    string description;
    double* amounts;
    int days;
    static int totalEntries;
}