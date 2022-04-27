#pragma once

#include "cinder/gl/gl.h"
#include "person.h"

using glm::vec2;

namespace covidsim {

/**
 * The engine to display
 */
class AreaDisplay {
public:
    AreaDisplay(float personSize, int windowSize, int margin);

    /**
   * Displays the area with people wondering in it
   */
  void Display(std::vector<Person*> people, int idx) const;

  /**
   * Display selected person
   * @param p the selected person
   */
  void DisplaySelected(Person* p) const;

private:
  float person_size_;
  int window_size_;
  int margin_;

  const ci::Color kDefaultSelectStatus = ci::Color("blue");
  const ci::Color kDefaultBoardColor = ci::Color("white");
  const ci::Color kDefaultStringColor = ci::Color("white");
  const float kDefaultFontSize = 30;
  const double kConditionDis = 0.5;

  const std::vector<std::string> kDefaultMsg = std::vector<std::string>(
            {"Wearing a Mask", "Fully Vaccinated", "Immunized"});

};

}  // namespace covidsim