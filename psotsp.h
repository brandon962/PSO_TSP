// #pragma once
#include <string>
#include <iostream>
#include "myVector.h"

using namespace std;

class psotsp
{
public:
    int runs;
    int iters;
    int popsize;
    int sol_size;
    double alpha;
    double beta;
    string inputfile;

    d2d solution;
    d1d fitness;
    d1d global_best;
    double global_fit;
    d2d personal_best;
    d1d personal_fit;
    d2d place;

    psotsp(int runs, int iters, int popsize, int sol_size, double alpha, double beta, string inputfile);
    ~psotsp();

    void initialvector();
    void initialization();
    void transistion();
    void evaluation();

    void run();
};


