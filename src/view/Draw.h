//
// Created by Phili on 12/11/2020.
//

#ifndef GP_DRAW_H
#define GP_DRAW_H

#include <engine/IndexBuffer.h>
#include <engine/Shader.h>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <deque>
#include <fstream>
#include <glm/matrix.hpp>
#include <glm/vec4.hpp>
#include <memory>
#include <typeinfo>
#include <utility>
#include <vector>

#include "model/Entity.h"
#include "model/Lane.h"
#include "model/Obstacle.h"
#include "model/Player.h"

static sf::Clock cloBlub;
static float deltaTime = 0.0f;
static float lastFrame = 0.0f;

class Draw {
 public:
  Draw(sf::RenderWindow& window);

  //    void DrawEntities(std::deque<std::shared_ptr<logic::Entity>>&);

  //    void DrawLanes(std::deque<std::shared_ptr<logic::Lane>>&);

  //    std::shared_ptr<sf::RectangleShape> CalcFace(glm::vec4, glm::vec4,
  //    std::uint8_t);

  //    glm::mat4 GetRotateX(double angle);

 private:
  sf::RenderWindow& window;

  //    float scale = 60;

  //    float angle = 45; // specified in degrees

  //    std::unique_ptr<Shader> entity_shader;

  std::unique_ptr<IndexBuffer> cube_indeces;

  //    glm::mat4 view = glm::mat4(1.0f);
  //    glm::mat4 projection = glm::mat4(1.0f);
};

#endif  // GP_DRAW_H
