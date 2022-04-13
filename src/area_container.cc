#include "area_container.h"
#include "person.h"
#include <iostream>
#include <map>
#include <math.h>

namespace covidsim {

using glm::vec2;

AreaContainer::AreaContainer() {
}

void AreaContainer::AddPerson(Person p) {
  people_.push_back(p);
}

void AreaContainer::Display() const {
  for (auto each : people_) {
    ci::gl::color(each.getStatus());
    ci::gl::drawSolidCircle(each.getPosition(), kDefaultPersonSize);
  }
}

void AreaContainer::AdvanceOneFrame() {
  for (auto each : people_) {
    each.AdvanceOneStep();
  }
}

const std::vector<Person> &AreaContainer::getPeople() const {
  return people_;
}

}  // namespace idealgas
