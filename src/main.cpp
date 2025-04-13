#include <raylib.h>
#include <raymath.h>
#include <iostream>

#include "planet.h"

#include "downloader.hpp"

#include "json_parser.hpp"

#include <fstream>
#include <sstream>
#include <iostream>
#include <array>

using namespace std;

static Planet planets[] = {
    Planet{
        .name = "Sun",
        .position = Vector3Zero(),
        .velocity = Vector3Zero(),
        .mass_kg = 1.989e30f,
        .radius_km = 695700.0f,
        .color = YELLOW,
    },
    Planet{
        .name = "Mercury",
        .position = Vector3Zero(),
        .velocity = Vector3Zero(),
        .mass_kg = 3.301e23f,
        .radius_km = 2439.7,
        .color = RAYWHITE,
    },
    Planet{
        .name = "Venus",
        .position = Vector3Zero(),
        .velocity = Vector3Zero(),
        .mass_kg = 4.867e24f,
        .radius_km = 6051.8f,
        .color = RED,
    },
    Planet{
        .name = "Earth",
        .position = Vector3Zero(),
        .velocity = Vector3Zero(),
        .mass_kg = 5.972e24f,
        .radius_km = 6371.0f,
        .color = GREEN,
    },
    Planet{
        .name = "Mars",
        .position = Vector3Zero(),
        .velocity = Vector3Zero(),
        .mass_kg = 6.417e23f,
        .radius_km = 3389.5f,
        .color = ORANGE,
    },
    Planet{
        .name = "Jupiter",
        .position = Vector3Zero(),
        .velocity = Vector3Zero(),
        .mass_kg = 1.898e27f,
        .radius_km = 69911.0f,
        .color = BROWN,
    },
    Planet{
        .name = "Saturn",
        .position = Vector3Zero(),
        .velocity = Vector3Zero(),
        .mass_kg = 5.68e26f,
        .radius_km = 60268.0f,
        .color = YELLOW,
    },
    Planet{
        .name = "Uranus",
        .position = Vector3Zero(),
        .velocity = Vector3Zero(),
        .mass_kg = 8.682e25f,
        .radius_km = 51118.0f,
        .color = BLUE,
    },
    Planet{
        .name = "Neptune",
        .position = Vector3Zero(),
        .velocity = Vector3Zero(),
        .mass_kg = 1.024e26f,
        .radius_km = 24764.0f,
        .color = PURPLE,
    },
    Planet{
        .name = "Pluto",
        .position = Vector3Zero(),
        .velocity = Vector3Zero(),
        .mass_kg = 1.31e22f,
        .radius_km = 2370.0f,
        .color = GOLD,
    },
};

int main()
{
    InitWindow(1920, 1080, "Space Sim");
    SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

    Camera3D camera = {
        .position = Vector3{0, 0, -5},
        .target = Vector3{0, 0, 0},
        .up = Vector3{0, 1, 0},
        .fovy = 60.0f,
        .projection = CAMERA_PERSPECTIVE,
    };

    while (!WindowShouldClose())
    {
        UpdateCamera(&camera, CAMERA_THIRD_PERSON);

        BeginDrawing();
        {
            ClearBackground(BLACK);

            BeginMode3D(camera);
            {
                for (auto &p : planets)
                {
                    DrawSphereEx(p.position, p.radius_km / 100000, 100, 100, p.color);
                }
            }
            EndMode3D();

            DrawFPS(10, 10);
        }
        EndDrawing();
    }

    CloseWindow();
}
