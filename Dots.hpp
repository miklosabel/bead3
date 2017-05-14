#ifndef DOTS_HPP_INCLUDED
#define DOTS_HPP_INCLUDED

#include "Box.hpp"
#include "graphics.hpp"

typedef enum{
     allWhite,
     ONEgotit,
     TWOgotit
}dotState;

class Dot: public Box
{
    public:
        Dot();
        Dot(CGRect _frame);
        virtual void Handle(genv::event ev);
        virtual void Draw();

        dotState getState() { return state; };
        void setState(dotState _dotState);
        void setCoulmnIndex(int c, int i);
        int getIndex() { return index; };
        int getColumn() { return column; };

    private:
        dotState state;
        int radius;
        int column;
        int index;
};

#endif // DOTS_HPP
