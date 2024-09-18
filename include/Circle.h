#ifndef CIRCLE_H
#define CIRCLE_H
#include <Point.h>
#include <Circle.h>
#include <Color.h>
#include<SDL2/SDL.h>

class Circle
{
    public:
        Circle();
        Circle(Point c, int radius, Color color);
        void setPixel(int x, int y, int r, int g, int b);
        void draw();
        virtual ~Circle();

    protected:

    private:
        Point c;
        int radius;
        Color color;
        void setPixel(int x, int y, int r, int g, int b, int a);
        void setPixel(int x, int y, Color color);
        void setPixel(int x, int y, Uint32 cor);
        void drawBresengamCircle();
        void bresenhamCircle(int x, int y);

};

#endif // LINE_H
