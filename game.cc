#include "game.hh"

game::game() : exit(false) {} 
game::~game() {}

void game::init(const char* title, 
                int x, int y, 
                int w, int h,
                bool fullscreen) 
{
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        std::cout << "SDL initialized\n";
        
        int flags = 0;
        if(fullscreen)
        {
            flags = SDL_WINDOW_FULLSCREEN;
        }
        window = SDL_CreateWindow(title, x, y, w, h, flags);
        renderer = SDL_CreateRenderer(window, -1, 0);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        exit = false;
    }
    else
        exit = true;
}

void game::update()
{
    
}

void game::handle_events()
{
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type)
    {
    case SDL_QUIT:
        exit = true;
        break;
    
    default:
        break;
    }
}

void game::render()
{
    SDL_RenderClear(renderer);

    SDL_RenderPresent(renderer);
}

void game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "All cleaned up\n";
}
