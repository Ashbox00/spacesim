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
        .mass_kg = 1.989e30,
        .radius_km = 695700.0,
        .color = YELLOW,
    },
    Planet{
        .name = "Mercury",
        .position = Vector3Zero(),
        .velocity = Vector3Zero(),
        .mass_kg = 3.301e23,
        .radius_km = 2439.7,
        .color = RAYWHITE,
    },
    Planet{
        .name = "Venus",
        .position = Vector3Zero(),
        .velocity = Vector3Zero(),
        .mass_kg = 4.867e24,
        .radius_km = 6051.8,
        .color = RED,
    },
    Planet{
        .name = "Earth",
        .position = Vector3Zero(),
        .velocity = Vector3Zero(),
        .mass_kg = 5.972e24,
        .radius_km = 6371.0,
        .color = GREEN,
    },
    Planet{
        .name = "Mars",
        .position = Vector3Zero(),
        .velocity = Vector3Zero(),
        .mass_kg = 6.417e23,
        .radius_km = 3389.5,
        .color = ORANGE,
    },
    Planet{
        .name = "Jupiter",
        .position = Vector3Zero(),
        .velocity = Vector3Zero(),
        .mass_kg = 1.898e27,
        .radius_km = 69911.0,
        .color = BROWN,
    },
    Planet{
        .name = "Saturn",
        .position = Vector3Zero(),
        .velocity = Vector3Zero(),
        .mass_kg = 5.68e26,
        .radius_km = 60268.0,
        .color = YELLOW,
    },
    Planet{
        .name = "Uranus",
        .position = Vector3Zero(),
        .velocity = Vector3Zero(),
        .mass_kg = 8.682e25,
        .radius_km = 51118.0,
        .color = BLUE,
    },
    Planet{
        .name = "Neptune",
        .position = Vector3Zero(),
        .velocity = Vector3Zero(),
        .mass_kg = 1.024e26,
        .radius_km = 24764.0,
        .color = PURPLE,
    },
    Planet{
        .name = "Pluto",
        .position = Vector3Zero(),
        .velocity = Vector3Zero(),
        .mass_kg = 1.31e22,
        .radius_km = 2370.0,
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
