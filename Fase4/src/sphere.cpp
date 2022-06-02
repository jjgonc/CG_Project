#include <string>
#include "./headers/sphere.hpp"

using namespace std;

Sphere::Sphere(float r, int sli, int sta)
{
    radius = r;
    slices = sli;
    stacks = sta;
}

vector<Point> Sphere::pointsGenerator()
{
    vector<Point> points;
    float alpha = (2 * M_PI) / slices;
    float beta = (M_PI) / stacks;

    for (int i = 0; i < slices; i++)
    {
        for (int j = 0; j < stacks / 2; j++)
        {

            // Parte superior da esfera
            // Triângulo inferior

            // ponto de cima
            points.push_back(Point(radius * cos((j + 1) * beta) * sin((i + 1) * alpha), radius * sin((j + 1) * beta),
                                   radius * cos((j + 1) * beta) * cos((i + 1) * alpha)));

            // pontos de baixo
            points.push_back(Point(radius * cos(j * beta) * sin(i * alpha), radius * sin(j * beta),
                                   radius * cos(j * beta) * cos(i * alpha)));

            points.push_back(Point(radius * cos(j * beta) * sin((i + 1) * alpha), radius * sin(j * beta),
                                   radius * cos(j * beta) * cos((i + 1) * alpha)));

            // Triângulo superior

            // Ponto de baixo

            points.push_back(Point(radius * cos(j * beta) * sin(i * alpha), radius * sin(j * beta),
                                   radius * cos(j * beta) * cos(i * alpha)));

            // Pontos de cima

            points.push_back(Point(radius * cos((j + 1) * beta) * sin((i + 1) * alpha), radius * sin((j + 1) * beta),
                                   radius * cos((j + 1) * beta) * cos((i + 1) * alpha)));

            points.push_back(Point(radius * cos((j + 1) * beta) * sin(i * alpha), radius * sin((j + 1) * beta),
                                   radius * cos((j + 1) * beta) * cos(i * alpha)));

            // Parte inferior da esfera

            // Triângulo inferior

            points.push_back(Point(radius * cos(-(j + 1) * beta) * sin(i * alpha), radius * sin(-(j + 1) * beta),
                                   radius * cos(-(j + 1) * beta) * cos(i * alpha)));

            points.push_back(Point(radius * cos(-(j + 1) * beta) * sin((i + 1) * alpha), radius * sin(-(j + 1) * beta),
                                   radius * cos(-(j + 1) * beta) * cos((i + 1) * alpha)));

            points.push_back(Point(radius * cos(-j * beta) * sin((i + 1) * alpha), radius * sin(-j * beta),
                                   radius * cos(-j * beta) * cos((i + 1) * alpha)));

            // Triângulo superior

            points.push_back(Point(radius * cos(-j * beta) * sin((i + 1) * alpha), radius * sin(-j * beta),
                                   radius * cos(-j * beta) * cos((i + 1) * alpha)));
            points.push_back(Point(radius * cos(-j * beta) * sin(i * alpha), radius * sin(-j * beta),
                                   radius * cos(-j * beta) * cos(i * alpha)));
            points.push_back(Point(radius * cos(-(j + 1) * beta) * sin(i * alpha), radius * sin(-(j + 1) * beta),
                                   radius * cos(-(j + 1) * beta) * cos(i * alpha)));
        }
    }

    return points;
}