#include<SDL3/SDL.h>
#include<SDL3_ttf/SDL_ttf.h>
#include<iostream>
#include<string>
#define WIDTH 720
#define HEIGHT 1000
#define A 100
#define W 50

void Drawparts(SDL_Surface* psurface,int x,Uint32 COLOR){

    for (int i = 5;i <= x;i+=1){
        float width = WIDTH*5/x;
        SDL_Rect parts = {WIDTH/2 - width/2,i,width,1};
        SDL_FillSurfaceRect(psurface,&parts,COLOR);
    }

}

void RenderText(SDL_Surface*psurface,std::string text_str,int x,int y,int font_size){

    if (TTF_Init() == -1){
        printf("program is unable to initialize the library.the error is %s",SDL_GetError());
    }

    const char * text_char = text_str.c_str();

    TTF_Font*pfont = TTF_OpenFont("arial.ttf",font_size);
    SDL_Color textcolor = {255,98,235,255};
    SDL_Surface* ptextsurface = TTF_RenderText_Blended(pfont,text_char,0,textcolor);
    SDL_Rect textrect = {x,y,ptextsurface->w,ptextsurface->h};
    SDL_BlitSurface(ptextsurface,NULL,psurface,&textrect);
    SDL_DestroySurface(ptextsurface);
}

int main(){
    
    SDL_Window* pwindow = SDL_CreateWindow("SPRING SIMULATION",WIDTH,HEIGHT,0);
    SDL_Surface* psurface = SDL_GetWindowSurface(pwindow);

    SDL_Rect block = {WIDTH/2 - 25,HEIGHT/2,50,50};
    SDL_Rect spri_hook = {WIDTH/2 - 25,0,50,5};

    SDL_FillSurfaceRect(psurface,&spri_hook,0xFF0000);
    Drawparts(psurface,block.y,0xFF0000);
    SDL_FillSurfaceRect(psurface,&block,0xFFFFFF);

    SDL_UpdateWindowSurface(pwindow);

    bool is_running = true;
    SDL_Event event;
    float t = 1;
    int i = 1;
    bool start_sim = false;
    int space_count = 0;
    while (is_running){
        while (SDL_PollEvent(&event)){
            if (event.type == SDL_EVENT_QUIT){
                is_running = false;
                break;
            }
            if (event.type == SDL_EVENT_KEY_DOWN){

                if (event.key.key == SDLK_SPACE && start_sim){
                    start_sim = false;
                    space_count = 0;
                }
                if (event.key.key == SDLK_SPACE && space_count == 0){
                    start_sim = true;
                    space_count = 1;
                    SDL_Delay(50);
                }
            }
            
        }
        if (start_sim){

            SDL_FillSurfaceRect(psurface,&block,0x000000);
            
            Drawparts(psurface,block.y,0x000000);
            block.y = (100/i)*SDL_sin(W*t/i) + HEIGHT/2;//the function that we use to express oscillation x = Asin(wt)
            Drawparts(psurface,block.y,0x00FF00);
            SDL_FillSurfaceRect(psurface,&block,0xFFFFFF);
            
            std::string A_str = std::to_string(A);
            std::string block_y = std::to_string(block.y);
            RenderText(psurface,A_str,20,50,32);
            RenderText(psurface,block_y,20,20,32);

            SDL_UpdateWindowSurface(pwindow);

            SDL_Delay(1000/30);
            t+=1;
            i+=0.01;
        }

    }

}
