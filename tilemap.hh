#ifndef TILEMAP_HH_
#define TILEMAP_HH_

#include "texture.hh"

class tilemap
{
public:
    tilemap();
    ~tilemap();

    void load();
    void draw();

private:
    SDL_Rect src, dst;
    SDL_Texture* dirt;
    SDL_Texture* grass;
    SDL_Texture* water;

    int map[20][25];
};

#endif //TILEMAP_HH_