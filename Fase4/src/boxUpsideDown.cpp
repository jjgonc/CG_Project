#include "headers/boxUpsideDown.hpp"

using namespace std;

BoxUpsideDown::BoxUpsideDown(float e, int g)
{
    edge = e;
    grid = g;
}

array<vector<Point>,3> BoxUpsideDown::pointsGenerator()
{
    vector<Point> points;
    vector<Point> normals;
    vector<Point> textures;

    float subEdge = edge / grid;
    float halfEdge = edge / 2.0;

    for (float i = 0; i < grid; i++)
    {
        for (float j = 0; j < grid; j++)
        {

            // face 1 - virada para a frente
            Point p1_frente = Point(-halfEdge + i * subEdge, -halfEdge + j * subEdge, halfEdge); // começa do lado esquerdo e vai somando subEdges
            Point p2_frente = Point(-halfEdge + (i + 1) * subEdge, -halfEdge + j * subEdge, halfEdge);
            Point p3_frente = Point(-halfEdge + (i + 1) * subEdge, -halfEdge + (j + 1) * subEdge, halfEdge);
            Point p4_frente = Point(-halfEdge + i * subEdge, -halfEdge + (j + 1) * subEdge, halfEdge);

            points.push_back(p1_frente);
            points.push_back(p4_frente);
            points.push_back(p2_frente);
            

            points.push_back(p2_frente);
            points.push_back(p4_frente);
            points.push_back(p3_frente);
           

            normals.push_back(Point(0,0,1));
            normals.push_back(Point(0,0,1));
            normals.push_back(Point(0,0,1));
           
            normals.push_back(Point(0,0,1));
            normals.push_back(Point(0,0,1));
            normals.push_back(Point(0,0,1));
            

            textures.push_back(Point(i/grid     ,j/grid ,0)); // ponto 1
            textures.push_back(Point(i/grid     ,(j+1)/grid ,0)); // ponto 4
             textures.push_back(Point((i+1) /grid,j/grid ,0)); // ponto 2

            textures.push_back(Point((i+1)/grid ,j/grid ,0)); // ponto 2
            textures.push_back(Point(i/ grid    ,(j+1)/grid ,0)); // ponto 4
            textures.push_back(Point((i+1)/grid ,(j+1)/grid ,0)); // ponto 3

            // face 2 - virada para a esquerda
            Point p1_lado1 = Point(-halfEdge, -halfEdge + i * subEdge, -halfEdge + j * subEdge);
            Point p2_lado1 = Point(-halfEdge, -halfEdge + (i + 1) * subEdge, -halfEdge + j * subEdge);
            Point p3_lado1 = Point(-halfEdge, -halfEdge + (i + 1) * subEdge, -halfEdge + (j + 1) * subEdge);
            Point p4_lado1 = Point(-halfEdge, -halfEdge + i * subEdge, -halfEdge + (j + 1) * subEdge);

            points.push_back(p1_lado1);
            points.push_back(p2_lado1);
            points.push_back(p4_lado1);

            points.push_back(p2_lado1);
            points.push_back(p3_lado1);
            points.push_back(p4_lado1);
           

            normals.push_back(Point(-1,0,0));
            normals.push_back(Point(-1,0,0));
            normals.push_back(Point(-1,0,0));
          
            normals.push_back(Point(-1,0,0));
            normals.push_back(Point(-1,0,0));
            normals.push_back(Point(-1,0,0));
            

            textures.push_back(Point(j/grid ,i/grid     ,0)); // ponto 1
            textures.push_back(Point(j/grid ,(i+1) /grid,0)); // ponto 2
            textures.push_back(Point((j+1)/grid ,i/grid     ,0)); // ponto 4
            

            textures.push_back(Point(j/grid ,(i+1)/grid ,0)); // ponto 2
            textures.push_back(Point((j+1)/grid ,(i+1)/grid ,0)); // ponto 3
            textures.push_back(Point((j+1)/grid ,i/ grid    ,0)); // ponto 4
            


            // face 3 - virada para a direita
            Point p1_lado2 = Point(halfEdge, -halfEdge + i * subEdge, -halfEdge + j * subEdge);
            Point p2_lado2 = Point(halfEdge, -halfEdge + (i + 1) * subEdge, -halfEdge + j * subEdge);
            Point p3_lado2 = Point(halfEdge, -halfEdge + (i + 1) * subEdge, -halfEdge + (j + 1) * subEdge);
            Point p4_lado2 = Point(halfEdge, -halfEdge + i * subEdge, -halfEdge + (j + 1) * subEdge);

            points.push_back(p1_lado2);
            points.push_back(p4_lado2);
            points.push_back(p2_lado2);
            

            points.push_back(p2_lado2);
            points.push_back(p4_lado2);
            points.push_back(p3_lado2);
            

            normals.push_back(Point(1,0,0));
            normals.push_back(Point(1,0,0));
            normals.push_back(Point(1,0,0));
            
            normals.push_back(Point(1,0,0));
            normals.push_back(Point(1,0,0));
            normals.push_back(Point(1,0,0));
            

            textures.push_back(Point(1-(j/grid) ,i/grid     ,0)); // ponto 1
            textures.push_back(Point(1-((j+1)/grid),i/grid     ,0)); // ponto 4
            textures.push_back(Point(1-(j/grid) ,(i+1) /grid,0)); // ponto 2
           
            textures.push_back(Point(1-(j/grid) ,(i+1)/grid ,0)); // ponto 2
            textures.push_back(Point(1-((j+1)/grid) ,i/ grid    ,0)); // ponto 4
            textures.push_back(Point(1-((j+1)/grid) ,(i+1)/grid ,0)); // ponto 3
            

            // face 4 - virada para trás
            Point p1_tras = Point(-halfEdge + i * subEdge, -halfEdge + j * subEdge, -halfEdge);
            Point p2_tras = Point(-halfEdge + (i + 1) * subEdge, -halfEdge + j * subEdge, -halfEdge);
            Point p3_tras = Point(-halfEdge + (i + 1) * subEdge, -halfEdge + (j + 1) * subEdge, -halfEdge);
            Point p4_tras = Point(-halfEdge + i * subEdge, -halfEdge + (j + 1) * subEdge, -halfEdge);

            points.push_back(p1_tras);
            points.push_back(p2_tras);
            points.push_back(p4_tras);
           

            points.push_back(p2_tras);
            points.push_back(p3_tras);
            points.push_back(p4_tras);
            

            normals.push_back(Point(0,0,-1));
            normals.push_back(Point(0,0,-1));
            normals.push_back(Point(0,0,-1));
            
            normals.push_back(Point(0,0,-1));
            normals.push_back(Point(0,0,-1));
            normals.push_back(Point(0,0,-1));
            

            textures.push_back(Point(1-(i/grid)     ,j/grid     ,0)); // ponto 1
            textures.push_back(Point(1-((i+1) /grid),j/grid     ,0)); // ponto 2
            textures.push_back(Point(1-(i/grid)     ,(j+1)/grid ,0)); // ponto 4
          
            textures.push_back(Point(1-((i+1)/grid) ,j/grid     ,0)); // ponto 2
            textures.push_back(Point(1-((i+1)/grid) ,(j+1)/grid ,0)); // ponto 3
            textures.push_back(Point(1-(i/ grid)    ,(j+1)/grid ,0)); // ponto 4
            

            // face 5 - virada para cima

            /*
             * 2 ----- 3
             * |       |
             * 1 ----- 4
             */
            Point p1_cima = Point(-halfEdge + i * subEdge, halfEdge, -halfEdge + j * subEdge);
            Point p2_cima = Point(-halfEdge + (i + 1) * subEdge, halfEdge, -halfEdge + j * subEdge);
            Point p3_cima = Point(-halfEdge + (i + 1) * subEdge, halfEdge, -halfEdge + (j + 1) * subEdge);
            Point p4_cima = Point(-halfEdge + i * subEdge, halfEdge, -halfEdge + (j + 1) * subEdge);

            points.push_back(p1_cima);
            points.push_back(p2_cima);
            points.push_back(p4_cima);
            

            points.push_back(p2_cima);
            points.push_back(p3_cima);
            points.push_back(p4_cima);
          

            normals.push_back(Point(0,1,0));
            normals.push_back(Point(0,1,0));
            normals.push_back(Point(0,1,0));
            
            normals.push_back(Point(0,1,0));
            normals.push_back(Point(0,1,0));
            normals.push_back(Point(0,1,0));
            

            textures.push_back(Point(i/grid     ,1-(j/grid) ,0)); // ponto 1
            textures.push_back(Point((i+1) /grid,1-(j/grid) ,0)); // ponto 2
            textures.push_back(Point(i/grid     ,1-((j+1)/grid) ,0)); // ponto 4
            
            textures.push_back(Point((i+1)/grid ,1-(j/grid) ,0)); // ponto 2
            textures.push_back(Point((i+1)/grid ,1-((j+1)/grid),0)); // ponto 3
            textures.push_back(Point(i/ grid    ,1-((j+1)/grid) ,0)); // ponto 4
           


            // face 6 - virada para baixo
            Point p1_baixo = Point(-halfEdge + i * subEdge, -halfEdge, -halfEdge + j * subEdge);
            Point p2_baixo = Point(-halfEdge + (i + 1) * subEdge, -halfEdge, -halfEdge + j * subEdge);
            Point p3_baixo = Point(-halfEdge + (i + 1) * subEdge, -halfEdge, -halfEdge + (j + 1) * subEdge);
            Point p4_baixo = Point(-halfEdge + i * subEdge, -halfEdge, -halfEdge + (j + 1) * subEdge);

            points.push_back(p1_baixo);
            points.push_back(p4_baixo);
            points.push_back(p2_baixo);
            

            points.push_back(p2_baixo);
            points.push_back(p4_baixo);
            points.push_back(p3_baixo);
           

            normals.push_back(Point(0,-1,0));
            normals.push_back(Point(0,-1,0));
            normals.push_back(Point(0,-1,0));
            
            normals.push_back(Point(0,-1,0));
            normals.push_back(Point(0,-1,0));
            normals.push_back(Point(0,-1,0));
            

            textures.push_back(Point(i/grid     ,j/grid ,0)); // ponto 1
            textures.push_back(Point(i/grid     ,(j+1)/grid ,0)); // ponto 4
            textures.push_back(Point((i+1) /grid,j/grid ,0)); // ponto 2
            
            textures.push_back(Point((i+1)/grid ,j/grid ,0)); // ponto 2
            textures.push_back(Point(i/ grid    ,(j+1)/grid ,0)); // ponto 4
            textures.push_back(Point((i+1)/grid ,(j+1)/grid ,0)); // ponto 3
            

        }
    }

    array<vector<Point>,3> result = {points, normals, textures};
    return result;
}
