#include "person.h"

namespace covidsim {

Person::Person(const ci::Color &status, float speed,
               const std::vector<vec2> &routes, const std::vector<bool> &health) :
               status_(status), speed_(speed),
               routes_(routes), health_(health) {
  assert(routes.size() >= 2);
  position_ = routes_[0];
  velocity_ = glm::normalize(routes_[1] - routes_[0]) * speed_;
  route_idx_ = 1;
}

const vec2 &Person::getPosition() const {
  return position_;
}

const vec2 &Person::getVelocity() const {
  return velocity_;
}

const ci::Color &Person::getStatus() const {
  return status_;
}

void Person::setStatus(const cinder::Color &status) {
  status_ = status;
}

void Person::AdvanceOneStep() {
  UpdateRoute();
  position_ += velocity_;
}

void Person::UpdateRoute() {
  if (glm::distance(position_, routes_[route_idx_]) <= kDefaultMargin) {
    position_ = routes_[route_idx_];
    int new_idx = (route_idx_ + 1) % routes_.size();
    velocity_ = glm::normalize(routes_[new_idx] - routes_[route_idx_]) * speed_;
    route_idx_ = new_idx;
  }
}

}  // namespace idealgas