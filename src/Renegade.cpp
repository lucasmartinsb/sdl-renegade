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

Renegade::Renegade(Point start, int wheelRotation, int degrees, Color color) {
    this->start = start;
    this->wheelRotation = wheelRotation;
    this->degrees = degrees;
    this->color = color;
    this->antialias = 0;
}

Renegade::Renegade(Point start, int wheelRotation, int degrees, Color color, int antialias) {
    this->start = start;
    this->wheelRotation = wheelRotation;
    this->degrees = degrees;
    this->color = color;
    this->antialias = antialias;
}

double Renegade::toRadians(int degrees) {
    return degrees * M_PI / 180.0;
}

Point Renegade::applyRampTransform(Point p, int degrees) {
    double angleRadians = this->toRadians(degrees);
    double cosTheta = cos(angleRadians);
    double sinTheta = sin(angleRadians);

    // Transladar o ponto para a origem
    double x = p.getX() - this->start.getX();
    double y = p.getY() - this->start.getY();

    // Aplicar a rotação
    double newX = x * cosTheta - y * sinTheta;
    double newY = x * sinTheta + y * cosTheta;

    // Transladar de volta
    return Point(newX + this->start.getX(), newY + this->start.getY());
}

void Renegade::draw() {
    Color color = this->color;
    int yAssoalho = this->start.getY() - 45;

    // Linha para-choque traseiro
    Point p1Line1 = applyRampTransform(Point(this->start.getX(), yAssoalho), this->degrees);
    Point p2Line1 = applyRampTransform(Point(this->start.getX() + 54, yAssoalho), this->degrees);
    Line line1 = Line(p1Line1, p2Line1, this->color);

    // Linha saia
    Point p1Line2 = applyRampTransform(Point(this->start.getX() + 106, yAssoalho), this->degrees);
    Point p2Line2 = applyRampTransform(Point(this->start.getX() + 275, yAssoalho), this->degrees);
    Line line2 = Line(p1Line2, p2Line2, this->color);

    // Linha para-choque dianteiro
    Point p1Line3 = applyRampTransform(Point(this->start.getX() + 326, yAssoalho), this->degrees);
    Point p2Line3 = applyRampTransform(Point(this->start.getX() + 380, yAssoalho), this->degrees);
    Line line3 = Line(p1Line3, p2Line3, this->color);

    // Roda traseira
    Point pCenterWheel1 = applyRampTransform(Point(this->start.getX() + 80, this->start.getY() - 30), this->degrees);
    Wheel wheel1 = Wheel(pCenterWheel1, 30, this->wheelRotation, this->color);

    // Roda dianteira
    Point pCenterWheel2 = applyRampTransform(Point(this->start.getX() + 300, this->start.getY() - 30), this->degrees);
    Wheel wheel2 = Wheel(pCenterWheel2, 30, this->wheelRotation, this->color);

    // Desenhar as rodas e linhas
    wheel1.draw();
    wheel2.draw();
    line1.draw();
    line2.draw();
    line3.draw();
}
