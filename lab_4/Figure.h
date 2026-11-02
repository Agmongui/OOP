#ifndef FIGURE_H
#define FIGURE_H

#include "Drawable.h"
#include "Printable.h"
#include <iostream>

using namespace std;

class Figure : public Drawable, public Printable
{
protected:
    static int figureCount;
    static double totalArea;

public:
    virtual double area() const = 0;
    virtual void print() const
    {
        cout << "Площадь фигуры: " << area() << endl;
    }

    static int getFigureCount();
    static double getAverageArea();
};

#endif
