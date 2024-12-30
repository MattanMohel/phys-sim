#include "renderer.h"
#include <SDL2/SDL_image.h>
#include <iostream>

#define APP_NAME "phys-sim"

namespace cds::rend {
  Renderer::Renderer(int h, int w) {
    resize(h, w);

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) < 0) {
      log_error("SDL couldn't initialize!");
      return;
    }
    
    m_window = SDL_CreateWindow(APP_NAME, 0, 0, m_w, m_h, SDL_WINDOW_SHOWN);
    
    if (!m_window) {
      log_error("Window couldn't initialize!");
      return;
    }

    m_rend = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
  }

  Renderer::~Renderer() {
    SDL_DestroyRenderer(m_rend);
    SDL_DestroyWindow(m_window);
    SDL_Quit();
  }

  void Renderer::push_obj(Object* obj) {
    int w, h;
    SDL_Texture* tex = IMG_LoadTexture(m_rend, obj->texture_path().c_str()) ;
    
    if (!tex) {
      log_error("Couldn't load texture!");
    }

    SDL_QueryTexture(tex, NULL, NULL, &w, &h);
    obj->load_texture(tex, h, w);

    m_objs.emplace_back(obj);
  }

  void Renderer::resize(int h, int w) {
    m_h = h;
    m_w = w;
    m_ppm = (float) w / 16.0;
  }

  void Renderer::entry() {
    bool quit = false;
    SDL_Event e;

    auto time = Clock::now();

    while (!quit) {
      while (SDL_PollEvent(&e)) {
        switch (e.type) {
          case SDL_QUIT: 
            quit = true;
            break;
          default: break;
        }
 
        auto now = Clock::now();
        float dt = std::chrono::duration_cast<std::chrono::milliseconds>(now - time).count();
        time = now;

        SDL_RenderClear(m_rend);
        
        // update objects 
        for (Object* obj : m_objs) {
          obj->update(m_state, dt);

          SDL_Rect rect = obj->rect();

          // rescale
          rect.w = m_ppm * obj->scale_x();
          rect.h = m_ppm * obj->scale_y();

          rect.x = (m_ppm / 2) * SCREEN_W + rect.x - (float) rect.w / 2;
          rect.y = (m_ppm / 2) * SCREEN_H + rect.y - (float) rect.h / 2;

          SDL_RenderCopy(m_rend, obj->texture(), NULL, &rect);
        }
      
        SDL_RenderPresent(m_rend);
      }

      SDL_UpdateWindowSurface(m_window);
    }
  }

  void Renderer::log_error(const std::string& err) {
    /* debug */ std::cout << "ERROR!" << std::endl;
    m_errs.emplace_back(err);
  }

  bool Renderer::passing() {
    return m_errs.size() == 0;
  }

  void Renderer::print_errors() {
    for (const std::string& mes : m_errs) {
      std::cout << mes << std::endl;
    }
  }
}

