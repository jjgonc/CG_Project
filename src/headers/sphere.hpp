#ifndef CG_PROJECT_SPHERE_HPP
#define CG_PROJECT_SPHERE_HPP

class Sphere
{
private:
    float radius;
    int slices;
    int stacks;

public:
    Sphere(float radius, int slices, int stacks);
    // std::vector<Point> Sphere::pointsGenerator();
};



#endif //CG_PROJECT_SPHERE_HPP
