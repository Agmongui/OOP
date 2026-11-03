#include "Rectangle.h"
#include <iostream>
#include <stdexcept>

using namespace std;

static double* makePoints(double width, double height)
{
    if (width <= 0 || height <= 0)
    {
        throw invalid_argument("Некорректные размеры прямоугольника");
    }

    double* points = new double[8]
    {
        0, 0,
        width, 0,
        width, height,
        0, height
    };

    return points;
}

Rectangle::Rectangle(double width, double height)
    : Polygon(4, makePoints(width, height))
{
}

double Rectangle::area() const
{
    double width = coordinates[2] - coordinates[0];
    double height = coordinates[5] - coordinates[1];

    return width * height;
}

void Rectangle::draw() const
{
    cout << "Координаты прямоугольника:" << endl;

    for (int i = 0; i < sides; i++)
    {
        cout << "Вершина " << i + 1 << ": (" << coordinates[i * 2] << ", "
             << coordinates[i * 2 + 1] << ")" << endl;
    }
}