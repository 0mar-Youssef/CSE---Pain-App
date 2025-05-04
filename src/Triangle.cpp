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
   return mx >= x - base/2 && mx <= x + height/2 && my >= y - height/2 && my <= y + height/2;
}

void Triangle::move(float dx, float dy){
    x += dx;
    y += dy;
}

// void Triangle::resize() {
//     float dx = std::abs(mx-x);
//     float dy = std::abs(my-y);

//     float newBase = 2.0f * dx;
//     float newHeight = 2.0f * dy;

//     if (newBase > 0.01f && newHeight > 0.01f) {
//         base = newBase;
//         height = newHeight;
//     }
// }

void Triangle::increaseSize() {
    base += 0.1;
    height += 0.1;
}

void Triangle::decreaseSize() {
    // Threshold is set slightly higher due to floating float precision
    // And to prevent the shape from going to oblivion
    if (base > 0.11 && height > 0.11) {
        base -= 0.1;
        height -=0.1;
    }
}