#include "area_display.h"
#include "person.h"

namespace covidsim {

AreaDisplay::AreaDisplay(float personSize, int windowSize, int margin) {
  person_size_ = personSize;
  window_size_ = windowSize;
  margin_ = margin;
}

void AreaDisplay::Display(std::vector<Person*> people, int idx, std::vector<bool> setting) const {
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
  DisplaySetting(setting);

  ci::gl::color(kDefaultBoardColor);
  ci::gl::drawStrokedRect(ci::Rectf(glm::vec2(margin_ / 2, margin_ / 2),
                                    glm::vec2(window_size_ - margin_ * 5 / 2,
                                              window_size_ - margin_ / 2)));
}

void AreaDisplay::DisplaySetting(std::vector<bool> setting) const {
  ci::gl::color(kDefaultBoardColor);
  float pos1 = static_cast<float>(margin_);
  float pos2 = static_cast<float>(window_size_ - margin_ * 2);
  for (size_t i = 0; i < setting.size() - 1; i++) {
    if (setting[i]) {
      ci::gl::drawSolidRect(ci::Rectf(glm::vec2(pos2 + static_cast<float>(2 * i) / 2 * pos1, pos2),
                                      glm::vec2(pos2 + static_cast<float>(2 * i + 1) / 2 * pos1,
                                                pos2 + pos1)));
    } else {
      ci::gl::drawStrokedRect(ci::Rectf(glm::vec2(pos2 + static_cast<float>(2 * i) / 2 * pos1, pos2),
                                      glm::vec2(pos2 + static_cast<float>(2 * i + 1) / 2 * pos1,
                                                pos2 + pos1)));
    }
  }
}

void AreaDisplay::DisplaySelected(Person* p) const {
  ci::gl::color(kDefaultSelectStatus);
  ci::gl::drawSolidCircle(p->getPosition(), person_size_);

  float y_pos = static_cast<float>(margin_);
  float x_pos = static_cast<float>(window_size_ - margin_ * 2);
  std::vector<bool> condition = p->getHealth();

  ci::gl::color(p->getStatus());
  ci::gl::drawSolidCircle(glm::vec2(x_pos, y_pos), person_size_ * 4);

  ci::gl::color(kDefaultStringColor);
  for (size_t i = 0; i < kDefaultMsg.size(); i++) {
    ci::gl::drawString(kDefaultMsg[i], vec2(x_pos, y_pos *
    static_cast<float>(i + 2)),kDefaultStringColor,
                       ci::Font("helvetica", kDefaultFontSize));

    if (condition[i]) {
      ci::gl::drawSolidCircle(glm::vec2(x_pos + y_pos,y_pos *
      static_cast<float>(i + 2 + kConditionDis)), person_size_ * 4);
    } else {
      ci::gl::drawStrokedCircle(glm::vec2(x_pos + y_pos,y_pos *
      static_cast<float>(i + 2 + kConditionDis)), person_size_ * 4);
    }

  }
}

}  // namespace covidsim