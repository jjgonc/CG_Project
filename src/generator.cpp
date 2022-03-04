
#include <point.hpp>
#include <string>
#include <ostream>
#include <iostream>
#include <fstream>

using namespace std;

template <typename T>

void write3D(T primitive, string fileName)
{
    ofstream file3d(fileName);
    for (Point p : primitive.pointGenerator())
    {
        file3d << p.to_string() << "\n";
    }
}

int main(int argc, char **argv)
{

    string primitive = argv[1];

    if (primitive == "plane")
        printf("ola");

    else if (primitive == "box")
        printf("ola");

    else if (primitive == "sphere")
        printf("ola");

    else if (primitive == "cone")
        printf("ola");
}