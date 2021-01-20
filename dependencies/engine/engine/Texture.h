//
// Created by phil on 1/19/21.
//

#ifndef GP_DEPENDENCIES_ENGINE_ENGINE_TEXTURE_H_
#define GP_DEPENDENCIES_ENGINE_ENGINE_TEXTURE_H_

#include "Renderer.h"

class Texture {
 private:
  unsigned int m_RendererID;
  std::string m_Filepath;
  unsigned char* m_LocalBuffer;
  int m_Width, m_Height, m_BPP;

 public:
  int GetMWidth() const;
  int GetMHeight() const;

 public:
  explicit Texture(const std::string& path);
  ~Texture();

  void Bind(unsigned int slot = 0) const;
  void UnBind();

};

#endif  // GP_DEPENDENCIES_ENGINE_ENGINE_TEXTURE_H_
