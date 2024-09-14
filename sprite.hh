#ifndef SPRITE_HH_
#define SPRITE_HH_

#include <SDL2/SDL.h>
#include "components.hh"
//#include "texture.hh"

class sprite : public component
{
public:
    sprite() = default;
    sprite(const char* file)
    {
        set_tex(file);
    }
    ~sprite() { SDL_DestroyTexture(tex); }

    void set_tex(const char* file)
    {
        tex = texture::load(file);
    }

    void init() override
    {
        transf = &ent->get_component<transform>();
        
        src_rect.x = 0;
        src_rect.y = 0;
        src_rect.w = transf->width;
        src_rect.h = transf->height;

        dst_rect.w = transf->width * transf->scale;
        dst_rect.h = transf->height * transf->scale;
    }

    void update() override
    {
        dst_rect.x = static_cast<int>(transf->position.x);
        dst_rect.y = static_cast<int>(transf->position.y);
    }

    void draw() override
    {
        texture::draw(tex, src_rect, dst_rect);
    }

private:
    transform* transf;
    SDL_Texture* tex;
    SDL_Rect src_rect, dst_rect;
};

#endif //SPRITE_HH_