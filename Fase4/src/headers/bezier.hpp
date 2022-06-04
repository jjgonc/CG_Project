#ifndef ENGINE_BEZIER_HPP
#define ENGINE_BEZIER_HPP

using namespace std;

#include "point.hpp"
#include <vector>
#include <array>

class Bezier
{
private:
    string inputFile;
    int tessellation;
    int numPatches;
    unsigned int *patches;
    int numControlPoints;
    vector<Point> controlPoints;


public:
    Bezier(string filename,int tess);
    void parsing (string filename);
    Point pointBezier(int p, float u, float v,int option);
    array<vector<Point>,3> pointsGenerator();
};


#endif //BEZIER_HPP
