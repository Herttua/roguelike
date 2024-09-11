#ifndef TRANSFORM_HH_
#define TRANSFORM_HH_

#include "components.hh"

class transform : public component
{
public:
    transform() : x_pos(0), y_pos(0) {}
    transform(int x, int y) : x_pos(x), y_pos(y) {}

    int x() { return x_pos; }
    int y() { return y_pos; }

    void update() override
    {
        //x_pos++;
    }

    void set_pos(int x, int y)
    {
        x_pos = x;
        y_pos = y;
    }

private:
    int x_pos;
    int y_pos;
};

#endif //TRANSFORM_HH_