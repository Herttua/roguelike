#ifndef SPRITE_HH_
#define SPRITE_HH_

#include <SDL2/SDL.h>
#include "components.hh"

class sprite : public component
{
public:
    sprite() = default;
    sprite(const char* file)
    {

    }

    void init() override
    {
        
    }

    void update() override
    {

    }

    void draw() override
    {
        
    }

private:
    position* pos;
    SDL_Texture* tex;
    SDL_Rect src_rect, dst_rect;
};

#endif //SPRITE_HH_