#ifndef KEYBOARD_HH_
#define KEYBOARD_HH_

#include "game.hh"
#include "components.hh"

class keyboard : public component
{
public:
    transform *transf;
    const Uint8* keystates = SDL_GetKeyboardState(NULL); 

    void init() override
    {
        transf = &ent->get_component<transform>();
    }

    void update() override
    {
        transf->velocity.x = 0;
		transf->velocity.y = 0;

		if (keystates[SDL_SCANCODE_UP]) 
        {
		    
		}
		if (keystates[SDL_SCANCODE_LEFT]) 
        {
			
		}
		if (keystates[SDL_SCANCODE_DOWN]) 
        {
			
		}
		if (keystates[SDL_SCANCODE_RIGHT]) 
        {
			transf->move_one_tile(0);
		}
    }
};

#endif //KEYBOARD_HH_