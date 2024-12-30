#include <SDL2/SDL.h>
#include <iostream>
#include "renderer.h"
#include "test_obj.h"

#define STB_IMAGE_IMPLEMENTATION

#include "include/stb_image.h"

#define SCREEN_WIDTH  640
#define SCREEN_HEIGHT 480

void SDL_log (const char* mes) {
  printf("%s Error: %s\n", mes, SDL_GetError());
}

bool init (SDL_Window** window, SDL_Surface** surface) {
  SDL_Quit();
  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) < 0) {
    SDL_log("SDL Could Not Initialize!");
    return false;
  }
  else {
    *window = SDL_CreateWindow("phys-sim", 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    if (!(*window)) {
      SDL_log("Window could not be created!");
      return false;
    } 
    else {
      *surface = SDL_GetWindowSurface(*window);
    }
  }

  return true;
}

void close (SDL_Window* window, SDL_Surface* surface) {
  SDL_FreeSurface(surface);
  SDL_DestroyWindow(window);
  SDL_Quit();
}

bool loadMedia (SDL_Surface** surface, const char* path) {
  *surface = SDL_LoadBMP(path);
  
  if (!(*surface)) {
    SDL_log("Couldn't load image path!");
    return false;
  }

  printf("loaded!\n");

  return true;
}

int main (int argc, char** args) {
  // SDL_Window*  window  = nullptr;
  // SDL_Surface* surface = nullptr;
  // SDL_Surface* image   = nullptr;
  // SDL_Event e;

 
  // if (!init(&window, &surface)) return 0;
  // if (!loadMedia(&image, "space.bmp")) return 0;
 
  // bool quit = false; 
  // while (quit == false) { 
    // while (SDL_PollEvent(&e) != 0) { 
      // if (e.type == SDL_QUIT) { 
        // quit = true; 
      // }
      // else if (e.type == SDL_KEYDOWN) {
        // switch (e.key.keysym.sym) {
          // case SDLK_DOWN: {
            // printf("down\n");
            // break;

          // }
        // }
      // }

      // SDL_BlitSurface(image, NULL, surface, NULL);
      // SDL_UpdateWindowSurface(window);
    // } 
  // }

  // close(window, surface);


  cds::rend::Renderer rend(480, 640);
  cds::rend::TestObj* obj = new cds::rend::TestObj();
  rend.push_obj(obj);

  rend.print_errors();

  rend.entry();

  return 0;
}
