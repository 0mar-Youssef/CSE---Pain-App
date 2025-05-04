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

void ColorSelector::onChange(bobcat::Widget* sender){

    if(!redInput->empty()){
        r = ColorSelector::clamp(redInput->value()/255, 0, 1);
    }
    if(!blueInput->empty()){
        b = ColorSelector::clamp(blueInput->value()/255, 0, 1);
    }
    if(!greenInput->empty()){
        g = ColorSelector::clamp(greenInput->value()/255, 0, 1);
    }

    colorPreview->color(fl_rgb_color(
    static_cast<uchar>(r * 255),
    static_cast<uchar>(g * 255),
    static_cast<uchar>(b * 255)
    ));
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

void ColorSelector::onClick(bobcat::Widget* sender){

    std::cout<< r << std::endl;
    std::cout<< g << std::endl;
    std::cout<< b << std::endl;

    if(colorPicker){
        colorPicker = false;
        colorChanger->label("");
    }
    else if(!colorPicker){
        colorChanger->label("@+5square");
        colorPicker = true;
    }

}

bool ColorSelector::colorChange(){

    return colorPicker;

}

ColorSelector::ColorSelector(int x, int y, int w, int h) : Group(x, y, w, h) {

    colorPicker = false;
    redInput = new FloatInput(x +20, y+20, 50, 20, "Red");
    blueInput = new FloatInput(x +80, y+20, 50, 20, "Blue");
    greenInput = new FloatInput(x + 140, y+20, 50, 20, "Green");
    colorPreview = new Fl_Box(x+ 200, y + 1, 49, 49, "");
    colorChanger = new Button(x + 260, y +5, 40, 40,"");
    colorPreview->box(FL_FLAT_BOX);
    colorPreview->color(fl_rgb_color(0, 0 ,0));
    r = 0;
    g = 0;
    b = 0;
    
    ON_CHANGE(redInput, ColorSelector::onChange);
    ON_CHANGE(blueInput, ColorSelector::onChange);
    ON_CHANGE(greenInput, ColorSelector::onChange);
    ON_CLICK(colorChanger, ColorSelector::onClick);

}