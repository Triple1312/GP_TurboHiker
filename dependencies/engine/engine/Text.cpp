//
// Created by ppp on 1/9/21.
//

#include "Text.h"
FT_Library ft;

void Text::LoadFont(std::string font_file) {
  FT_Face face;
  if (FT_New_Face(ft, font_file.c_str(), 0, &face)) {
    std::cout << "ERROR::FREETYPE: Failed to load font" << std::endl;
  } else {
    // set size to load glyphs as
    FT_Set_Pixel_Sizes(face, 0, 48);

    // disable byte-alignment restriction
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    // load first 128 characters of ASCII set
    for (unsigned char c = 0; c < 128; c++) {
      // Load character glyph
      if (FT_Load_Char(face, c, FT_LOAD_RENDER)) {
        std::cout << "ERROR::FREETYTPE: Failed to load Glyph" << std::endl;
        continue;
      }
      // generate texture
      unsigned int texture;
      glGenTextures(1, &texture);
      glBindTexture(GL_TEXTURE_2D, texture);
      glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, face->glyph->bitmap.width,
                   face->glyph->bitmap.rows, 0, GL_RED, GL_UNSIGNED_BYTE,
                   face->glyph->bitmap.buffer);
      // set texture options
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
      // now store character for later use
      Char character = {
          texture,
          glm::ivec2(face->glyph->bitmap.width, face->glyph->bitmap.rows),
          glm::ivec2(face->glyph->bitmap_left, face->glyph->bitmap_top),
          static_cast<unsigned int>(face->glyph->advance.x)};
      this->chars_.insert(std::pair<char, Char>(c, character));
    }
    glBindTexture(GL_TEXTURE_2D, 0);
  }
  FT_Done_Face(face);
}

Text::Text(const std::string &font)
    : color_({0.0, 0.0, 0.0, 1.0}),
      vbo_(VertexBuffer({}, 4 * 4 * sizeof(float))) {

  if (FT_Init_FreeType(&ft))
  {
    std::cout << "ERROR::FREETYPE: Could not init FreeType Library" << std::endl;
  }
  if (FT_New_Face(ft, font.c_str(), 0, &face))
  {
    std::cout << "ERROR::FREETYPE: Failed to load font" << std::endl;
  }

  this->shader_ = Shader("recources/Shaders/text.shader");
  indeces_ = {0, 1, 3,
              1, 2, 3};
  ibo_ = std::make_unique<IndexBuffer>((uint32_t *)&indeces_, 6);
  VertexBufferLayout vblo_;
  vblo_.Push(2);  // points
  vblo_.Push(2);  // texture coords
  vao_->AddBuffer(vbo_, vblo_);

}
void Text::SetString(std::string str) { this->string_ = str; }
void Text::Draw() {
  for (auto c : this->string_) {
    std::map<char, Char>::iterator it = chars_.find(c);
    if (it == chars_.end()) {

    }
    Char ch = this->chars_[c];
    float xpos = this->pos_.x + ch.bearing_.x * scale_;
    float ypos = this->pos_.y - (ch.size_.y - ch.bearing_.y) * scale_;

    float w = ch.size_.x * scale_;
    float h = ch.size_.y * scale_;
    // update VBO for each character
    float vertices[6][4] = {
        {xpos, ypos + h, 0.0f, 0.0f},    {xpos, ypos, 0.0f, 1.0f},
        {xpos + w, ypos, 1.0f, 1.0f},

        {xpos, ypos + h, 0.0f, 0.0f},    {xpos + w, ypos, 1.0f, 1.0f},
        {xpos + w, ypos + h, 1.0f, 0.0f}};
    Renderer::Get()->Draw(*vao_,*ibo_,shader_);
    // todo duidelijk niet af
  }
}
void Text::GenChar(char c) {
  if (FT_Load_Char(face, c, FT_LOAD_RENDER))
  {
    std::cout << "ERROR::FREETYTPE: Failed to load Glyph" << std::endl;
  }
  unsigned int texture;
  glGenTextures(1, &texture);
  glBindTexture(GL_TEXTURE_2D, texture);
  glTexImage2D(
      GL_TEXTURE_2D,
      0,
      GL_RED,
      face->glyph->bitmap.width,
      face->glyph->bitmap.rows,
      0,
      GL_RED,
      GL_UNSIGNED_BYTE,
      face->glyph->bitmap.buffer
  );
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  // now store character for later use
  Char character = {
      texture,
      glm::ivec2(face->glyph->bitmap.width, face->glyph->bitmap.rows),
      glm::ivec2(face->glyph->bitmap_left, face->glyph->bitmap_top),
      (uint32_t) face->glyph->advance.x
  };
  chars_.insert(std::pair<char, Char>(c, character));
}




















































