#include "raylib.h"
#include "rcamera.h"
#include "raymath.h"

#include <stdio.h>

#define MAX_COLUMNS 20

int main(void) {

  // INITIALIZATION

  const int screenWidth = 1280;
  const int screenHeight = 960;

  InitWindow(screenWidth, screenHeight, "zanim");

  // Camera setup
  Camera3D camera = { 0 };
  camera.position = (Vector3) { 0.0f, 2.0f, 4.0f };  // camera position
  camera.target = (Vector3) {0.0f, 2.0f, 0.0f };       // camera looking at point
  camera.up = (Vector3) { 0.0f, 1.0f, 0.0f };          // cameras up vector (normal to pov plane i believe)
  camera.fovy = 80.0f;
  camera.projection = CAMERA_PERSPECTIVE;              // camera mode
  
  // Generate random column cubes
  float heights[MAX_COLUMNS] = { 0 };
  Vector3 positions[MAX_COLUMNS] = { 0 };
  Color colors[MAX_COLUMNS] = { 0 };

  for (int i = 0; i < MAX_COLUMNS; i++) {
    heights[i] = (float)GetRandomValue(1, 12);
    positions[i] = (Vector3){ (float)GetRandomValue(-15, 15), (heights[i] / 2.0f), (float)GetRandomValue(-15, 15) };
    colors[i] = (Color){ GetRandomValue(20, 255), GetRandomValue(10, 55), 30, 255 };
  }

  DisableCursor();

  SetTargetFPS(120);

  while (!WindowShouldClose()) {
    
    Vector2 horizontalMoveDirNorm = Vector2Normalize((Vector2){
      (float)(IsKeyDown(KEY_W) - IsKeyDown(KEY_S)),
      (float)(IsKeyDown(KEY_D) - IsKeyDown(KEY_A))
    });

    UpdateCameraPro(&camera,
      (Vector3){
        horizontalMoveDirNorm.x*0.1f, // Forward-backward
        horizontalMoveDirNorm.y*0.1f, // Right-left
        0.0f                                             // Up-down
      },
      (Vector3){
        GetMouseDelta().x*0.05f,                         // Yaw rotation
        GetMouseDelta().y*0.05f,                         // Pitch rotation
        0.0f                                             // Roll rotation
      },
      0.0f                                               // Zoom. Was GetMouseWheelMove()*2.0f
    );

    BeginDrawing();

      ClearBackground(RAYWHITE);

      BeginMode3D(camera);

        DrawPlane((Vector3) { 0.0f, 0.0f, 0.0f }, (Vector2){ 32.0f, 32.0f }, LIGHTGRAY); // Draw ground
        DrawCube((Vector3){ -16.0f, 2.5f, 0.0f }, 1.0f, 5.0f, 32.0f, BLUE);              // Draw a blue wall
        DrawCube((Vector3){ 16.0f, 2.5f, 0.0f }, 1.0f, 5.0f, 32.0f, LIME);               // Draw a green wall
        DrawCube((Vector3){ 0.0f, 2.5f, 16.0f }, 32.0f, 5.0f, 1.0f, GOLD);               // Draw yellow wall
    
        // Draw cubes around
        for (int i = 0; i < MAX_COLUMNS; i++) {
          DrawCube(positions[i], 2.0f, heights[i], 2.0f, colors[i]);
          DrawCubeWires(positions[i], 2.0f, heights[i], 2.0f, BLACK);
        }

        DrawGrid(10, 1.0f);

      EndMode3D();

      // Camera info
      DrawText(
        TextFormat("Position: (%.1f, %.1f, %.1f)",
        camera.position.x, camera.position.y, camera.position.z), 20, 60, 20, DARKGRAY);
      DrawText(
        TextFormat("Target: (%.1f, %.1f, %.1f)",
        camera.target.x, camera.target.y, camera.target.z), 20, 75, 20, DARKGRAY);
      DrawText(
        TextFormat("Up: (%.1f, %.1f, %.1f)",
        camera.up.x, camera.up.y, camera.up.z), 20, 90, 20, DARKGRAY);

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
