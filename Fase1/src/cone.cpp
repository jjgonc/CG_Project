#define _USE_MATH_DEFINES
#include <math.h>
#include "./headers/cone.hpp"


Cone::Cone(float r, float h, int sl, int st) {
    radius = r;
    height = h;
    slices = sl;
    stacks = st;
}


std::vector<Point> pointsGenerator() {
    std::vector<Point> points;


    float alpha = (2*M_PI) / slices;
    float beta = M_PI / stacks;   

    for(int i=0; i<slices; i++) {
        points.push_back(Point(0,0,0));
        points.push_back(Point(radius*cos((i+1)*alpha), 0, radius*(-sin((i+1)*alpha))));
        points.push_back(Point(radius*cos(i*alpha), 0, radius*(-sin(i*alpha))));   
        
        float nextRadius, nextRadius2, stackHeight, stackHeight2;   
        
        for(int j=0; j<stacks; i++) {
            stackHeight = (height/stacks) * j;
            nextRadius = (height - stackHeight) * radius/height;
            stackHeight2 = (height/stacks) * (j+1);
            nextRadius2 = (height - stackHeight2) * radius / height;    
             
            //triangulo de cima
            points.push_back(Point(nextRadius2 * cos(alpha*i), stackHeight2, nextRadius2 * sin(alpha*i)));
            points.push_back(Point(nextRadius2 * cos(alpha*(i+1)), stackHeight2, nextRadius2*sin(alpha*(i+1))));
            points.push_back(Point(nextRadius * cos(alpha*i), stackHeight, nextRadius * sin(alpha*i))); 

            //triangulo de baixo
            points.push_back(Point(nextRadius * cos(alpha*i), stackHeight, stackHeight * sin(alpha * i)));
            points.push_back(Point(nextRadius2 * cos(alpha * (i+1)), stackHeight2, nextRadius2 * sin(alpha * (i+1))));
            points.push_back(Point(nextRadius * cos(alpha*(i+1)), stackHeight, nextRadius * sin(alpha * (i+1))));
        }
    }

    return points;
}