#ifndef CSURFACE_H_INCLUDED
#define CSURFACE_H_INCLUDED

#include <SDL.h>

class CSurface {
public:
    CSurface();

    static SDL_Surface* OnLoad(char* file);

    static bool OnDraw(SDL_Renderer* Renderer, SDL_Surface* Surf_Src, int X, int Y);

    static bool OnDraw(SDL_Renderer* Renderer, SDL_Surface* Surf_Src, int X, int Y, int X2, int Y2, int W, int H);

    static bool Transparent(SDL_Surface* Surf_Dest, int R, int G, int B);
};


#endif // CSURFACE_H_INCLUDED
