#include "Window.h"
#include "raymath.h"

Vector2 GetCanvasSize()
{
    return {SCREEN_WIDTH, SCREEN_HEIGHT};
}

Vector2 GetWindowSize()
{
    Vector2 sizesScreen = Vector2Divide(
        {(float)GetScreenWidth(), (float)GetScreenHeight()},
        GetCanvasSize());

    return Vector2Scale(
        GetCanvasSize(),
        sizesScreen.x > sizesScreen.y ? sizesScreen.y : sizesScreen.x);
}

Vector2 GetWindowScale()
{
    return Vector2Divide(GetWindowSize(), GetCanvasSize());
}

Vector2 GetOrigin()
{
    return Vector2Subtract(
        Vector2Scale(GetWindowSize(), 0.5f),
        Vector2Scale({(float)GetScreenWidth(), (float)GetScreenHeight()}, 0.5f));
}