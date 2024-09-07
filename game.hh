#ifndef GAME_HH_
#define GAME_HH_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

class game
{
public:
    game();
    ~game();

    void init(const char* title, 
              int x, int y, 
              int w, int h,
              bool fullscreen);
    void update();
    void handle_events();
    void render();
    void clean();
    bool quit() { return exit; }

private:
    bool exit;
    SDL_Window*   window;
    SDL_Renderer* renderer;
};

#endif //GAME_HH_