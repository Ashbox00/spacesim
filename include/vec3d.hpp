#pragma once

#include <raymath.h>

class vec3d
{
public:
    inline vec3d()
        : x(0), y(0), z(0)
    {
    }

    inline vec3d(double _x, double _y, double _z)
        : x(_x), y(_y), z(_z)
    {
    }

    inline vec3d(Vector3 vec3)
        : x(vec3.x), y(vec3.y), z(vec3.z)
    {
    }

public:
    inline vec3d operator+(const vec3d &other)
    {
        return vec3d(x + other.x, y + other.y, z + other.z);
    }

    inline vec3d &operator+=(const vec3d &other)
    {
        x += other.x;
        y += other.y;
        z += other.z;
        return *this;
    }

    inline vec3d operator-()
    {
        return vec3d(x, y, z);
    }

    inline vec3d operator-(const vec3d &other)
    {
        return vec3d(x - other.x, y - other.y, z - other.z);
    }

    inline vec3d operator-=(const vec3d &other)
    {
        x -= other.x;
        y -= other.y;
        z -= other.z;
        return *this;
    }

    inline vec3d operator*(double scale) const
    {
        return vec3d(x * scale, y * scale, z * scale);
    }

    inline vec3d &operator*=(double scale)
    {
        x *= scale;
        y *= scale;
        z *= scale;
        return *this;
    }

    inline vec3d operator/(double scale)
    {
        return vec3d(x / scale, y / scale, z / scale);
    }

    inline vec3d &operator/=(double scale)
    {
        x /= scale;
        y /= scale;
        z /= scale;
        return *this;
    }

    inline explicit operator Vector3() const
    {
        return Vector3{
            .x = (float)x,
            .y = (float)y,
            .z = (float)z,
        };
    }

    inline vec3d invert()
    {
        if (x == 0.0)
        {
            printf("Sadge\n");
        }
        return vec3d(1.0 / x, 1.0 / y, 1.0 / z);
    }

public:
    double x;
    double y;
    double z;
};

inline double mag(const vec3d &vec)
{
    return sqrt(vec.x*vec.x + vec.y*vec.y + vec.z*vec.z);
}

inline vec3d operator*(double scale, const vec3d &vec)
{
    return vec * scale;
}

inline vec3d operator+(const vec3d &lhs, const vec3d &rhs)
{
    return vec3d(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z);
}

inline vec3d operator-(const vec3d &lhs, const vec3d &rhs)
{
    return vec3d(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z);
}