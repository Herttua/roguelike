#ifndef TRANSFORM_HH_
#define TRANSFORM_HH_

#include "components.hh"
#include "vector2.hh"

class transform : public component
{
public:
    vector2 position;
    vector2 velocity;
    
    int speed   = 3;

    int width   = 24;
    int height  = 24;
    int scale   = 1;

    transform() 
    {
        position.zero();
    }
    transform(int sc)
    {
        position.zero();
        scale = sc;
    }
    transform(float x, float y, int w, int h, int sc) 
    {
        position.x = x;
        position.y = y;
        width = w;
        height = h;
        scale = sc;
    }

    ~transform() {}

    void init() override
    {
        velocity.x = 0.0f;
        velocity.y = 0.0f;
    }

    int x() { return position.x; }
    int y() { return position.y; }

    void move_one_tile(int direction)
    {
        switch(direction)
        {
            case 0: position.x = position.x + 32;
                break;

            default: break;
        }
    }

    void update() override
    {
        position.x += velocity.x * speed;
        position.y += velocity.y * speed;
    }

    void set_pos(float x, float y)
    {
        position.x = x;
        position.y = y;
    }    
};

#endif //TRANSFORM_HH_