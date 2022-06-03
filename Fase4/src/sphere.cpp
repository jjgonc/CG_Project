#include <string>
#include <array>
#include "./headers/sphere.hpp"

using namespace std;

Sphere::Sphere(float r, int sli, int sta)
{
    radius = r;
    slices = sli;
    stacks = sta;
}

array<vector<Point>,3> Sphere::pointsGenerator()
{
    vector<Point> points;
    vector<Point> normals;
    vector<Point> textures;

    float alpha = (2 * M_PI) / slices;
    float beta = (M_PI) / stacks;

    float itSlice = 1.0/slices;
    float itStack = 1.0/stacks;


    for (int i = 0; i < slices; i++)
    {
        for (int j = 0; j < stacks / 2; j++)
        {

    // parte superior da esfera
            /*  6 --- 1=5
             *  |   /  |
             *  |  /   |
             *  | /    |
             *  2=4 ---3
             */

        // Triângulo inferior

            // ponto de cima
            Point p1 = Point(radius * cos((j + 1) * beta) * sin((i + 1) * alpha), radius * sin((j + 1) * beta),
                            radius * cos((j + 1) * beta) * cos((i + 1) * alpha));
            points.push_back(p1);


            // pontos de baixo
            Point p2 = Point(radius * cos(j * beta) * sin(i * alpha), radius * sin(j * beta),
                             radius * cos(j * beta) * cos(i * alpha));
            points.push_back(p2);

            Point p3 = Point(radius * cos(j * beta) * sin((i + 1) * alpha), radius * sin(j * beta),
                             radius * cos(j * beta) * cos((i + 1) * alpha));
            points.push_back(p3);

        // Triângulo superior

            // Ponto de baixo

            Point p4 = Point(radius * cos(j * beta) * sin(i * alpha), radius * sin(j * beta),
                             radius * cos(j * beta) * cos(i * alpha));
            points.push_back(p4);

            // Pontos de cima

            Point p5 = Point(radius * cos((j + 1) * beta) * sin((i + 1) * alpha), radius * sin((j + 1) * beta),
                             radius * cos((j + 1) * beta) * cos((i + 1) * alpha));
            points.push_back(p5);

            Point p6 = Point(radius * cos((j + 1) * beta) * sin(i * alpha), radius * sin((j + 1) * beta),
                             radius * cos((j + 1) * beta) * cos(i * alpha));
            points.push_back(p6);




    // Parte inferior da esfera
            /*  11 --- 10=9
             *  |   /  |
             *  |  /   |
             *  | /    |
             * 7=12 ---8
             */

        // Triângulo inferior

            Point p7 = Point(radius * cos(-(j + 1) * beta) * sin(i * alpha), radius * sin(-(j + 1) * beta),
                             radius * cos(-(j + 1) * beta) * cos(i * alpha));
            points.push_back(p7);

            Point p8 = Point(radius * cos(-(j + 1) * beta) * sin((i + 1) * alpha), radius * sin(-(j + 1) * beta),
                             radius * cos(-(j + 1) * beta) * cos((i + 1) * alpha));
            points.push_back(p8);


            Point p9 = Point(radius * cos(-j * beta) * sin((i + 1) * alpha), radius * sin(-j * beta),
                             radius * cos(-j * beta) * cos((i + 1) * alpha));
            points.push_back(p9);

        // Triângulo superior

            Point p10 = Point(radius * cos(-j * beta) * sin((i + 1) * alpha), radius * sin(-j * beta),
                              radius * cos(-j * beta) * cos((i + 1) * alpha));
            points.push_back(p10);


            Point p11 = Point(radius * cos(-j * beta) * sin(i * alpha), radius * sin(-j * beta),
                              radius * cos(-j * beta) * cos(i * alpha));
            points.push_back(p11);



            Point p12 = Point(radius * cos(-(j + 1) * beta) * sin(i * alpha), radius * sin(-(j + 1) * beta),
                              radius * cos(-(j + 1) * beta) * cos(i * alpha));
            points.push_back(p12);


            normals.push_back(p1.normalize());
            normals.push_back(p2.normalize());
            normals.push_back(p3.normalize());
            normals.push_back(p4.normalize());
            normals.push_back(p5.normalize());
            normals.push_back(p6.normalize());
            normals.push_back(p7.normalize());
            normals.push_back(p8.normalize());
            normals.push_back(p9.normalize());
            normals.push_back(p10.normalize());
            normals.push_back(p11.normalize());
            normals.push_back(p12.normalize());


            /*      i      i+1   j+1 => 0.25 (0.5 - (j+1)/stacks)
             * j+1  6 --- 1=5
             *      |   /  |
             *      |  /   |
             *      | /    |
             * j    2=4 ---3                 (0.5 - j/stacks)
             * j    11 --- 10=9   j=0 => 0.5  (0.5 + j/stacks)
             *      |   /  |
             *      |  /   |
             *      | /    |
             * j+1  7=12 ---8      j+1 => 0.75 (0.5 + (j+1)/stacks)
             */


            textures.push_back(Point( (i+1)/slices, 0.5 - ((j+1)/stacks) ,0)); // Ponto 1
            textures.push_back(Point( i/slices    , 0.5 - (j/stacks)     ,0)); // Ponto 2
            textures.push_back(Point( (i+1)/slices, 0.5 - (j/stacks)     ,0)); // Ponto 3
            textures.push_back(Point( i/slices    , 0.5 - (j/stacks)     ,0)); // Ponto 4
            textures.push_back(Point( (i+1)/slices, 0.5 - ((j+1)/stacks) ,0)); // Ponto 5
            textures.push_back(Point( i/slices    , 0.5 - ((j+1)/stacks) ,0)); // Ponto 6
            textures.push_back(Point( i/slices    , 0.5 + ((j+1)/stacks) ,0)); // Ponto 7
            textures.push_back(Point( (i+1)/slices, 0.5 + ((j+1)/stacks) ,0)); // Ponto 8
            textures.push_back(Point( (i+1)/slices, 0.5 + (j/stacks)     ,0)); // Ponto 9
            textures.push_back(Point( (i+1)/slices, 0.5 + (j/stacks)     ,0)); // Ponto 10
            textures.push_back(Point( i/slices    , 0.5 + (j/stacks)     ,0)); // Ponto 11
            textures.push_back(Point( i/slices    , 0.5 + ((j+1)/stacks) ,0)); // Ponto 12

        }
    }

    array<vector<Point>,3> result = {points, normals, textures};
    return result;
}