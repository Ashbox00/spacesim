#include <raylib.h>
#include <raymath.h>

int main()
{
    InitWindow(640, 480, "Space Sim");

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
}