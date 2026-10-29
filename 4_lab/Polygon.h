#ifndef POLYGON_H
#define POLYGON_H

#include "Figure.h"

using namespace std;

struct Point 
{
    double x;
    double y;
};

class Polygon : public Figure 
{
protected:
    Point* points;
    int pointCount;

public:
    Polygon(const Point* points, int pointCount,
            const string& color = "white");

    Polygon(const Polygon& other);
    Polygon& operator=(const Polygon& other);

    double area() const override;
    void draw() const override;
    void printInfo() const override;

    virtual ~Polygon();
};

#endif
