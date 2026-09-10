#include "vec4.h"

#include <cmath>
#include <stdexcept>
#include <iostream>

// -----------------------------------------------------------------------------
// Constructors
// -----------------------------------------------------------------------------

vec4::vec4()
    : data{0.0f, 0.0f, 0.0f, 0.0f}
{}

vec4::vec4(float x, float y, float z, float w)
    : data{x, y, z, w}
{}

vec4::vec4(const vec4 &v2)
    : data{v2.data}
{}

// -----------------------------------------------------------------------------
// Getters/Setters
// -----------------------------------------------------------------------------

float vec4::operator[](unsigned int index) const
{
    if (index > 3 ) {
        throw std::out_of_range("Index out of range");
    }

    return data[index];
}

float& vec4::operator[](unsigned int index)
{
    if (index > 3 ) {
        throw std::out_of_range("Index out of range");
    }

    return data[index];
}

// -----------------------------------------------------------------------------
// Operator Functions
// -----------------------------------------------------------------------------

vec4& vec4::operator=(const vec4 &v2)
{

    if (this != &v2) {
        for (unsigned int i = 0; i < 4; ++i) {
            data[i] = v2.data[i];
        }
    }

    return *this;
}

bool vec4::operator==(const vec4 &v2) const
{
    for (unsigned int i = 0; i < 4; ++i) {
        if (data[i] != v2.data[i]) {
            return false;
        }
    }

    return true;
}

bool vec4::operator!=(const vec4 &v2) const
{
    return !(*this == v2);
}

// -----------------------------------------------------------------------------
// Arithmetic
// -----------------------------------------------------------------------------

vec4& vec4::operator+=(const vec4 &v2)
{
    for (unsigned int i = 0; i < 4; ++i) {
        data[i] += v2.data[i];
    }

    return *this;
}

vec4& vec4::operator-=(const vec4 &v2)
{
    for (unsigned int i = 0; i < 4; ++i) {
        data[i] -= v2.data[i];
    }

    return *this;
}

vec4& vec4::operator*=(float c)
{
    for (unsigned int i = 0; i < 4; ++i) {
        data[i] *= c;
    }

    return *this;
}

vec4& vec4::operator/=(float c)
{
    for (unsigned int i = 0; i < 4; ++i) {
        data[i] /= c;
    }

    return *this;
}


vec4 vec4::operator+(const vec4 &v2) const
{
    vec4 add(*this);
    add += v2;
    return add;
}

vec4 vec4::operator-(const vec4 &v2) const
{
    vec4 sub(*this);
    sub -= v2;
    return sub;
}

vec4 vec4::operator*(float c) const
{
    vec4 mult(*this);
    mult *= c;
    return mult;
}

vec4 vec4::operator/(float c) const
{
    vec4 div(*this);
    div /= c;
    return div;
}


float dot(const vec4 &v1, const vec4 &v2)
{
    float dot = 0.0f;

    for (unsigned int i = 0; i < 4; ++i) {
        dot += v1[i] * v2[i];
    }

    return dot;
}

vec4 cross(const vec4 &v1, const vec4 &v2)
{
    return vec4(
        v1[1] * v2[2] - v1[2] * v2[1],
        v1[2] * v2[0] - v1[0] * v2[2],
        v1[0] * v2[1] - v1[1] * v2[0],
        0.0f
    );
}


float length(const vec4 &v)
{
    return std::sqrt(dot(v, v));
}

vec4 operator*(float c, const vec4 &v)
{
    return v * c;
}

vec4 normalize(const vec4& v)
{
    return (v / length(v));
}

std::ostream &operator<<(std::ostream &o, const vec4 &v)
{
    o << "("
      << v[0] << ", "
      << v[1] << ", "
      << v[2] << ", "
      << v[3]
      << ")";

    return o;
}
