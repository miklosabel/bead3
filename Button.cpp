#include "Button.hpp"
#include <iostream>

using namespace std;
using namespace genv;

Button::Button(CGRect _frame) : Box(_frame) {}


void Button::Handle(event ev)
{
    if(ev.type == ev_mouse)
    {
        if(ev.button == btn_left)
        {
            if(selected(ev.pos_x,ev.pos_y))
            {
                this->isPressed = true;
                callback();
            }
            else this->isPressed = false;
        }
        else this->isPressed = false;
    }
}
void Button::Draw()
{
    if(this->isPressed)
    {
        gout    << move_to(frame.position.x, frame.position.y) 
                << color(boxColour.r()-50, boxColour.g()-50, boxColour.b()-50) 
                << box(frame.r_size.width, frame.r_size.height);
    }
    else
    {
        gout    << move_to(frame.position.x, frame.position.y) 
                << color(boxColour.r(), boxColour.g(), boxColour.b()) 
                << box(frame.r_size.width, frame.r_size.height);
    }
}
