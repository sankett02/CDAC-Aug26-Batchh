#include <iostream>
#include <memory>

class Engine
{
public:
    void start()
    {
        std::cout << "Engine started\n";
    }
};

class Car
{
private:
    std::unique_ptr<Engine> engine;

public:
    Car()
        : engine(std::make_unique<Engine>())
    {
    }

    void startCar()
    {
        engine->start();
    }
};

int main()
{
    Car car;

    car.startCar();

    return 0;
}