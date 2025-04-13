#include <raylib.h>
#include <raymath.h>

#include "json_parser.hpp"

#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

string readFileAsString(const string &filename)
{
    ifstream inFile(filename);
    ostringstream ss;
    ss << inFile.rdbuf();
    return ss.str();
}

int main()
{
    string json = readFileAsString("./test.json");
    Jparser(json);


    InitWindow(640, 480, "Space Sim");
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
                // DrawSphere(Vector3Zero(), 3, GREEN);
                DrawSphereEx(Vector3Zero(), 3, 100, 100, YELLOW);
            }
            EndMode3D();

            DrawFPS(10, 10);
        }
        EndDrawing();
    }

    CloseWindow();
}
