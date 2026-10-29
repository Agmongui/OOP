#include "Square.h"
#include <iostream>

using namespace std;

// Обычный конструктор
Square::Square(double side, const string& color)
    : Rectangle(side, side, color)
{}

// Конструктор копирования
Square::Square(const Square& other)
    : Rectangle(other)
{}

// Оператор присваивания
Square& Square::operator=(const Square& other)
{
    if (this != &other)
    {
        Rectangle::operator=(other);
    }

    return *this;
}

// Вычисление площади
double Square::area() const
{
    return width * width;
}

// Рисование квадрата
void Square::draw() const
{
    cout << "Рисуем квадрат со стороной "
         << width << endl;
}

// Вывод информации
void Square::printInfo() const
{
    Figure::printInfo();

    cout << "Тип фигуры: квадрат" << endl;
    cout << "Сторона: " << width << endl;
    cout << "Площадь: " << area() << endl;
}
