#ifndef COLLISION_HH_
#define COLLISION_HH_

#include <SDL2/SDL.h>

class collision
{
public:     
    static bool aabb(const SDL_Rect& a, const SDL_Rect& b);
};

#endif //COLLISION_HH_