#include <string>
#include "headers/plane.hpp"

using namespace std;

Plane::Plane(int argc, char **args)
{
    side = stof(args[0]);
    divisions = stof(args[1]);
}

// FIXME ver depois a parte das divisions por cada eixo !!!
vector<Point> Plane::pointsGenerator()
{
    vector<Point> points;
    float half = side / 2;

    Point p0 = Point(-half, 0, -half);
    Point p1 = Point(-half, 0, half);
    Point p2 = Point(half, 0, -half);
    Point p3 = Point(half, 0, half);

    // back triangle
    points.push_back(p0);
    points.push_back(p1);
    points.push_back(p2);

    // front triangle
    points.push_back(p2);
    points.push_back(p1);
    points.push_back(p3);

    return points;
}