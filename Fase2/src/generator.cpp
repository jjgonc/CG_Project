
#include "headers/point.hpp"
#include "headers/plane.hpp"
#include "headers/box.hpp"
#include "headers/cone.hpp"
#include "headers/sphere.hpp"
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

    if (primitive == "plane" && argc == 5) // adicionar && argc == 5
    {
        float length = stof(argv[2]);
        int divisions = stoi(argv[3]);
        write3D(Plane(length, divisions), argv[4]);
    }

    else if (primitive == "box" && argc == 5)
    {
        float edge = stof(argv[2]);
        int grid = stoi(argv[3]);
        write3D(Box(edge, grid), argv[4]);
    }

    else if (primitive == "sphere" && argc == 6)
    {
        float radius = stof(argv[2]);
        int slices = stoi(argv[3]);
        int stacks = stoi(argv[4]);
        write3D(Sphere(radius, slices, stacks), argv[5]);
    }

    else if (primitive == "cone" && argc == 7)
    {
        float radius = stof(argv[2]);
        float height = stof(argv[3]);
        int slices = stoi(argv[4]);
        int stacks = stoi(argv[5]);
        write3D(Cone(radius, height, slices, stacks), argv[6]);
    }

    else
    {
        printf("Not a valid input. Number of arguments might not be valid or this solid does not exist...");
    }
}