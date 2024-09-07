#include "texture.hh"

SDL_Texture* texture::load_texture(const char* file, SDL_Renderer* ren)
{
    SDL_Surface* tmp_srfc = IMG_Load(file);
    SDL_Texture* tex = SDL_CreateTextureFromSurface(ren, tmp_srfc);
    SDL_FreeSurface(tmp_srfc);

    return tex;
}