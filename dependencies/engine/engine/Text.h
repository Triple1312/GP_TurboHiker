//https://learnopengl.com/code_viewer_gh.php?code=src/7.in_practice/2.text_rendering
#ifndef GP_DEPENDENCIES_ENGINE_ENGINE_TEXT_H_
#define GP_DEPENDENCIES_ENGINE_ENGINE_TEXT_H_

#include <iostream>
#include <string>
#include <map>
#include <vector>

#include <glm/vec2.hpp>
#include <glad/glad.h>
#include <ft2build.h>
#include FT_FREETYPE_H

#include "Renderer.h"

struct Char {
  unsigned int texture_id_; // ID handle of the glyph texture
  glm::ivec2   size_;      // Size of glyph
  glm::ivec2   bearing_;   // Offset from baseline to left/top of glyph
  unsigned int advance_;   // Horizontal offset to advance to next glyph
};

class Text {
 public:

  void LoadFont(std::string);

  void SetString(std::string);

  void Draw();

  Text();

 private:
  std::map<char, Char> chars_;
  glm::vec2 pos_;
  float scale_;
  Shader shader_ = Shader("recources/Shaders/text.shader");
  std::string string_;

};

#endif //GP_DEPENDENCIES_ENGINE_ENGINE_TEXT_H_
