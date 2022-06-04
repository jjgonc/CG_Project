#define _USE_MATH_DEFINES
#include <math.h>
#include "./headers/cone.hpp"


Cone::Cone(float r, float h, int sl, int st) {
    radius = r;
    height = h;
    slices = sl;
    stacks = st;
}


array<vector<Point>,3> Cone::pointsGenerator() {
    vector<Point> points;
    vector<Point> normals;
    vector<Point> textures;



    float alpha = (2*M_PI) / slices;        //usando apenas coordenadas polares
    // float beta = M_PI / stacks;   

    for(int i=0; i<slices; i++) {
        Point p1 = Point(0,0,0);
        Point p2 = Point(radius*cos((i+1)*alpha), 0, radius*-sin((i+1)*alpha));
        Point p3 = Point(radius*cos(i*alpha), 0, radius*-sin(i*alpha));


        points.push_back(p1);
        points.push_back(p2);
        points.push_back(p3);   

        normals.push_back(Point(0,-1,0));
        normals.push_back(Point(0,-1,0));
        normals.push_back(Point(0,-1,0));

        textures.push_back(Point(0,0,0));
        textures.push_back(Point(0,1,0));
        textures.push_back(Point(1,1,0));

        float nextRadius, nextRadius2, stackHeight, stackHeight2;   
        
        for(int j=0; j<stacks; j++) {
            stackHeight = (height / stacks) * j;
            nextRadius = (height - stackHeight) * radius / height;
            stackHeight2 = (height / stacks) * (j + 1);
            nextRadius2 = (height - stackHeight2) * radius / height;    
             
            
            //triangulo de cima
            Point p1_cima = Point(nextRadius2 * cos(alpha*i), stackHeight2, nextRadius2 * sin(alpha*i));
            Point p2_cima = Point(nextRadius2 * cos(alpha*(i + 1)), stackHeight2, nextRadius2 * sin(alpha*(i + 1)));
            Point p3_cima = Point(nextRadius * cos(alpha*i), stackHeight, nextRadius * sin(alpha*i));

            points.push_back(p1_cima);
            points.push_back(p2_cima);
            points.push_back(p3_cima);

            // calcular distancia do topo do cone ao ponto que queremos calcular normal
            float dist1 = sqrt(pow(p1_cima.getX()-0,2) + pow(p1_cima.getY()-height,2) + pow(p1_cima.getZ()-0,2));
            float h1 = cos(atan(radius/height)) * dist1;
            //normal P1-A     A(0,height-h1,0)
            normals.push_back(Point(p1_cima.getX(),p1_cima.getY()- (height - h1),p1_cima.getZ()).normalize());

            float dist2 = sqrt(pow(p2_cima.getX()-0,2) + pow(p2_cima.getY()-height,2) + pow(p2_cima.getZ()-0,2));
            float h2 = cos(atan(radius/height)) * dist2;
            normals.push_back(Point(p2_cima.getX(),p2_cima.getY()- (height - h2),p2_cima.getZ()).normalize());

            float dist3 = sqrt(pow(p3_cima.getX()-0,2) + pow(p3_cima.getY()-height,2) + pow(p3_cima.getZ()-0,2));
            float h3 = cos(atan(radius/height)) * dist3;
            normals.push_back(Point(p3_cima.getX(),p3_cima.getY()- (height - h3),p3_cima.getZ()).normalize());


            textures.push_back(Point( i/slices     , (j+1)/stacks ,0));
            textures.push_back(Point( (i+1)/slices , (j+1)/stacks ,0));
            textures.push_back(Point( i/slices     , j / stacks   ,0));

            //triangulo de baixo
            Point p1_baixo = Point(nextRadius * cos(alpha*i), stackHeight, nextRadius * sin(alpha*i));
            Point p2_baixo = Point(nextRadius2 * cos(alpha *(i+1)), stackHeight2, nextRadius2 * sin(alpha *(i + 1)));
            Point p3_baixo = Point(nextRadius * cos(alpha*(i + 1)), stackHeight, nextRadius * sin(alpha*(i + 1)));

            points.push_back(p1_baixo);
            points.push_back(p2_baixo);
            points.push_back(p3_baixo);

            float dist1_b = sqrt(pow(p1_baixo.getX()-0,2) + pow(p1_baixo.getY()-height,2) + pow(p1_baixo.getZ()-0,2));
            float h1_b = cos(atan(radius/height)) * dist1_b;
            normals.push_back(Point(p1_baixo.getX(),p1_baixo.getY()- (height - h1_b),p1_baixo.getZ()).normalize());

            float dist2_b = sqrt(pow(p2_baixo.getX()-0,2) + pow(p2_baixo.getY()-height,2) + pow(p2_baixo.getZ()-0,2));
            float h2_b = cos(atan(radius/height)) * dist2_b;
            normals.push_back(Point(p2_baixo.getX(),p2_baixo.getY()- (height - h2_b),p2_baixo.getZ()).normalize());

            float dist3_b = sqrt(pow(p3_baixo.getX()-0,2) + pow(p3_baixo.getY()-height,2) + pow(p3_baixo.getZ()-0,2));
            float h3_b = cos(atan(radius/height)) * dist3_b;
            normals.push_back(Point(p3_baixo.getX(),p3_baixo.getY()- (height - h3_b),p3_baixo.getZ()).normalize());

            textures.push_back(Point( i/slices    , j/stacks ,0));
            textures.push_back(Point( (i+1)/slices, (j+1)/stacks ,0));
            textures.push_back(Point( (i+1)/slices, j/stacks ,0));


        }
    }

    array<vector<Point>,3> result = {points, normals, textures};
    return result;
}