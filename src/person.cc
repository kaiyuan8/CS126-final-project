#include "person.h"

namespace covidsim {

Person::Person(const std::string &status, const std::vector<vec2> &routes, int routeIdx,
           const std::vector<bool> &health) : status_(status), routes_(routes),
           route_idx_(routeIdx), health_(health) {}

}  // namespace idealgas