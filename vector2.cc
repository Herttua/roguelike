#include "vector2.hh"

vector2::~vector2() {}

vector2::vector2()
{
    x = 0.0f;
    y = 0.0f;
}

vector2::vector2(float x, float y)
{
    this->x = x;
    this->y = y;
}

vector2& vector2::add(const vector2& vec)
{
    this->x += vec.x;
    this->y += vec.y;

    return *this;
}

vector2& vector2::subtract(const vector2& vec)
{
    this->x -= vec.x;
    this->y -= vec.y;

    return *this;
}

vector2& vector2::multiply(const vector2& vec)
{
    this->x *= vec.x;
    this->y *= vec.y;

    return *this;
}

vector2& vector2::divide(const vector2& vec)
{
    this->x /= vec.x;
    this->y /= vec.y;

    return *this;
}

vector2& operator+(vector2& v1, const vector2& v2)
{
    return v1.add(v2);
}

vector2& operator-(vector2& v1, const vector2& v2)
{
    return v1.subtract(v2);
}

vector2& operator*(vector2& v1, const vector2& v2)
{
    return v1.multiply(v2);
}

vector2& operator/(vector2& v1, const vector2& v2)
{
    return v1.divide(v2);
}

vector2& vector2::operator+=(const vector2& vec)
{
    return this->add(vec);
}

vector2& vector2::operator-=(const vector2& vec)
{
    return this->subtract(vec);
}

vector2& vector2::operator*=(const vector2& vec)
{
    return this->multiply(vec);
}

vector2& vector2::operator/=(const vector2& vec)
{
    return this->divide(vec);
}

std::ostream& operator<<(std::ostream& stream, const vector2& vec)
{
    stream << "(" << vec.x << "," << vec.y << ")";
    return stream;
}