
#include "Polygon.h"
#include <iostream>
#include <stdexcept>
#include <cmath>

using namespace std;

static double calculateArea(int sides, double* coordinates)
{
    double result = 0;

    for (int i = 0; i < sides; i++)
    {
        int next = (i + 1) % sides;

        result += coordinates[i * 2] * coordinates[next * 2 + 1]
                - coordinates[next * 2] * coordinates[i * 2 + 1];
    }

    return fabs(result) / 2;
}

Polygon::Polygon(int sides, double* coordinates)
{
    if (sides < 3 || coordinates == nullptr)
    {
        delete[] coordinates;
        throw invalid_argument("Некорректные данные многоугольника");
    }

    this->sides = sides;
    this->coordinates = new double[sides * 2];

    for (int i = 0; i < sides * 2; i++)
    {
        this->coordinates[i] = coordinates[i];
    }

    delete[] coordinates;

    figureCount++;
    totalArea += calculateArea(sides, this->coordinates);
}

Polygon::Polygon(const Polygon& other)
{
    sides = other.sides;

    coordinates = new double[sides * 2];

    for (int i = 0; i < sides * 2; i++)
    {
        coordinates[i] = other.coordinates[i];
    }

    figureCount++;
    totalArea += calculateArea(sides, coordinates);
}

Polygon& Polygon::operator=(const Polygon& other)
{
    if (this == &other)
    {
        return *this;
    }

    double* newCoordinates = new double[other.sides * 2];

    for (int i = 0; i < other.sides * 2; i++)
    {
        newCoordinates[i] = other.coordinates[i];
    }

    totalArea -= calculateArea(sides, coordinates);

    delete[] coordinates;

    sides = other.sides;
    coordinates = newCoordinates;

    totalArea += calculateArea(sides, coordinates);

    return *this;
}

Polygon::~Polygon()
{
    totalArea -= calculateArea(sides, coordinates);

    delete[] coordinates;

    figureCount--;
}

void Polygon::draw() const
{
    cout << "Координаты многоугольника:" << endl;

    for (int i = 0; i < sides; i++)
    {
        cout << "Вершина " << i + 1 << ": ("
             << coordinates[i * 2] << ", "
             << coordinates[i * 2 + 1] << ")" << endl;
    }
}
