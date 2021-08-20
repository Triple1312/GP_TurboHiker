
#ifndef GP_SRC_VIEW_MENU_H_
#define GP_SRC_VIEW_MENU_H_

#include <glad/glad.h>

#define GLT_IMPLEMENTATION
#include "Utils/gltext.h"

namespace view {

class Menu {
  GLTtext* name = gltCreateText();
  GLTtext* play_ = gltCreateText();
  GLTtext* press_play_ = gltCreateText();
  GLTtext* highscore_ = gltCreateText();

 public:
  void Display();

  explicit Menu();

  ~Menu();
};
} //namespace view

#endif  // GP_SRC_VIEW_MENU_H_
