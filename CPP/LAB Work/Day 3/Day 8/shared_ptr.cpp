#include <iostream>
#include <memory>

class Student
{
public:
    Student()
    {
        std::cout << "Student created\n";
    }

    ~Student()
    {
        std::cout << "Student destroyed\n";
    }
};

int main()
{
    std::shared_ptr<Student> s1 =
        std::make_shared<Student>();

    std::shared_ptr<Student> s2 = s1;

    std::cout << "Done\n";
}