#ifndef SPHERE_H
#define SPHERE_H

#include <raymath.h>
#include <string>

// === Planet Info Struct ===
struct Planet
{
    std::string name;
    Vector3 position;
    Vector3 velocity;
    float mass_kg;
    float radius_km;
};

#endif // SPHERE_H
