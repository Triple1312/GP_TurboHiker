//
// Created by phil on 1/19/21.
//

#include "Texture.h"
#include "stb_image.h"
int Texture::GetMWidth() const { return m_Width; }
int Texture::GetMHeight() const { return m_Height; }
Texture::Texture(const std::string& path):
                                            m_Filepath(path),
                                            m_LocalBuffer(nullptr),
                                            m_Width(0),
                                            m_Height(0),
                                            m_BPP(0),
                                            m_RendererID(0) {
  stbi_set_flip_vertically_on_load(1);
  m_LocalBuffer = stbi_load(path.c_str(), &m_Width, &m_Height, &m_BPP, 4);
  glGenTextures(1, &m_RendererID);
  glBindTexture(GL_TEXTURE_2D, m_RendererID);

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_Width, m_Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_LocalBuffer);
  glBindTexture(GL_TEXTURE_2D, 0);
  if (m_LocalBuffer)
    stbi_image_free(m_LocalBuffer);
}
void Texture::UnBind() {
  glBindTexture(GL_TEXTURE_2D, 0);
}
Texture::~Texture() {
  glDeleteTextures(1, &m_RendererID);
}
void Texture::Bind(unsigned int slot) const {
  glActiveTexture(GL_TEXTURE0 + slot);
  glBindTexture(GL_TEXTURE_2D, m_RendererID);
}
