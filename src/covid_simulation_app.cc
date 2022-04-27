#include "covid_simulation_app.h"

namespace covidsim {

CovidSimApp::CovidSimApp() {
  ci::app::setWindowSize(kWindowSize, kWindowSize);
}

void CovidSimApp::draw() {
  ci::Color background_color("black");
  ci::gl::clear(background_color);

  container_.Display();
}

void CovidSimApp::update() {
  container_.AdvanceOneFrame();
}

void CovidSimApp::keyDown(cinder::app::KeyEvent event ) {
  if(event.getChar() == 'q' ) {
    container_.AddPerson(true);
  }

  if(event.getChar() == 'w' ) {
    container_.AddPerson(false);
  }

  else if( event.getCode() == cinder::app::KeyEvent::KEY_SPACE ) {
    container_.GetNextPerson();
  }
}

}  // namespace idealgas
