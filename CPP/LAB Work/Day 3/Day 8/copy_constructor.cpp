#include <iostream>

class Student
{
public:
    int age;

    Student(int a)
    {
        age = a;
    }

    Student(const Student& other)
    {
        age = other.age;
    }
};

int main()
{
    Student s1(20);

    Student s2 = s1;

    std::cout << s2.age;
}