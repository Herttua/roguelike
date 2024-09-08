#include "tilemap.hh"
#include "texture.hh"

tilemap::~tilemap()
{
    SDL_DestroyTexture(grass);
    SDL_DestroyTexture(dirt);
    SDL_DestroyTexture(water);
}

tilemap::tilemap() 
{
    grass = texture::load_texture("assets/grass.png");
    dirt  = texture::load_texture("assets/dirt.png");
    water = texture::load_texture("assets/water.png");
}

void tilemap::load()
{

}

void tilemap::draw()
{

}