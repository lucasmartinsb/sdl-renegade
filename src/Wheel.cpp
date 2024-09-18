#include "Wheel.h"
#include "Circle.h"
#include "Line.h"
#include "Point.h"
#include "Context.h"
#include <cmath>

Wheel::Wheel()
{
    //ctor
}

Wheel::~Wheel()
{
    //dtor
}

Wheel::Wheel(Point c, int radius, int degrees, Color color) {
    this->c = c;
    this->radius = radius;
    this->degrees = degrees;
    this->color = color;
}

void Wheel::setPixel(int x, int y, Uint32 cor) {

    Color color = Color();
    Uint8 r = color.getColorComponent(cor, 'r');
    Uint8 g = color.getColorComponent(cor, 'g');
    Uint8 b = color.getColorComponent(cor, 'b');
    this->setPixel(x, y, r, g, b);
}

void Wheel::setPixel(int x, int y, Color color) {
	this->setPixel(x, y, color.getR(),color.getG(),color.getB());
}

void Wheel::setPixel(int x, int y, int r, int g, int b) {
    setPixel(x, y, r, g, b, 255);
}

void Wheel::setPixel(int x, int y, int r, int g, int b, int a) {
    unsigned int * pixels;
    SDL_Surface * window_surface = Context::getInstance()->getWindowSurface();
    pixels = (unsigned int *) window_surface->pixels;
    pixels[x + y * window_surface->w] = SDL_MapRGBA(window_surface->format, r, g, b, a);
}

double Wheel::toRadians(int degrees) {
    return degrees * 0.017453293;
}

void Wheel::draw() {
    Line raio1 = this->raio(0);
    Line raio2 = this->raio(this->toRadians(45));
    Line raio3 = this->raio(this->toRadians(90));
    Line raio4 = this->raio(this->toRadians(135));
    Line raio5 = this->raio(this->toRadians(270));

    Circle circulo = Circle(this->c, this->radius, this->color);

    circulo.draw();
    raio1.draw();
    raio2.draw();
    raio3.draw();
    raio4.draw();
    raio5.draw();
}

Line Wheel::raio(double plusAngle) {
    // Raio vertical
    int x1 = this->c.getX() - this->radius;
    int y1 = this->c.getY();

    int x2 = this->c.getX() + this->radius;
    int y2 = this->c.getY();

    // Coordenadas do centro da linha
    int centerX = this->c.getX();
    int centerY = this->c.getY();

    // Ângulo em radianos
    double angle = this->toRadians(this->degrees) + plusAngle;

     // Rotaciona os pontos ao redor do centro usando transformações de rotação
    int rotatedX1 = centerX + (x1 - centerX) * cos(angle) - (y1 - centerY) * sin(angle);
    int rotatedY1 = centerY + (x1 - centerX) * sin(angle) + (y1 - centerY) * cos(angle);

    int rotatedX2 = centerX + (x2 - centerX) * cos(angle) - (y2 - centerY) * sin(angle);
    int rotatedY2 = centerY + (x2 - centerX) * sin(angle) + (y2 - centerY) * cos(angle);

    // Pontos rotacionados
    Point p1 = Point(rotatedX1, rotatedY1);
    Point p2 = Point(rotatedX2, rotatedY2);

    // Desenhar a linha rotacionada
    Line raio = Line(p1, p2, this->color);
    
    return raio;
}