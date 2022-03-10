
#include "headers/point.hpp"
#include "headers/plane.hpp"
#include "headers/box.hpp"
#include "headers/cone.hpp"
#include <string>
#include <ostream>
#include <iostream>
#include <fstream>

using namespace std;

template <typename T>

void write3D(T primitive, string fileName)
{
    ofstream file3d("../../vertices/" + fileName);
    for (Point p : primitive.pointsGenerator())
    {
        file3d << p.toString() << "\n";
    }
}

int main(int argc, char **argv)
{

    string primitive = argv[1];

    if (primitive == "plane")           //adicionar && argc == 5
    {
        float length = stof(argv[2]);
        int divisions = stoi(argv[3]);
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

    else if (primitive == "cone" && argc==7) {
        float radius = stof(argv[2]);
        float height = stof(argv[3]);
        int slices = stoi(argv[4]);
        int stacks = stoi(argv[5]);
        write3D(Cone(radius, height, slices, stacks), argv[6]);
    }

    else {
        printf("Not a valid input. Number of arguments might not be valid or this solid does not exist...");
    }
}