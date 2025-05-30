#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

class Circle : public Shape{
    float x;
    float y;
    float radius;

public:
    Circle();
    Circle(float x, float y, float r, float g, float b);
    void draw();
    bool contains(float mx, float my);
    void move(float dx, float dy);
    void increaseSize();
    void decreaseSize();
};

#endif