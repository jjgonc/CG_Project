
#include "headers/point.hpp"
#include "headers/plane.hpp"
#include "headers/box.hpp"
#include <string>
#include <ostream>
#include <iostream>
#include <fstream>

using namespace std;

template <typename T>

void write3D(T primitive, string fileName)
{
    ofstream file3d(fileName);
    for (Point p : primitive.pointsGenerator())
    {
        file3d << p.toString() << "\n";
    }
}

int main(int argc, char **argv)
{

    string primitive = argv[1];

    if (primitive == "plane")
    {
        int length = stoi(argv[2]);
        float divisions = stof(argv[3]);
        write3D(Plane(length, divisions), argv[4]);
    }

    else if (primitive == "box")
    {
        float edge = stof(argv[2]);
        int grid = stoi(argv[3]);
        write3D(Box(edge, grid), argv[4]);
    }

    else if (primitive == "sphere")
        printf("ola");

    else if (primitive == "cone")
        printf("ola");
}