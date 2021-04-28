// Copyright [2021] <Gabriel Vega>
#ifndef _HOME_GABRIEL_DESKTOP_COMP4_HW_PS5_TRIANGLE_H_
#define _HOME_GABRIEL_DESKTOP_COMP4_HW_PS5_TRIANGLE_H_

#include <cmath>
#include <SFML/Graphics.hpp>

using sf::ConvexShape;
using sf::Vector2f;

class Triangle : public sf::Drawable{
 public:
    Triangle(double initX, double initY, double initL);
 private:
    ConvexShape triangle;
    double x, y;
    double l;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif  // _HOME_GABRIEL_DESKTOP_COMP4_HW_PS5_TRIANGLE_H_
