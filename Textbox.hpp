#ifndef TEXTBOX_HPP_INCLUDED
#define TEXTBOX_HPP_INCLUDED

#include "Box.hpp"
#include "graphics.hpp"

class Textbox: public Box
{
    public:
        Textbox(CGRect _frame, std::string text, genv::color tColor);
        virtual void Handle(genv::event ev);
        virtual void Draw();
    protected:

    private:
        std::string textToDisp;
        genv::color textColor;
};

#endif // TEXTBOX_HPP
