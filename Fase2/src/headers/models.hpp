#ifndef CG_PROJECT_MODELS_HPP
#define CG_PROJECT_MODELS_HPP

#include <vector>
#include "point.hpp"

using namespace std;

class Coordinate
{
public:
    float x, y, z, angle;
};

class Figure
{
public:
    vector<Point> pontos;
};

class Models
{
public:
    vector<Models> groups;
    Coordinate rotate, translate, scale;
    vector<Figure> figures;
};

#endif // CG_PROJECT_MODELS_HPP
