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
   vector<Point> pontos;
        vector<Point> normais;
        vector<Point> texturas;
        float alpha = 2 * M_PI / slices;
        float beta = M_PI / stacks;
        float itStacks = 1.0f/((float) stacks);
        float itSlices = 1.0f/((float) slices);
        float cSlices = 0;
        float cStacks = 0;

        //metade superior da esfera
        for (int stack = stacks/2; stack >= 0; stack--){
            for (int slice=0; slice <= slices; slice++) {

                pontos.push_back(Point(radius * cosf(stack*beta) * sinf(slice*alpha), radius * sinf(stack*beta), radius * cosf(stack*beta) * cosf(slice*alpha)));
                pontos.push_back(Point(radius * cosf((stack - 1)*beta) * sinf(slice*alpha), radius * sinf((stack - 1)*beta), radius * cosf((stack - 1)*beta) * cosf(slice*alpha)));

                normais.push_back(Point(cosf(stack*beta) * sinf(slice*alpha), sinf(stack*beta), cosf(stack*beta) * cosf(slice*alpha)));
                normais.push_back(Point(cosf((stack - 1)*beta) * sinf(slice*alpha), sinf((stack - 1)*beta), cosf((stack - 1)*beta) * cosf(slice*alpha)));

                texturas.push_back(Point(cSlices, cStacks, 0));
                texturas.push_back(Point(cSlices, cStacks - itStacks, 0));

                cSlices = cSlices + itSlices;
            }
            cStacks = cStacks - itStacks;
            cSlices = 0.0;
        }

        cSlices = 0;
        cStacks = 0.5;

        //metade inferior da esfera
        for (int stack = 0; stack <= stacks/2; stack++){
            for (int slice=0; slice <= slices; slice++) {
                pontos.push_back(Point(radius * cosf(-stack * beta) * sinf(slice*alpha), radius * sinf(-stack * beta), radius * cosf(-stack * beta) * cosf(slice*alpha)));
                pontos.push_back(Point(radius * cosf(-(stack + 1)*beta) * sinf(slice*alpha), radius * sinf(-(stack + 1)*beta), radius * cosf(-(stack + 1)*beta) * cosf(slice*alpha)));

                normais.push_back(Point(cosf(-stack * beta) * sinf(slice*alpha), sinf(-stack * beta), cosf(-stack * beta) * cosf(slice*alpha)));
                normais.push_back(Point(cosf(-(stack + 1)*beta) * sinf(slice*alpha), sinf(-(stack + 1)*beta), cosf(-(stack + 1)*beta) * cosf(slice*alpha)));

                texturas.push_back(Point(cSlices, cStacks, 0));
                texturas.push_back(Point(cSlices, cStacks - itStacks, 0));

                cSlices = cSlices + itSlices;
            }
            cStacks = cStacks - itStacks;
            cSlices = 0.0;
        }

    array<vector<Point>,3> result = {pontos, normais, texturas};
    return result;
}