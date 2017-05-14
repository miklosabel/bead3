#ifndef BUTTON_HPP_INCLUDED
#define BUTTON_HPP_INCLUDED

#include "Box.hpp"

class Button: public Box
{
public:
    Button(CGRect _frame);
    virtual void Handle(genv::event ev);
    virtual void Draw();

private:
    bool isPressed;
};

#endif // BUTTON_HPP
