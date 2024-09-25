#ifndef RENEGADE_H
#define RENEGADE_H
#include <Point.h>
#include <Color.h>
#include <vector>
#include<SDL2/SDL.h>
#include "PolygonDrawer.h"

class Renegade {
private:
    Point start;
    int wheelRotation;
    int degrees;
    Color color;
    int offsetX;
    int startY;
    PolygonDrawer polygonDrawer;

public:
    Renegade(Point start, int wheelRotation, int degrees, Color color);

    ~Renegade();

    void draw();

    void moveOnRamp(int rampDegrees);

    double toRadians(int degrees);

    Point applyRampTransform(Point p, int degrees);
};

#endif // RENEGAD_H
