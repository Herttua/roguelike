#ifndef OBJECT_HH_
#define OBJECT_HH_

#include "game.hh"

class object
{
public:
    object();
    object(const char* texture_sht, 
           SDL_Renderer* r,
           int x, int y);
    ~object();

    void update();
    void render();

private:
    int x_pos;
    int y_pos;
    SDL_Texture* txtr;
    SDL_Rect src_rect, dst_rect;
    SDL_Renderer* rend;
};

#endif //OBJECT_HH_