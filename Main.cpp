#include "KobiWareEngine.h"

int sx = rand() % 100;
int sy = rand() % 100;
int snakeSize = 8;

void PlaceSquareRandom()
{
    if ((px - sx <= 10 && px - sx >= 0) && (py - sy <= 10 && py - sy >= 0))
    {
        sx = rand() % 300;
        sy = rand() % 300;

        glColor3f(0, 1, 1);
        glPointSize(8);
        glBegin(GL_POINTS);
        glVertex2i(sx, sy);
        glEnd();
        glutSwapBuffers();

        snakeSize += 1;
    }
}

void InitialSquarePlace()
{
    glColor3f(0, 1, 1);
    glPointSize(8);
    glBegin(GL_POINTS);
    glVertex2i(sx, sy);
    glEnd();
    glutSwapBuffers();
}

void _drawPlayer2D()
{
    glColor3f(1, 1, 0);
    glPointSize(snakeSize);
    glBegin(GL_POINTS);
    glVertex2i(px, py);
    glEnd();
}

void _display2D()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    _drawPlayer2D();
    PlaceSquareRandom();
    InitialSquarePlace();
    glutSwapBuffers();

    if (input.w == 1)
    {
        py -= 5;
    }
    if (input.s == 1)
    {
        py += 5;
    }
    if (input.a == 1)
    {
        px -= 5;
    }
    if (input.d == 1)
    {
        px += 5;
    }
}

int main(int argc, char *argv[])
{
    px = 300;
    py = 300;
    createWindow(800, 600, "Snake", 0);
    InitialSquarePlace();
    glutDisplayFunc(_display2D);
    glutMainLoop();
}