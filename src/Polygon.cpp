#include "Polygon.h"
#include <GL/freeglut.h>
#include <cmath>

Polygon::Polygon() {
    x = 0.0;
    y = 0.0;
    sides = 5;
    length = 0.1;
    r = 0.0;
    g = 0.0;
    b = 0.0;
} 

Polygon::Polygon(float x, float y, float r, float g, float b) {
    this->x = x;
    this->y = y;
    sides = 5;
    length = 0.225;
    this->r = r;
    this->g = g;
    this->b = b;
}

void Polygon::draw() {
    glColor3f(r, g, b);
    
    glBegin(GL_POLYGON);
        float inc = 2 * M_PI / sides;
        // Theta can't start at 0 because on the unit circle
        // the positioning would already start tilted since cos(0) = 1 which 
        // we want the first vertex to be at 0 (the top) in this case so lets start the angle at 90
        float startAngle = M_PI / 2; // pi/2 is 90 degrees

        float angle;
        for (float theta = 0; theta < 2 * M_PI; theta += inc) {
            angle = theta + startAngle; 
            // calculate new angle based off starting
            // & the continuous increment of theta
            glVertex2f(x + length * cos(angle), y + length * sin(angle));
        }
    glEnd();
}
bool Polygon::contains(float mx, float my) {
    // Who implemented this?
    return mx >= x - length && mx <= x + length && my >= y - length && my <= y + length;
}

void Polygon::move(float dx, float dy) {
    x += dx;
    y += dy;
}

// void Polygon::resize(float mx, float my) {
//     float dx = mx - x;
//     float dy = my - y;
//     float newLength = sqrt(dx * dx + dy * dy);
//     if (newLength > 0.01f) { // avoid zero raidus by telling program to treat 0.01f as a float not a double cause
//                              // raidus is a float
//         length = newLength;
//     }
// }

void Polygon::increaseSize() {
    length += 0.1125;
}
void Polygon::decreaseSize() {
    // Threshold is set slightly higher due to floating float precision
    // And to prevent the shape from going to oblivion
    if (length > 0.12) {
        length -= 0.1125;
    }
}