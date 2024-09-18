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

    Point p1Line1 = Point(this->start.getX(), this->start.getY()-45);
    Point p2Line1 = Point(this->start.getX()+54, this->start.getY()-45);
    Line line1 = Line(p1Line1, p2Line1, this->color);

    Point p1Line2 = Point(this->start.getX()+106, this->start.getY()-45);
    Point p2Line2 = Point(this->start.getX()+275, this->start.getY()-45);
    Line line2 = Line(p1Line2, p2Line2, this->color);

    Point p1Line3 = Point(this->start.getX()+327, this->start.getY()-45);
    Point p2Line3 = Point(this->start.getX()+381, this->start.getY()-45);
    Line line3 = Line(p1Line3, p2Line3, this->color);

    Point pCenterWheel1 = Point(this->start.getX()+80, this->start.getY()-30);
    Wheel wheel1 = Wheel(pCenterWheel1, this->degrees, this->color);

    Point pCenterWheel2 = Point(this->start.getX()+300, this->start.getY()-30);
    Wheel wheel2 = Wheel(pCenterWheel2, this->degrees+60, this->color);

    wheel1.draw();
    wheel2.draw();
    line1.draw();
    line2.draw();
    line3.draw();
}