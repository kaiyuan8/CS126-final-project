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
  AreaContainer();

  const std::vector<Person*> &getPeople() const;

  void AddPerson(Person* p);

  const cinder::Color &getKDefaultCovidStatus() const;

  const cinder::Color &getKDefaultHealthyStatus() const;

    /**
     * Displays the area with people wondering in it
     */
  void Display() const;

  /**
   * Updates the positions and velocities of all people
   */
  void AdvanceOneFrame();

 private:
  std::vector<Person*> people_;

  const float kDefaultPersonSize = 10;
  const float kDefaultDistanceFactor = 3;
  const ci::Color kDefaultCovidStatus = ci::Color("red");
  const ci::Color kDefaultHealthyStatus = ci::Color("green");
    const ci::Color kDefaultSelectStatus = ci::Color("blue");

  float EuclideanDistance(const vec2& a, const vec2& b);
  void CheckContact();
};

}  // namespace idealgas
