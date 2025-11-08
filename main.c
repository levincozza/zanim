#include "raylib.h"

int main(void) {

    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "is this title");

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawText("Basic window woop", 190, 200, 20, LIGHTGRAY);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}




// #include "raylib.h"

// int main(void) {
//     InitWindow(800, 450, "Hello Raylib!");
//     while (!WindowShouldClose()) {
//         BeginDrawing();
//         ClearBackground(RAYWHITE);
//         DrawText("Hello from raylib!", 200, 200, 20, BLACK);
//         EndDrawing();
//     }
//     CloseWindow();
//     return 0;
// }

// gcc main.c -o main.exe -I"C:\raylib\include" -L"C:\raylib\lib" -lraylib -lopengl32 -lgdi32 -lwinmm

// in new file build.bat (i want to use makefile instead, as it is the standard right??)
// gcc main.c -o main.exe -I"C:\raylib\include" -L"C:\raylib\lib" -lraylib -lopengl32 -lgdi32 -lwinmm
// .\main.exe
// pause
