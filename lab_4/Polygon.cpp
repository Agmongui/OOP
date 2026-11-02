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
    this->coordinates = coordinates;
}

Polygon::~Polygon()
{
    delete[] coordinates;
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