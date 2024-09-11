#ifndef VECTOR2_HH_
#define VECTOR2_HH_

class vector2
{
    float x;
    float y;

    vector2() {}
    vector2(float x_pos, float y_pos) : x(x_pos), y(y_pos) {}
    ~vector2() {}

    vector2& add(const vector2& vec);
    vector2& subtract(const vector2& vec);
    vector2& multiply(const vector2& vec);
    vector2& divide(const vector2& vec);

    friend vector2& operator+(vector2& v1, const vector2& v2); 
};

#endif //VECTOR2_HH_