#ifndef CG_PROJECT_SPHERE_HPP
#define CG_PROJECT_SPHERE_HPP

#include <vector>
#include <math.h>
#include "point.hpp"

using namespace std;

class Sphere
{
private:
    float radius;
    int slices;
    int stacks;

public:
    Sphere(float r, int sli, int sta);
    vector<Point> pointsGenerator();
};

#endif // CG_PROJECT_SPHERE_HPP
