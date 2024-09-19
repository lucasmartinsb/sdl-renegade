#include "Ramp.h"
#include "Circle.h"
#include "Line.h"
#include "Point.h"
#include "Context.h"
#include <cmath>

Ramp::Ramp()
{
    //ctor
}

Ramp::~Ramp()
{
    //dtor
}

Ramp::Ramp(Point start, int degrees, Color color) {
    this->start = start;
    this->degrees = degrees;
    this->color = color;
}

void Ramp::setPixel(int x, int y, Uint32 cor) {

    Color color = Color();
    Uint8 r = color.getColorComponent(cor, 'r');
    Uint8 g = color.getColorComponent(cor, 'g');
    Uint8 b = color.getColorComponent(cor, 'b');
    this->setPixel(x, y, r, g, b);
}

void Ramp::setPixel(int x, int y, Color color) {
	this->setPixel(x, y, color.getR(),color.getG(),color.getB());
}

void Ramp::setPixel(int x, int y, int r, int g, int b) {
    setPixel(x, y, r, g, b, 255);
}

void Ramp::setPixel(int x, int y, int r, int g, int b, int a) {
    unsigned int * pixels;
    SDL_Surface * window_surface = Context::getInstance()->getWindowSurface();
    pixels = (unsigned int *) window_surface->pixels;
    pixels[x + y * window_surface->w] = SDL_MapRGBA(window_surface->format, r, g, b, a);
}

double Ramp::toRadians() {
    return this->degrees * 0.017453293;
}

void Ramp::draw() {
    // Ponto inicial
    Point start = this->start;

    // Ângulo em radianos
    double angle = this->toRadians();

    // Definir um comprimento arbitrário para a linha
    int length = 700;

    // Calcular as coordenadas do ponto final com base no ângulo
    int xFinal = start.getX() + length * cos(angle);
    int yFinal = start.getY() - length * sin(angle); // Subtrair para que o ângulo positivo vá para cima

    // Criar o ponto final
    Point pFinal = Point(xFinal, yFinal);

    // Desenhar a linha
    Line line = Line(start, pFinal, this->color);
    line.draw();
}
