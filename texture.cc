#include "texture.hh"
#include "game.hh"

SDL_Texture* texture::load(const char* file)
{
    SDL_Surface* tmp_srfc = IMG_Load(file);
    SDL_Texture* tex = SDL_CreateTextureFromSurface(game::renderer, tmp_srfc);
    SDL_FreeSurface(tmp_srfc);

    return tex;
}

void texture::draw(SDL_Texture* txtr, SDL_Rect src, SDL_Rect dst)
{
    SDL_RenderCopy(game::renderer, txtr, NULL, &dst);
}