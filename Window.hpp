#ifndef WINDOW_HPP_INCLUDED
#define WINDOW_HPP_INCLUDED

#include <vector>
#include "Box.hpp"
#include "graphics.hpp"
#include "Dots.hpp"
#include "Arrow.hpp"
#include "Textbox.hpp"


class Window
{
public:
    Window();
    Arrow *arrow;
    std::vector<std::vector<Dot *>> dotWidgets;
    std::vector<Box *> widgets;
    void fuss();
};

#endif // WINDOW_HPP
