#define SDL_MAIN_HANDLED
#include<SDL2/SDL.h>
#include<stdio.h>
#include <unistd.h>

#include<Context.h>
#include<Color.h>
#include<Point.h>
#include<Line.h>
#include<Renegade.h>
#include<Ramp.h>

// SDL stuff
SDL_Window *pWindow = nullptr;
SDL_Renderer *pRenderer = nullptr;
SDL_Surface *window_surface = nullptr;

Renegade *renegade = nullptr;

void display() {
    int degrees = -30; // Inclinação da rampa
    Color color = Color(0, 0, 0);

    // Movimenta o carro na rampa
    renegade->moveOnRamp(degrees);
    renegade->draw();

    Point pRamp = Point(55, 479);
    Ramp ramp = Ramp(pRamp, -degrees, color);
    ramp.draw();
}

void clear() {
    Line l = Line();
    SDL_Surface *window_surface = Context::getInstance()->getWindowSurface();
    for (int x = 0; x < window_surface->w; x++) {
        for (int y = 0; y < window_surface->h; y++) {
            l.setPixel(x, y, 255, 255, 255);
        }
    }
}

// Driver code
int main(int argc, char *args[]) {
    SDL_Event event;

    // initialize SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) >= 0) {
        // if succeeded create our window
        pWindow = SDL_CreateWindow("SDL_Renegade",
                                   SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                   640, 480,
                                   SDL_WINDOW_SHOWN);

        // if the window creation succeeded create our renderer
        if (pWindow != 0) {
            window_surface = SDL_GetWindowSurface(pWindow);

            // Inicializa o contexto gráfico da aplicação
            Context *context = Context::getInstance();
            context->setWindowSurface(window_surface);

            // Inicializa o Renegade
            Point startPoint = Point(40, 500);
            Color renegadeColor = Color(0, 0, 0);
            renegade = new Renegade(startPoint, 10, -30, renegadeColor);
        }
    } else
        return 1; // sdl could not initialize

    while (1) {
        // Limpa a tela
        clear();

        // Realiza o desenho
        display();

        // Aguarda instantes
        usleep(60000);

        // Verifica se foi mandado fechar a janela
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                delete renegade;
                SDL_Quit();
                return 0;
            }
        }

        // Atualiza a tela
        SDL_UpdateWindowSurface(pWindow);
    }

    return 0;
}
