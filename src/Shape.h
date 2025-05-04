#ifndef SHAPE_H
#define SHAPE_H

#include <GL/freeglut.h>
#include <GL/gl.h>
#include "Color.h"

// Abstract Data Type
class Shape{
protected:
    float r, g, b;

public:
    // This function is now pure virtual
    virtual void draw() = 0;

    virtual bool contains(float mx, float my) = 0;

    virtual void move(float dx, float dy) = 0;

    virtual void increaseSize() = 0;

    virtual void decreaseSize() = 0;

    virtual void setColor(float r, float g, float b) {
        this->r = r;
        this->g = g;
        this->b = b;
    }


    // Since Shape contains at least one pure virtual function
    // Shape is an Abstract Data Type

    // This forces every child of Shape to have a draw
    // function implemented

    // Any ADT must have a virtual destructor
    virtual ~Shape(){}
};

#endif