#include <string>
#include <raylib.h>
#include <raymath.h>
#include <cmath>

#include "planet.h"
#include "vec3d.hpp"

const double G = 6.67430e-13;

// void updatePlanets(double timesec)
// {
//     Planet sun = planets[0];

//     for (int i = 1; i < NUM_PLANETS; i++)
//     {
//         // Getting the x, y, and z components of the force

//         // float Fx = G*sun.mass_kg*planets[i].mass_kg / planets[i].position.x; for single components
//         vec3d force = (G * sun.mass_kg * planets[i].mass_kg) * planets[i].position.invert();

//         // Updating position
//         planets[i].position += planets[i].velocity * timesec + force / planets[i].mass_kg * pow(timesec, 2) / 2;

//         // updating velocity
//         planets[i].velocity += force / planets[i].mass_kg * timesec;
//     }
// }

Planet satelliteStep(const PlanetStates &state, const Planet &satellite, double timesec)
{
    Planet ret = {
        .name = satellite.name,
        .position = satellite.position,
        .velocity = satellite.velocity,
        .mass_kg = satellite.mass_kg,
        .radius_km = satellite.radius_km,
        .color = satellite.color,
    };

    vec3d force(0, 0, 0);

    for (int i = 0; i < NUM_PLANETS; i++)
    {
        if (&satellite == &state.planets[i])
        {
            continue;
        }

        force.x += (G * state.planets[i].mass_kg * satellite.mass_kg) / pow((satellite.position.x - state.planets[i].position.x), 2);
        force.y += (G * state.planets[i].mass_kg * satellite.mass_kg) / pow((satellite.position.y - state.planets[i].position.y), 2);
        force.z += (G * state.planets[i].mass_kg * satellite.mass_kg) / pow((satellite.position.z - state.planets[i].position.z), 2);
    }

    // Updating position
    ret.position = satellite.position + satellite.velocity * timesec + force / satellite.mass_kg * pow(timesec, 2) / 2;

    // updating velocity
    ret.velocity = satellite.velocity + force / satellite.mass_kg * timesec;

    return ret;
}