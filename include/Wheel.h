#ifndef WHEEL_H
#define WHEEL_H
#include <Point.h>
#include <Line.h>
#include <Wheel.h>
#include <Color.h>
#include<SDL2/SDL.h>

class Wheel
{
    public:
        Wheel();
        Wheel(Point c, int radius, int wheelRotation, Color color);
        void setPixel(int x, int y, int r, int g, int b);
        void draw();
        virtual ~Wheel();

    protected:

    private:
        Point c;
        Color color;
        int wheelRotation;
        int radius;
        void setPixel(int x, int y, int r, int g, int b, int a);
        void setPixel(int x, int y, Color color);
        void setPixel(int x, int y, Uint32 cor);
        double toRadians(int wheelRotation);
        Line raio(double plusAngle);
};

#endif // WHEEL_H
