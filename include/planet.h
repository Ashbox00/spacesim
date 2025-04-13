#pragma once

#include <raylib.h>
#include <raymath.h>
#include <string>
#include "vec3d.hpp"

// === Planet Info Struct ===
struct Planet
{
    std::string name;
    vec3d position;
    vec3d velocity;
    double mass_kg;
    double radius_km;
    Color color;
};

#define NUM_PLANETS (9) // The sun counts as a planet

struct PlanetStates
{
    Planet planets[NUM_PLANETS];
};

extern PlanetStates initialState;