#include <iostream>
#include "SensorReadings.h"

int main() 
{
    system("chcp 65001 > nul");
    SensorReadings<int> temperature(25);
    SensorReadings<double> humidity(65.5);
    SensorReadings<float> pressure(101.3f);

    std::cout << "Температура: "
              << temperature.getReading() << std::endl;

    std::cout << "Влажность: "
              << humidity.getReading() << std::endl;

    std::cout << "Давление: "
              << pressure.getReading() << std::endl;

    return 0;
}