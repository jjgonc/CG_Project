#include <vector>
#include <math.h>
#define _USE_MATH_DEFINES
#include "../headers/point.hpp"
#include "../headers/sphere.hpp"


Sphere::Sphere(float r, int sl, int st) {
    radius = r;
    slices = sl;
    stacks = st;
}

/*

std::vector<Point> Sphere::pointsGenerator(){
    Point top = Point(0, 2*radius, 0);
    Point bottom = Point(0,0,0);

    float pi = M_PI;

    float sliceStep = 2*pi/slices;
    float stackStep = pi/stacks;
    float sectorAngle, stackAngle;


    std::vector<Point> points;


    for(int i = 0; i < stacks; i++) {
        stackAngle = pi/2 - i*stackStep;
        stackAngle = pi/2 - (i+1) * stackStep;
    }
}
*/