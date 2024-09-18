#include "Renegade.h"
#include "Line.h"
#include "Circle.h"
#include "Wheel.h"
#include "Point.h"
#include "Context.h"

Renegade::Renegade()
{
    //ctor
}

Renegade::~Renegade()
{
    //dtor
}

Renegade::Renegade(Point start, int degrees, Color color) {
    this->start = start;
    this->degrees = degrees;
    this->color = color;
    this->antialias = 0;
}

Renegade::Renegade(Point start, int degrees, Color color, int antialias) {
    this->start = start;
    this->degrees = degrees;
    this->color = color;
    this->antialias = antialias;
}

void Renegade::draw() {
    Color color = this->color;

    Point p1 = Point(this->start.getX()+100, this->start.getY()+50);
    Wheel wheel1 = Wheel(p1, this->degrees, this->color);

    Point p2 = Point(this->start.getX()+300, this->start.getY()+50);
    Wheel wheel2 = Wheel(p2, this->degrees+60, this->color);

    wheel1.draw();
    wheel2.draw();
}