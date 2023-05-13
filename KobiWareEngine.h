#include <GL/glut.h>
#include <stdio.h>
#include <string>
#include <iostream>

int px, py;
int fScreen = 0;
int sWidth = 800, sHeight = 600;

typedef struct
{
    int fScreen, sWidth, sHeight;
    char sName;
} ScreenValues;
ScreenValues screenValues;

typedef struct{
    int xIncr, yIncr;
} InputIncrements;
InputIncrements inptIncr;

typedef struct
{
    int w, a, s, d;
} _Input2D;
_Input2D input;

void inputCase(int xIncr, int yIncr){
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

void clear(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

bool inRange(unsigned low, unsigned high, unsigned x)
{
    return ((x - low) <= (high - low));
}

void drawLine(float r, float g, float b, int size, int x, int y)
{
    glColor3f(r, g, b);
    glPointSize(size);
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void drawPlayer2D()
{
    glColor3f(1, 1, 0);
    glPointSize(8);
    glBegin(GL_POINTS);
    glVertex2i(px, py);
    glEnd();
}

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

void init()
{
    glClearColor(0.3, 0.3, 0.3, 0);
    gluOrtho2D(0, 800, 600, 0);
}

void display2D()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
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

void createWindow(int width, int height, char *name, int _fScreen)
{
    screenValues.sWidth = width;
    screenValues.sHeight = height;
    screenValues.fScreen = _fScreen;
    int argc = 1;
    char *argv[1] = {(char *)"Something"};
    std::cout << "\nCreating window named " << screenValues.sName << " of size " << screenValues.sWidth << " X " << screenValues.sHeight;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(width, height);
    glutCreateWindow(name);
    init();
    if (_fScreen == 1)
    {
        glutFullScreen();
        std::cout << "\nEntering fullscreen";
    }
    else
    {
        std::cout << "\nNon-fullscreen";
    }
    glutKeyboardFunc(input2DDown);
    glutKeyboardUpFunc(input2DUp);
}