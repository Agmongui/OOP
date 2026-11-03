/**
 * @file Figure.h
 * @brief Объявление базового класса геометрических фигур.
 */

#ifndef FIGURE_H
#define FIGURE_H

#include "Drawable.h"
#include "Printable.h"
#include "Lab3Export.h"
#include <iostream>

using namespace std;

/**
 * @class Figure
 * @brief Абстрактный базовый класс геометрической фигуры.
 *
 * Класс наследуется от Drawable и Printable,
 * поэтому поддерживает отрисовку и вывод информации.
 * Содержит общие статические данные для всех фигур.
 */
class LAB3_API Figure : public Drawable, public Printable
{
protected:
    /**
     * @brief Количество созданных фигур.
     */
    static int figureCount;

    /**
     * @brief Суммарная площадь существующих фигур.
     */
    static double totalArea;

public:
    /**
     * @brief Вычисляет площадь фигуры.
     * @return Площадь фигуры.
     *
     * Чисто виртуальная функция. Должна быть реализована
     * в производных классах.
     */
    virtual double area() const = 0;

    /**
     * @brief Выводит информацию о фигуре.
     *
     * Реализация по умолчанию выводит площадь фигуры.
     * Функция может быть переопределена в производных классах.
     */
    virtual void print() const override;

    /**
     * @brief Возвращает количество созданных фигур.
     * @return Количество фигур.
     */
    static int getFigureCount();

    /**
     * @brief Вычисляет среднюю площадь фигур.
     * @return Средняя площадь фигур.
     */
    static double getAverageArea();

    /**
     * @brief Дружественная функция для вывода площади фигуры.
     *
     * Получает доступ к закрытым и защищённым членам класса.
     * @param figure Объект геометрической фигуры.
     */
    friend void showArea(const Figure& figure);
};

/**
 * @brief Выводит площадь переданной фигуры.
 * @param figure Объект геометрической фигуры.
 */
LAB3_API void showArea(const Figure& figure);

#endif