#include "area_container.h"
#include "person.h"
#include <iostream>
#include <map>
#include <math.h>

namespace covidsim {

using glm::vec2;

AreaContainer::AreaContainer(int windowSize, int margin) :
      window_size_(windowSize), margin_(margin) {}

void AreaContainer::AddPerson(ci::Color status, std::vector<bool> cond) {
  std::vector<vec2> routes;
  for (int i = 0; i < kDefaultMaxRoute; i++) {
    float x_position = static_cast<float>(rand() %
               static_cast<int>(window_size_ - 3 * margin_) + margin_ / 2);
    float y_position = static_cast<float>(rand() %
               static_cast<int>(window_size_ - margin_) + margin_ / 2);
    routes.push_back(vec2(x_position, y_position));
  }
  Person* p = new Person(status,kDefaultSpeed, routes,cond);
  people_.push_back(p);
}

void AreaContainer::AddPerson(Person* p) {
  people_.push_back(p);
}

const std::vector<Person*> &AreaContainer::getPeople() const {
  return people_;
}

void AreaContainer::AdvanceOneFrame(ci::Color status, float distance) {
  for (auto each : people_) {
    each->AdvanceOneStep();
    if (each->getStatus() == status) {
      for (auto other : people_) {
        if (EuclideanDistance(each->getPosition(), other->getPosition()) <= distance) {
          std::vector<bool> vec = other->getHealth();
          if (UpdateStatus(vec)) {
            other->setStatus(status);
          }
        }
      }
    }
  }
}

float AreaContainer::EuclideanDistance(const vec2& a, const vec2& b) {
  float x = a[0] - b[0];
  float y = a[1] - b[1];
  return std::sqrt(std::pow(x, 2) + pow(y, 2));
}

bool AreaContainer::UpdateStatus(std::vector<bool> vec) {
  float threshold = 1;
  for (auto each : vec) {
    if (each) {
      threshold *= kDefaultDecayRate;
    }
  }
  return ((float) rand()/RAND_MAX) < threshold;
}

}  // namespace covidsim
