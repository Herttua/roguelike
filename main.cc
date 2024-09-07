#include "game.hh"

game* g = nullptr;

int main(int argc, char* argv[])
{
    const int FPS = 60;
    const int frame_delay = 1000 / FPS;
    Uint32    frame_start;
    int       frame_time;

    g = new game();
    g->init("Roguelike", SDL_WINDOWPOS_CENTERED, 
                         SDL_WINDOWPOS_CENTERED, 
                         640, 400, false);
    while(!g->quit())
    {
        frame_start = SDL_GetTicks();
        
        g->handle_events();
        g->update();
        g->render();

        frame_time = SDL_GetTicks() - frame_start;
        if(frame_delay > frame_time)
        {
            SDL_Delay(frame_delay - frame_time);
        }
    }
    g->clean();
    return 0;
}