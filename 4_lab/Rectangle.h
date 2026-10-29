#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Polygon.h"

using namespace std;

class Rectangle : public Polygon 
{
protected:
    double width;
    double height;

public:
    Rectangle(double width, double height,
              const string& color = "white");

    Rectangle(const Rectangle& other);
    Rectangle& operator=(const Rectangle& other);

    double area() const override;
    void draw() const override;
    void printInfo() const override;

    virtual ~Rectangle() = default;
};

#endif
