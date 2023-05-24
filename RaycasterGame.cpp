#include <KobiWare/KobiWare.Raycaster.h>
#include <KobiWare/KobiWare.Window.h>

int main(int argc, char *argv[])
{
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    createWindow(800, 600, "Raycaster", 0);
    int screenWidth = glutGet(GLUT_SCREEN_WIDTH);
    int screenHeight = glutGet(GLUT_SCREEN_HEIGHT);
    init();
    glutDisplayFunc(raycast);
    glutKeyboardFunc(_buttons);
    displayLoop();
}