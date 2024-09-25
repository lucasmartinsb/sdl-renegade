#ifndef RENEGADE_H
#define RENEGADE_H
#include <Point.h>
#include <Color.h>
#include <vector>
#include<SDL2/SDL.h>

class Renegade {
public:
    Renegade();

    Renegade(Point start, int wheelRotation, int degrees, Color color);

    Renegade(Point start, int wheelRotation, int degrees, Color color, int antialias);

    void draw();

    void drawPolygon(std::vector<Point> points, Color cor);

    virtual ~Renegade();

protected:

private:
    Point start;
    int wheelRotation;
    int degrees;
    Color color;
    int antialias = 0;

    double toRadians(int degrees);

    Point applyRampTransform(Point p, int degrees);
};

#endif // LINE_H