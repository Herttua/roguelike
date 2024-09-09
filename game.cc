#include "game.hh"
#include "texture.hh"
#include "object.hh"
#include "tilemap.hh"
#include "component_system.hh"
#include "components.hh"

SDL_Renderer* game::renderer = nullptr;
object* obj;
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

    obj = new object("assets/wizard.png", 72, 72);
    world = new tilemap();
    player.add_component<position_component>();
}

void game::update()
{
    obj->update();
    mastr.update();
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
    obj->render();

    ///RENDER END///
    SDL_RenderPresent(renderer);
}

void game::clean()
{
    delete obj;
    delete world;

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "All cleaned up\n";
}
