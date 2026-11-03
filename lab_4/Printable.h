/**
 * @file Printable.h
 * @brief Объявление интерфейса для вывода информации об объектах.
 */

#ifndef PRINTABLE_H
#define PRINTABLE_H

#include "Lab3Export.h"

/**
 * @class Printable
 * @brief Интерфейс для объектов, информацию о которых можно вывести.
 *
 * Класс содержит чисто виртуальную функцию print(),
 * которую должны реализовать производные классы.
 */
class LAB3_API Printable
{
public:
    /**
     * @brief Выводит информацию об объекте.
     *
     * Чисто виртуальная функция, поэтому класс Printable
     * является абстрактным.
     */
    virtual void print() const = 0;

    /**
     * @brief Виртуальный деструктор.
     *
     * Обеспечивает корректное удаление объектов
     * производных классов через указатель Printable.
     */
    virtual ~Printable();
};

#endif