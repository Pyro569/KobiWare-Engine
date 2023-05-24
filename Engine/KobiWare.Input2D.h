#include <KobiWare/KobiWare.Include.h>

float px, py;

typedef struct
{
    int w, a, s, d;
} _Input2D;
_Input2D input;

void input2DDown(unsigned char key, int x, int y)
{
    if (key == 'a')
    {
        input.a = 1;
    }
    if (key == 'd')
    {
        input.d = 1;
    }
    if (key == 'w')
    {
        input.w = 1;
    }
    if (key == 's')
    {
        input.s = 1;
    }
    if (key == 27)
    {
        glutDestroyWindow(1);
    }
    glutPostRedisplay();
}

void input2DUp(unsigned char key, int x, int y)
{
    if (key == 'a')
    {
        input.a = 0;
    }
    if (key == 'd')
    {
        input.d = 0;
    }
    if (key == 'w')
    {
        input.w = 0;
    }
    if (key == 's')
    {
        input.s = 0;
    }
    if (key == 27)
    {
        glutDestroyWindow(1);
        std::cout << "\nQuitting game";
    }
    glutPostRedisplay();
}

typedef struct
{
    int xIncr, yIncr;
} InputIncrements;
InputIncrements inptIncr;

void inputCase2D(int xIncr, int yIncr)
{
    if (input.w == 1)
    {
        py -= yIncr;
    }
    if (input.s == 1)
    {
        py += yIncr;
    }
    if (input.a == 1)
    {
        px -= xIncr;
    }
    if (input.d == 1)
    {
        px += xIncr;
    }
}