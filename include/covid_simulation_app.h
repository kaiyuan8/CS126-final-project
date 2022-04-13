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

  const int kWindowSize = 875;
  const int kMargin = 100;

 private:
  AreaContainer container_;

  std::vector<vec2> defaultRoutes = {vec2(50, 50), vec2(50, 500),
                                     vec2(400, 50), vec2(400, 500),
                                     vec2(800, 50), vec2(800, 500)};
  std::vector<int> defaultShuffle = {0, 1, 2, 3, 4, 5};

  const int kDefaultPopulationSize = 5;
};

}  // namespace idealgas
