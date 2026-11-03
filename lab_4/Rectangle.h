#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Polygon.h"
#include "Lab3Export.h"

class LAB3_API Rectangle : public Polygon
{
public:
    Rectangle(double width, double height);
    double area() const override;
    void draw() const override;
};

#endif