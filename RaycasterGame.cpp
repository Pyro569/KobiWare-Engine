#include "Engine/KobiWare.Raycaster.h"
#include <KobiWare/KobiWare.Window.h>

int main(int argc, char *argv[])
{
    int screenWidth = glutGet(GLUT_SCREEN_WIDTH);
    int screenHeight = glutGet(GLUT_SCREEN_HEIGHT);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    createWindow(screenWidth, screenHeight);
    winInitSize(screenWidth, screenHeight);
    glutDisplayFunc(raycast);
    glutKeyboardFunc(_buttons);
}