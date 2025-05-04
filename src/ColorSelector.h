#ifndef COLOR_SELECTOR_H
#define COLOR_SELECTOR_H

#include <bobcat_ui/all.h>
#include "Color.h"
#include "Enums.h"

class ColorSelector : public bobcat::Group {

    bobcat::FloatInput* redInput;
    bobcat::FloatInput* greenInput;
    bobcat::FloatInput* blueInput;
    bobcat::Button* colorChanger;
    bool colorPicker;

    Color* color;

    float r,g,b;

    void inputChange(bobcat::Widget* sender);
    void onClick(bobcat::Widget* sender);
    bool colorChange();


public:
    ColorSelector(int x, int y, int w, int h);

    Color getColor() const;

};

#endif