#ifndef SPHERE_H
#define SPHERE_H

#include <raylib.h>
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
    Color color;
};

#endif // SPHERE_H
