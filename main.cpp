#include "include/raylib.h"
#include "include/helper.h"

#include <cmath>
#include <stdio.h>

#define S_WIDTH 800
#define S_HEIGHT 450

int CircleVCircle() {
    float x1 = 100.0f;
    float y1 = 100.0f;

    float x2 = 170.0f;
    float y2 = 100.0f;

    float xSpeed1 = 2.0f;
    float ySpeed1 = 3.0f;

    float xSpeed2 = -1.0f;
    float ySpeed2 = 2.0f;

    InitWindow(S_WIDTH, S_HEIGHT, "raylib [core] example - basic window");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        x1 += xSpeed1;
        y1 += ySpeed1;

        x2 += xSpeed2;
        y2 += ySpeed2;

        if (x1 < 0 || x1 > S_WIDTH) {
            xSpeed1 *= -1.0f;
        }

        if (y1 < 0 || y1 > S_HEIGHT) {
            ySpeed1 *= -1.0f;
        }

        if (x2 < 0 || x2 > S_WIDTH) {
            xSpeed2 *= -1.0f;
        }

        if (y2 < 0 || y2 > S_HEIGHT) {
            ySpeed2 *= -1.0f;
        }

        if (dist(x1, y1, x2, y2) < 75) {
            xSpeed1 *= -1.0f;
            ySpeed1 *= -1.0f;

            xSpeed2 *= -1.0f;
        } 

        BeginDrawing();
            ClearBackground(BLACK);
            DrawCircle(x1, y1, 25, RED);
            DrawCircle(x2, y2, 50, GREEN);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}

int RectangleVRectangle() {
    Vector2 mousePos = GetMousePosition();

    float rectX = 300.0f;
    float rectY = 100.0f; 

    float rectWidth = 300.0f;
    float rectHeight = 200.0f;

    auto rectColor = GREEN;

    InitWindow(S_WIDTH, S_HEIGHT, "Rectangle V Rectangle");
    SetTargetFPS(60);

    while (!WindowShouldClose()) 
    {
        mousePos = GetMousePosition();

        if (mousePos.x > rectX && mousePos.x < rectX + rectWidth) {
            if (mousePos.y > rectY && mousePos.y < rectY + rectHeight) {
                rectColor = RED;
            }
        } else {
            rectColor = GREEN;
        }

        BeginDrawing();
            DrawRectangle(rectX, rectY, rectWidth, rectHeight, rectColor);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}

int main(void)
{ 
    return RectangleVRectangle();
}