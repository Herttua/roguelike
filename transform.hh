#ifndef TRANSFORM_HH_
#define TRANSFORM_HH_

#include "components.hh"
#include "vector2.hh"

class transform : public component
{
public:
    vector2 position;

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

    int x() { return position.x; }
    int y() { return position.y; }

    void update() override
    {
        position.x++;
    }

    void set_pos(float x, float y)
    {
        position.x = x;
        position.y = y;
    }    
};

#endif //TRANSFORM_HH_