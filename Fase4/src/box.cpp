#include <array>
#include "headers/box.hpp"

using namespace std;

Box::Box(float e, int g)
{
    edge = e;
    grid = g;
}

array<vector<Point>,3> Box::pointsGenerator()
{
    vector<Point> points;
    vector<Point> normals;
    vector<Point> textures;

    float subEdge = edge / grid;
    float halfEdge = edge / 2.0;

    for (int i = 0; i < grid; i++)
    {
        for (int j = 0; j < grid; j++)
        {

            // face 1 - virada para a frente
            Point p1_frente = Point(-halfEdge + i * subEdge, -halfEdge + j * subEdge, halfEdge); // começa do lado esquerdo e vai somando subEdges
            Point p2_frente = Point(-halfEdge + (i + 1) * subEdge, -halfEdge + j * subEdge, halfEdge);
            Point p3_frente = Point(-halfEdge + (i + 1) * subEdge, -halfEdge + (j + 1) * subEdge, halfEdge);
            Point p4_frente = Point(-halfEdge + i * subEdge, -halfEdge + (j + 1) * subEdge, halfEdge);

            points.push_back(p1_frente);
            points.push_back(p2_frente);
            points.push_back(p4_frente);

            points.push_back(p2_frente);
            points.push_back(p3_frente);
            points.push_back(p4_frente);

            // face 2 - virada para a esquerda
            Point p1_lado1 = Point(-halfEdge, -halfEdge + i * subEdge, -halfEdge + j * subEdge);
            Point p2_lado1 = Point(-halfEdge, -halfEdge + (i + 1) * subEdge, -halfEdge + j * subEdge);
            Point p3_lado1 = Point(-halfEdge, -halfEdge + (i + 1) * subEdge, -halfEdge + (j + 1) * subEdge);
            Point p4_lado1 = Point(-halfEdge, -halfEdge + i * subEdge, -halfEdge + (j + 1) * subEdge);

            points.push_back(p1_lado1);
            points.push_back(p4_lado1);
            points.push_back(p2_lado1);

            points.push_back(p2_lado1);
            points.push_back(p4_lado1);
            points.push_back(p3_lado1);

            // face 3 - virada para a direita
            Point p1_lado2 = Point(halfEdge, -halfEdge + i * subEdge, -halfEdge + j * subEdge);
            Point p2_lado2 = Point(halfEdge, -halfEdge + (i + 1) * subEdge, -halfEdge + j * subEdge);
            Point p3_lado2 = Point(halfEdge, -halfEdge + (i + 1) * subEdge, -halfEdge + (j + 1) * subEdge);
            Point p4_lado2 = Point(halfEdge, -halfEdge + i * subEdge, -halfEdge + (j + 1) * subEdge);

            points.push_back(p1_lado2);
            points.push_back(p2_lado2);
            points.push_back(p4_lado2);

            points.push_back(p2_lado2);
            points.push_back(p3_lado2);
            points.push_back(p4_lado2);

            // face 4 - virada para trás
            Point p1_tras = Point(-halfEdge + i * subEdge, -halfEdge + j * subEdge, -halfEdge);
            Point p2_tras = Point(-halfEdge + (i + 1) * subEdge, -halfEdge + j * subEdge, -halfEdge);
            Point p3_tras = Point(-halfEdge + (i + 1) * subEdge, -halfEdge + (j + 1) * subEdge, -halfEdge);
            Point p4_tras = Point(-halfEdge + i * subEdge, -halfEdge + (j + 1) * subEdge, -halfEdge);

            points.push_back(p1_tras);
            points.push_back(p4_tras);
            points.push_back(p2_tras);

            points.push_back(p2_tras);
            points.push_back(p4_tras);
            points.push_back(p3_tras);

            // face 5 - virada para cima
            Point p1_cima = Point(-halfEdge + i * subEdge, halfEdge, -halfEdge + j * subEdge);
            Point p2_cima = Point(-halfEdge + (i + 1) * subEdge, halfEdge, -halfEdge + j * subEdge);
            Point p3_cima = Point(-halfEdge + (i + 1) * subEdge, halfEdge, -halfEdge + (j + 1) * subEdge);
            Point p4_cima = Point(-halfEdge + i * subEdge, halfEdge, -halfEdge + (j + 1) * subEdge);

            points.push_back(p1_cima);
            points.push_back(p4_cima);
            points.push_back(p2_cima);

            points.push_back(p2_cima);
            points.push_back(p4_cima);
            points.push_back(p3_cima);

            // face 6 - virada para baixo
            Point p1_baixo = Point(-halfEdge + i * subEdge, -halfEdge, -halfEdge + j * subEdge);
            Point p2_baixo = Point(-halfEdge + (i + 1) * subEdge, -halfEdge, -halfEdge + j * subEdge);
            Point p3_baixo = Point(-halfEdge + (i + 1) * subEdge, -halfEdge, -halfEdge + (j + 1) * subEdge);
            Point p4_baixo = Point(-halfEdge + i * subEdge, -halfEdge, -halfEdge + (j + 1) * subEdge);

            points.push_back(p1_baixo);
            points.push_back(p2_baixo);
            points.push_back(p4_baixo);

            points.push_back(p2_baixo);
            points.push_back(p3_baixo);
            points.push_back(p4_baixo);
        }
    }

    array<vector<Point>,3> result = {points, normals, textures};
    return result;
}
