#ifndef OBJECT_H
#define OBJECT_H

#include "state.h"
#include <string>
#include <SDL2/SDL.h>

namespace cds::rend {
  class Object {
    public: 
      Object(const std::string& path);
      ~Object();

      virtual void update(State& system, float dt) {};
      int world_x();
      int world_y();

      int scale_x();
      int scale_y();

      SDL_Rect rect();
      SDL_Texture* texture();
      
      void set_scale(int x, int y);
      void set_scale_x(int x);
      void set_scale_y(int y);

      const std::string& texture_path();
      void load_texture(SDL_Texture* tex, int h, int w);

    protected:
      int m_world_x;
      int m_world_y;

    private:
      std::string m_tex_path;
      SDL_Texture* m_tex = nullptr;
      int m_tex_h;
      int m_tex_w;

      SDL_Rect m_rect;
      int m_scale_x;
      int m_scale_y;
  };
}

#endif
