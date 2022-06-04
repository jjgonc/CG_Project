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
    // controlPoints = (float *) malloc(sizeof(float) * 3 * numControlPoints);
    for (int cp = 0; cp < numControlPoints; cp++) {
        getline(file, line);
        istringstream indexes(line);
        string indexCP;

        getline(indexes, indexCP, ',');
        float x = (float)atof(indexCP.c_str());
        getline(indexes, indexCP, ',');
        float y = (float)atof(indexCP.c_str());
        getline(indexes, indexCP, ',');
        float z = (float)atof(indexCP.c_str());
        controlPoints.push_back(Point(x,y,z));
    }
}



void multMatrixVector(float *m, float *v, float *res) {

    for (int j = 0; j < 4; ++j) {
        res[j] = 0;
        for (int k = 0; k < 4; ++k) {
            res[j] += v[k] * m[j * 4 + k];
        }
    }

}

void multVectorMatrix(float *v, float *m, float *res) {

    for (int j = 0; j < 4; j++) {
        res[j] = 0;
        for (int k = 0; k < 4; k++) {
            res[j] += v[k] * m[k * 4 + j];
        }
    }

}

float multVectorVector(float *v1, float *v2) {
    float res = 0;
    for (int j = 0; j < 4; j++) {
        res += v1[j] * v2[j];
    }
    return res;
}


Point Bezier::pointBezier(int p, float u, float v, int option) { // option = 0 nao derivada
                                                                 // option = 1 derivada em u
                                                                 // option = 2 derivada em v

    float m[4][4] = {{-1.0f, +3.0f, -3.0f, +1.0f},
                     {+3.0f, -6.0f, +3.0f, +0.0f},
                     {-3.0f, +3.0f, +0.0f, +0.0f},
                     {+1.0f, +0.0f, +0.0f, +0.0f}};


    float bu[4], bv[4];
    if (option == 0){
        bu[0] = powf(u,3);
        bu[1] = powf(u,2);
        bu[2] = u;
        bu[3] = 1;
        bv[0] = powf(v,3);
        bv[1] = powf(v,2);
        bv[2] = v;
        bv[3] = 1;
    }

    if (option == 1) {
        bu[0] = 3*powf(u,2);
        bu[1] = 2*u;
        bu[2] = 1;
        bu[3] = 0;
        bv[0] = powf(v,3);
        bv[1] = powf(v,2);
        bv[2] = v;
        bv[3] = 1;
    }

    if (option == 2){
        bu[0] = powf(u,3);
        bu[1] = powf(u,2);
        bu[2] = u;
        bu[3] = 1;
        bv[0] = 3*powf(v,2);
        bv[1] = 2*v;
        bv[2] = 1;
        bv[3] = 0;
    }

    float pointsX[4][4] = {{controlPoints[patches[p * 16]].getX(), controlPoints[patches[p * 16+1]].getX(), controlPoints[patches[p * 16+2]].getX(), controlPoints[patches[p * 16+3]].getX()},
                          {controlPoints[patches[p * 16+4]].getX(), controlPoints[patches[p * 16+5]].getX(), controlPoints[patches[p * 16+6]].getX(), controlPoints[patches[p * 16+7]].getX()},
                          {controlPoints[patches[p * 16+8]].getX(), controlPoints[patches[p * 16+9]].getX(), controlPoints[patches[p * 16+10]].getX(), controlPoints[patches[p * 16+11]].getX()},
                          {controlPoints[patches[p * 16+12]].getX(), controlPoints[patches[p * 16+13]].getX(), controlPoints[patches[p * 16+14]].getX(), controlPoints[patches[p * 16+15]].getX()}};

    float pointsY[4][4] = {{controlPoints[patches[p * 16]].getY(), controlPoints[patches[p * 16+1]].getY(), controlPoints[patches[p * 16+2]].getY(), controlPoints[patches[p * 16+3]].getY()},
                           {controlPoints[patches[p * 16+4]].getY(), controlPoints[patches[p * 16+5]].getY(), controlPoints[patches[p * 16+6]].getY(), controlPoints[patches[p * 16+7]].getY()},
                           {controlPoints[patches[p * 16+8]].getY(), controlPoints[patches[p * 16+9]].getY(), controlPoints[patches[p * 16+10]].getY(), controlPoints[patches[p * 16+11]].getY()},
                           {controlPoints[patches[p * 16+12]].getY(), controlPoints[patches[p * 16+13]].getY(), controlPoints[patches[p * 16+14]].getY(), controlPoints[patches[p * 16+15]].getY()}};

    float pointsZ[4][4] = {{controlPoints[patches[p * 16]].getZ(), controlPoints[patches[p * 16+1]].getZ(), controlPoints[patches[p * 16+2]].getZ(), controlPoints[patches[p * 16+3]].getZ()},
                           {controlPoints[patches[p * 16+4]].getZ(), controlPoints[patches[p * 16+5]].getZ(), controlPoints[patches[p * 16+6]].getZ(), controlPoints[patches[p * 16+7]].getZ()},
                           {controlPoints[patches[p * 16+8]].getZ(), controlPoints[patches[p * 16+9]].getZ(), controlPoints[patches[p * 16+10]].getZ(), controlPoints[patches[p * 16+11]].getZ()},
                           {controlPoints[patches[p * 16+12]].getZ(), controlPoints[patches[p * 16+13]].getZ(), controlPoints[patches[p * 16+14]].getZ(), controlPoints[patches[p * 16+15]].getZ()}};

    // RES = U * M
    float res[4];
    multMatrixVector(*m,bu,res);


    // RES2 = RES * P
    float res2X[4],res2Y[4],res2Z[4];
    multVectorMatrix(res,*pointsX,res2X);
    multVectorMatrix(res,*pointsY,res2Y);
    multVectorMatrix(res,*pointsZ,res2Z);

    // RES3 = RES2 * M
    float res3X[4],res3Y[4],res3Z[4];;
    multVectorMatrix(res2X,*m,res3X);
    multVectorMatrix(res2Y,*m,res3Y);
    multVectorMatrix(res2Z,*m,res3Z);

    // * BV
    float resX = multVectorVector(res3X,bv);
    float resY = multVectorVector(res3Y,bv);
    float resZ = multVectorVector(res3Z,bv);

    Point ponto = Point(resX, resY, resZ);
    return ponto;

}


array<vector<Point>,3> Bezier::pointsGenerator() {
    parsing(inputFile);

    vector<Point> pontos;
    vector<Point> normals;
    vector<Point> textures;


    for (int p=0; p<numPatches; p++) {

        for (int tv=0; tv<tessellation; tv++) {
            float v = (float) tv/tessellation;

            for (int tu = 0; tu < tessellation; tu++) {
                float u = (float) tu/tessellation;

                // triângulo superior
                // 0 no fim opçao para nao derivar
                pontos.push_back(pointBezier(p, (u + (1.0f/tessellation)), (v + (1.0f/tessellation)),0));
                pontos.push_back(pointBezier(p, u, (v + (1.0f/tessellation)),0));
                pontos.push_back(pointBezier(p, u, v,0));

                Point normalU1 = pointBezier(p, (u + (1.0f/tessellation)), (v + (1.0f/tessellation)),1); // derivar em ordem a U
                Point normalV1 = pointBezier(p, (u + (1.0f/tessellation)), (v + (1.0f/tessellation)),2); // derivar em ordem a V
                float x = (normalU1.getY() * normalV1.getZ()) - (normalU1.getZ() * normalV1.getY());
                float y = (normalU1.getZ() * normalV1.getX()) - (normalU1.getX() * normalV1.getZ());
                float z = (normalU1.getX() * normalV1.getY()) - (normalU1.getY() * normalV1.getX());
                normals.push_back(Point(x,y,z));

                Point normalU2 = pointBezier(p, u, (v + (1.0f/tessellation)),1); // derivar em ordem a U
                Point normalV2 = pointBezier(p, u, (v + (1.0f/tessellation)),2); // derivar em ordem a V
                x = (normalU2.getY() * normalV2.getZ()) - (normalU2.getZ() * normalV2.getY());
                y = (normalU2.getZ() * normalV2.getX()) - (normalU2.getX() * normalV2.getZ());
                z = (normalU2.getX() * normalV2.getY()) - (normalU2.getY() * normalV2.getX());
                normals.push_back(Point(x,y,z));


                Point normalU3 = pointBezier(p, u, v,1); // derivar em ordem a U
                Point normalV3 = pointBezier(p, u, v,2); // derivar em ordem a V
                x = (normalU3.getY() * normalV3.getZ()) - (normalU3.getZ() * normalV3.getY());
                y = (normalU3.getZ() * normalV3.getX()) - (normalU3.getX() * normalV3.getZ());
                z = (normalU3.getX() * normalV3.getY()) - (normalU3.getY() * normalV3.getX());
                normals.push_back(Point(x,y,z));


                // triângulo inferior
                pontos.push_back(pointBezier(p, u, v,0));
                pontos.push_back(pointBezier(p, (u + (1.0f/tessellation)), v,0));
                pontos.push_back(pointBezier(p, (u + (1.0f/tessellation)), (v + (1.0f/tessellation)),0));

                Point normalU4 = pointBezier(p, u, v,1); // derivar em ordem a U
                Point normalV4 = pointBezier(p, u, v,2); // derivar em ordem a V
                x = (normalU4.getY() * normalV4.getZ()) - (normalU4.getZ() * normalV4.getY());
                y = (normalU4.getZ() * normalV4.getX()) - (normalU4.getX() * normalV4.getZ());
                z = (normalU4.getX() * normalV4.getY()) - (normalU4.getY() * normalV4.getX());
                normals.push_back(Point(x,y,z));


                Point normalU5 = pointBezier(p, (u + (1.0f/tessellation)), v,1); // derivar em ordem a U
                Point normalV5 = pointBezier(p, (u + (1.0f/tessellation)), v,2); // derivar em ordem a V
                x = (normalU5.getY() * normalV5.getZ()) - (normalU5.getZ() * normalV5.getY());
                y = (normalU5.getZ() * normalV5.getX()) - (normalU5.getX() * normalV5.getZ());
                z = (normalU5.getX() * normalV5.getY()) - (normalU5.getY() * normalV5.getX());
                normals.push_back(Point(x,y,z));


                Point normalU6 = pointBezier(p, (u + (1.0f/tessellation)), (v + (1.0f/tessellation)),1); // derivar em ordem a U
                Point normalV6 = pointBezier(p, (u + (1.0f/tessellation)), (v + (1.0f/tessellation)),2); // derivar em ordem a V
                x = (normalU6.getY() * normalV6.getZ()) - (normalU6.getZ() * normalV6.getY());
                y = (normalU6.getZ() * normalV6.getX()) - (normalU6.getX() * normalV6.getZ());
                z = (normalU6.getX() * normalV6.getY()) - (normalU6.getY() * normalV6.getX());
                normals.push_back(Point(x,y,z));
            }
        }
    }

    array<vector<Point>,3> result = {pontos, normals, textures};
    return result;
}
