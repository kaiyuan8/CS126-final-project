#include "area_container.h"
#include "person.h"
#include <iostream>
#include <map>
#include <math.h>

namespace covidsim {

using glm::vec2;

AreaContainer::AreaContainer() {
  index_ = 0;
}

void AreaContainer::AddPerson(bool isHealthy) {
  std::vector<vec2> routes;
  for (int i = 0; i < kDefaultMaxRoute; i++) {
    float x_position = static_cast<float>(rand() %
                                          static_cast<int>(kWindowSize - 3 * kMargin) + kMargin / 2);
    float y_position = static_cast<float>(rand() %
                                          static_cast<int>(kWindowSize - kMargin) + kMargin / 2);
    routes.push_back(vec2(x_position, y_position));
  }
  Person* p = new Person(isHealthy ? kDefaultHealthyStatus : kDefaultCovidStatus,
                         kDefaultSpeed, routes,
                         std::vector<bool>({false, false, false}));
  people_.push_back(p);
}

void AreaContainer::Display() const {
  if (!people_.empty()) {
    for (size_t i = 0; i < people_.size(); i++) {
      auto each = people_[i];
      ci::gl::color(each->getStatus());
      if (index_ == i) {
        ci::gl::color(kDefaultSelectStatus);
      }
      ci::gl::drawSolidCircle(each->getPosition(), kDefaultPersonSize);
    }
  }

  ci::gl::color(kDefaultBoardColor);
  ci::gl::drawStrokedRect(ci::Rectf(glm::vec2(kMargin / 2, kMargin / 2),
            glm::vec2(kWindowSize - kMargin * 5 / 2,kWindowSize - kMargin / 2)));
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

void AreaContainer::GetNextPerson() {
  if (!people_.empty()) {
    index_ = (index_ + 1) % people_.size();
  }
}


}  // namespace idealgas
