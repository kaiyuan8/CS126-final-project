#pragma once

#include "cinder/gl/gl.h"

using glm::vec2;

namespace covidsim {

/**
 * The particle in the gas container. Particle
 * stores the particle information including position and velocity.
 */
class Person {
public:
    Person(const std::string &status, float speed, const std::vector<vec2> &routes,
           const std::vector<bool> &health);

    const vec2 &getPosition() const;

    const vec2 &getVelocity() const;

    const std::string &getStatus() const;

private:
  glm::vec2 position_;
  glm::vec2 velocity_;

  std::string status_;
  int route_idx_;
  float speed_;
  std::vector<vec2> routes_;

  // only three checkers: has_mask_, has_vaccine_, has_immune_
  std::vector<bool> health_;

  const float kDefaultSize = 10;
  const float kDefaultMargin = 5;

  void UpdateRoute();
};

}  // namespace idealgas