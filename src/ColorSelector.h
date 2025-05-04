#ifndef COLOR_SELECTOR_H
#define COLOR_SELECTOR_H

#include <FL/Fl_Box.H>
#include <bobcat_ui/all.h>
#include "Color.h"
#include "Enums.h"
#include <algorithm>

class ColorSelector : public bobcat::Group {

    bobcat::FloatInput* redInput;
    bobcat::FloatInput* greenInput;
    bobcat::FloatInput* blueInput;
    bobcat::Button* colorChanger;
    Fl_Box* colorPreview;

    float r,g,b;

    void visualizeButton(bobcat::Widget* sender);
    void inputColor(bobcat::Widget* sender);
    bool colorChange();
    float clamp (float value, float min, float max);

public:

    bool colorPicker;

    ColorSelector(int x, int y, int w, int h);

    Color getColor() const;

};

#endif