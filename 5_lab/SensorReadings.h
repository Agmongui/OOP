#ifndef SENSOR_READINGS_H
#define SENSOR_READINGS_H

#include <iostream>

template <typename T>
class SensorReadings 
{
private:
    T reading;

public:
    SensorReadings(T value) 
    {
        reading = value;
    }

    T getReading() const 
    {
        return reading;
    }

    void setReading(T value) 
    {
        reading = value;
    }
};

#endif