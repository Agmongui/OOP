#ifndef POLYGON_H
#define POLYGON_H

#include "Figure.h"

class Polygon : public Figure
{
protected:
    int sides;
    double* coordinates; // хранит адрес динамически выделенного массива 
    
public:
    Polygon(int sides, double* coordinates);
    ~Polygon();
    
    virtual void draw() const;
};

#endif