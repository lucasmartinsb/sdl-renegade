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

Wheel::Wheel(Point c, int degrees, Color color) {
    this->c = c;
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
    int radius = 30;

    // Coordenadas do centro da linha
    int centerX = this->c.getX();
    int centerY = this->c.getY();

    // Calcular o ângulo em radianos
    double angle = this->toRadians(this->degrees);

    // Calcular as extremidades da linha em relação ao centro
    int x1 = centerX - radius;
    int y1 = centerY;

    int x2 = centerX + radius;
    int y2 = centerY;

    // Rotacionar os pontos ao redor do centro usando transformações de rotação
    int rotatedX1 = centerX + (x1 - centerX) * cos(angle) - (y1 - centerY) * sin(angle);
    int rotatedY1 = centerY + (x1 - centerX) * sin(angle) + (y1 - centerY) * cos(angle);

    int rotatedX2 = centerX + (x2 - centerX) * cos(angle) - (y2 - centerY) * sin(angle);
    int rotatedY2 = centerY + (x2 - centerX) * sin(angle) + (y2 - centerY) * cos(angle);

    // Criar pontos rotacionados
    Point p1 = Point(rotatedX1, rotatedY1);
    Point p2 = Point(rotatedX2, rotatedY2);

    // Desenhar a linha rotacionada
    Line raio1 = Line(p1, p2, this->color);


    // Calcular as extremidades da linha em relação ao centro
    int x3 = centerX;
    int y3 = centerY - radius;

    int x4 = centerX;
    int y4 = centerY + radius;

    // Rotacionar os pontos ao redor do centro usando transformações de rotação
    int rotatedX3 = centerX + (x3 - centerX) * cos(angle) - (y3 - centerY) * sin(angle);
    int rotatedY3 = centerY + (x3 - centerX) * sin(angle) + (y3 - centerY) * cos(angle);

    int rotatedX4 = centerX + (x4 - centerX) * cos(angle) - (y4 - centerY) * sin(angle);
    int rotatedY4 = centerY + (x4 - centerX) * sin(angle) + (y4 - centerY) * cos(angle);

    // Criar pontos rotacionados
    Point p3 = Point(rotatedX3, rotatedY3);
    Point p4 = Point(rotatedX4, rotatedY4);

    // Desenhar a linha rotacionada
    Line raio2 = Line(p3, p4, this->color);

    Circle circulo = Circle(this->c, radius, this->color);

    circulo.draw();
    raio1.draw();
    raio2.draw();
}
