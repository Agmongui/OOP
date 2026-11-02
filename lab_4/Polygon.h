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
    Polygon(const Polygon& other); //конструктор копирования
    Polygon& operator=(const Polygon& other); // оператор присваивания
    ~Polygon();
    
    virtual void draw() const;
};

#endif