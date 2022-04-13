#include <catch2/catch.hpp>
#include <iostream>
#include <area_container.h>

using covidsim::AreaContainer;
using covidsim::Person;

TEST_CASE("Person movement speed Test") {
  AreaContainer c;
  SECTION("Person direct movement with speed 1") {
    std::vector<vec2> routes = {vec2(0, 0), vec2(10, 0)};
    Person* p = new Person(ci::Color("green"), float(1), routes,
                           std::vector<bool>({false, false, false}));
    c.AddPerson(p);
    c.AdvanceOneFrame();
    REQUIRE(c.getPeople()[0]->getPosition() == vec2(1, 0));
  }

  SECTION("Person direct movement with speed 1 goal does not affect speed") {
    std::vector<vec2> routes = {vec2(0, 0), vec2(100, 0)};
    Person* p = new Person(ci::Color("green"), float(1), routes,
                           std::vector<bool>({false, false, false}));
    c.AddPerson(p);
    c.AdvanceOneFrame();
    REQUIRE(c.getPeople()[0]->getPosition() == vec2(1, 0));
  }

  SECTION("Person direct movement with speed 2") {
    std::vector<vec2> routes = {vec2(0, 0), vec2(10, 0)};
    Person* p = new Person(ci::Color("green"), float(2), routes,
                           std::vector<bool>({false, false, false}));
    c.AddPerson(p);
    c.AdvanceOneFrame();
    REQUIRE(c.getPeople()[0]->getPosition() == vec2(2, 0));
  }

  SECTION("Person diagonal movement with speed 1") {
    std::vector<vec2> routes = {vec2(0, 0), vec2(100, 100)};
    Person* p = new Person(ci::Color("green"), float(1), routes,
                           std::vector<bool>({false, false, false}));
    c.AddPerson(p);
    c.AdvanceOneFrame();
    float position_difference = glm::distance(c.getPeople()[0]->getPosition(),
                                              vec2(1 / sqrt(2), 1 / sqrt(2)));
    REQUIRE(position_difference < 1e-6);
  }
}

TEST_CASE("Container movement goal test") {
  AreaContainer c;
  SECTION("Test person will go to next goal after reaching the first one") {
    std::vector<vec2> routes = {vec2(0, 0), vec2(100, 0), vec2(100, 100)};
    Person* p = new Person(ci::Color("green"), float(100), routes,
                           std::vector<bool>({false, false, false}));
    c.AddPerson(p);
    c.AdvanceOneFrame();
    c.AdvanceOneFrame();
    REQUIRE(c.getPeople()[0]->getPosition() == vec2(100, 100));
  }
}
