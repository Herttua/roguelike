#include "game.hh"

SDL_Texture* player_text;
SDL_Rect dst_r;

game::game()  {} 
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

    SDL_Surface* tmp_srfc = IMG_Load("assets/wizard.png");
    player_text = SDL_CreateTextureFromSurface(renderer, tmp_srfc);
    SDL_FreeSurface(tmp_srfc);
}

void game::update()
{
    dst_r.w = 24;
    dst_r.h = 24;
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

    case SDL_KEYDOWN:
        {
            switch(event.key.keysym.sym)
            {
                case SDLK_ESCAPE:
                    exit = true;
                    break;
                default: break;
            }
        }
        break;
    
    default:
        break;
    }
}

void game::render()
{
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, player_text, 0, &dst_r);
    SDL_RenderPresent(renderer);
}

void game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyTexture(player_text);
    SDL_Quit();
    std::cout << "All cleaned up\n";
}
