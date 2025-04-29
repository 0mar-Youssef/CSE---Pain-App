#include "Triangle.h"
#include <GL/freeglut.h>

Triangle::Triangle() {
    x = 0.0;
    y = 0.0;
    base = 0.2;
    height = 0.2;
    r = 0.0;
    g = 0.0;
    b = 0.0;
}

Triangle::Triangle(float x, float y, float r, float g, float b) {
    this->x = x;
    this->y = y;
    base = 0.4;
    height = 0.4;
    this->r = r;
    this->g = g;
    this->b = b;
}

void Triangle::draw() {
    glColor3f(r, g, b);
    
    glBegin(GL_POLYGON);
        glVertex2f(x - base/2, y - height/2);
        glVertex2f(x, y + height/2);
        glVertex2f(x + base/2, y - height/2);
    glEnd();
}
bool Triangle::contains(float mx, float my) {
    float x1 = x - base/2, y1 = y - height/2;
    float x2 = x, y2 = y + height/2;
    float x3 = x + base/2, y3 = y - height/2;

    float denom = ((y2 - y3)*(x1 - x3) + (x3 - x2)*(y1 - y3));
    float a = ((y2 - y3)*(mx - x3) + (x3 - x2)*(my - y3)) / denom;
    float b = ((y3 - y1)*(mx - x3) + (x1 - x3)*(my - y3)) / denom;
    float c = 1 - a - b;
    return a >= 0 && b >= 0 && c >= 0;
}

void Triangle::move(float dx, float dy){
    x += dx;
    y += dy;
}