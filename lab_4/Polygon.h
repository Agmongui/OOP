#ifndef POLYGON_H
#define POLYGON_H

#include "Figure.h"
#include "Lab3Export.h"

class LAB3_API Polygon : public Figure
{
protected:
    int sides;
    double* coordinates;

public:
    Polygon(int sides, double* coordinates);
    Polygon(const Polygon& other);
    Polygon& operator=(const Polygon& other);
    ~Polygon();

    void draw() const override;
};

#endif