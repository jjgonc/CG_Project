#ifndef ENGINE_TORUS_HPP
#define ENGINE_TORUS_HPP

using namespace std;
#include <vector>
#include "point.hpp"


class Torus {
private:
    float radius;
    float ringRadius;
    int slices;
    int stacks;

public:
    Torus(float radius,float ringRadius,int slices,int stacks);
    vector<Point> pointsGenerator();
};

#endif //ENGINE_TORUS_HPP
