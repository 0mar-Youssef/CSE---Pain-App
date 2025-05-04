#include "ColorSelector.h"
#include <FL/Enumerations.H>
#include <FL/Fl_Box.H>
#include "Color.h"
#include "Canvas.h"
#include <FL/Fl_Widget.H>
#include <GL/gl.h>
#include <bobcat_ui/bobcat_ui.h>
#include <algorithm>
#include <bobcat_ui/button.h>
#include <cstddef>
using namespace bobcat;

Color ColorSelector::getColor() const{
    return Color(r, g, b);
}

void ColorSelector::inputColor(bobcat::Widget* sender){

    if(!redInput->empty()){
        r = clamp(redInput->value()/255, 0, 1);
    }
    if(!blueInput->empty()){
        b = clamp(blueInput->value()/255, 0, 1);
    }
    if(!greenInput->empty()){
        g = clamp(greenInput->value()/255, 0, 1);
    }

    colorPreview->color(fl_rgb_color(
    static_cast<uchar>(r * 255),
    static_cast<uchar>(g * 255),
    static_cast<uchar>(b * 255)
    ));

    if (onChangeCb) {
        onChangeCb(this);
    }

    colorPreview->redraw();



}

float ColorSelector::clamp(float value, float min, float max){

    if(value > max){
        value = max;
    }
    else if(value < min){
        value = min;
    }
    
    return value;
}

ColorSelector::ColorSelector(int x, int y, int w, int h) : Group(x, y, w, h) {

    r = 255.0;
    g = 0.0;
    b = 0.0;

    colorPicker = false;
    redInput = new FloatInput(x + 20, y + 20, 50, 20, "Red");
    blueInput = new FloatInput(x + 80, y + 20, 50, 20, "Blue");
    greenInput = new FloatInput(x + 140, y + 20, 50, 20, "Green");
    colorPreview = new Fl_Box(x + 200, y + 1, 49, 49, "E");

// Fix this, it initializes with zeros
    redInput->value(r);
    greenInput->value(b);
    blueInput->value(g);

    colorPreview->box(FL_FLAT_BOX);
    colorPreview->color(fl_rgb_color(r, g ,b));
    
    
    ON_CHANGE(redInput, ColorSelector::inputColor);
    ON_CHANGE(blueInput, ColorSelector::inputColor);
    ON_CHANGE(greenInput, ColorSelector::inputColor);
}