#include <string>
#include <raylib.h>
#include <raymath.h>
#include <cmath>

class Planet{
    public:
    float mass;
    float radius;
    Vector3 pos;
    Vector3 vel;
    
};

Planet* updatePlanets(Planet planets[])
{
    Planet sun = planets[0];
    float G = 6.67e-11f; //placeholder gravatational constant(the real one is too small)

    for (int i = 1; i < sizeof(planets); i++)
    {
        //Getting the x, y, and z components of the force
        
        //float Fx = G*sun.mass*planets[i].mass / planets[i].pos.x; for single components
        Vector3 force = Vector3Scale(planets[i].pos, G*sun.mass*planets[i].mass);

        //Updating position
        int time = 100000; //how many "seconds" between each "update"
        planets[i].pos += planets[i].vel*time + force/planets[i].mass*pow(time, 2)/2;

        //updating velocity
        planets[i].vel += force/planets[i].mass * time;
    }

    return planets;
}