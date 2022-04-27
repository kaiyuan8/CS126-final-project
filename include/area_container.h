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

  /**
   * Get the people list as vector
   * @return Person in vector
   */
  const std::vector<Person*> &getPeople() const;

  /**
   * Add a person to the environment
   * @param isHealthy if the person is healthy
   */
  void AddPerson(bool isHealthy);

  const cinder::Color &getKDefaultCovidStatus() const;

  const cinder::Color &getKDefaultHealthyStatus() const;

  /**
   * Get next person to display
   */
  void GetNextPerson();

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
  int index_;

  const float kDefaultPersonSize = 5;
  const float kDefaultDistanceFactor = 3;
  const int kWindowSize = 875;
  const int kMargin = 100;
  const int kDefaultMaxRoute = 10;
  const float kDefaultSpeed = 1;
  const ci::Color kDefaultCovidStatus = ci::Color("red");
  const ci::Color kDefaultHealthyStatus = ci::Color("green");
  const ci::Color kDefaultSelectStatus = ci::Color("blue");
  const ci::Color kDefaultBoardColor = ci::Color("white");

  float EuclideanDistance(const vec2& a, const vec2& b);
};

}  // namespace idealgas
