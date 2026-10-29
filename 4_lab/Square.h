#ifndef SQUARE_H
#define SQUARE_H

#include "Rectangle.h"

using namespace std;

class Square : public Rectangle {
public:
    Square(double side, const string& color = "white");

    Square(const Square& other);
    Square& operator=(const Square& other);

    double area() const override;
    void draw() const override;
    void printInfo() const override;

    virtual ~Square() = default;
};

#endif
