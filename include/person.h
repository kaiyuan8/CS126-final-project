#pragma once

#include "cinder/gl/gl.h"

using glm::vec2;

namespace covidsim {

/**
 * The person in the map, which controls person movement and status
 */
class Person {
 public:
  Person(const ci::Color &status, float speed, const std::vector<vec2> &routes,
         const std::vector<bool> &health);

  const vec2 &getPosition() const;

  const vec2 &getVelocity() const;

  const ci::Color &getStatus() const;

  const std::vector<bool> &getHealth() const;

  void setHealth(const std::vector<bool> &health);

  void setStatus(const cinder::Color &status);

  /**
   * Change health status of index to desired one
   * @param index the index to change
   * @param status the status to change to
   */
  void setHealth(int index, bool status);

  /**
   * Advance one step towards next route point
   */
  void AdvanceOneStep();

 private:
  glm::vec2 position_;
  glm::vec2 velocity_;

  ci::Color status_;
  int route_idx_;
  float speed_;
  std::vector<vec2> routes_;

  // only three checkers: has_mask_, has_vaccine_, has_immune_
  std::vector<bool> health_;

  const float kDefaultSize = 10;
  const float kDefaultMargin = 5;

  /**
   * Update route goal to next goal if current is reached
   */
  void UpdateRoute();
};

}  // namespace covidsim