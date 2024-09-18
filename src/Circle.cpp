#include "Circle.h"
#include "Context.h"

Circle::Circle()
{
    //ctor
}

Circle::~Circle()
{
    //dtor
}

Circle::Circle(Point c, int radius, Color color) {
    this->c = c;
    this->radius = radius;
    this->color = color;
}

void Circle::setPixel(int x, int y, Uint32 cor) {

    Color color = Color();
    Uint8 r = color.getColorComponent(cor, 'r');
    Uint8 g = color.getColorComponent(cor, 'g');
    Uint8 b = color.getColorComponent(cor, 'b');
    this->setPixel(x, y, r, g, b);
}

void Circle::setPixel(int x, int y, Color color) {
	this->setPixel(x, y, color.getR(),color.getG(),color.getB());
}

void Circle::setPixel(int x, int y, int r, int g, int b) {
    setPixel(x, y, r, g, b, 255);
}

void Circle::setPixel(int x, int y, int r, int g, int b, int a) {
    unsigned int * pixels;
    SDL_Surface * window_surface = Context::getInstance()->getWindowSurface();
    pixels = (unsigned int *) window_surface->pixels;
    pixels[x + y * window_surface->w] = SDL_MapRGBA(window_surface->format, r, g, b, a);
}

void Circle::draw() {
    this->drawBresengamCircle();
}

void Circle::bresenhamCircle(int x, int y) {
    setPixel(this->c.getX()+x, this->c.getY()+y, this->color);
    setPixel(this->c.getX()-x, this->c.getY()+y, this->color);
    setPixel(this->c.getX()+x, this->c.getY()-y, this->color);
    setPixel(this->c.getX()-x, this->c.getY()-y, this->color);

    setPixel(this->c.getX()+y, this->c.getY()+x, this->color);
    setPixel(this->c.getX()-y, this->c.getY()+x, this->color);
    setPixel(this->c.getX()+y, this->c.getY()-x, this->color);
    setPixel(this->c.getX()-y, this->c.getY()-x, this->color);
}

void Circle::drawBresengamCircle() {
    int x = 0, y = this->radius;
    int decesionParameter = 3-2*this->radius;
    bresenhamCircle(x, y);
    while (y>=x) {
        x++;
        if(decesionParameter > 0) {
            y--;
            decesionParameter = decesionParameter + 4 * (x - y) + 10;
        }
        else {
            decesionParameter = decesionParameter + 4 * x + 6;
        }
        bresenhamCircle(x, y);
    }
}