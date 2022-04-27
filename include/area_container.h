#pragma once

#include "cinder/gl/gl.h"
#include "person.h"

using glm::vec2;

namespace covidsim {

/**
 * The container in which all of the gas particles are contained. This class
 * stores all of the particles and updates them on each frame of the simulation.
 */
class AreaContainer {
 public:
    AreaContainer(int windowSize, int margin);

    /**
     * Get the people list as vector
     * @return Person in vector
     */
  const std::vector<Person*> &getPeople() const;

  /**
   * Add a person to the environment
   * @param status if the person is healthy
   */
  void AddPerson(ci::Color status);

  /**
   * Add a person to the environment
   * @param p the new Person
   */
  void AddPerson(Person* p);

  /**
   * Advance one frame for all person in area
   * @param status the status that needs to update
   * @param distance the distance to consider contact
   */
  void AdvanceOneFrame(ci::Color status, float distance);

private:
  int window_size_;
  int margin_;
  std::vector<Person*> people_;

  const int kDefaultMaxRoute = 10;
  const float kDefaultSpeed = 1;

  float AreaContainer::EuclideanDistance(const vec2& a, const vec2& b);
};

}  // namespace covidsim
