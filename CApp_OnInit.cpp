#include "CApp.h"

bool CApp::OnInit()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        return false;
    }

    if ((Screen = SDL_CreateWindow("My Game Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 600, 600, SDL_WINDOW_OPENGL)) == NULL) {
        return false;
    }

    Renderer = SDL_CreateRenderer(Screen, -1, 0);
    if (Renderer == NULL) {
        return false;
    }
//  Deprecated in 2.0
//    if ((Surf_Display = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE } SDL_DOUBLEBUF)) == NULL) {
//        return false;
//    }

    Surf_Grid = CSurface::OnLoad("./gfx/grid.bmp");
    if (Surf_Grid == NULL) return false;

    Surf_X = CSurface::OnLoad("./gfx/x.bmp");
    if (Surf_X == NULL) return false;

    Surf_O = CSurface::OnLoad("./gfx/o.bmp");
    if (Surf_O == NULL) return false;

    CSurface::Transparent(Surf_X, 255, 0, 255);
    CSurface::Transparent(Surf_O, 255, 0, 255);

    Reset();

    return true;
}
