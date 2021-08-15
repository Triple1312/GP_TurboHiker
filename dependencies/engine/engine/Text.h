// https://learnopengl.com/code_viewer_gh.php?code=src/7.in_practice/2.text_rendering
#ifndef GP_DEPENDENCIES_ENGINE_ENGINE_TEXT_H_
#define GP_DEPENDENCIES_ENGINE_ENGINE_TEXT_H_

#include <ft2build.h>
#include <glad/glad.h>

#include <glm/vec2.hpp>
#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <vector>
#include FT_FREETYPE_H

#include "Renderer.h"
#include "VertexBufferLayout.h"
#include "Texture.h"

struct Char {
  unsigned int texture_id_;  // ID handle of the glyph texture
  glm::ivec2 size_;          // Size of glyph
  glm::ivec2 bearing_;       // Offset from baseline to left/top of glyph
  unsigned int advance_;     // Horizontal offset to advance to next glyph
};

class Text {
 public:
  void LoadFont(std::string);

  void SetString(std::string);

  void Draw();

  Text(const std::string &font, float x, float y, float scale);

 private:
  std::map<char, Char> chars_;
  glm::vec2 pos_;
  float scale_;
  std::array<uint32_t, 6> indeces_;
  Shader shader_ = Shader("recources/Shaders/text.shader");
  std::string string_;
  std::unique_ptr<VertexArray> vao_;
  VertexBuffer vbo_;
  std::unique_ptr<IndexBuffer> ibo_;
  glm::vec4 color_;
  FT_Library ft;
  FT_Face face;


  void GenChar(char c);

  // VertexBufferLayout vblo_;
};

#endif  // GP_DEPENDENCIES_ENGINE_ENGINE_TEXT_H_
