#ifndef DRAWABLE_H
#define DRAWABLE_H

#include "Lab3Export.h"

class LAB3_API Drawable
{
public:
    virtual void draw() const = 0;

    virtual ~Drawable();
};

#endif