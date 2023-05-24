#include <KobiWare/KobiWare.Include.h>

typedef struct
{
    int fScreen, sWidth, sHeight;
    char sName;
} ScreenValues;
ScreenValues screenValues;

void refresh()
{
    glutSwapBuffers();
}

void displayLoop()
{
    glutMainLoop();
}

void clear()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void init()
{
    glClearColor(0.3, 0.3, 0.3, 0);
}

void display2D()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glutSwapBuffers();
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
}