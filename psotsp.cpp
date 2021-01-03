#include "psotsp.h"
psotsp::psotsp(int _runs, int _iters, int _popsize, int _sol_size, double _alpha, double _beta, string _inputfile)
{
    runs = _runs;
    iters = _iters;
    popsize = _popsize;
    cities = _sol_size;
    alpha = _alpha;
    beta = _beta;
    inputfile = _inputfile;
    cout << inputfile << endl;
}
psotsp::~psotsp() {}

void psotsp::run()
{
    for (int i = 0; i < runs; i++)
    {
        initialization();
        for (int j = 0; j < iters; j++)
        {
            transistion();
            evaluation();
        }
    }
}

void psotsp::initialization()
{
    srand(time(NULL));
    initialvector();
    e_count = 0;
    // readfile
    fp = fopen(inputfile.c_str(), "r");
        for (int i = 0; i < cities; i++)
            fscanf(fp, "%d %d %d", &place[i][0], &place[i][0], &place[i][1]);
    fclose(fp);

    for(int i = 0; i < popsize; i++)
    {
        for (int j = 0; j < cities; j++)
        {
            solution[i][j] = j;
        }
    }
    
}

void psotsp::initialvector()
{
    solution.assign(popsize,d1d(cities,0));
    fitness.assign(popsize,0);
    global_best.assign(cities,0);
    personal_best.assign(popsize,d1d(cities,0));
    personal_fit.assign(popsize,0);
    place.assign(cities,i1d(2,0));
}

void psotsp::transistion()
{

}

void psotsp::evaluation()
{

}
