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

Renegade::Renegade(Point start, int wheelRotation, Color color) {
    this->start = start;
    this->wheelRotation = wheelRotation;
    this->color = color;
    this->antialias = 0;
}

Renegade::Renegade(Point start, int wheelRotation, Color color, int antialias) {
    this->start = start;
    this->wheelRotation = wheelRotation;
    this->color = color;
    this->antialias = antialias;
}

void Renegade::draw() {
    Color color = this->color;

    int yAssoalho = this->start.getY()-45;

    // Linha para-choque traseiro
    Point p1Line1 = Point(this->start.getX(), yAssoalho);
    Point p2Line1 = Point(this->start.getX()+54, yAssoalho);
    Line line1 = Line(p1Line1, p2Line1, this->color);

    // Linha saia
    Point p1Line2 = Point(this->start.getX()+106, yAssoalho);
    Point p2Line2 = Point(this->start.getX()+275, yAssoalho);
    Line line2 = Line(p1Line2, p2Line2, this->color);

    // Linha para-choque dianteiro
    Point p1Line3 = Point(this->start.getX()+327, yAssoalho);
    Point p2Line3 = Point(this->start.getX()+381, yAssoalho);
    Line line3 = Line(p1Line3, p2Line3, this->color);

    // Roda traseira
    Point pCenterWheel1 = Point(this->start.getX()+80, this->start.getY()-30);
    Wheel wheel1 = Wheel(pCenterWheel1, 30, this->wheelRotation, this->color);

    // Roda dianteira
    Point pCenterWheel2 = Point(this->start.getX()+300, this->start.getY()-30);
    Wheel wheel2 = Wheel(pCenterWheel2, 30, this->wheelRotation+60, this->color);

    wheel1.draw();
    wheel2.draw();
    line1.draw();
    line2.draw();
    line3.draw();
}