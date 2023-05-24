#include <KobiWare/KobiWare.Raycaster.h>
#include <KobiWare/KobiWare.Window.h>

int main(int argc, char *argv[])
{
    int screenWidth = glutGet(GLUT_SCREEN_WIDTH);
    int screenHeight = glutGet(GLUT_SCREEN_HEIGHT);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    createWindow(screenWidth, screenHeight, "Raycaster", 0);
    winInitSize(screenWidth, screenHeight);
    glutDisplayFunc(raycast);
    glutKeyboardFunc(_buttons);
}