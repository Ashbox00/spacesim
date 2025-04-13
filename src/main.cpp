#include <raylib.h>
#include <raymath.h>
#include <iostream>

#include "sphere.h"

#include "downloader.hpp"

#include "json_parser.hpp"

#include <fstream>
#include <sstream>
#include <iostream>
#include <array>

using namespace std;

static array<Planet, 10> planets = {
    Planet{
        .name = "Sun",
        .position = Vector3Zero(),
        .velocity = Vector3Zero(),
        .mass_kg = 1.989e30f,
        .radius_km = 695700.0f,
    },
    Planet{
        .name = "Mercury",
        .position = Vector3Zero(),
        .velocity = Vector3Zero(),
        .mass_kg = 3.301e23f,
        .radius_km = 2439.7,
    },
    Planet{
        .name = "Venus",
        .position = Vector3Zero(),
        .velocity = Vector3Zero(),
        .mass_kg = 4.867e24f,
        .radius_km = 6051.8f,
    },
    Planet{
        .name = "Earth",
        .position = Vector3Zero(),
        .velocity = Vector3Zero(),
        .mass_kg = 5.972e24f,
        .radius_km = 6371.0f,
    },
    Planet{
        .name = "Mars",
        .position = Vector3Zero(),
        .velocity = Vector3Zero(),
        .mass_kg = 6.417e23f,
        .radius_km = 3389.5f,
    },
    Planet{
        .name = "Jupiter",
        .position = Vector3Zero(),
        .velocity = Vector3Zero(),
        .mass_kg = 1.898e27f,
        .radius_km = 69911.0f,
    },
    Planet{
        .name = "Saturn",
        .position = Vector3Zero(),
        .velocity = Vector3Zero(),
        .mass_kg = 5.68e26f,
        .radius_km = 60268.0f,
    },
    Planet{
        .name = "Uranus",
        .position = Vector3Zero(),
        .velocity = Vector3Zero(),
        .mass_kg = 8.682e25f,
        .radius_km = 51118.0f,
    },
    Planet{
        .name = "Neptune",
        .position = Vector3Zero(),
        .velocity = Vector3Zero(),
        .mass_kg = 1.024e26f,
        .radius_km = 24764.0f,
    },
    Planet{
        .name = "Pluto",
        .position = Vector3Zero(),
        .velocity = Vector3Zero(),
        .mass_kg = 1.31e22f,
        .radius_km = 2370.0f,
    },
};

string readFileAsString(const string &filename)
{
    ifstream inFile(filename);
    ostringstream ss;
    ss << inFile.rdbuf();
    return ss.str();
}

int main()
{
    InitWindow(640, 480, "Space Sim");
    SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

    Camera3D camera = {
        .position = Vector3{0, 0, -5},
        .target = Vector3{0, 0, 0},
        .up = Vector3{0, 1, 0},
        .fovy = 60.0f,
        .projection = CAMERA_PERSPECTIVE,
    };

    for (auto &p : planets)
    {
        p.position = Vector3{
            .x = (float)GetRandomValue(-100, 100),
            .y = (float)GetRandomValue(-100, 100),
            .z = (float)GetRandomValue(-100, 100),
        };
    }

    while (!WindowShouldClose())
    {
        UpdateCamera(&camera, CAMERA_THIRD_PERSON);

        BeginDrawing();
        {
            ClearBackground(BLACK);

            BeginMode3D(camera);
            {
                // DrawSphere(Vector3Zero(), 3, GREEN);
                // DrawSphereEx(Vector3Zero(), 3, 100, 100, YELLOW);

                for (auto &p : planets)
                {
                    DrawSphereEx(p.position, p.radius_km / 10000, 100, 100, YELLOW);
                }
            }
            EndMode3D();

            DrawFPS(10, 10);
        }
        EndDrawing();
    }

    CloseWindow();
}
