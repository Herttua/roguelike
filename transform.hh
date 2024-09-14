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
        position.x = 0.0f;
        position.y = 0.0f;
    }
    transform(float x, float y) 
    {
        position.x = x;
        position.y = y;
    }

    ~transform() {}

    void init() override
    {
        velocity.x = 0.0f;
        velocity.y = 0.0f;
    }

    int x() { return position.x; }
    int y() { return position.y; }

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