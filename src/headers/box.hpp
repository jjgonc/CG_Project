#ifndef CG_PROJECT_BOX_HPP
#define CG_PROJECT_BOX_HPP
#include "point.hpp"
#include <vector>


class Box{
    private:
        float edge;
        int grid;

    public:
        Box(float e, int g);
};

#endif //CG_PROJECT_BOX_HPP
