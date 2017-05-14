#ifndef ARROW_HPP_INCLUDED
#define ARROW_HPP_INCLUDED

#include "Box.hpp"
#include "graphics.hpp"
#include "Dots.hpp"

typedef enum{
    NON,ONE,TWO
}player;

class Arrow: public Box
{
    public:
        Arrow(CGRect _frame);
        virtual void Handle(genv::event ev);
        virtual void Draw();
        void setPlayer(player nextPlayer);
        player getPlayer() { return CurrentPlayer; };
    protected:

    private:
        player CurrentPlayer;
};

#endif // ARROW_HPP
