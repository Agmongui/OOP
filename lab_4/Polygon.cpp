#include "Polygon.h"
#include <iostream>
#include <stdexcept>

using namespace std;

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
}

Polygon& Polygon::operator=(const Polygon& other)
{
    if (this == &other)
    {
        return *this;
    }

    double* newCoordinates = new double[other.sides * 2]; // Выделяем память под координаты нового объекта

    for (int i = 0; i < other.sides * 2; i++)
    {
        newCoordinates[i] = other.coordinates[i];
    }

    delete[] coordinates;

    sides = other.sides;
    coordinates = newCoordinates;

    return *this;
}

Polygon::~Polygon()
{
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