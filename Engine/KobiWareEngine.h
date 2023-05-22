#include "KobiWare.Include.h"

void drawPlayer2D()
{
    glColor3f(1, 1, 0);
    glPointSize(8);
    glBegin(GL_POINTS);
    glVertex2i(0, 0);
    glEnd();
}