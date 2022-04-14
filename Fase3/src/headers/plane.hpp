#ifndef CG_PROJECT_PLANE_HPP
#define CG_PROJECT_PLANE_HPP

using namespace std;

#include "point.hpp"
#include <vector>

class Plane
{
private:
    float side;
    int divisions;

public:
    Plane(float s,int div);

    vector<Point> pointsGenerator();
};

#endif // CG_PROJECT_PLANE_HPP
