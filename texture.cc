#include "texture.hh"
#include "game.hh"

SDL_Texture* texture::load_texture(const char* file)
{
    SDL_Surface* tmp_srfc = IMG_Load(file);
    SDL_Texture* tex = SDL_CreateTextureFromSurface(game::renderer, tmp_srfc);
    SDL_FreeSurface(tmp_srfc);

    return tex;
}