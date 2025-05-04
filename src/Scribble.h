#ifndef SCRIBBLE_H
#define SCRIBBLE_H

#include "Shape.h"
#include "Point.h"
#include <vector>

class Scribble: public Shape {
    std::vector<Point*> points;
    float x;
    float y;

    float length;
    float width;

    float xMax, yMax, xMin, yMin;

public:

    void setColor(float r, float g, float b);

    void updateHitbox();

    void addPoint(float x, float y, float r, float g, float b, int size);

    void draw();

    ~Scribble();
    void createHitbox();

    bool contains(float mx, float my);
    void increaseSize();
    void decreaseSize();
    void move(float dx, float dy);
};
#endif