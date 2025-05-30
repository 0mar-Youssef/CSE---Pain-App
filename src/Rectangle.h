#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape {
    float x;
    float y;
    float width;
    float height;


public:
    Rectangle();
    Rectangle(float x, float y, float r, float g, float b);
    void draw();
    bool contains(float mx, float my);
    void move(float dx, float dy);
    void increaseSize();
    void decreaseSize();
};

#endif