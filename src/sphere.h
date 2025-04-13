#ifndef SPHERE_H
#define SPHERE_H

//raylib magic
#include <raylib.h>
#include <raymath.h>
#include <vector>

//insert header files from gage

class Sphere 
{
public:
    //basic constructor
    Sphere()
    {
        x = 0;
        y = 0;
        z = 0;
        radius = 1;
    };

    Vector3 getCoords()
    {
        return pos;
    };

    void setCoords(float xCoords, float yCoords, float zCoords)
    {
        pos = Vector3
        {
            pos.x = xCoords,
            pos.y = yCoords,
            pos.z = zCoords,
        };
    };

    Vector3 getVelocity()
    {
        return vel;
    };

    void setVelocity(double xVel, double yVel, double zVel)
    {
        vel = Vector3
        {
            vel.x = xVel,
            vel.y = yVel,
            vel.z = zVel,
        };
    };

    float getRadius()
    {
        return radius;
    }

    void setRadius(float rad)
    {
        radius = rad;
    }

    float getMass()
    {
        return mass;
    }

    void setMass(float mass)
    {
        mass = mass;
    }

private:
    float x, y, z, mass, radius;
    Vector3 vel, pos;
};

#endif