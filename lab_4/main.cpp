#include "Rectangle.h"
#include "Square.h"
#include "Figure.h"
#include <iostream>

using namespace std;

int main()
{
    Rectangle rectangle(5, 3);
    Square square(4);

    Figure* figures[2];

    figures[0] = &rectangle;
    figures[1] = &square;

    for (int i = 0; i < 2; i++)
    {
        cout << "Площадь фигуры: " << figures[i]->area() << endl;
        showArea(*figures[i]);

        cout << "Отрисовка фигуры:" << endl;
        figures[i]->draw();

        cout << endl;
    }

    cout << "Количество фигур: " << Figure::getFigureCount() << endl;

    cout << "Средняя площадь фигур: " << Figure::getAverageArea() << endl;

    return 0;
}