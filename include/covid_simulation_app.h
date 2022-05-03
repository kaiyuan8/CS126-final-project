#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "area_container.h"
#include "area_display.h"

namespace covidsim {

/**
 * An app for visualizing the behavior of an ideal gas.
 */
class CovidSimApp : public ci::app::App {
 public:
  CovidSimApp();

  void draw() override;
  void update() override;
  void keyDown(ci::app::KeyEvent event) override;

  const int kWindowSize = 875;
  const int kMargin = 100;
  const float kDefaultPersonSize = 5;
  const float kDefaultDistanceFactor = 3;
  const ci::Color kDefaultCovidStatus = ci::Color("red");
  const ci::Color kDefaultHealthyStatus = ci::Color("green");

 private:
  int index_;
  std::vector<bool> status_;
  AreaContainer* container_;
  AreaDisplay* display_;

};

}  // namespace idealgas
