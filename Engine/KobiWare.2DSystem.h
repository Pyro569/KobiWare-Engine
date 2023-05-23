#include <KobiWare/KobiWare.Include.h>

void drawLine(float r, float g, float b, int size, int x, int y)
{
    glColor3f(r, g, b);
    glPointSize(size);
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void drawPlayer2D(int x, int y)
{
    glColor3f(1, 1, 0);
    glPointSize(8);
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}