#ifndef CG_PROJECT_BOXUPSIDEDOWN_HPP
#define CG_PROJECT_BOXUPSIDEDOWN_HPP
#include "point.hpp"
#include <vector>
#include <array>

using namespace std;

class BoxUpsideDown
{
private:
    float edge;
    int grid;

public:
    BoxUpsideDown(float e, int g);
    array<vector<Point>,3> pointsGenerator();
};

#endif // CG_PROJECT_BOX_HPP
