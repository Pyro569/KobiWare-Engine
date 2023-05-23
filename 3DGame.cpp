#include "Engine/KobiWare.3D.h"
#include <KobiWare/KobiWare.Window.h>

int main(int argc, char *argv[])
{
    createWindow(800, 600, "Cube", 1);
    glutDisplayFunc(displayCube);
    displayLoop();
}