#ifndef POSITION_HH_
#define POSITION_HH_

#include "components.hh"

class position_component : public component
{
public:
    int x() { return x_pos; }
    int y() { return y_pos; }

    void init() override
    {
        x_pos = 0;
        y_pos = 0;
    }

    void update() override
    {
        x_pos++;
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

#endif //POSITION_HH_