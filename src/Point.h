#ifndef POINT_H
#define POINT_H

#include "Shape.h"

class Point: public Shape {
    float x;
    float y;
    float r;
    float g;
    float b;
    int size;

public:
    Point();
    Point(float x, float y);
    Point(float x, float y, float r, float g, float b);
    Point(float x, float y, float r, float g, float b, int size);

    void draw();

    float getX() const;
    float getY() const;
    float getR() const;
    float getG() const;
    float getB() const;
    int getSize() const;

    bool contains(float mx, float my);
    void resize(float mx, float my);

    void move(float dx, float dy);
};

#endif