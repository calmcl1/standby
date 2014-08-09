#include <SDL2/SDL.h>
#include <stdio.h>
#include <unistd.h>
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>

using namespace std;
int main(int argc, char* argv[])
{
    // Initialize SDL with the audio and video modules.
    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0)
    {
        fprintf(stderr,"%s",SDL_GetError());
        SDL_Quit();
        return 1;
    }
    else
    {
        printf("SDL initialized with audio and video\n");
    }

    av_register_all();

    SDL_Window *window;
    SDL_Renderer *renderer;

    printf("Creating window: %d",SDL_CreateWindowAndRenderer(640,480,0,&window,&renderer));

    SDL_SetRenderDrawColor(renderer,255,0,255,255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);

    sleep(3);

    SDL_Quit();
}
