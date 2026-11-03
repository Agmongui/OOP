/**
 * @file Rectangle.h
 * @brief Объявление класса прямоугольника.
 */

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Polygon.h"
#include "Lab3Export.h"

/**
 * @class Rectangle
 * @brief Класс прямоугольника.
 *
 * Наследуется от Polygon и реализует вычисление площади
 * и отрисовку прямоугольника.
 */
class LAB3_API Rectangle : public Polygon
{
public:
    /**
     * @brief Создаёт прямоугольник заданной ширины и высоты.
     * @param width Ширина прямоугольника.
     * @param height Высота прямоугольника.
     */
    Rectangle(double width, double height);

    /**
     * @brief Вычисляет площадь прямоугольника.
     * @return Площадь прямоугольника.
     *
     * Реализует чисто виртуальную функцию area()
     * базового класса Figure.
     */
    double area() const override;

    /**
     * @brief Выводит координаты вершин прямоугольника.
     *
     * Переопределяет виртуальную функцию draw()
     * базового класса Polygon.
     */
    void draw() const override;
};

#endif