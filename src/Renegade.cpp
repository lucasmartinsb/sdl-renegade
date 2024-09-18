#include "Renegade.h"
#include "Line.h"
#include "Circle.h"
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

Renegade::Renegade(Point start, Color color) {
    this->start = start;
    this->color = color;
    this->antialias = 0;
}

Renegade::Renegade(Point start, Color color, int antialias) {
    this->start = start;
    this->color = color;
    this->antialias = antialias;
}

void Renegade::draw() {
    Color color = this->color;

    Point p1 = Point(this->start.getX(), this->start.getY());
    Point p2 = Point(this->start.getX() +400, this->start.getY());

    Line l1 = Line(p1, p2, color, this->antialias);
    l1.draw();

    Circle c1 = Circle(p1, 10, color);
    c1.draw();
}