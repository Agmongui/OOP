#ifndef FIGURE_H
#define FIGURE_H

#include "Drawable.h"
#include "Printable.h"
#include "Lab3Export.h"
#include <iostream>

using namespace std;

class LAB3_API Figure : public Drawable, public Printable
{
protected:
    static int figureCount;
    static double totalArea;

public:
    virtual double area() const = 0;

    virtual void print() const override;

    static int getFigureCount();
    static double getAverageArea();

    friend void showArea(const Figure& figure);
};

LAB3_API void showArea(const Figure& figure);

#endif