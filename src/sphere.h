#ifndef SPHERE_H
#define SPHERE_H

//Gonna see if I can test it here?
#include <raylib.h>
#include <raymath.h>
#include <vector>

//class that creates a general 3d sphere shape for celestial bodies
//data we are grabbing: position and velocity
//draw sphere based on the object utilizng vectors from the provided information above

class Sphere 
{
public:
    Sphere()
    {
        x = 0;
        y = 0;
        z = 0;
    };

    Sphere(float xCoords, float yCoords, float zCoords) 
    {
        vec = Vector3
        {
            //is this supposed to be xCoords, yCoord, zCoords instead of storing them?
            x = xCoords,
            y = yCoords,
            z = zCoords,
        };
    };

    float getX()
    {
        return vec.x;
    };

    void setX(float coord)
    {
        vec.x = coord;
    };

    float getY()
    {
        return vec.y;
    };

    void setY(float coord)
    {
        vec.y = coord;
    };

    float getZ()
    {
        return vec.z;
    };

    void setZ(float coord)
    {
        vec.z = coord;
    };

private:
    float x, y, z;
    Vector3 vec;
    std::vector<float> coords;
};

#endif