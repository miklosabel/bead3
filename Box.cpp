#include "Box.hpp"

using namespace genv;
const int contourWidth = 2;

CGSize::CGSize(float s_width, float s_height) : width(s_width), height(s_height) {}

CGPoint::CGPoint(float p_x, float p_y) : x(p_x), y(p_y) {}

CGRect::CGRect(float x, float y, float width, float height) : r_size(width,height), position(x,y) {}

Colour::Colour(int r, int g, int b)
{
    pr = r;
    pg = g;
    pb = b;
}


Box::Box(CGRect box_frame) : frame(box_frame), boxColour(Colour(255,255,255)) {}

bool Box::selected(int mouse_x, int mouse_y) const
{
    return mouse_x >= frame.position.x && mouse_x <= frame.position.x+frame.r_size.width && mouse_y >= frame.position.y && mouse_y <= frame.position.y+frame.r_size.height;
}

void Box::Handle(event ev)
{
    this->HandleSelection(ev);
}

void Box::HandleSelection(event ev)
{
    this->DrawContour(this->selected(ev.pos_x,ev.pos_y));
}

void Box::DrawContour(bool isSelected)
{
    if(isSelected) 
    {
        gout    << move_to(frame.position.x-contourWidth,frame.position.y-contourWidth) 
                << color(255,255,255) 
                << box(frame.r_size.width+2*contourWidth,frame.r_size.height+2*contourWidth);
    }
    else 
    {
        gout    << move_to(frame.position.x-contourWidth,frame.position.y-contourWidth) 
                << color(0,0,0) 
                << box(frame.r_size.width+2*contourWidth,frame.r_size.height+2*contourWidth);
    }
}

void Box::Draw()
{
    gout    << move_to(frame.position.x,frame.position.y) 
            << color(boxColour.r(),boxColour.g(),boxColour.b()) 
            << box(frame.r_size.width,frame.r_size.height);
}

void Box::setColor(Colour _color)
{
    boxColour = _color;
}

