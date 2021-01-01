#include "pch.h"
#include "Vector4.h"
#include <cmath>

Vector4::Vector4()
{
    x = 0; y = 0; z = 0; w = 0;
}

Vector4::Vector4(float x, float y, float z, float w)
{
    this->x = x;
    this->y = y;
    this->z = z;
    this->w = w;
}

float Vector4::getMagnitude()
{
    return (float)sqrt(x * x + y * y + z * z + w * w);
}

Vector4 Vector4::getNormalized()
{
    return normalize(*this);
}

Vector4 Vector4::normalize(Vector4 vector)
{
    if (vector.getMagnitude() == 0)
        return Vector4();

    return vector / vector.getMagnitude();
}

float Vector4::dotProduct(Vector4 lhs, Vector4 rhs)
{
    return (lhs.x * rhs.x) + (lhs.y * rhs.y) + (lhs.z * rhs.z);
}

Vector4 Vector4::crossProduct(Vector4 lhs, Vector4 rhs)
{
    return Vector4(lhs.y * rhs.z - lhs.z * rhs.y, lhs.z * rhs.x - lhs.x * rhs.z, lhs.x * rhs.y - lhs.y * rhs.x, 0);
}

Vector4 Vector4::operator +(Vector4 rhs)
{
    return Vector4(x + rhs.x, y + rhs.y, z + rhs.z, w + rhs.w);
}

Vector4 Vector4::operator-(Vector4 rhs)
{
    return Vector4(x - rhs.x, y - rhs.y, z - rhs.z, w - rhs.w);
}

Vector4 Vector4::operator*(float scalar)
{
    return Vector4(x * scalar, y * scalar, z * scalar, w * scalar);
}

Vector4 Vector4::operator/(float scalar)
{
    return Vector4(x / scalar, y / scalar, z / scalar, w / scalar);
}

bool Vector4::operator==(Vector4 rhs)
{
    return x == rhs.x && y == rhs.y && z == rhs.z && w == rhs.w;
}

Vector4 operator*(float scalar, Vector4 rhs)
{
    return Vector4(scalar * rhs.x, scalar * rhs.y, scalar * rhs.z, scalar * rhs.w);
}
