#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <bits/stdc++.h>
using namespace std;

SDL_Window *window;
SDL_Event event;

int main(){
    window=SDL_CreateWindow("Window", 0, 0, 800, 800, SDL_WINDOW_OPENGL);

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);

    SDL_GLContext context=SDL_GL_CreateContext(window);

    while(window!=NULL){
        while(SDL_PollEvent(&event)){
            if(event.type==SDL_QUIT)
                window=NULL;
        }

        glClear(GL_COLOR_BUFFER_BIT);

        glBegin(GL_QUADS);
            glVertex2f(-0.5, 0.5);
            glVertex2f(0.5, 0.5);
            glVertex2f(0.5, -0.5);
            glVertex2f(-0.5, -0.5);
        glEnd();

        SDL_GL_SwapWindow(window);
    }
}
