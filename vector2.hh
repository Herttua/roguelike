#ifndef VECTOR2_HH_
#define VECTOR2_HH_

#include <iostream>

class vector2
{
    float x;
    float y;

    vector2();
    vector2(float x_pos, float y_pos);
    ~vector2();

    vector2& add(const vector2& vec);
    vector2& subtract(const vector2& vec);
    vector2& multiply(const vector2& vec);
    vector2& divide(const vector2& vec);

    friend vector2& operator+(vector2& v1, const vector2& v2);
    friend vector2& operator-(vector2& v1, const vector2& v2);
    friend vector2& operator*(vector2& v1, const vector2& v2);
    friend vector2& operator/(vector2& v1, const vector2& v2);

    vector2& operator+=(const vector2& vec);
    vector2& operator-=(const vector2& vec);
    vector2& operator*=(const vector2& vec);
    vector2& operator/=(const vector2& vec);

    friend std::ostream& operator<<(std::ostream& stream, const vector2& vec); 
};

#endif //VECTOR2_HH_