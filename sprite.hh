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
        tex = texture::load(file);
    }

    void init() override
    {
        pos = &ent->get_component<position_component>();
        
        src_rect.x = 0;
        src_rect.y = 0;
        src_rect.w = 24;
        src_rect.h = 24;

        dst_rect.w = 24;
        dst_rect.h = 24;
    }

    void update() override
    {
        dst_rect.x = pos->x();
        dst_rect.y = pos->y();
    }

    void draw() override
    {
        texture::draw(tex, src_rect, dst_rect);
    }

private:
    position_component* pos;
    SDL_Texture* tex;
    SDL_Rect src_rect, dst_rect;
};

#endif //SPRITE_HH_