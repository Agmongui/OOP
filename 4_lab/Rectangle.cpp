#include "Rectangle.h"
#include <iostream>

using namespace std;

// Обычный конструктор
Rectangle::Rectangle(double width, double height, const string& color)
    : Polygon(nullptr, 0, color), width(width), height(height)
{
    if (width <= 0 || height <= 0)
    {
        this->width = 0;
        this->height = 0;
    }

    pointCount = 4;
    points = new Point[pointCount];

    points[0] = {0, 0};
    points[1] = {this->width, 0};
    points[2] = {this->width, this->height};
    points[3] = {0, this->height};
}

// Конструктор копирования
Rectangle::Rectangle(const Rectangle& other)
    : Polygon(other), width(other.width), height(other.height)
{}

// Оператор присваивания
Rectangle& Rectangle::operator=(const Rectangle& other)
{
    if (this != &other)
    {
        Polygon::operator=(other);

        width = other.width;
        height = other.height;
    }

    return *this;
}

// Вычисление площади
double Rectangle::area() const
{
    return width * height;
}

// Рисование прямоугольника
void Rectangle::draw() const
{
    cout << "Рисуем прямоугольник размером "
         << width << " x " << height << endl;
}

// Вывод информации
void Rectangle::printInfo() const
{
    Figure::printInfo();

    cout << "Тип фигуры: прямоугольник" << endl;
    cout << "Ширина: " << width << endl;
    cout << "Высота: " << height << endl;
    cout << "Площадь: " << area() << endl;
}
