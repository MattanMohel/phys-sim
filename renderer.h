#ifndef RENDERER_H
#define RENDERER_H

#include "state.h"
#include "object.h"
#include <string>
#include <vector>
#include <SDL2/SDL.h>
#include <chrono>

// screen will be 16 x 12 meters
#define SCREEN_W 16
#define SCREEN_H 12

typedef std::chrono::steady_clock Clock;

namespace cds::rend {
  class Renderer {
    public:
      Renderer(int h, int w);
      ~Renderer();

      void push_obj(Object* obj);

      void resize(int h, int w);

      void entry();
      void log_error(const std::string& err);
      
      bool passing();
      void print_errors();

    private:
      // screen height and width in pixels
      int m_h;
      int m_w;

      // pixels per meter = height (pixels) / 12
      float m_ppm;

      SDL_Window* m_window = nullptr;
      SDL_Renderer* m_rend = nullptr;

      State m_state;
      std::vector<std::string> m_errs;
      std::vector<Object*> m_objs;
  };
}

#endif
