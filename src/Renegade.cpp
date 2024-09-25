#include "Renegade.h"
#include "Line.h"
#include "Wheel.h"
#include "Point.h"
#include <cmath>

Renegade::Renegade() {
    //ctor
}

Renegade::~Renegade() {
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

void Renegade::drawPolygon(std::vector<Point> points, Color cor) {
    if (points.size() < 2) {
        return;
    }

    for (size_t i = 0; i < points.size() - 1; ++i) {
        Line line = Line(points[i], points[i + 1], cor);
        line.draw();
    }

    Line closingLine = Line(points.back(), points.front(), cor);
    closingLine.draw();
}


void Renegade::draw() {
    int yAssoalho = this->start.getY() - 100;

    std::vector<Point> carBody = {
        applyRampTransform(Point(this->start.getX() + 16, yAssoalho + 89), this->degrees),
        applyRampTransform(Point(this->start.getX() + 20, yAssoalho + 89), this->degrees),
        applyRampTransform(Point(this->start.getX() + 29, yAssoalho + 64), this->degrees),
        applyRampTransform(Point(this->start.getX() + 61, yAssoalho + 65), this->degrees),
        applyRampTransform(Point(this->start.getX() + 74, yAssoalho + 92), this->degrees),
        applyRampTransform(Point(this->start.getX() + 184, yAssoalho + 93), this->degrees),
        applyRampTransform(Point(this->start.getX() + 194, yAssoalho + 65), this->degrees),
        applyRampTransform(Point(this->start.getX() + 232, yAssoalho + 65), this->degrees),
        applyRampTransform(Point(this->start.getX() + 240, yAssoalho + 92), this->degrees),
        applyRampTransform(Point(this->start.getX() + 248, yAssoalho + 92), this->degrees),
        applyRampTransform(Point(this->start.getX() + 256, yAssoalho + 86), this->degrees),
        applyRampTransform(Point(this->start.getX() + 256, yAssoalho + 83), this->degrees),
        applyRampTransform(Point(this->start.getX() + 265, yAssoalho + 71), this->degrees),
        applyRampTransform(Point(this->start.getX() + 265, yAssoalho + 67), this->degrees),
        applyRampTransform(Point(this->start.getX() + 263, yAssoalho + 65), this->degrees),
        applyRampTransform(Point(this->start.getX() + 263, yAssoalho + 59), this->degrees),
        applyRampTransform(Point(this->start.getX() + 259, yAssoalho + 56), this->degrees),
        applyRampTransform(Point(this->start.getX() + 257, yAssoalho + 55), this->degrees),
        applyRampTransform(Point(this->start.getX() + 257, yAssoalho + 47), this->degrees),
        applyRampTransform(Point(this->start.getX() + 256, yAssoalho + 44), this->degrees),
        applyRampTransform(Point(this->start.getX() + 246, yAssoalho + 37), this->degrees),
        applyRampTransform(Point(this->start.getX() + 227, yAssoalho + 33), this->degrees),
        applyRampTransform(Point(this->start.getX() + 192, yAssoalho + 29), this->degrees),
        applyRampTransform(Point(this->start.getX() + 161, yAssoalho + 4), this->degrees),
        applyRampTransform(Point(this->start.getX() + 125, yAssoalho + 1), this->degrees),
        applyRampTransform(Point(this->start.getX() + 74, yAssoalho + 0), this->degrees),
        applyRampTransform(Point(this->start.getX() + 28, yAssoalho + 3), this->degrees),
        applyRampTransform(Point(this->start.getX() + 17, yAssoalho + 4), this->degrees),
        applyRampTransform(Point(this->start.getX() + 13, yAssoalho + 4), this->degrees),
        applyRampTransform(Point(this->start.getX() + 12, yAssoalho + 6), this->degrees),
        applyRampTransform(Point(this->start.getX() + 16, yAssoalho + 9), this->degrees),
        applyRampTransform(Point(this->start.getX() + 9, yAssoalho + 28), this->degrees),
        applyRampTransform(Point(this->start.getX() + 7, yAssoalho + 31), this->degrees),
        applyRampTransform(Point(this->start.getX() + 6, yAssoalho + 35), this->degrees),
        applyRampTransform(Point(this->start.getX() + 6, yAssoalho + 47), this->degrees),
        applyRampTransform(Point(this->start.getX() + 5, yAssoalho + 47), this->degrees),
        applyRampTransform(Point(this->start.getX() + 5, yAssoalho + 52), this->degrees),
        applyRampTransform(Point(this->start.getX() + 3, yAssoalho + 63), this->degrees),
        applyRampTransform(Point(this->start.getX() + 1, yAssoalho + 65), this->degrees),
        applyRampTransform(Point(this->start.getX() + 2, yAssoalho + 77), this->degrees),
        applyRampTransform(Point(this->start.getX() + 10, yAssoalho + 87), this->degrees),
        applyRampTransform(Point(this->start.getX() + 16, yAssoalho + 89), this->degrees),
        applyRampTransform(Point(this->start.getX() + 16, yAssoalho + 89), this->degrees)
    };

    drawPolygon(carBody, this->color);

    Point pCenterWheel1 = applyRampTransform(Point(this->start.getX() + 46, this->start.getY() - 10), this->degrees);
    Wheel wheel1 = Wheel(pCenterWheel1, 22, this->wheelRotation, this->color); // Roda traseira

    Point pCenterWheel2 = applyRampTransform(Point(this->start.getX() + 213, this->start.getY() - 10), this->degrees);
    Wheel wheel2 = Wheel(pCenterWheel2, 22, this->wheelRotation, this->color); // Roda dianteira

    wheel1.draw();
    wheel2.draw();
}