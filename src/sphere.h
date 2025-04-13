#ifndef SPHERE_H
#define SPHERE_H

//Gonna see if I can test it here?
#include <raylib.h>
#include <raymath.h>

//class that creates a general 3d sphere shape for celestial bodies
//data we are grabbing: position and velocity
//draw sphere based on the object utilizng vectors from the provided information above

class Sphere 
{
public:
    Sphere();

    Sphere(float xCoords, float yCoords, float zCoords) 
    {
        vec = Vector3
        {
            x = xCoords,
            y = yCoords,
            z = zCoords,
        };
    };

private:
float x, y, z = 0;
    Vector3 vec;
};

#endif