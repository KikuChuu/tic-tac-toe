#include "CSurface.h"

CSurface::CSurface()
{

}

SDL_Surface* CSurface::OnLoad(char* File)
{
    SDL_Surface* Surf_Temp = NULL;
    SDL_Texture* Texture_Return = NULL;

    Surf_Temp = SDL_LoadBMP(File);
    if (Surf_Temp == NULL) return NULL;

    //SDL_FreeSurface(Surf_Temp);

    return Surf_Temp;
}

bool CSurface::OnDraw(SDL_Renderer* Renderer, SDL_Surface* Surf_Src, int X, int Y)
{
    if (Surf_Src == NULL) return false;

    SDL_Texture* Texture_Src = SDL_CreateTextureFromSurface(Renderer, Surf_Src);

    int img_width, img_height;
    SDL_QueryTexture(Texture_Src , NULL, NULL, &img_width, &img_height);

    SDL_Rect DestR;

    DestR.x = X;
    DestR.y = Y;
    DestR.w = img_width;
    DestR.h = img_height;

//    SDL_RenderClear(Renderer);
    SDL_RenderCopy(Renderer, Texture_Src, NULL, &DestR);
    SDL_DestroyTexture(Texture_Src);
    return true;
}

bool CSurface::OnDraw(SDL_Renderer* Renderer, SDL_Surface* Surf_Src, int X, int Y, int X2, int Y2, int W, int H)
{
    if (Surf_Src == NULL) return false;

    SDL_Texture* Texture_Src = SDL_CreateTextureFromSurface(Renderer, Surf_Src);

    SDL_Rect DestR;

    DestR.x = X;
    DestR.y = Y;
    DestR.w = W;
    DestR.h = H;

    SDL_Rect SrcR;

    SrcR.x = X2;
    SrcR.y = Y2;
    SrcR.w = W;
    SrcR.h = H;

//    SDL_RenderClear(Renderer);
    SDL_RenderCopy(Renderer, Texture_Src, &SrcR, &DestR);
    SDL_DestroyTexture(Texture_Src);
    return true;
}

bool CSurface::Transparent(SDL_Surface* Surf_Dest, int R, int G, int B)
{
    if (Surf_Dest == NULL) {
        return false;
    }

    SDL_SetColorKey(Surf_Dest, SDL_TRUE | SDL_RLEACCEL, SDL_MapRGB(Surf_Dest->format, R, G, B));

    return true;
}
