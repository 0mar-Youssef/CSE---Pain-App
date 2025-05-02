#ifndef TOOLBAR_H
#define TOOLBAR_H

#include <bobcat_ui/all.h>
#include <bobcat_ui/image.h>
#include "Enums.h"

class Toolbar : public bobcat::Group {
    bobcat::Image* pencilButton;
    bobcat::Image* eraserButton;
    bobcat::Image* circleButton;
    bobcat::Image* triangleButton;
    bobcat::Image* rectangleButton;
    bobcat::Image* polygonButton;
    bobcat::Image* undoButton;
    bobcat::Image* clearButton;
    bobcat::Image* minusButton;
    bobcat::Image* plusButton;
    bobcat::Image* bringToFrontButton;
    bobcat::Image* sendToBackButton;
    bobcat::Image* mouseButton;
    bobcat::Image* resizeButton;


    TOOL tool;
    ACTION action;
    void deselectAllTools();
    void visualizeSelectedTool();
    void onClick(bobcat::Widget* sender);

public:
    Toolbar(int x, int y, int w, int h);

    TOOL getTool() const;
    ACTION getAction() const;
};

#endif