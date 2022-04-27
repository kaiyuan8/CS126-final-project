#include "covid_simulation_app.h"

namespace covidsim {

CovidSimApp::CovidSimApp() {
  index_ = 0;
  ci::app::setWindowSize(kWindowSize, kWindowSize);
  container_ = new AreaContainer(kWindowSize, kMargin);
  display_ = new AreaDisplay(kDefaultPersonSize, kWindowSize, kMargin);
}

void CovidSimApp::draw() {
  ci::Color background_color("black");
  ci::gl::clear(background_color);

  std::vector<Person*> people = container_->getPeople();
  display_->Display(people, index_);
}

void CovidSimApp::update() {
  container_->AdvanceOneFrame(kDefaultCovidStatus,
                              kDefaultPersonSize * kDefaultDistanceFactor);
}

void CovidSimApp::keyDown(cinder::app::KeyEvent event ) {
  if(event.getChar() == 'q' ) {
    container_->AddPerson(kDefaultHealthyStatus);
  }

  if(event.getChar() == 'w' ) {
    container_->AddPerson(kDefaultCovidStatus);
  }

  else if( event.getCode() == cinder::app::KeyEvent::KEY_SPACE ) {
    int count = container_->getPeople().size();
    if (count > 0) {
      index_ = (index_ + 1) % count;
    }
  }
}

}  // namespace idealgas
