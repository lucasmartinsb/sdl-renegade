#ifndef WHEEL_H
#define WHEEL_H
#include <Point.h>
#include <Wheel.h>
#include <Color.h>
#include<SDL2/SDL.h>

class Wheel
{
    public:
        Wheel();
        Wheel(Point c, int degrees, Color color);
        void setPixel(int x, int y, int r, int g, int b);
        void draw();
        virtual ~Wheel();

    protected:

    private:
        Point c;
        Color color;
        int degrees;
        void setPixel(int x, int y, int r, int g, int b, int a);
        void setPixel(int x, int y, Color color);
        void setPixel(int x, int y, Uint32 cor);
        double toRadians(int degrees);

};

#endif // WHEEL_H
