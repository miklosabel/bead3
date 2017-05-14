#include "Dots.hpp"
#include <cmath>

using namespace genv;

extern const int windowWidth;
extern const int windowHeight;
extern const color backround;
extern const color playerOne;
extern const color playerTwo;
extern const color emptyColor;
extern const int boxSize;


Dot::Dot() : Box( CGRect(0,0,0,0) ) {}

Dot::Dot(CGRect _frame) : Box(_frame)
{
    radius = (boxSize-15);
}

void Dot::Handle(event ev) {}

void Dot::Draw()
{
    switch(state)
    {
        case allWhite:
            gout << emptyColor;
            break;
        case ONEgotit:
            gout << playerOne;
            break;
        case TWOgotit:
            gout << playerTwo;
            break;
    }
    gout    << move_to(frame.position.x,frame.position.y) 
            << box(radius,radius);
}
void Dot::setCoulmnIndex(int c, int i)
{
    column = c;
    index = i;
}

void Dot::setState(dotState _dotState)
{
    state = _dotState;
}
