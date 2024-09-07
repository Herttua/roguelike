#ifndef GAME_HH_
#define GAME_HH_

#include <SDL2/SDL.h>

class game
{
public:
    game() {}
    ~game() {}

    void init(const char* title, 
              int x, int y, 
              int w, int h,
              bool fullscreen);
    void update();
    void render();
    void clean();
    bool running();

private:
    bool quit;
    SDL_Window*   window;
    SDL_Renderer* renderer;
};

#endif //GAME_HH_