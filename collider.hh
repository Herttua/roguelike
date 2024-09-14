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
};

#define //COLLIDER_HH_