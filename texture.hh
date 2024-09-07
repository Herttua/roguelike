#ifndef TEXTURE_HH_
#define TEXTURE_HH_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class texture
{
public:
    static SDL_Texture* load_texture(const char* file, SDL_Renderer* ren);
};

#endif //TEXTURE_HH_