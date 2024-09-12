#include "game.hh"
#include "texture.hh"
#include "tilemap.hh"
#include "components.hh"

SDL_Renderer* game::renderer = nullptr;
tilemap* world;

master mastr;
auto& player(mastr.add_entity());

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
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        exit = false;
    }
    else
        exit = true;

    world = new tilemap();
    player.add_component<transform>(50, 50);
    player.add_component<sprite>("assets/wizard.png");
}

void game::update()
{
    mastr.refresh();
    mastr.update();

    if(player.get_component<transform>().x() > 150)
    {
        player.get_component<transform>().set_pos(200, 300);
    }
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
    ///RENDER START///

    world->draw();
    mastr.draw();

    ///RENDER END///
    SDL_RenderPresent(renderer);
}

void game::clean()
{
    delete world;

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "All cleaned up\n";
}
