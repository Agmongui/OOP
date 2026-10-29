#ifndef FIGURE_H
#define FIGURE_H

#include "Drawable.h"
#include "Paintable.h"
#include <string>
#include <iostream>

using namespace std;

class Figure : public Drawable, public Paintable 
{
protected://доступ внутри класса и его наследников
    string color;
//статик принадлежит всему классу, а не каждому объекту отдельно
    static int totalCreated;//кол-во фигур
    static double totalArea;//сумма площадей

public:
    // Конструктор
    Figure(const string& color = "white");

    // Конструктор копирования
    Figure(const Figure& other);

    // Оператор присваивания
    Figure& operator=(const Figure& other);

    // Установка и получение цвета
    void setColor(const string& color) override;
    string getColor() const override;//возвращает текущий цвет фигуры

    // Чисто виртуальная функция вычисления площади
    virtual double area() const = 0;

    // Виртуальная функция с реализацией по умолчанию
    virtual void printInfo() const;//выводит информацию о фигуре

    // Статические функции
    static int getTotalCreated();
    static double getAverageArea();

    // Дружественная функция
    friend ostream& operator<<(ostream& out, const Figure& figure);

    // Виртуальный деструктор
    virtual ~Figure() = default;//мы будем работать с фигурами полиморфно
};

#endif