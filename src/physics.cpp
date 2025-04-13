#include <string>
#include <raylib.h>
#include <raymath.h>
#include <cmath>

const float G = 6.67e-11f;

class Planet{
    public:
    float mass;
    float radius;
    Vector3 pos;
    Vector3 vel;
    
};


Planet* updatePlanets(Planet planets[], float timesec)
{
    Planet sun = planets[0];
    //placeholder gravatational constant(the real one is too small)

    for (int i = 1; i < sizeof(planets); i++)
    {
        //Getting the x, y, and z components of the force
        
        //float Fx = G*sun.mass*planets[i].mass / planets[i].pos.x; for single components
        Vector3 force = Vector3Scale(Vector3Invert(planets[i].pos), (G*sun.mass)*planets[i].mass);
        
        //Updating position
        planets[i].pos += planets[i].vel*timesec + force/planets[i].mass*pow(timesec, 2)/2;

        //updating velocity
        planets[i].vel += force/planets[i].mass * timesec;
    }

    return planets;
}

Planet satelliteStep(Planet planets[], Planet &satellite, float timesec)
{
    Vector3 force = {0,0,0};

    for(int i = 0; i < sizeof(planets); i++)
    {
        force += Vector3Scale(Vector3Invert(satellite.pos - planets[i].pos), (G*planets[i].mass)*satellite.mass);
    }
    
    //Updating position
    satellite.pos += satellite.vel*timesec + force/satellite.mass*pow(timesec, 2)/2;

    //updating velocity
    satellite.vel += force/satellite.mass * timesec;

    return satellite;
}