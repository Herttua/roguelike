#include "game.hh"

game* g = nullptr;

int main(int argc, char* argv[])
{
    g = new game();
    g->init("Roguelike", SDL_WINDOWPOS_CENTERED, 
                         SDL_WINDOWPOS_CENTERED, 
                         640, 400, false);
    while(!g->quit())
    {
        g->handle_events();
        g->update();
        g->render();
    }
    g->clean();
    return 0;
}