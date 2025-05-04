#include "ColorSelector.h"
#include "Color.h"
#include "Canvas.h"
using namespace bobcat;

Color ColorSelector::getColor() const{

    if(!redInput->empty() && !blueInput->empty() && !blueInput->empty()){
        return Color(r, g, b);
    } else {
        return Color(0, 0, 0);
    }

}

void ColorSelector::inputChange(bobcat::Widget* sender){

    if(!redInput->empty() && !blueInput->empty() && !greenInput->empty()){
        r = redInput->value();
        b = blueInput->value();
        g = greenInput->value();

        colorChanger->color(fl_rgb_color(r, g, b));

    }

}

void ColorSelector::onClick(bobcat::Widget* sender){

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
    y = 400;

    colorPicker = false;
    redInput = new FloatInput(x, y+20, 50, 20, "Red");
    blueInput = new FloatInput(x +60, y+20, 50, 20, "Blue");
    greenInput = new FloatInput(x + 120, y+20, 50, 20, "Green");
    colorChanger = new Button(x + 180, y +5, 40, 40,""); 

}