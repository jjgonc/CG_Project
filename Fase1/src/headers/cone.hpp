#ifndef CG_PROJECT_CONE_HPP
#define CG_PROJECT_CONE_HPP


class Cone
{
private:
    float radius;
    float height;
    int slices;
    int stacks;

public:
    Cone(float radius, float height, int slices, int stacks);
    std::vector<Point> drawCone(double radius, double height, int slices, int stacks);
};


#endif //CG_PROJECT_CONE_HPP
