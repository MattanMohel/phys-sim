#include "object.h"

namespace cds::rend {
  Object::Object(const std::string& tex_path) : m_tex_path(tex_path) {
    m_rect.x = 0;
    m_rect.y = 0;
  }

  Object::~Object() {
    SDL_DestroyTexture(m_tex);
  }

  const std::string& Object::texture_path() { return m_tex_path; } 

  void Object::load_texture(SDL_Texture* tex, int h, int w) {
    m_tex = tex;  
    m_tex_h = h;
    m_tex_w = w;

    set_scale(1, 1);
  }

  int Object::world_x() { return m_world_x; }
  int Object::world_y() { return m_world_y; }

  int Object::scale_x() { return m_scale_x; }
  int Object::scale_y() { return m_scale_y; }

  SDL_Rect Object::rect() { return m_rect; }

  SDL_Texture* Object::texture() { return m_tex; } 

  void Object::set_scale(int x, int y) {
    m_scale_x = x;
    m_scale_y = y;

    // rescale
    m_rect.w = m_tex_w;
    m_rect.h = m_tex_h;
  }

  void Object::set_scale_x(int x) {
    set_scale(x, m_scale_y);
  }

  void Object::set_scale_y(int y) {
    set_scale(m_scale_x, y);
  }
}
