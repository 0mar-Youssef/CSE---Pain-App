#include "Scribble.h"

#include <iostream>

void Scribble::addPoint(float x, float y, float r, float g, float b, int size){
    points.push_back(new Point(x, y, r, g, b, size));
}

void Scribble::draw(){

    for (unsigned int i = 0; i < points.size(); i++){
        points[i]->draw();

        if (points[i] == points[0]) {
            xMax = points[0]->getX();
            xMin = points[0]->getX();
            yMax = points[0]->getY();
            yMin = points[0]->getY();
        }

        // Creating width
        if (points[i]->getX() > xMax) xMax = points[i]->getX();
        if (points[i]->getX() < xMin) xMin = points[i]->getX();

        // // Creating length
        if (points[i]->getY() > yMax) yMax = points[i]->getY();
        if (points[i]->getY() < yMin) yMin = points[i]->getY();
    }

    std::cout << "xMax: " << xMax << std::endl;
    std::cout << "xMin: " << xMin << std::endl;
    std::cout << "yMax: " << yMax << std::endl;
    std::cout << "yMin: " << yMin << std::endl;
}

void Scribble::updateHitbox(){
    for(unsigned int i = 0; i < points.size(); i++){
        // Creating width
        if (points[i]->getX() > xMax) xMax = points[i]->getX();
        if (points[i]->getX() < xMin) xMin = points[i]->getX();

        // // Creating length
        if (points[i]->getY() > yMax) yMax = points[i]->getY();
        if (points[i]->getY() < yMin) yMin = points[i]->getY();
    }

    createHitbox();
}

void Scribble::createHitbox() {
    this->width = xMax - xMin;
    this->length = yMax - yMin;

    std::cout << "Width: " << width << std::endl;
    std::cout << "Length: " << length << std::endl;
}

void Scribble::setColor(float r, float g, float b){
    for(unsigned int i = 0; i < points.size(); i++){
        points[i]->changePointColor(r, g, b);
    }
}

Scribble::~Scribble(){
    for (unsigned int i = 0; i < points.size(); i++){
        delete points[i];
    }
    points.clear();
}


void Scribble::move(float dx, float dy) {
    for (unsigned int i = 0; i < points.size(); i++) {
        points[i]->move(dx, dy);
    }

    updateHitbox();
}

void Scribble::increaseSize() {
    return;
}
void Scribble::decreaseSize() {
    return;
}

bool Scribble::contains(float mx, float my) {
    return mx >= x - width/2 && mx <= x + width/2 && my >= y - length/2 && my <= y + length/2;
}