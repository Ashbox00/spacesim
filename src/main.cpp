#include "planet.h"
#include "downloader.hpp"
#include "physics.hpp"
#include "json_parser.hpp"

#include <raylib.h>
#include <raymath.h>

#include <fstream>
#include <iostream>
#include <sstream>
#include <iostream>
#include <array>
#include <sstream>
#include <cstdint>

using namespace std;

#define NUM_STATES (100)
PlanetStates states[NUM_STATES] = {};
int last_state = 0;
int current_state = 0;
constexpr double STEP_TIME = 1.0f;

int main()
{
    srand(time(NULL));

    InitWindow(1920, 1080, "Space Sim");
    SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);
    SetTargetFPS(120);

    HideCursor();

    Camera3D camera = {
        .position = Vector3{0, 0, -50},
        .target = Vector3{0, 0, 0},
        .up = Vector3{0, 1, 0},
        .fovy = 60.0f,
        .projection = CAMERA_PERSPECTIVE,
    };

    ifstream json_file("test.json");
    stringstream ss;
    ss << json_file.rdbuf();

    Jparser(ss.str());

    states[current_state] = initialState;

    for (int i = 1; i < NUM_STATES; i++)
    {
        states[i].planets[0] = states[i - 1].planets[0];
        for (int ii = 1; ii < NUM_PLANETS; ii++)
        {
            states[i].planets[ii] = satelliteStep(states[i - 1], states[i - 1].planets[ii], STEP_TIME);
        }
    }

    Mesh circleMesh = GenMeshSphere(1.0f, 100, 100);
    Model circleModel = LoadModelFromMesh(circleMesh);

    double totalTime = 0;

    while (!WindowShouldClose())
    {
        current_state = (int)((uint64_t)(floor(GetTime())) % NUM_STATES);

        UpdateCamera(&camera, CAMERA_THIRD_PERSON);
        SetMousePosition(GetScreenWidth() / 2, GetScreenHeight() / 2);

        BeginDrawing();
        {
            ClearBackground(BLACK);

            BeginMode3D(camera);
            {
                for (auto &p : states[current_state].planets)
                {

                    DrawModel(circleModel, (Vector3)(p.position / 1e6), p.radius_km / 500, p.color);
                }
            }
            EndMode3D();

            DrawFPS(10, 10);
        }
        EndDrawing();

        if (current_state != last_state)
        {
            int last_last_state = (last_state - 1 + NUM_STATES) % NUM_STATES;
            // states[last_state].planets[0] = states[last_last_state].planets[0];
            for (int i = 1; i < NUM_PLANETS; i++)
            {
                states[last_state].planets[i] = satelliteStep(states[last_last_state], states[last_last_state].planets[i], STEP_TIME);
            }

            last_state = current_state;
        }

        totalTime += GetFrameTime();
    }

    UnloadModel(circleModel); // Also unloads mesh

    CloseWindow();
}
