#include "Figure.h"

int Figure::figureCount = 0;
double Figure::totalArea = 0;

int Figure::getFigureCount()
{
    return figureCount;
}

double Figure::getAverageArea()
{
    if (figureCount == 0)
    {
        return 0;
    }

    return totalArea / figureCount;
}

void showArea(const Figure& figure)
{
    cout << "Площадь фигуры: " << figure.area() << endl;
}