#include "Rectangle.h"
#include "Square.h"
#include "Figure.h"
#include "Drawable.h"
#include "Printable.h"

#include <iostream>
#include <fstream> // для работы с файлами
#include <string>
#include <stdexcept>

using namespace std;

int main()
{
    cout << "Тест" << endl;

    {
        cout << "\n1. Чтение объектов из файла:" << endl;

        ifstream file("figures.txt"); // открывает файл

        if (!file)
        {
            cout << "Ошибка открытия файла figures.txt" << endl;
            return 1;
        }

        Figure* figures[10] = {}; // массив для хранения 10 объектов

        for (int i = 0; i < 10; i++)
        {
            string type;

            if (!(file >> type))
            {
                cout << "Ошибка чтения данных из файла" << endl;

                for (int j = 0; j < i; j++)
                {
                    delete figures[j];
                }

                return 1;
            }

            if (type == "Rectangle")
            {
                double width, height;

                if (!(file >> width >> height))
                {
                    cout << "Ошибка чтения размеров прямоугольника" << endl;

                    for (int j = 0; j < i; j++)
                    {
                        delete figures[j];
                    }

                    return 1;
                }

                figures[i] = new Rectangle(width, height); // создаёт прямоугольник
            }
            else if (type == "Square")
            {
                double side;

                if (!(file >> side))
                {
                    cout << "Ошибка чтения размера квадрата" << endl;

                    for (int j = 0; j < i; j++)
                    {
                        delete figures[j];
                    }

                    return 1;
                }

                figures[i] = new Square(side); // создаёт квадрат
            }
            else
            {
                cout << "Неизвестный тип фигуры: " << type << endl;

                for (int j = 0; j < i; j++)
                {
                    delete figures[j]; // удаляет созданные объекты после тестирования
                }

                return 1;
            }
        }

        file.close();

        cout << "Из файла загружено 10 объектов." << endl;

        cout << "\n2. Площади фигур и полиморфизм:" << endl;

        for (int i = 0; i < 10; i++)
        {
            cout << "\nОбъект " << i + 1 << ":" << endl;

            showArea(*figures[i]);
            figures[i]->draw();
            figures[i]->print();
        }

        cout << "\n3. Статические члены:" << endl;

        cout << "Количество фигур: "
             << Figure::getFigureCount() << endl;

        cout << "Средняя площадь: "
             << Figure::getAverageArea() << endl;

        cout << "\n4. Конструктор копирования:" << endl;

        Rectangle rectangle(5, 3);
        Rectangle copiedRectangle(rectangle);

        cout << "Площадь исходного прямоугольника: "
             << rectangle.area() << endl;

        cout << "Площадь копии: "
             << copiedRectangle.area() << endl;

        cout << "\n5. Оператор присваивания:" << endl;

        Rectangle assignedRectangle(2, 2);
        assignedRectangle = rectangle;

        cout << "Площадь после присваивания: "
             << assignedRectangle.area() << endl;

        Rectangle anotherRectangle(3, 3);
        assignedRectangle = anotherRectangle;

        cout << "Площадь изменённой копии: "
             << assignedRectangle.area() << endl;

        cout << "Площадь исходного прямоугольника: "
             << rectangle.area() << endl;

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
            cout << "Перехвачено исключение: "
                 << error.what() << endl;
        }

        cout << "\n8. Удаление объектов из файла:" << endl;

        for (int i = 0; i < 10; i++)
        {
            delete figures[i];
        }
    }

    cout << "\n9. Проверка после удаления объектов:" << endl;

    cout << "Количество фигур: "
         << Figure::getFigureCount() << endl;

    cout << "Средняя площадь: "
         << Figure::getAverageArea() << endl;

    return 0;
}
