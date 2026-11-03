#include "Rectangle.h"
#include "Square.h"
#include "Figure.h"
#include "Drawable.h"
#include "Printable.h"
#include <iostream>
#include <stdexcept>

using namespace std;

int main()
{
    cout << "Тест" << endl;

    {
        cout << "\n1. Создание объектов:" << endl;

        Rectangle rectangle(5, 3);
        Square square(4);

        cout << "Площадь прямоугольника: " << rectangle.area() << endl;
        cout << "Площадь квадрата: " << square.area() << endl;

        cout << "\n2. Полиморфизм:" << endl;

        Figure* figures[2];
        figures[0] = &rectangle;
        figures[1] = &square;

        for (int i = 0; i < 2; i++)
        {
            showArea(*figures[i]);
            figures[i]->draw();
            figures[i]->print();
            cout << endl;
        }

        cout << "\n3. Статические члены:" << endl;

        cout << "Количество фигур: " << Figure::getFigureCount() << endl;

        cout << "Средняя площадь: " << Figure::getAverageArea() << endl;

        cout << "\n4. Конструктор копирования:" << endl;

        Rectangle copiedRectangle(rectangle);

        cout << "Площадь исходного прямоугольника: " << rectangle.area() << endl;

        cout << "Площадь копии: " << copiedRectangle.area() << endl;

        cout << "\n5. Оператор присваивания:" << endl;

        Rectangle assignedRectangle(2, 2);
        assignedRectangle = rectangle;

        cout << "Площадь после присваивания: " << assignedRectangle.area() << endl;

        Rectangle anotherRectangle(3, 3);
        assignedRectangle = anotherRectangle;

        cout << "Площадь изменённой копии: " << assignedRectangle.area() << endl;

        cout << "Площадь исходного прямоугольника: " << rectangle.area() << endl;

        cout << "\n6. Множественное наследование:" << endl;

        Drawable* drawable = &rectangle;
        Printable* printable = &rectangle;

        drawable->draw();
        printable->print();

        cout << "\n7. Обработка исключений:" << endl;

        try
        {
            Rectangle invalidRectangle(-5, 3);
        }
        catch (const invalid_argument& error)
        {
            cout << "Перехвачено исключение: " << error.what() << endl;
        }
    }

    cout << "\n8. Проверка после удаления объектов:" << endl;

    cout << "Количество фигур: " << Figure::getFigureCount() << endl;

    cout << "Средняя площадь: " << Figure::getAverageArea() << endl;

    return 0;
}