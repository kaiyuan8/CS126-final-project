#include "covid_simulation_app.h"

using covidsim::CovidSimApp;

void prepareSettings(CovidSimApp::Settings* settings) {
  settings->setResizable(false);
}

// This line is a macro that expands into an "int main()" function.
CINDER_APP(CovidSimApp, ci::app::RendererGl, prepareSettings);
