#include "headers/bezier.hpp"
#include <math.h>
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <sstream>

using namespace std;

Bezier::Bezier(string filename, int tess) {
    inputFile = filename;
    tessellation = tess;
}

void Bezier::parsing (string filenameInput) {

    string patch_generated_path = "../" + filenameInput;
    ifstream file(patch_generated_path.c_str());
    string firstLine, line;

    // Colocar valor dos indices de cada patch no array.
    getline(file, firstLine);
    numPatches = atoi(firstLine.c_str());
    //C++ always requires cast in mallocs
    // cada linha sao 16 pontos que sao int
    patches = (unsigned int*) malloc(sizeof(unsigned int) * numPatches * 16);
    for (int p = 0; p < numPatches; p++) {
        getline(file, line);
        istringstream indexes(line);
        string indexP;
        for (int i = 0; i < 16 && getline(indexes, indexP, ','); i++){
            patches[p * 16 + i] = atoi(indexP.c_str());
        }
    }

    // Colocar valor dos pontos de controlo no array.
    getline(file, firstLine);
    numControlPoints = atoi(firstLine.c_str());
    controlPoints = (float *)malloc(sizeof(float) * 3 * numControlPoints);
    for (int cp = 0; cp < numControlPoints; cp++) {
        getline(file, line);
        istringstream indexes(line);
        string indexCP;
        for (int i = 0; i < 3 && getline(indexes, indexCP, ','); i++){
            controlPoints[cp * 3 + i] = (float)atof(indexCP.c_str());
        }
    }
}


Point Bezier::pontoBezier(int p, float u, float v) {
    Point ponto = Point(0.0, 0.0, 0.0);

    // Polinomio de Bernstein
    // P(t) = (1-t)^3 P0 + 3t(1-t)^2 P1 + 3t^2(1-t) P2 + t^3 P3
    //          b03          b13             b23           b33
    float bernsteinU[4] = { powf(1-u, 3), 3 * u * powf(1-u, 2), 3 * powf(u, 2) * (1-u), powf(u, 3) };
    float bernsteinV[4] = { powf(1-v, 3), 3 * v * powf(1-v, 2), 3 * powf(v, 2) * (1-v), powf(v, 3) };


    for (int j=0; j<4; j++)
        for (int i=0; i<4; i++) {

            //Indice dentro de um patch p
            int indexPatch = j*4+i;
            //Respetivo indice do ponto de controlo
            int indexCP = patches[p*16 + indexPatch];
            ponto = Point(ponto.getX() + controlPoints[indexCP * 3 + 0] * bernsteinU[j] * bernsteinV[i],
                          ponto.getY() + controlPoints[indexCP * 3 + 1] * bernsteinU[j] * bernsteinV[i],
                          ponto.getZ() + controlPoints[indexCP * 3 + 2] * bernsteinU[j] * bernsteinV[i]);


        }

    return ponto;
}


vector<Point> Bezier::pointsGenerator() {
    parsing(inputFile);

    vector<Point> pontos;

    for (int p=0; p<numPatches; p++) {

        for (int tv=0; tv<tessellation; tv++) {
            float v = (float) tv/tessellation;

            for (int tu = 0; tu < tessellation; tu++) {
                float u = (float) tu/tessellation;

                // triângulo superior
                pontos.push_back(pontoBezier(p, (u + (1.0f/tessellation)), (v + (1.0f/tessellation))));
                pontos.push_back(pontoBezier(p, u, (v + (1.0f/tessellation))));
                pontos.push_back(pontoBezier(p, u, v));
                // triângulo inferior
                pontos.push_back(pontoBezier(p, u, v));
                pontos.push_back(pontoBezier(p, (u + (1.0f/tessellation)), v));
                pontos.push_back(pontoBezier(p, (u + (1.0f/tessellation)), (v + (1.0f/tessellation))));
            }
        }
    }

    return pontos;
}
