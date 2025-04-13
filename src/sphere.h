#ifndef SPHERE_H
#define SPHERE_H

//raylib magic
#include <raylib.h>
#include <raymath.h>
#include <vector>

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
/*
    Sphere(double xVel, double yVel, double zVel)
    {
        vel = Vector3
        {
            x = xVel,
            y = yVel,
            z = zVel,
        };
    }
*/
    Sphere(float xCoords, float yCoords, float zCoords) 
    {
        vec = Vector3
        {
            //is this supposed to be xCoords, yCoord, zCoords instead of storing them?
            x = xCoords,
            y = yCoords,
            z = zCoords,
        };
        radius = 1;
    };

    Vector3 getCoords()
    {
        return vec;
    };

    void setCoords(float xCoords, float yCoords, float zCoords)
    {
        vec.x = xCoords;
        vec.y = yCoords;
        vec.z = zCoords;
    };

    Vector3 getVelocity()
    {
        return vel;
    };

    void setVelocity(double xVel, double yVel, double zVel)
    {
        vel.x = xVel;
        vel.y = yVel;
        vel.z = zVel;
    }

    float getRadius()
    {
        return radius;
    }

    void setRadius(float rad)
    {
        radius = rad;
    }

private:
    float x, y, z, mass, radius;
    Vector3 vel, vec;
};

#endif