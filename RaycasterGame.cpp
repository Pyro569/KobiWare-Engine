#include "Engine/KobiWare.Raycaster.h"
#include <KobiWare/KobiWare.Window.h>

int main(int argc, char *argv[])
{
    createWindow(800, 600, "Raycaster", 0);
    px = 300;
    py = 300;
    pdx = cos(pa) * 5;
    pdy = sin(pa) * 5;
    glutDisplayFunc(raycast);
    glutKeyboardFunc(_buttons);
    displayLoop();
}