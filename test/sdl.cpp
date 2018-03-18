#include "../include/cwdrawer.hpp"
#include "image.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>

SDL_Window *Window = NULL;
SDL_Surface *WindowScreen = NULL;
SDL_Renderer *renderer = NULL;

class drawBMP:public cwdrawer::base{
  public:
    drawBMP():base(20,20){
        this->deflight=16;
    }
    virtual bool getUnusual(int x,int y){
        return pixelmap[y][x];
    }
    virtual void autorender(){
        backgroundmode=rand()%2;
        SDL_RenderClear(renderer);
        this->render();
        SDL_RenderPresent(renderer);
    }
    virtual void draw(int x,int y,int r,int g,int b){
        SDL_Rect sr;
        sr.x=x*30;
        sr.y=y*30;
        sr.w=30;
        sr.h=30;
        SDL_SetRenderDrawColor(renderer, r, g, b, 255);
        SDL_RenderFillRect(renderer,&sr);
    }
}bmp;
int main(){
    SDL_Event e;
    SDL_Init(SDL_INIT_VIDEO);
    Window = SDL_CreateWindow(
      "demo",
      SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
      600,                    600,
      SDL_WINDOW_SHOWN
    );
    if (Window == NULL){
      exit(1);
    }
    WindowScreen = SDL_GetWindowSurface(Window);
    renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED);
    while(1){
        while( SDL_PollEvent( &e ) != 0 ){
            if( e.type == SDL_QUIT ){
                return 0;
            }
        }
        bmp.autorender();
    }
    return 0;
}