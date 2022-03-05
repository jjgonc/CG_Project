#ifndef CG_PROJECT_BOX_HPP
#define CG_PROJECT_BOX_HPP
#include "point.hpp"
#include <vector>

using namespace std;

class Box
{
private:
    float edge;
    int grid;

public:
    Box(float e, int g);
    vector<Point> pointsGenerator();
};

#endif // CG_PROJECT_BOX_HPP
