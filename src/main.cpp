/*
** EPITECH PROJECT, 2021
** B-YEP-400-BAR-4-1-indiestudio-arnau.espejo-hernandez
** File description:
** Created by aespejo,
*/

#include "inputHandler.hpp"
#include "Core/gameLogic.hpp"
#include "SceneManager.hpp"
#include "RenderComponent.hpp"

int openRaylib()
{
    const int width = 800;
    const int height = 450;
    InitWindow(width, height, "\0");
    SetTargetFPS(60);
    MessageBus bus;
    InputHandler handler(&bus);
    GameLogic logic(&bus);
    SceneManager sceneManager;
    Object *currentObj = sceneManager.CreateObject();
    RenderComponent *renderComponent = new RenderComponent();
    renderComponent->load_texture("./resources/barracks_diffuse.png");
    renderComponent->load_model("./resources/barracks.obj");
    currentObj->loadComponent(renderComponent);
    Camera camera = { 0 };
    camera.position = (Vector3){ 50.0f, 50.0f, 50.0f }; // Camera position
    camera.target = (Vector3){ 0.0f, 10.0f, 0.0f };     // Camera looking at point
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
    camera.fovy = 45.0f;                                // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE;                   // Camera mode type
    while (!WindowShouldClose())
    {

        logic.update();
        handler.update();
        bus.notify();
        BeginDrawing();

        ClearBackground(RAYWHITE);
        BeginMode3D(camera);
        renderComponent->draw();
        DrawGrid(20, 10.0f);         // Draw a grid
        EndMode3D();
        EndDrawing();
    }
    CloseWindow();
    return 0;
}

int main()
{
    openRaylib();
}

