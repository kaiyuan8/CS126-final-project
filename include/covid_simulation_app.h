#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "area_container.h"

namespace covidsim {

/**
 * An app for visualizing the behavior of an ideal gas.
 */
class CovidSimApp : public ci::app::App {
 public:
  CovidSimApp();

  void draw() override;
  void update() override;

  // TODO: Delete this comment. Feel free to play around with these variables
  // provided that you can see the entire UI on your screen.
  const int kWindowSize = 875;
  const int kMargin = 100;

 private:
  AreaContainer container_;
};

}  // namespace idealgas