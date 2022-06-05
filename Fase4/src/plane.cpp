#include <string>
#include <array>
#include "headers/plane.hpp"

using namespace std;

Plane::Plane(float s,int div){
    side = s;
    divisions = div;
}

array<vector<Point>,3> Plane::pointsGenerator()
{
    vector<Point> points;
    vector<Point> normals; // temos que ter em conta que normal é um vetor
    vector<Point> textures; // ignoramos z Coordenadas bidimensionais

    float px = side / divisions;
    float pz = side / divisions;

    for (float i = 0; i < divisions; i++) {
        for (float q = 0; q < divisions; q++) {
            // triangulo superior

            points.push_back(Point(px * i - side/2      ,0, pz * q - side/2)); // ponto A
            points.push_back(Point(px * i - side/2      ,0, pz * q - side/2 + pz)); // ponto B
            points.push_back(Point(px * i - side/2 + px ,0, pz * q - side/2)); // ponto C

            // como é um plano x0z as normais dos pontos sao todas (0,1,0)
            normals.push_back(Point(0,1,0));
            normals.push_back(Point(0,1,0));
            normals.push_back(Point(0,1,0));


            textures.push_back(Point(i/divisions      , q/divisions ,0)); // ponto A
            textures.push_back(Point(i/divisions      , (q+1)/divisions ,0)); // ponto B
            textures.push_back(Point((i+1)/divisions  , q/divisions ,0)); // ponto C



            // triangulo inferior


            points.push_back(Point(px * i - side/2      ,0, pz * q - side/2 + pz)); // Ponto B
            points.push_back(Point(px * i - side/2 + px ,0, pz * q - side/2 + pz)); // ponto D
            points.push_back(Point(px * i - side/2 + px ,0, pz * q - side/2)); // ponto C

            normals.push_back(Point(0,1,0));
            normals.push_back(Point(0,1,0));
            normals.push_back(Point(0,1,0));

            textures.push_back(Point(i/divisions      , (q+1)/divisions ,0)); // ponto B
            textures.push_back(Point((i+1)/divisions , (q+1)/divisions ,0)); // ponto D
            textures.push_back(Point((i+1)/divisions  , q/divisions ,0)); // ponto C

        }
    }

    array<vector<Point>,3> result = {points, normals, textures};
    return result;
}
