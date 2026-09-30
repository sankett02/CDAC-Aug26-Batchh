#include <iostream>
#include <memory>

int main()
{
    std::shared_ptr<int> s =
        std::make_shared<int>(100);

    std::weak_ptr<int> w = s;

    std::cout << w.expired() << '\n';  // 0

    if (auto temp = w.lock())
    {
        std::cout << *temp << '\n';
    }

    s.reset();

    std::cout << w.expired() << '\n';  // 1

    if (auto temp = w.lock())
    {
        std::cout << *temp << '\n';
    }
    else
    {
        std::cout << "Object no longer exists\n";
    }
}