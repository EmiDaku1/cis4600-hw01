#include "mat4.h"

#include <cmath>
#include <stdexcept>
#include <iostream>

// -----------------------------------------------------------------------------
// Constructors
// -----------------------------------------------------------------------------

mat4::mat4()
    : data{
        vec4(1.0f, 0.0f, 0.0f, 0.0f),
        vec4(0.0f, 1.0f, 0.0f, 0.0f),
        vec4(0.0f, 0.0f, 1.0f, 0.0f),
        vec4(0.0f, 0.0f, 0.0f, 1.0f)
    }
{}

mat4::mat4(float diag)
    : data {
        vec4(diag, 0.0f, 0.0f, 0.0f),
        vec4(0.0f, diag, 0.0f, 0.0f),
        vec4(0.0f, 0.0f, diag, 0.0f),
        vec4(0.0f, 0.0f, 0.0f, diag)
    }
{}

mat4::mat4(const vec4 &col0, const vec4 &col1, const vec4 &col2, const vec4& col3)
    : data {col0, col1, col2, col3}
{}

mat4::mat4(const mat4 &m2)
    : data {m2.data}
{}


// -----------------------------------------------------------------------------
// Getters
// -----------------------------------------------------------------------------

vec4 mat4::operator[](unsigned int index) const
{
    if (index > 3)
    {
        throw std::out_of_range("Index out of range");
    }

    return data[index];
}

vec4& mat4::operator[](unsigned int index)
{
    if (index > 3)
    {
        throw std::out_of_range("mat4 index out of range");
    }

    return data[index];
}


// -----------------------------------------------------------------------------
// Static Initializers
// -----------------------------------------------------------------------------

mat4 mat4::rotate(float angle, float x, float y, float z)
{
    const float pi = std::acos(-1.0f);
    float radians = angle * pi / 180.0f;

    float axisLength = std::sqrt(x * x + y * y + z * z);

    x /= axisLength;
    y /= axisLength;
    z /= axisLength;

    float c = std::cos(radians);
    float s = std::sin(radians);
    float t = 1.0f - c;

    vec4 col0(
        t * x * x + c,
        t * x * y + s * z,
        t * x * z - s * y,
        0.0f
        );

    vec4 col1(
        t * x * y - s * z,
        t * y * y + c,
        t * y * z + s * x,
        0.0f
        );

    vec4 col2(
        t * x * z + s * y,
        t * y * z - s * x,
        t * z * z + c,
        0.0f
        );

    vec4 col3(
        0.0f,
        0.0f,
        0.0f,
        1.0f
        );

    return mat4(col0, col1, col2, col3);
}

mat4 mat4::translate(float x, float y, float z) {
    return mat4(
        vec4(1.0f, 0.0f, 0.0f, 0.0f),
        vec4(0.0f, 1.0f, 0.0f, 0.0f),
        vec4(0.0f, 0.0f, 1.0f, 0.0f),
        vec4(x,    y,    z,    1.0f)
        );
}

mat4 mat4::scale(float x, float y, float z)
{
    return mat4(
        vec4(x,    0.0f, 0.0f, 0.0f),
        vec4(0.0f, y,    0.0f, 0.0f),
        vec4(0.0f, 0.0f, z,    0.0f),
        vec4(0.0f, 0.0f, 0.0f, 1.0f)
        );
}

mat4 mat4::identity()
{
    return mat4();
}

// -----------------------------------------------------------------------------
// Operator Functions
// -----------------------------------------------------------------------------

mat4& mat4::operator=(const mat4 &m2)
{
    if (this != &m2)
    {
        for (unsigned int i = 0; i < 4; ++i)
        {
            data[i] = m2.data[i];
        }
    }

    return *this;
}

bool mat4::operator==(const mat4 &m2) const
{
    for (unsigned int i = 0; i < 4; ++i)
    {
        if (data[i] != m2.data[i])
        {
            return false;
        }
    }

    return true;
}

/// Test for inequality
bool mat4::operator!=(const mat4 &m2) const
{
    return !(*this == m2);
}

// -----------------------------------------------------------------------------
// Arithmetic
// -----------------------------------------------------------------------------

mat4& mat4::operator+=(const mat4 &m2)
{
    for (unsigned int i = 0; i < 4; ++i)
    {
        data[i] += m2.data[i];
    }

    return *this;
}

mat4& mat4::operator-=(const mat4 &m2)
{
    for (unsigned int i = 0; i < 4; ++i)
    {
        data[i] -= m2.data[i];
    }

    return *this;
}

mat4& mat4::operator*=(float c)
{
    for (unsigned int i = 0; i < 4; ++i)
    {
        data[i] *= c;
    }

    return *this;
}

mat4& mat4::operator/=(float c){
    for (unsigned int i = 0; i < 4; ++i)
    {
        data[i] /= c;
    }

    return *this;
}

mat4  mat4::operator+(const mat4 &m2) const
{
    mat4 result(*this);
    result += m2;
    return result;
}

mat4  mat4::operator-(const mat4 &m2) const
{
    mat4 result(*this);
    result -= m2;
    return result;
}

mat4  mat4::operator*(float c) const
{
    mat4 result(*this);
    result *= c;
    return result;
}

mat4  mat4::operator/(float c) const
{
    mat4 result(*this);
    result /= c;
    return result;
}


mat4 mat4::operator*(const mat4 &m2) const
{
    mat4 mult(0.0f);

    for (unsigned int col = 0; col < 4; ++col)
    {
        for (unsigned int rowIndex = 0; rowIndex < 4; ++rowIndex)
        {
            mult[col][rowIndex] = dot(row(*this, rowIndex), m2[col]);
        }
    }

    return mult;
}

vec4 mat4::operator*(const vec4 &v) const
{
    vec4 mult;

    for (unsigned int i = 0; i < 4; ++i)
    {
        mult[i] = dot(row(*this, i), v);
    }

    return mult;
}

// -----------------------------------------------------------------------------
// Matrix Operations
// -----------------------------------------------------------------------------

mat4 transpose(const mat4 &m)
{
    return mat4(
            row(m, 0),
            row(m, 1),
            row(m, 2),
            row(m, 3)
            );
}

vec4 row(const mat4 &m, unsigned int index)
{
    if (index >= 4)
    {
        throw std::out_of_range("mat4 row index out of range");
    }

    return vec4(
        m[0][index],
        m[1][index],
        m[2][index],
        m[3][index]
        );
}


mat4 operator*(float c, const mat4 &m)
{
    return c * m;
}

vec4 operator*(const vec4 &v, const mat4 &m)
{
    vec4 result;

    for (unsigned int i = 0; i < 4; ++i)
    {
        result[i] = dot(v, m[i]);
    }

    return result;
}

std::ostream &operator<<(std::ostream &o, const mat4 &m)
{
    for (unsigned int r = 0; r < 4; ++r)
    {
        o << "[ ";

        for (unsigned int c = 0; c < 4; ++c)
        {
            o << m[c][r];

            if (c < 3)
            {
                o << " ";
            }
        }

        o << " ]";

        if (r < 3)
        {
            o << std::endl;
        }
    }

    return o;
}
