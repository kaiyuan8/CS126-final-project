#include "area_display.h"
#include "person.h"

namespace covidsim {

AreaDisplay::AreaDisplay(float personSize, int windowSize, int margin) {
  person_size_ = personSize;
  window_size_ = windowSize;
  margin_ = margin;
}

void AreaDisplay::Display(std::vector<Person*> people, int idx) const {
  if (!people.empty()) {
    for (size_t i = 0; i < people.size(); i++) {
      auto each = people[i];
      if (idx == i) {
        DisplaySelected(each);
      } else {
        ci::gl::color(each->getStatus());
        ci::gl::drawSolidCircle(each->getPosition(), person_size_);
      }
    }
  }

  ci::gl::color(kDefaultBoardColor);
  ci::gl::drawStrokedRect(ci::Rectf(glm::vec2(margin_ / 2, margin_ / 2),
                                    glm::vec2(window_size_ - margin_ * 5 / 2,
                                              window_size_ - margin_ / 2)));
}

void AreaDisplay::DisplaySelected(Person* p) const {
  ci::gl::color(kDefaultSelectStatus);
  ci::gl::drawSolidCircle(p->getPosition(), person_size_);
}

}  // namespace covidsim