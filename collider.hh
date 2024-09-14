#ifndef COLLIDER_HH_
#define COLLIDER_HH_

#include <string>
#include "components.hh"

class collider : public component
{
public:
    SDL_Rect    box;
    std::string tag;
    transform   transf;

    void init() override
    {
        if(!ent->has_component<transform>())
        {
            ent->add_component<transform>();
        }
        transf = &ent->get_component<transform>();
    }

    void update() override
    {
        box.x = transf->position.x;
        box.y = transf->position.y;
        box.w = transf->width * transf->scale;
        box.h = transf->height * transf->scale;
    }
};

#define //COLLIDER_HH_