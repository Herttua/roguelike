#include "object.hh"
#include "texture.hh"

object::object() {}
object::~object() 
{
    SDL_DestroyTexture(txtr);
}
object::object(const char* texture_sht, 
               int x, int y) : x_pos(x), y_pos(y)
{
    txtr = texture::load_texture(texture_sht);
}

void object::update()
{
    src_rect.w = 24;
    src_rect.h = 24;
    
    dst_rect.w = 24;
    dst_rect.h = 24;
    dst_rect.x = x_pos;
    dst_rect.y = y_pos;
}

void object::render()
{
    SDL_RenderCopy(game::renderer, txtr, &src_rect, &dst_rect);
}