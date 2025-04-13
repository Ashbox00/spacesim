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

    float getCoords()
    {
        return vec.x, vec.y, vec.z;
    };

    void setCoords(float xCoords, float yCoords, float zCoords)
    {
        vec.x = xCoords;
        vec.y = yCoords;
        vec.z = zCoords;
    };

private:
    float x, y, z;
    Vector3 vec;
    std::vector<float> coords;
};

#endif