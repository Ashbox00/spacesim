#include <raylib.h>
#include <raymath.h>
#include <iostream>

#include "planet.h"
#include "downloader.hpp"
#include "physics.hpp"

#include "json_parser.hpp"

#include <fstream>
#include <sstream>
#include <iostream>
#include <array>

using namespace std;

#define NUM_STATES (100)
PlanetStates states[NUM_STATES] = {};
int current_state = 0;
constexpr double STEP_TIME = 0.1f;

vec3d randomPos()
{
    double x = 1e10 * ((double)rand() / (double)RAND_MAX) - 5e9;
    double y = 1e10 * ((double)rand() / (double)RAND_MAX) - 5e9;
    double z = 1e10 * ((double)rand() / (double)RAND_MAX) - 5e9;

    return vec3d(x, y, z);
}

int main()
{
    InitWindow(1920, 1080, "Space Sim");
    SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

    Camera3D camera = {
        .position = Vector3{0, 0, -50},
        .target = Vector3{0, 0, 0},
        .up = Vector3{0, 1, 0},
        .fovy = 60.0f,
        .projection = CAMERA_PERSPECTIVE,
    };

    states[current_state] = initialState;

    for (int i = 1; i < NUM_PLANETS; i++)
    {
        states[current_state].planets[i].position = randomPos();
        states[current_state].planets[i].velocity = {0, 0, 0};
    }

    for (int i = 1; i < NUM_STATES; i++)
    {
        states[i].planets[0] = states[i - 1].planets[0];
        for (int ii = 1; ii < NUM_PLANETS; ii++)
        {
            states[i].planets[ii] = satelliteStep(states[i - 1], states[i - 1].planets[ii], STEP_TIME);

            // printf("%lf, %lf, %lf\n", states[i].planets[ii].position.x, states[i].planets[ii].position.y, states[i].planets[ii].position.z);
        }
    }

    Mesh circleMesh = GenMeshSphere(1.0f, 100, 100);
    Model circleModel = LoadModelFromMesh(circleMesh);

    while (!WindowShouldClose())
    {
        current_state = (int)(floor(GetTime() / STEP_TIME)) % NUM_STATES;

        UpdateCamera(&camera, CAMERA_THIRD_PERSON);

        BeginDrawing();
        {
            ClearBackground(BLACK);

            BeginMode3D(camera);
            {
                for (auto &p : states[current_state].planets)
                {
                    DrawModel(circleModel, (Vector3)p.position / 1e8, p.radius_km / 100000, p.color);
                }
            }
            EndMode3D();

            DrawFPS(10, 10);
        }
        EndDrawing();
    }

    UnloadModel(circleModel); // Also unloads mesh

    CloseWindow();
}
