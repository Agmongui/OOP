#ifndef FIGURE_H
#define FIGURE_H

#include "Drawable.h"

class Figure : public Drawable
{
protected:
    static int figureCount;

public:
    virtual double area() const = 0;
    static int getFigureCount();
};

#endif