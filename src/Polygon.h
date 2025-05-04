#ifndef POLYGON_H
#define POLYGON_H

#include "Shape.h"

class Polygon : public Shape{
    float x;
    float y;
    int sides;
    float length;
    
public:
    Polygon();
    Polygon(float x, float y, float r, float g, float b);

    void draw();
    bool contains(float mx, float my);
    void move(float dx, float dy);
    void increaseSize();
    void decreaseSize();
};

#endif