#include "Polygon.h"
#include <iostream>

using namespace std;

// Обычный конструктор
Polygon::Polygon(const Point* points, int pointCount, const string& color)
    : Figure(color), points(nullptr), pointCount(pointCount)
{
    if (pointCount < 3 || points == nullptr)
    {
        this->pointCount = 0;
        return;
    }

    this->points = new Point[pointCount];

    for (int i = 0; i < pointCount; i++)
    {
        this->points[i] = points[i];
    }
}

// Конструктор копирования
Polygon::Polygon(const Polygon& other)
    : Figure(other), points(nullptr), pointCount(other.pointCount)
{
    if (pointCount > 0)
    {
        points = new Point[pointCount];

        for (int i = 0; i < pointCount; i++)
        {
            points[i] = other.points[i];
        }
    }
}

// Оператор присваивания
Polygon& Polygon::operator=(const Polygon& other)
{
    if (this != &other)
    {
        Point* newPoints = nullptr;

        if (other.pointCount > 0)
        {
            newPoints = new Point[other.pointCount];

            for (int i = 0; i < other.pointCount; i++)
            {
                newPoints[i] = other.points[i];
            }
        }

        delete[] points;

        points = newPoints;
        pointCount = other.pointCount;

        Figure::operator=(other);
    }

    return *this;
}

// Вычисление площади по формуле Гаусса
double Polygon::area() const
{
    if (pointCount < 3 || points == nullptr)
    {
        return 0.0;
    }

    double result = 0.0;

    for (int i = 0; i < pointCount; i++)
    {
        int next = (i + 1) % pointCount;

        result += points[i].x * points[next].y
                - points[next].x * points[i].y;
    }

    if (result < 0)
    {
        result = -result;
    }

    return result / 2.0;
}

// Рисование многоугольника в консоли
void Polygon::draw() const
{
    cout << "Рисуем многоугольник с "
         << pointCount << " вершинами." << endl;
}

// Вывод информации о многоугольнике
void Polygon::printInfo() const
{
    Figure::printInfo();

    cout << "Количество вершин: " << pointCount << endl;
    cout << "Площадь: " << area() << endl;
}

// Деструктор
Polygon::~Polygon()
{
    delete[] points;
}
