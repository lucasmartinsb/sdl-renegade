#ifndef RENEGADE_H
#define RENEGADE_H
#include <Point.h>
#include <Color.h>
#include<SDL2/SDL.h>

class Renegade
{
    public:
        Renegade();
        Renegade(Point start, int wheelRotation, Color color);
        Renegade(Point start, int wheelRotation, Color color, int antialias);
        void draw();
        virtual ~Renegade();

    protected:

    private:
        Point start;
        int wheelRotation;
        Color color;
        int antialias = 0;

};

#endif // LINE_H
