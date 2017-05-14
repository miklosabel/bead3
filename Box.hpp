#include "graphics.hpp"
#include "functional"


#ifndef CGSIZE_HPP_INCLUDED
#define CGSIZE_HPP_INCLUDED

class CGSize
{
public:
    CGSize(float s_width, float s_height);
    float width;
    float height;
};

#endif // CGSIZE_H



#ifndef CGPOINT_HPP_INDLUDED
#define CGPOINT_HPP_INDLUDED

class CGPoint
{
public:
    CGPoint(float p_x, float p_y);
    float x,y;
};
#endif // CGPOINT_H



#ifndef CGRECT_HPP_INCLUDED
#define CGRECT_HPP_INCLUDED

class CGRect
{
public:
    CGRect(float x, float y, float width, float height);
    CGSize r_size;
    CGPoint position;
};
#endif // CGRECT_H



#ifndef COLOR_HPP_INCLUDED
#define COLOR_HPP_INCLUDED

class Colour
{
public:
    Colour(int r, int g, int b);
    int r() const { return pr; };
    int g() const { return pg; };
    int b () const { return pb; };
protected:
    int pr, pg, pb;
};
#endif // COLOR_H



#ifndef BOX_HPP_INCLUDED
#define BOX_HPP_INCLUDED

class Box
{
    protected:
    CGRect frame;
    Colour boxColour;
    std::function<void()> callback;

public:
    Box(CGRect box_frame);

    virtual void Draw();
    virtual void DrawContour(bool isSelected);

    virtual bool selected(int mouse_x, int mouse_y) const;

    virtual void Handle(genv::event ev);
    void HandleSelection(genv::event ev);

    CGRect getFrame() { return frame; };
    virtual void setColor(Colour _color);

    template <typename lambdaFn>
    void setCallBack(lambdaFn&& _fn)
    {
        callback = _fn;
    }
    int tag;
};
#endif // BOX_HPP


