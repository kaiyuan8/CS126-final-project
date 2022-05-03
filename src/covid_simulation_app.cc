#include "covid_simulation_app.h"

namespace covidsim {

CovidSimApp::CovidSimApp() {
  index_ = 0;
  for (int i = 0; i < 3; i++) {
    status_.push_back(false);
  }
  ci::app::setWindowSize(kWindowSize, kWindowSize);
  container_ = new AreaContainer(kWindowSize, kMargin);
  display_ = new AreaDisplay(kDefaultPersonSize, kWindowSize, kMargin);
}

void CovidSimApp::draw() {
  ci::Color background_color("black");
  ci::gl::clear(background_color);

  std::vector<Person*> people = container_->getPeople();
  display_->Display(people, index_, status_);
}

void CovidSimApp::update() {
  container_->AdvanceOneFrame(kDefaultCovidStatus,
                              kDefaultPersonSize * kDefaultDistanceFactor);
}

void CovidSimApp::keyDown(cinder::app::KeyEvent event ) {
  if(event.getChar() == 'k' ) {
    container_->AddPerson(kDefaultHealthyStatus, status_);
  }

  if(event.getChar() == 'l' ) {
    container_->AddPerson(kDefaultCovidStatus, status_);
  }

  if(event.getChar() == 'q' ) {
    status_[0] = !status_[0];
  }

  if(event.getChar() == 'w' ) {
    status_[1] = !status_[1];
  }

  else if( event.getCode() == cinder::app::KeyEvent::KEY_SPACE ) {
    int count = container_->getPeople().size();
    if (count > 0) {
      index_ = (index_ + 1) % count;
    }
  }
}

}  // namespace idealgas
