// #pragma once
#define _CRT_SECURE_NO_DEPRECATE
#include <string>
#include <iostream>
#include "myVector.h"
#include <fstream>
#include <ctime>
#include <cfloat>
#include <cmath>

using namespace std;

class psotsp
{
public:
    int runs;
    int iters;
    int popsize;
    int cities;
    double decay;
    double alpha;
    double beta;
    string inputfile;
    int e_count;
    int p_count;
    FILE *fp;

    d2d solution;
    d2d speed;
    i2d path;
    d1d fitness;
    i1d global_best;
    double global_fit;
    i2d personal_best;
    d1d personal_fit;
    i2d place;
    i1d choosen;

    psotsp(int runs, int iters, int popsize, int cities, double decay, double alpha, double beta, string inputfile);
    ~psotsp();

    void initialvector();
    void initialization();
    void transistion();
    void evaluation();
    double distance(int x1, int x2);
    void printAllpath();
    void sol2path();
    void printALLfit();

    void run();
};
