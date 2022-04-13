#include "covid_simulation_app.h"

namespace covidsim {

CovidSimApp::CovidSimApp() {
  ci::app::setWindowSize(kWindowSize, kWindowSize);
  std::vector<vec2> routes_1{ vec2()};
  for (int i = 0; i < kDefaultPopulationSize; i++) {
    std::random_shuffle(defaultShuffle.begin(), defaultShuffle.end());
    std::vector<vec2> routes;
    for (auto each : defaultShuffle) {
      routes.push_back(defaultRoutes[each]);
    }
    ci::Color color(float(0), float((i + 1) * 30), float(0));
    Person* p = new Person(color, float(i + 1), routes,
                          std::vector<bool>({false, false, false}));
    container_.AddPerson(p);
  }

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
