#include "../headers/box.hpp"

using namespace std;

Box::Box(float e, int g)
{
    edge = e;
    grid = g;
}

vector<Point> Box::pointsGenerator()
{
    vector<Point> points;

    float subEdge = edge / grid;

    // float halfEdge = edge/2.0;   //ignorar pq nao estamos a centrar na origem

    for (int i = 0; i < grid; i++)
    {
        for (int j = 0; j < grid; j++)
        {

            // face 1 - virada para o user
            Point p1_frente = Point(0, 0, subEdge * i);
            Point p2_frente = Point(subEdge * i, 0, subEdge * i);
            Point p3_frente = Point(subEdge * i, subEdge * i, subEdge * i);
            Point p4_frente = Point(0, subEdge * i, subEdge * i);

            points.push_back(p1_frente);
            points.push_back(p2_frente);
            points.push_back(p3_frente);
            points.push_back(p4_frente);

            // face 2 - virada para a esquerda
            Point p1_lado1 = Point(0, 0, subEdge * i);
            Point p2_lado1 = Point(0, subEdge * i, 0);
            Point p3_lado1 = Point(0, 0, subEdge * i);
            Point p4_lado1 = Point(0, 0, 0);

            points.push_back(p1_lado1);
            points.push_back(p2_lado1);
            points.push_back(p3_lado1);
            points.push_back(p4_lado1);

            // face 3 - virada para a direita
            Point p1_lado2 = Point(subEdge * i, 0, 0);
            Point p2_lado2 = Point(subEdge * i, subEdge * i, 0);
            Point p3_lado2 = Point(subEdge * i, subEdge * i, subEdge * i);
            Point p4_lado2 = Point(subEdge * i, 0, subEdge * i);

            points.push_back(p1_lado2);
            points.push_back(p2_lado2);
            points.push_back(p3_lado2);
            points.push_back(p4_lado2);

            // face 4 - virada para trás
            Point p1_tras = Point(0, subEdge * i, 0);
            Point p2_tras = Point(subEdge * i, 0, subEdge * i);
            Point p3_tras = Point(subEdge * i, 0, 0);
            Point p4_tras = Point(0, 0, 0);

            points.push_back(p1_tras);
            points.push_back(p2_tras);
            points.push_back(p3_tras);
            points.push_back(p4_tras);

            // face 5 - virada para cima
            Point p1_cima = Point(0, subEdge * i, subEdge * i);
            Point p2_cima = Point(subEdge * i, subEdge * i, subEdge * i);
            Point p3_cima = Point(subEdge * i, 0, subEdge * i);
            Point p4_cima = Point(0, subEdge * i, 0);

            points.push_back(p1_cima);
            points.push_back(p2_cima);
            points.push_back(p3_cima);
            points.push_back(p4_cima);

            // face 6 - virada para baixo
            Point p1_baixo = Point(0, 0, subEdge * i);
            Point p2_baixo = Point(0, 0, 0);
            Point p3_baixo = Point(subEdge * i, 0, 0);
            Point p4_baixo = Point(subEdge * i, 0, subEdge * i);

            points.push_back(p1_baixo);
            points.push_back(p2_baixo);
            points.push_back(p3_baixo);
            points.push_back(p4_baixo);
        }
    }

    return points;
}