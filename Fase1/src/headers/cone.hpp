#ifndef CG_PROJECT_CONE_HPP
#define CG_PROJECT_CONE_HPP
#include <vector>
#include "point.hpp"

class Cone
{
private:
    float radius;
    float height;
    int slices;
    int stacks;

public:
    Cone(float r, float h, int sl, int st);
    std::vector<Point> pointsGenerator();
};


#endif //CG_PROJECT_CONE_HPP
