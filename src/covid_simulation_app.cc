#include "covid_simulation_app.h"

namespace covidsim {

CovidSimApp::CovidSimApp() {
  ci::app::setWindowSize(kWindowSize, kWindowSize);
  Person p = new Person();
  container_.AddPerson()
}

void CovidSimApp::draw() {
  ci::Color background_color("black");
  ci::gl::clear(background_color);

  container_.Display();
}

void CovidSimApp::update() {
  container_.AdvanceOneFrame();
}

}  // namespace idealgas
