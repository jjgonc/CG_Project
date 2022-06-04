#ifndef CG_PROJECT_BOX_HPP
#define CG_PROJECT_BOX_HPP
#include "point.hpp"
#include <vector>
#include <array>

using namespace std;

class Box
{
private:
    float edge;
    int grid;

public:
    Box(float e, int g);
    array<vector<Point>,3> pointsGenerator();
};

#endif // CG_PROJECT_BOX_HPP
