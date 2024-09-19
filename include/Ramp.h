#ifndef WHEEL_H
#define WHEEL_H
#include <Point.h>
#include <Line.h>
#include <Ramp.h>
#include <Color.h>
#include<SDL2/SDL.h>

class Ramp
{
    public:
        Ramp();
        Ramp(Point start, int degrees, Color color);
        void setPixel(int x, int y, int r, int g, int b);
        void draw();
        virtual ~Ramp();

    protected:

    private:
        Point start;
        int degrees;
        Color color;
        void setPixel(int x, int y, int r, int g, int b, int a);
        void setPixel(int x, int y, Color color);
        void setPixel(int x, int y, Uint32 cor);
        double toRadians();
};

#endif // WHEEL_H
