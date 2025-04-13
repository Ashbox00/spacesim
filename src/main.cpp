#include <raylib.h>
#include <raymath.h>
#include "sphere.h"

int main()
{
    InitWindow(640, 480, "Space Sim");
    SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);
    Sphere s;
    
    std::vector<float> coords;

    Camera3D camera = {
        .position = Vector3{0, 0, -5},
        .target = Vector3{0, 0, 0},
        .up = Vector3{0, 1, 0},
        .fovy = 60.0f,
        .projection = CAMERA_PERSPECTIVE,

        /*.position = s.getCoords(),
        .target = s.getCoords(),
        .up = s.getCoords(),
        .fovy = 60.0f,
        .projection = CAMERA_PERSPECTIVE,*/
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
                //DrawSphereEx(Vector3Zero(), 3, 100, 100, YELLOW);
                DrawSphereEx(s.getCoords(), 3, 100, 100 ,YELLOW);

                while (true)
                {
                    DrawSphereEx(s.getCoords(), s.getRadius(), 100, 100, YELLOW);
                };
            }
            EndMode3D();

            DrawFPS(10, 10);
        }
        EndDrawing();
    }

    CloseWindow();
}
