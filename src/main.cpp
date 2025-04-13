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
