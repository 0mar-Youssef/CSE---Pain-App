#include "Rectangle.h"
#include <GL/freeglut.h>
#include <iostream>

Rectangle::Rectangle() {
    x = 0.0;
    y = 0.0;
    width = 0.4;
    height = 0.4;
    r = 0.0;
    g = 0.0;
    b = 0.0;
}

Rectangle::Rectangle(float x, float y, float r, float g, float b) {
    this->x = x;
    this->y = y;
    width = 0.4;
    height = 0.4;
    this->r = r;
    this->g = g;
    this->b = b;
}

void Rectangle::draw() {
    glColor3f(r, g, b);

    glBegin(GL_POLYGON);
        glVertex2f(x - width/2, y + height/2);
        glVertex2f(x + width/2, y + height/2);
        glVertex2f(x + width/2, y - height/2);
        glVertex2f(x - width/2, y - height/2);
    glEnd();
}

bool Rectangle::contains(float mx, float my) {
    return mx >= x - width/2 && mx <= x + width/2 && my >= y - height/2 && my <= y + height/2;
}

void Rectangle::move(float dx, float dy) {
    x += dx;
    y += dy;
    std::cout << "Moved to " << x << y << std::endl;
}

// void Rectangle::resize(float mx, float my) {
//     float dx = std::abs(mx-x);
//     float dy = std::abs(my-y);

//     float newWidth = 2.0f * dx;
//     float newHeight = 2.0f * dy;

//     if (newWidth > 0.01f && newHeight > 0.01f) {
//         width = newWidth;
//         height = newHeight;
//     }
// };

void Rectangle::increaseSize() {
    width += 0.1;
    height += 0.1;
}
void Rectangle::decreaseSize() {
    // Threshold is set slightly higher due to floating float precision
    // And to prevent the shape from going to oblivion
    if (width > 0.11 && height > 0.11) {
        width -= 0.1;
        height -= 0.1;
    }
}

