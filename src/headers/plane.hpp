#ifndef CG_PROJECT_PLANE_HPP
#define CG_PROJECT_PLANE_HPP

#include "point.hpp"
#include <vector>

class Plane {
private:
    float side;
    float divisions;

public:
    Plane(int argc, char **args);
    std::vector<Point> draw() const;
};

#endif //CG_PROJECT_PLANE_HPP
