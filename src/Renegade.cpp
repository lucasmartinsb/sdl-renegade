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
    int xStart = this->start.getX();
    int yStart = this->start.getY() - 100;

    std::vector<Point> tailLight = {
        applyRampTransform(Point(xStart + 8, yStart + 48), this->degrees),
        applyRampTransform(Point(xStart + 6, yStart + 47), this->degrees),
        applyRampTransform(Point(xStart + 6, yStart + 34), this->degrees),
        applyRampTransform(Point(xStart + 11, yStart + 34), this->degrees),
        applyRampTransform(Point(xStart + 15, yStart + 35), this->degrees),
        applyRampTransform(Point(xStart + 15, yStart + 41), this->degrees),
        applyRampTransform(Point(xStart + 9, yStart + 48), this->degrees),
        applyRampTransform(Point(xStart + 8, yStart + 48), this->degrees),
        applyRampTransform(Point(xStart + 8, yStart + 48), this->degrees)
    };

    std::vector<Point> carHandle1 = {
        applyRampTransform(Point(xStart + 133, yStart + 44), this->degrees),
        applyRampTransform(Point(xStart + 118, yStart + 44), this->degrees),
        applyRampTransform(Point(xStart + 116, yStart + 46), this->degrees),
        applyRampTransform(Point(xStart + 118, yStart + 48), this->degrees),
        applyRampTransform(Point(xStart + 133, yStart + 48), this->degrees),
        applyRampTransform(Point(xStart + 135, yStart + 47), this->degrees),
        applyRampTransform(Point(xStart + 133, yStart + 44), this->degrees),
        applyRampTransform(Point(xStart + 133, yStart + 44), this->degrees)
    };

    std::vector<Point> carHandle2 = {
        applyRampTransform(Point(xStart + 74, yStart + 44), this->degrees),
        applyRampTransform(Point(xStart + 59, yStart + 44), this->degrees),
        applyRampTransform(Point(xStart + 57, yStart + 46), this->degrees),
        applyRampTransform(Point(xStart + 59, yStart + 47), this->degrees),
        applyRampTransform(Point(xStart + 74, yStart + 47), this->degrees),
        applyRampTransform(Point(xStart + 75, yStart + 46), this->degrees),
        applyRampTransform(Point(xStart + 74, yStart + 44), this->degrees),
        applyRampTransform(Point(xStart + 74, yStart + 44), this->degrees)
    };

    std::vector<Point> window = {
        applyRampTransform(Point(xStart + 179, yStart + 34), this->degrees),
        applyRampTransform(Point(xStart + 158, yStart + 9), this->degrees),
        applyRampTransform(Point(xStart + 147, yStart + 7), this->degrees),
        applyRampTransform(Point(xStart + 107, yStart + 5), this->degrees),
        applyRampTransform(Point(xStart + 65, yStart + 5), this->degrees),
        applyRampTransform(Point(xStart + 48, yStart + 6), this->degrees),
        applyRampTransform(Point(xStart + 42, yStart + 7), this->degrees),
        applyRampTransform(Point(xStart + 42, yStart + 23), this->degrees),
        applyRampTransform(Point(xStart + 44, yStart + 26), this->degrees),
        applyRampTransform(Point(xStart + 75, yStart + 34), this->degrees),
        applyRampTransform(Point(xStart + 112, yStart + 36), this->degrees),
        applyRampTransform(Point(xStart + 169, yStart + 37), this->degrees),
        applyRampTransform(Point(xStart + 179, yStart + 34), this->degrees),
        applyRampTransform(Point(xStart + 179, yStart + 34), this->degrees)
    };

    std::vector<Point> frontWindow = {
        applyRampTransform(Point(xStart + 194, yStart + 34), this->degrees),
        applyRampTransform(Point(xStart + 192, yStart + 29), this->degrees),
        applyRampTransform(Point(xStart + 161, yStart + 4), this->degrees),
        applyRampTransform(Point(xStart + 162, yStart + 7), this->degrees),
        applyRampTransform(Point(xStart + 185, yStart + 29), this->degrees),
        applyRampTransform(Point(xStart + 190, yStart + 32), this->degrees),
        applyRampTransform(Point(xStart + 194, yStart + 34), this->degrees),
        applyRampTransform(Point(xStart + 194, yStart + 34), this->degrees)
    };

    std::vector<Point> door1 = {
        applyRampTransform(Point(xStart + 57, yStart + 29), this->degrees),
        applyRampTransform(Point(xStart + 54, yStart + 34), this->degrees),
        applyRampTransform(Point(xStart + 52, yStart + 39), this->degrees),
        applyRampTransform(Point(xStart + 52, yStart + 65), this->degrees),
        applyRampTransform(Point(xStart + 52, yStart + 65), this->degrees),
        applyRampTransform(Point(xStart + 52, yStart + 39), this->degrees),
        applyRampTransform(Point(xStart + 54, yStart + 34), this->degrees),
        applyRampTransform(Point(xStart + 57, yStart + 29), this->degrees)
    };

    std::vector<Point> door2 = {
        applyRampTransform(Point(xStart + 107, yStart + 5), this->degrees),
        applyRampTransform(Point(xStart + 112, yStart + 35), this->degrees),
        applyRampTransform(Point(xStart + 113, yStart + 46), this->degrees),
        applyRampTransform(Point(xStart + 118, yStart + 93), this->degrees),
        applyRampTransform(Point(xStart + 118, yStart + 93), this->degrees),
        applyRampTransform(Point(xStart + 113, yStart + 46), this->degrees),
        applyRampTransform(Point(xStart + 112, yStart + 35), this->degrees),
        applyRampTransform(Point(xStart + 107, yStart + 5), this->degrees)
    };

    std::vector<Point> door3 = {
        applyRampTransform(Point(xStart + 179, yStart + 34), this->degrees),
        applyRampTransform(Point(xStart + 183, yStart + 41), this->degrees),
        applyRampTransform(Point(xStart + 185, yStart + 54), this->degrees),
        applyRampTransform(Point(xStart + 185, yStart + 66), this->degrees),
        applyRampTransform(Point(xStart + 181, yStart + 82), this->degrees),
        applyRampTransform(Point(xStart + 177, yStart + 93), this->degrees),
        applyRampTransform(Point(xStart + 177, yStart + 93), this->degrees),
        applyRampTransform(Point(xStart + 181, yStart + 82), this->degrees),
        applyRampTransform(Point(xStart + 185, yStart + 66), this->degrees),
        applyRampTransform(Point(xStart + 185, yStart + 54), this->degrees),
        applyRampTransform(Point(xStart + 183, yStart + 41), this->degrees),
        applyRampTransform(Point(xStart + 179, yStart + 34), this->degrees)
    };
    
    std::vector<Point> headLight = {
        applyRampTransform(Point(xStart + 254, yStart + 45), this->degrees),
        applyRampTransform(Point(xStart + 256, yStart + 44), this->degrees),
        applyRampTransform(Point(xStart + 257, yStart + 47), this->degrees),
        applyRampTransform(Point(xStart + 257, yStart + 55), this->degrees),
        applyRampTransform(Point(xStart + 257, yStart + 57), this->degrees),
        applyRampTransform(Point(xStart + 256, yStart + 57), this->degrees),
        applyRampTransform(Point(xStart + 254, yStart + 55), this->degrees),
        applyRampTransform(Point(xStart + 254, yStart + 45), this->degrees),
        applyRampTransform(Point(xStart + 254, yStart + 45), this->degrees)
    };

    std::vector<Point> carBody = {
        applyRampTransform(Point(this->start.getX() + 16, yStart + 89), this->degrees),
        applyRampTransform(Point(this->start.getX() + 20, yStart + 89), this->degrees),
        applyRampTransform(Point(this->start.getX() + 29, yStart + 64), this->degrees),
        applyRampTransform(Point(this->start.getX() + 61, yStart + 65), this->degrees),
        applyRampTransform(Point(this->start.getX() + 74, yStart + 92), this->degrees),
        applyRampTransform(Point(this->start.getX() + 184, yStart + 93), this->degrees),
        applyRampTransform(Point(this->start.getX() + 194, yStart + 65), this->degrees),
        applyRampTransform(Point(this->start.getX() + 232, yStart + 65), this->degrees),
        applyRampTransform(Point(this->start.getX() + 240, yStart + 92), this->degrees),
        applyRampTransform(Point(this->start.getX() + 248, yStart + 92), this->degrees),
        applyRampTransform(Point(this->start.getX() + 256, yStart + 86), this->degrees),
        applyRampTransform(Point(this->start.getX() + 256, yStart + 83), this->degrees),
        applyRampTransform(Point(this->start.getX() + 265, yStart + 71), this->degrees),
        applyRampTransform(Point(this->start.getX() + 265, yStart + 67), this->degrees),
        applyRampTransform(Point(this->start.getX() + 263, yStart + 65), this->degrees),
        applyRampTransform(Point(this->start.getX() + 263, yStart + 59), this->degrees),
        applyRampTransform(Point(this->start.getX() + 259, yStart + 56), this->degrees),
        applyRampTransform(Point(this->start.getX() + 257, yStart + 55), this->degrees),
        applyRampTransform(Point(this->start.getX() + 257, yStart + 47), this->degrees),
        applyRampTransform(Point(this->start.getX() + 256, yStart + 44), this->degrees),
        applyRampTransform(Point(this->start.getX() + 246, yStart + 37), this->degrees),
        applyRampTransform(Point(this->start.getX() + 227, yStart + 33), this->degrees),
        applyRampTransform(Point(this->start.getX() + 192, yStart + 29), this->degrees),
        applyRampTransform(Point(this->start.getX() + 161, yStart + 4), this->degrees),
        applyRampTransform(Point(this->start.getX() + 125, yStart + 1), this->degrees),
        applyRampTransform(Point(this->start.getX() + 74, yStart + 0), this->degrees),
        applyRampTransform(Point(this->start.getX() + 28, yStart + 3), this->degrees),
        applyRampTransform(Point(this->start.getX() + 17, yStart + 4), this->degrees),
        applyRampTransform(Point(this->start.getX() + 13, yStart + 4), this->degrees),
        applyRampTransform(Point(this->start.getX() + 12, yStart + 6), this->degrees),
        applyRampTransform(Point(this->start.getX() + 16, yStart + 9), this->degrees),
        applyRampTransform(Point(this->start.getX() + 9, yStart + 28), this->degrees),
        applyRampTransform(Point(this->start.getX() + 7, yStart + 31), this->degrees),
        applyRampTransform(Point(this->start.getX() + 6, yStart + 35), this->degrees),
        applyRampTransform(Point(this->start.getX() + 6, yStart + 47), this->degrees),
        applyRampTransform(Point(this->start.getX() + 5, yStart + 47), this->degrees),
        applyRampTransform(Point(this->start.getX() + 5, yStart + 52), this->degrees),
        applyRampTransform(Point(this->start.getX() + 3, yStart + 63), this->degrees),
        applyRampTransform(Point(this->start.getX() + 1, yStart + 65), this->degrees),
        applyRampTransform(Point(this->start.getX() + 2, yStart + 77), this->degrees),
        applyRampTransform(Point(this->start.getX() + 10, yStart + 87), this->degrees),
        applyRampTransform(Point(this->start.getX() + 16, yStart + 89), this->degrees),
        applyRampTransform(Point(this->start.getX() + 16, yStart + 89), this->degrees)
    };

    Point pCenterWheel1 = applyRampTransform(Point(this->start.getX() + 46, this->start.getY() - 10), this->degrees);
    Wheel wheel1 = Wheel(pCenterWheel1, 22, this->wheelRotation, this->color); // Roda traseira

    Point pCenterWheel2 = applyRampTransform(Point(this->start.getX() + 213, this->start.getY() - 10), this->degrees);
    Wheel wheel2 = Wheel(pCenterWheel2, 22, this->wheelRotation, this->color); // Roda dianteira

    wheel1.draw();
    wheel2.draw();
    
    drawPolygon(tailLight, this->color);
    drawPolygon(carHandle1, this->color);
    drawPolygon(carHandle2, this->color);
    drawPolygon(window, this->color);
    drawPolygon(frontWindow, this->color);
    drawPolygon(door1, this->color);
    drawPolygon(door2, this->color);
    drawPolygon(door3, this->color);
    drawPolygon(headLight, this->color);
    drawPolygon(carBody, this->color);
}