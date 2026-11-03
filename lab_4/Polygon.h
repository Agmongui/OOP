/**
 * @file Polygon.h
 * @brief Объявление класса многоугольника.
 */

#ifndef POLYGON_H
#define POLYGON_H

#include "Figure.h"
#include "Lab3Export.h"

/**
 * @class Polygon
 * @brief Абстрактный класс многоугольника.
 *
 * Наследуется от Figure и хранит количество сторон
 * и координаты вершин в динамическом массиве.
 */
class LAB3_API Polygon : public Figure
{
protected:
    /**
     * @brief Количество сторон многоугольника.
     */
    int sides;

    /**
     * @brief Динамический массив координат вершин.
     *
     * Для каждой вершины хранятся две координаты: x и y.
     */
    double* coordinates;

public:
    /**
     * @brief Создаёт многоугольник с заданными координатами.
     * @param sides Количество сторон.
     * @param coordinates Массив координат вершин.
     */
    Polygon(int sides, double* coordinates);

    /**
     * @brief Конструктор копирования.
     *
     * Создаёт независимую копию динамического массива координат.
     * @param other Многоугольник, который копируется.
     */
    Polygon(const Polygon& other);

    /**
     * @brief Оператор присваивания.
     *
     * Копирует данные другого многоугольника
     * с выделением собственной памяти.
     * @param other Многоугольник, данные которого копируются.
     * @return Ссылка на текущий объект.
     */
    Polygon& operator=(const Polygon& other);

    /**
     * @brief Деструктор.
     *
     * Освобождает память, выделенную для координат.
     */
    ~Polygon();

    /**
     * @brief Отрисовывает многоугольник.
     *
     * Переопределяет виртуальную функцию draw()
     * базового класса Drawable.
     */
    void draw() const override;
};

#endif