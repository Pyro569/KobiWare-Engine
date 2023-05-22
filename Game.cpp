#include "Engine/KobiWareEngine.h"
#include "Engine/KobiWare.System.h"
#include "Engine/KobiWare.Math.h"
#include "Engine/KobiWare.Window.h"
#include "Engine/KobiWare.2DSystem.h"

int sx = rand() % 100;
int sy = rand() % 100;
int snakeSize = 1;

void PlaceSquareRandom()
{
    if ((px - sx <= 15 && px - sx >= 0) && (py - sy <= 15 && py - sy >= 0))
    {
        sx = rand() % 300;
        sy = rand() % 300;

        drawLine(0, 1, 1, 8, sx, sy);
        refresh();

        snakeSize += 1;

        debugLog("\nSquare eaten");
    }
}

void InitialSquarePlace()
{
    drawLine(0, 1, 1, 8, sx, sy);
    refresh();
}

void _drawPlayer2D()
{
    for (int i = 1; i <= snakeSize; i++)
    {
        drawLine(1, 1, 0, 8, px + i, py);
    }
}

void _display2D()
{
    clear();
    _drawPlayer2D();
    PlaceSquareRandom();
    InitialSquarePlace();

    inputCase2D(15, 15);
}

int main(int argc, char *argv[])
{
    px = 300;
    py = 300;
    createWindow(800, 600, "Snake", 0);
    InitialSquarePlace();
    glutDisplayFunc(_display2D);
    displayLoop();
}