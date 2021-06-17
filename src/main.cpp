    /*
** EPITECH PROJECT, 2021
** B-YEP-400-BAR-4-1-indiestudio-arnau.espejo-hernandez
** File description:
** Created by aespejo,
*/

#include <Core.hpp>
#include <MapModule/mapModule.h>
#include <Objects/renderModule.hpp>

    int test(void)
    {
        const int screenWidth = 1000;
        const int screenHeight = 750;
        Core core;

        Vector3 floor = {(float) MAX_ROW, 0.0f, (float) MAX_COL};
        InitWindow(screenWidth, screenHeight, "raylib [models] example - cubesmap loading and drawing");

        // Define the camera to look into our 3d world
        Camera camera = { { 13.0f, 25.0f, 19.0f }, { 5.0f, -14.0f, 0.0f }, { 0.0f, 1.0f, 0.0f }, 45.0f, 0 };
        SetCameraMode(camera, CAMERA_PERSPECTIVE);  // Set an orbital camera mode
        SetTargetFPS(60);                       // Set our game to run at 60 frames-per-second
        //--------------------------------------------------------------------------------------

        // Main game loop
        while (!WindowShouldClose())            // Detect window close button or ESC key
        {
            // Update
            //----------------------------------------------------------------------------------
            UpdateCamera(&camera);              // Update camera
            //----------------------------------------------------------------------------------

            // Draw
            //----------------------------------------------------------------------------------
            BeginDrawing();
            ClearBackground(RAYWHITE);
            BeginMode3D(camera);

            //Drawing floor
            DrawCube((Vector3) {(float) MAX_ROW / 2 -1, 0.0f, (float) MAX_ROW / 2 -1}, floor.x, floor.y, floor.z, BLACK);

            core.getRender().renderMap(core.getMap());
            EndMode3D();
            EndDrawing();
            //----------------------------------------------------------------------------------
        }
        core.gameLoop();              // Close window and OpenGL context
        //--------------------------------------------------------------------------------------

        return 0;
    }

    int main()
    {
        test();
        //Core core;
        //core.gameLoop();
    }