#ifndef CG_PROJECT_PLANE_HPP
#define CG_PROJECT_PLANE_HPP

using namespace std;

#include "point.hpp"
#include <vector>

class Plane
{
private:
    float side;
    float divisions;

public:
    Plane(int argc, char **args);
    vector<Point> pointsGenerator();
};

#endif // CG_PROJECT_PLANE_HPP
