#include "Application.h"
#include "Enums.h"

using namespace bobcat;
using namespace std;

void Application::onCanvasMouseDown(bobcat::Widget* sender, float mx, float my) {
    TOOL tool = toolbar->getTool();
    Color color = colorSelector->getColor();

    if (tool == PENCIL) {
        canvas->startScribble();
        canvas->redraw();
    }
    else if (tool == ERASER) {
        canvas->eraseShape(mx, my);
        canvas->redraw();
    }
    else if (tool == RECTANGLE) {
        canvas->addRectangle(mx, my, color.getR(), color.getG(), color.getB());
        canvas->redraw();
    }
    else if (tool == CIRCLE) { 
        canvas->addCircle(mx, my, color.getR(), color.getG(), color.getB());
        canvas->redraw();
    }
    else if (tool == TRIANGLE) {
        canvas->addTriangle(mx, my, color.getR(), color.getG(), color.getB());
        canvas->redraw();
    }
    else if (tool == POLYGON) {
        canvas->addPolygon(mx, my, color.getR(), color.getG(), color.getB());
        canvas->redraw();
    }
    else if (tool == MOUSE) {
        selectedShape = canvas->getSelectedShape(mx, my);
        if (selectedShape) {
            dragStartX = mx;
            dragStartY = my;
            std::cout << "Selected shape at (" << mx << ", " << my << ")" << std::endl;
        } else {
            std::cout << "No shape selected" << std::endl;
        }
    }

}

void Application::onCanvasDrag(bobcat::Widget* sender, float mx, float my) {
    std::cout << "Dragging to " << mx << my << std::endl;
    TOOL tool = toolbar->getTool();
    Color color = colorSelector->getColor();

    if (tool == PENCIL) {
        canvas->updateScribble(mx, my, color.getR(), color.getG(), color.getB(), 7);
        canvas->redraw();
    }
    else if (tool == ERASER) {
        canvas->eraseShape(mx, my);
        canvas->redraw();
    }
    else if (tool == MOUSE && selectedShape) {
        std::cout << "Moving shape?";
        float dx = mx - dragStartX;
        float dy = my - dragStartY;
        std::cout << "Moving by " << dx << ", " << dy << std::endl;
        selectedShape->move(dx, dy);
        dragStartX = mx;
        dragStartY = my;
        canvas->redraw();
    } 
}

void Application::onCanvasMouseUp(bobcat::Widget* sender, float mx, float my) {
    canvas->endScribble();
}

void Application::onToolbarChange(bobcat::Widget* sender) {
    
    ACTION action = toolbar->getAction();

    if (action == CLEAR) {
        canvas->clear();
        canvas->redraw();
    }
    else if (action == UNDO) {
        canvas->undo();
        canvas->redraw();
    }
    else if (action == PLUS && selectedShape) {
        selectedShape->increaseSize();
        canvas->redraw();
    }
    else if (action == MINUS && selectedShape) {
        selectedShape->decreaseSize();
        canvas->redraw();
    }
    else if (action == UP && selectedShape) {
        cout << "Bringing it forward" << endl;
        canvas->bringToFront(selectedShape);
        canvas->redraw();
    }
    else if (action == DOWN && selectedShape) {
        cout << "Bringing it back" << endl;
        canvas->sendToBack(selectedShape);
        canvas->redraw();
    }
}


void Application::onColorSelectorChange(bobcat::Widget* sender) {
    Color color = colorSelector->getColor();

    if (selectedShape) {
        selectedShape->setColor(color.getR(), color.getG(), color.getB());
        canvas->redraw();
    }
}


Application::Application() {
    window = new Window(100, 100, 650, 650, "Pain App");

    selectedShape = nullptr;

    toolbar = new Toolbar(0, 0, 50, 650);
    canvas = new Canvas(50, 0, 600, 600);
    colorSelector = new ColorSelector(50, 600, 550, 50);
    colorSelector->box(FL_BORDER_BOX);

    window->add(toolbar);
    window->add(canvas);
    window->add(colorSelector);

    
    dragStartX = 0.0;
    dragStartY = 0.0;

    ON_MOUSE_DOWN(canvas, Application::onCanvasMouseDown);
    ON_MOUSE_UP(canvas, Application::onCanvasMouseUp);
    ON_DRAG(canvas, Application::onCanvasDrag);
    ON_CHANGE(toolbar, Application::onToolbarChange);
    ON_CHANGE(colorSelector, Application::onColorSelectorChange);
    
    window->show();
}