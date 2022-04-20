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
  if(event.getChar() == 'a' ) {
    ci::Color color("green");
    std::vector<vec2> routes;
    for (int i = 0; i < kMaxRoute; i++) {
      float x_position = static_cast<float>(rand() %
              static_cast<int>(kWindowSize - kMargin) + kMargin / 2);
      float y_position = static_cast<float>(rand() %
              static_cast<int>(kWindowSize - kMargin) + kMargin / 2);
      routes.push_back(vec2(x_position, y_position));
    }
    Person* p = new Person(color, 1, routes,
                           std::vector<bool>({false, false, false}));
    container_.AddPerson(p);
  }
//  else if( event.getCode() == KeyEvent::KEY_SPACE ) {
//    // Clear the list of points when the user presses the space bar.
//    mPoints.clear();
//  }
//  else if( event.getCode() == KeyEvent::KEY_ESCAPE ) {
//    // Exit full screen, or quit the application, when the user presses the ESC key.
//    if( isFullScreen() )
//      setFullScreen( false );
//    else
//      quit();
//  }
}

}  // namespace idealgas
