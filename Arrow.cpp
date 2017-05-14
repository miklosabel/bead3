#include "Arrow.hpp"
#include <iostream>

using namespace genv;

const int topSpace = 7;
extern const color playerOne;
extern const color playerTwo;
extern const int edge;
extern const int boxSize;
extern const int columns;

Arrow::Arrow(CGRect _frame) : Box(_frame)
{
    CurrentPlayer = ONE;
}

int whichColumn(int x) 
{
    int column = (x-edge)/boxSize;
    if(column < 0)  column = 0;
    if(column > columns-1)  column = columns-1;
    return column;
}

void Arrow::Handle(event ev)
{
    if(ev.type == ev_mouse)
    {
        frame.position.x = edge + whichColumn(ev.pos_x) * boxSize;
        if(ev.button == btn_left)
        {
            if(CurrentPlayer == ONE) CurrentPlayer = TWO;
            else CurrentPlayer = ONE; 
        }
    }

}

void Arrow::Draw()
{
    if(CurrentPlayer == ONE) gout<< playerOne;
    else gout<< playerTwo;
    
     /// Arrow down
    gout    << move_to(frame.position.x + frame.r_size.width/2, frame.position.y + frame.r_size.height - topSpace) 
            << line_to(frame.position.x + frame.r_size.width, frame.position.y + topSpace + frame.r_size.height/2);
    gout    << move_to(frame.position.x + frame.r_size.width/2, frame.position.y + frame.r_size.height - topSpace)
            << line_to(frame.position.x, frame.position.y + topSpace+frame.r_size.height/2);
}

void Arrow::setPlayer(player nextPlayer)
{
    CurrentPlayer = nextPlayer;
}
