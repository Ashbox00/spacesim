#include <string>
#include <raylib.h>
#include <raymath.h>
#include <cmath>

#include "planet.h"
#include "vec3d.hpp"

const double G = 6.67430e-11;

Planet *updatePlanets(Planet planets[], double timesec)
{
    Planet sun = planets[0];
    // placeholder gravatational constant(the real one is too small)

    for (int i = 1; i < sizeof(planets); i++)
    {
        // Getting the x, y, and z components of the force

        // float Fx = G*sun.mass_kg*planets[i].mass_kg / planets[i].position.x; for single components
        vec3d force = (G * sun.mass_kg * planets[i].mass_kg) * planets[i].position.invert();

        // Updating position
        planets[i].position += planets[i].velocity * timesec + force / planets[i].mass_kg * pow(timesec, 2) / 2;

        // updating velocity
        planets[i].velocity += force / planets[i].mass_kg * timesec;
    }

    return planets;
}

Planet satelliteStep(Planet planets[], Planet &satellite, double timesec)
{
    vec3d force(0, 0, 0);

    for (int i = 0; i < sizeof(planets); i++)
    {
        force += (G * planets[i].mass_kg * satellite.mass_kg) * (satellite.position - planets[i].position).invert();
    }

    // Updating position
    satellite.position += satellite.velocity * timesec + force / satellite.mass_kg * pow(timesec, 2) / 2;

    // updating velocity
    satellite.velocity += force / satellite.mass_kg * timesec;

    return satellite;
}