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
   * Displays the container walls and the current positions of the particles.
   */
  void Display() const;

  /**
   * Updates the positions and velocities of all particles (based on the rules
   * described in the assignment documentation).
   */
  void AdvanceOneFrame();

 private:
  int dummy_variable_ = 0;
};

}  // namespace idealgas
