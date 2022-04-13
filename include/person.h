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
    Person();

    Person(const std::string &status, const std::vector<vec2> &routes, int routeIdx, const std::vector<bool> &health);

private:
  std::string status_;
  std::vector<vec2> routes_;
  int route_idx_;
  // only three checkers: has_mask_, has_vaccine_, has_immune_
  std::vector<bool> health_;

  const float kDefaultSize = 10;
};

}  // namespace idealgas