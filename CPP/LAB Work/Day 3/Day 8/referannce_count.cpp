#include <iostream>
#include <memory>

int main()
{
    auto p1 = std::make_shared<int>(100);

    std::cout << p1.use_count() << '\n';

    auto p2 = p1;

    std::cout << p1.use_count() << '\n';

    auto p3 = p1;

    std::cout << p1.use_count() << '\n';
}