#include "Figure.h"

// Начальные значения статических переменных
int Figure::totalCreated = 0;
double Figure::totalArea = 0.0;

// Конструктор
Figure::Figure(const string& color)
    : color(color)//список инициализации
{
    totalCreated++;
}

// Конструктор копирования
Figure::Figure(const Figure& other)
    : color(other.color)
{
    totalCreated++;
}

// Оператор присваивания
Figure& Figure::operator=(const Figure& other)
{
    if (this != &other) 
    {
        color = other.color;
    }

    return *this;
}

// Установка цвета
void Figure::setColor(const string& color)
{
    this->color = color;
}

// Получение цвета
string Figure::getColor() const
{
    return color;
}

// Информация о фигуре
void Figure::printInfo() const
{
    cout << "Цвет фигуры: " << color << endl;
}

// Количество созданных фигур
int Figure::getTotalCreated()
{
    return totalCreated;
}

// Средняя площадь
double Figure::getAverageArea()
{
    if (totalCreated == 0) 
    {
        return 0.0;
    }

    return totalArea / totalCreated;
}

// Дружественная функция вывода
ostream& operator<<(ostream& out, const Figure& figure)
{
    out << "Цвет фигуры: " << figure.color;
    return out;
}
