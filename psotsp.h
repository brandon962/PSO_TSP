// #pragma once
#define _CRT_SECURE_NO_DEPRECATE
#include <string>
#include <iostream>
#include "myVector.h"
#include <fstream>
#include <ctime>

using namespace std;

class psotsp
{
public:
    int runs;
    int iters;
    int popsize;
    int cities;
    double alpha;
    double beta;
    string inputfile;
    int e_count;
    FILE *fp;

    d2d solution;
    d1d fitness;
    d1d global_best;
    double global_fit;
    d2d personal_best;
    d1d personal_fit;
    i2d place;

    psotsp(int runs, int iters, int popsize, int cities, double alpha, double beta, string inputfile);
    ~psotsp();

    void initialvector();
    void initialization();
    void transistion();
    void evaluation();

    void run();
};


