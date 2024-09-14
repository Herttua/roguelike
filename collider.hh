#ifndef COLLIDER_HH_
#define COLLIDER_HH_

#include <string>
#include "components.hh"

class collider : public component
{
public:
    SDL_Rect    box;
    std::string tag;
    transform*   transf;

    collider(std::string t) : tag(t) {}

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
        box.x = static_cast<int>(transf->position.x);
        box.y = static_cast<int>(transf->position.y);
        box.w = transf->width * transf->scale;
        box.h = transf->height * transf->scale;
    }
};

#endif //COLLIDER_HH_