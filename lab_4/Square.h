/**
 * @file Square.h
 * @brief Объявление класса квадрата.
 */

#ifndef SQUARE_H
#define SQUARE_H

#include "Rectangle.h"
#include "Lab3Export.h"

/**
 * @class Square
 * @brief Класс квадрата.
 *
 * Наследуется от Rectangle. Квадрат является частным
 * случаем прямоугольника, у которого ширина равна высоте.
 */
class LAB3_API Square : public Rectangle
{
public:
    /**
     * @brief Создаёт квадрат с заданной длиной стороны.
     * @param side Длина стороны квадрата.
     */
    Square(double side);
};

#endif