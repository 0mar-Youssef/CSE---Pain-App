#ifndef SCRIBBLE_H
#define SCRIBBLE_H

#include "Shape.h"
#include "Point.h"
#include <vector>

class Scribble: public Shape {
    std::vector<Point*> points;
    float x;
    float y;

public:

    void addPoint(float x, float y, float r, float g, float b, int size);

    void draw();

    ~Scribble();
    bool contains(float mx, float my);
    void move(float dx, float dy);
};
#endif