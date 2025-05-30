#include "Canvas.h"
#include "Scribble.h"
#include <GL/freeglut.h>
#include <cstdlib>

Canvas::Canvas(int x, int y, int w, int h) : Canvas_(x, y, w, h) {
    curr = nullptr;
}

void Canvas::addPoint(float x, float y, float r, float g, float b, int size) {
    shapes.push_back(new Point(x, y, r, g, b, size));
}

void Canvas::addRectangle(float x, float y, float r, float g, float b) {
    shapes.push_back(new Rectangle(x, y, r, g, b));
}

void Canvas::addCircle(float x, float y, float r, float g, float b) {
    shapes.push_back(new Circle(x, y, r, g, b));
}

void Canvas::addTriangle(float x, float y, float r, float g, float b) {
    shapes.push_back(new Triangle(x, y, r, g, b));
}

void Canvas::addPolygon(float x, float y, float r, float g, float b) {
    shapes.push_back(new Polygon(x, y, r, g, b));
}

void Canvas::startScribble() {
    curr = new Scribble();
}

void Canvas::updateScribble(float x, float y, float r, float g, float b, int size) {
    if (curr) {
        curr->addPoint(x, y, r, g, b, size);
    }
}

void Canvas::endScribble() {
    if (curr) {
        curr->createHitbox();
        shapes.push_back(curr);
        curr = nullptr;
    }
}

void Canvas::clear() {
    for (unsigned int i = 0 ; i < shapes.size(); i++) {
        delete shapes[i];
    }
    shapes.clear();
}

void Canvas::undo(){
    if (shapes.size() > 0){
        delete shapes[shapes.size() - 1];
        shapes.pop_back();
    }
}

void Canvas::render() {
    for (unsigned int i = 0 ; i < shapes.size(); i++) {
        shapes[i]->draw();
    }

    if (curr) {
        curr->draw();
    }
}

Shape* Canvas::getSelectedShape(float mx, float my) {
    Shape* selectedShape = nullptr;

// Increment from the top-down to select the shape that's "on top"
    for (int i = shapes.size() - 1; i > -1; i--) {
        if (shapes[i]->contains(mx, my)) {
            std::cout << "Clicked on shape[" << i << "]" << std::endl;
            selectedShape = shapes[i];
            break;
        }
    }
    if (selectedShape == nullptr) {
        std::cout << "No selected shape" << std::endl;
    }

    return selectedShape;
}

void Canvas::eraseShape(float mx, float my) {

    for (int i = shapes.size() - 1; i > -1; i--) {
        if (shapes[i]->contains(mx, my)) {
            shapes.erase(shapes.begin() + i);
        }
    }
}

void Canvas::bringToFront(Shape* shape) {
    if (!shape) return;

    for(size_t i = 0; i < shapes.size(); i++) {
    if (shapes[i] == shape) {
        if (i < shapes.size() - 1) {
            Shape* temp = shapes[i];

            for (size_t j = i; j < shapes.size() - 1; j++) {
                shapes[j] = shapes[j + 1];
            }
            shapes[shapes.size() - 1] = temp;
        }
        break;
        }
    }   
}

void Canvas::sendToBack(Shape* shape) {
    if(!shape) return;

    for (size_t i = 0; i < shapes.size(); i++) {
        if (shapes[i] == shape) {
            if (i > 0) {
                Shape* temp = shapes[i];
                for (size_t j = i; j > 0; j--) {
                    shapes[j] = shapes[j -1];
                }
                shapes[0] = temp;
            }
            break;
        }
    }
}