#include "Circle.h"
#include <GL/freeglut.h>
#include <GL/gl.h>
#include <cmath>

Circle::Circle() {
    x = 0.0;
    y = 0.0;
    radius = 0.2;
    r = 0.0;
    g = 0.0;
    b = 0.0;
}

Circle::Circle(float x, float y, float r, float g, float b) {
    this->x = x; 
    this->y = y; 
    radius = 0.2;
    this->r = r; 
    this->g = g; 
    this->b = b; 
}

void Circle::draw() {
    glColor3f(r, g, b);

    float inc = M_PI / 32;
    glBegin(GL_POLYGON);
        for (float theta = 0; theta <= 2 * M_PI; theta += inc){
            glVertex2d(x + cos(theta) * radius, y + sin(theta) * radius);
        }
    glEnd();
}

bool Circle::contains(float mx, float my) {
    return mx >= x - radius && mx <= x + radius && my >= y - radius && my <= y + radius;
}

void Circle::move(float dx, float dy) {
    x += dx;
    y += dy;
}

// void Circle::resize(float mx, float my) {
//     float dx = mx - x;
//     float dy = my - y;
//     float newRadius = sqrt(dx * dx + dy * dy);
//     if (newRadius > 0.01f) { // avoid zero raidus by telling program to treat 0.01f as a float not a double cause
//                              // raidus is a float
//         radius = newRadius;
//     }
// }

void Circle::increaseSize() {
    radius += 0.1;
}
void Circle::decreaseSize() {
    // Threshold is set slightly higher due to floating float precision
    // And to prevent the shape from going to oblivion
    if (radius > 0.11) {
        radius -= 0.1;
    }
}