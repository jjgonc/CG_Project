#include <string>
#include "../headers/plane.hpp"

using namespace std;

Plane::Plane(int s,float div){
    side = s;
    divisions = div;
}

vector<Point> Plane::pointsGenerator()
{
    vector<Point> points;
    float px = side / divisions;
    float pz = side / divisions;



    for (int i = 0; i < divisions; i++) {
        for (int q = 0; q < divisions; q++) {
            points.push_back(Point(px * i - side/2 ,0, pz * q - side/2));
            points.push_back(Point(px * i - side/2 ,0, pz * q - side/2 + pz));
            points.push_back(Point(px * i - side/2 + px ,0, pz * q - side/2));

            points.push_back(Point(px * i - side/2 ,0, pz * q - side/2 + pz));
            points.push_back(Point(px * i - side/2 + px ,0, pz * q - side/2));
            points.push_back(Point(px * i - side/2 + px ,0, pz * q - side/2 + pz));
        }
    }

    return points;
}
