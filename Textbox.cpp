#include "Textbox.hpp"

using namespace genv;

Textbox::Textbox(CGRect _frame, std::string text,genv::color tColor) : textColor(tColor), Box(_frame)
{
    textToDisp = text;
}

void Textbox::Handle(event ev) {}

void Textbox::Draw()
{
    gout    << move_to(frame.position.x, frame.position.y)
            << color(textColor)
            << font("MANIFESTO.ttf",38,true)
            << text(textToDisp);
}

