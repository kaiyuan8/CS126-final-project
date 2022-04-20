#include "area_container.h"
#include "person.h"
#include <iostream>
#include <map>
#include <math.h>

namespace covidsim {

using glm::vec2;

AreaContainer::AreaContainer() {
}

void AreaContainer::AddPerson(Person* p) {
  people_.push_back(p);
}

void AreaContainer::Display() const {
  for (auto each : people_) {
    ci::gl::color(each->getStatus());
    ci::gl::drawSolidCircle(each->getPosition(), kDefaultPersonSize);
  }
}

void AreaContainer::AdvanceOneFrame() {
  for (auto each : people_) {
    each->AdvanceOneStep();
    if (each->getStatus() == kDefaultCovidStatus) {
      for (auto other : people_) {
        if (EuclideanDistance(each->getPosition(), other->getPosition()) <=
            kDefaultDistanceFactor * kDefaultPersonSize) {
          other->setStatus(kDefaultCovidStatus);
        }
      }
    }
  }
}

const std::vector<Person*> &AreaContainer::getPeople() const {
  return people_;
}

float AreaContainer::EuclideanDistance(const vec2& a, const vec2& b) {
  float x = a[0] - b[0];
  float y = a[1] - b[1];
  return std::sqrt(std::pow(x, 2) + pow(y, 2));
}

const cinder::Color &AreaContainer::getKDefaultCovidStatus() const {
  return kDefaultCovidStatus;
}

const cinder::Color &AreaContainer::getKDefaultHealthyStatus() const {
  return kDefaultHealthyStatus;
}


}  // namespace idealgas
