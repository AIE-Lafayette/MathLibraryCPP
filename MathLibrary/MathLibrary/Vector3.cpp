#include "pch.h"
#include "Vector3.h"
#include "pch.h"
#include <cmath>


Vector3::Vector3()
{
    x = 0;
    y = 0;
    z = 0;
}

Vector3::Vector3(float x, float y, float z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

float Vector3::getMagnitude()
{
    return sqrt(x * x + y * y + +z * z);
}

Vector3 Vector3::getNormalized()
{
    return normalize(*this);
}

Vector3 Vector3::normalize(Vector3 vector)
{
    if (vector.getMagnitude() == 0)
        return Vector3();

    return vector / vector.getMagnitude();
}

float Vector3::dotProduct(Vector3 lhs, Vector3 rhs)
{
    return (lhs.x * rhs.x) + (lhs.y * rhs.y) + (lhs.z * rhs.z);
}

Vector3 Vector3::crossProduct(Vector3 lhs, Vector3 rhs)
{
    return Vector3((lhs.y * rhs.z) - (lhs.z * rhs.y), (lhs.z * rhs.x) - (lhs.x * rhs.z), (lhs.x * rhs.y) - (lhs.y * rhs.x));
}

Vector3 Vector3::operator +(Vector3 rhs)
{
    return Vector3(x + rhs.x, y + rhs.y, z + rhs.z);
}

Vector3 Vector3::operator -(Vector3 rhs)
{
    return Vector3(x - rhs.x, y - rhs.y, z - rhs.z);
}

Vector3 Vector3::operator *(float scalar)
{
    return Vector3(x * scalar, y * scalar, z * scalar);
}

Vector3 operator *(float scalar, Vector3 rhs)
{
    return Vector3(scalar * rhs.x, scalar * rhs.y, scalar * rhs.z);
}

Vector3 Vector3::operator / (float scalar)
{
    return Vector3(x / scalar, y / scalar, z / scalar);
}

bool Vector3::operator==(Vector3 rhs)
{
    return x == rhs.x && y == rhs.y && z == rhs.z;
}
