
#include "headers/point.hpp"
#include "headers/plane.hpp"
#include "headers/box.hpp"
#include "headers/cone.hpp"
#include "headers/sphere.hpp"
#include "headers/torus.hpp"
#include "headers/bezier.hpp"
#include <string>
#include <ostream>
#include <iostream>
#include <fstream>
#include <array>

using namespace std;

template <typename T>

void write3D(T primitive, string fileName)
{
    ofstream file3d("../../vertices/" + fileName);
    array<vector<Point>,3> result = primitive.pointsGenerator();
    file3d << result[0].size() << "\n"; // escreve o numero de pontos do modelo que por consequente é igual ao nº de normals e textures

    for (Point p : result[0]){
        file3d << p.toString() << "\n";
    }
    
    for (Point normal : result[1]){
        file3d << normal.toString() << "\n";
    }

    for (Point texture : result[2]){
        file3d << texture.getX() << ' ' << texture.getY()  << "\n";
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

    else if (primitive == "torus" && argc == 7)
    {
        float innerRadius = std::stof(argv[2]);
        float outerRadius = std::stof(argv[3]);
        float radius = (innerRadius+outerRadius)/2.0f;
        float ringRadius = (outerRadius-innerRadius)/2.0f;
        int slices = std::stoi(argv[4]);
        int stacks = std::stoi(argv[5]);

        write3D(Torus(radius,ringRadius,slices,stacks), argv[6]);
    } else if (primitive == "bezier" && argc == 5){
        // generator bezier teapot.patch 10 bezier.3d

        int tessellation = std::atoi(argv[3]);
        write3D(Bezier(argv[2],tessellation), std::string(argv[4]));
    }
    else
    {
        printf("Not a valid input. Number of arguments might not be valid or this solid does not exist...");
    }
}