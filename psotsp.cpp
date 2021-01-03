#include "psotsp.h"
psotsp::psotsp(int _runs, int _iters, int _popsize, int _sol_size, double _alpha, double _beta, string _inputfile)
{
    runs = _runs;
    iters = _iters;
    popsize = _popsize;
    sol_size = _sol_size;
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
    initialvector();

}

void psotsp::initialvector()
{
    solution.assign(popsize,d1d(sol_size,0));
    fitness.assign(popsize,0);
    global_best.assign(sol_size,0);
    personal_best.assign(popsize,d1d(sol_size,0));
    personal_fit.assign(popsize,0);
    place.assign(sol_size,d1d(2,0));
}


