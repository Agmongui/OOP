#ifndef PRINTABLE_H
#define PRINTABLE_H

#include "Lab3Export.h"

class LAB3_API Printable
{
public:
    virtual void print() const = 0;

    virtual ~Printable();
};

#endif