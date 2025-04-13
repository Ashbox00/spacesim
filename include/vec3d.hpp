#pragma once

#include <raymath.h>

class vec3d
{
public:
    vec3d()
        : x(0), y(0), z(0)
    {
    }

    vec3d(double x, double y, double z)
        : x(x), y(y), z(z)
    {
    }

    vec3d(Vector3 vec3)
        : x(vec3.x), y(vec3.y), z(vec3.z)
    {
    }

public:
    vec3d operator+(const vec3d &other)
    {
        return vec3d(x + other.x, y + other.y, z + other.z);
    }

    vec3d &operator+=(const vec3d &other)
    {
        x += other.x;
        y += other.y;
        z += other.z;
        return *this;
    }

    vec3d operator-()
    {
        return vec3d(x, y, z);
    }

    vec3d operator-(const vec3d &other)
    {
        return vec3d(x - other.x, y - other.y, z - other.z);
    }

    vec3d operator-=(const vec3d &other)
    {
        x -= other.x;
        y -= other.y;
        z -= other.z;
        return *this;
    }

    vec3d operator*(double scale)
    {
        return vec3d(x * scale, y * scale, z * scale);
    }

    vec3d &operator*=(double scale)
    {
        x *= scale;
        y *= scale;
        z *= scale;
        return *this;
    }

    vec3d operator/(double scale)
    {
        return vec3d(x / scale, y / scale, z / scale);
    }

    vec3d &operator/=(double scale)
    {
        x /= scale;
        y /= scale;
        z /= scale;
        return *this;
    }

    operator Vector3() const
    {
        return Vector3{
            .x = (float)x,
            .y = (float)y,
            .z = (float)z,
        };
    }

    vec3d invert()
    {
        return vec3d(1.0 / x, 1.0 / y, 1.0 / z);
    }

public:
    double x;
    double y;
    double z;
};

vec3d operator*(double scale, const vec3d &vec)
{
    return vec * scale;
}

vec3d operator+(const vec3d &lhs, const vec3d &rhs)
{
    return vec3d(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z);
}

vec3d operator-(const vec3d &lhs, const vec3d &rhs)
{
    return vec3d(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z);
}