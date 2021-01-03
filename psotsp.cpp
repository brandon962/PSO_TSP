#include "psotsp.h"
psotsp::psotsp(int _runs, int _iters, int _popsize, int _sol_size, double _decay, double _alpha, double _beta, string _inputfile)
{
    srand(time(NULL));
    runs = _runs;
    iters = _iters;
    popsize = _popsize;
    cities = _sol_size;
    decay = _decay;
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
            printALLfit();
        }
    }
}

void psotsp::initialization()
{

    initialvector();
    // readfile
    fp = fopen(inputfile.c_str(), "r");
    for (int i = 0; i < cities; i++)
        fscanf(fp, "%d %d %d", &place[i][0], &place[i][0], &place[i][1]);
    fclose(fp);

    // for (int i = 0; i < cities; i++)
    // {
    //     cout << place[i][0] << " " << place[i][1] << endl;
    // }

    int r1, r2;
    for (int i = 0; i < popsize; i++)
    {
        for (int j = 0; j < cities; j++)
        {
            r1 = rand() % 2;
            r2 = rand() % ((int)cities / 5 - 1) + 1;
            if (r1 == 0)
                r1 = -1;
            solution[i][j] = j;
            if (j == 0 || j == 1)
                speed[i][j] = 0;
            else
                speed[i][j] = (double)r1 * r2;
        }
    }

    int a, b;
    double minpath = DBL_MAX;
    double dtemp;
    for (int i = 0; i < cities; i++)
    {
        for (int j = i + 1; j < cities; j++)
        {
            dtemp = distance(i, j);
            if (dtemp < minpath)
            {
                a = i;
                b = j;
                minpath = dtemp;
            }
        }
    }

    for (int i = 0; i < popsize; i++)
    {
        swap(solution[i][a], solution[i][0]);
        swap(solution[i][b], solution[i][1]);
        for (int j = 0; j < cities; j++)
        {
            r1 = rand() % (cities - 2) + 2;
            r2 = rand() % (cities - 2) + 2;
            swap(solution[i][r1], solution[i][r2]);
        }
    }

    global_fit = DBL_MAX;
    printAllpath();
    evaluation();
    printALLfit();
    e_count = 0;
    p_count = 0;
}

void psotsp::sol2path()
{
    int r1;
    for (int i = 0; i < popsize; i++)
    {
        // init choosen array for checking which city has been choosen.
        for (int j = 0; j < cities; j++)
            choosen[j] = 0;
        // init path array
        for (int j = 0; j < cities; j++)
            path[i][j] = -1;

        // path[i][j] = (int)solution[i][j] with no repeat, if repeat path[i][j] still be -1
        for (int j = 0; j < cities; j++)
        {
            cout << (int)solution[i][j] << endl;
            if (choosen[(int)solution[i][j]] == 0)
            {
                choosen[(int)solution[i][j]] = 1;
                path[i][j] = (int)solution[i][j];
            }
        }
        // deteat if there exist path[i][j] = -1, if exist assign it a random but not choosen cities.
        for (int j = 0; j < cities; j++)
        {
            if (path[i][j] == -1)
            {
                r1 = rand() & cities;
                while (choosen[r1 % (cities)] == 1)
                    r1++;
                choosen[r1] = 1;
                path[i][j] = r1;
            }
        }
    }
}

void psotsp::printAllpath()
{
    sol2path();
    for (int i = 0; i < popsize; i++)
    {
        for (int j = 0; j < cities; j++)
            cout << path[i][j] + 1 << " ";
        cout << path[i][0] + 1 << endl;
    }
}

void psotsp::printALLfit()
{
    for (int i = 0; i < popsize; i++)
        cout << fitness[i] << endl;
}

void psotsp::initialvector()
{
    solution.assign(popsize, d1d(cities, 0));
    fitness.assign(popsize, 0);
    global_best.assign(cities, 0);
    personal_best.assign(popsize, i1d(cities, 0));
    personal_fit.assign(popsize, DBL_MAX);
    place.assign(cities, i1d(2, 0));
    speed.assign(popsize, d1d(cities, 0));
    choosen.assign(cities, 0);
    path.assign(popsize, i1d(cities, 0));
}

double psotsp::distance(int x1, int x2)
{
    p_count++;
    return sqrt(pow((place[x1][0] - place[x2][0]), 2) + pow((place[x1][1] - place[x2][1]), 2));
}

void psotsp::transistion()
{
    double r1;
    // count the particle speed v = w*v + a*r*(gb-x) + b*r*(pb-x)
    for (int i = 0; i < popsize; i++)
    {
        for (int j = 0; j < cities; j++)
        {
            speed[i][j] = decay * speed[i][j];
            r1 = (rand() / (RAND_MAX + 1.0));
            speed[i][j] += alpha * r1 * (global_best[j] - solution[i][j]);
            r1 = (rand() / (RAND_MAX + 1.0));
            speed[i][j] += beta * r1 * (personal_best[i][j] - solution[i][j]);
        }
    }

    // count particle new place x = x + v, if out of range equal random number
    for (int i = 0; i < popsize; i++)
    {
        for (int j = 0; j < cities; j++)
        {
            // cout << solution[i][j] << " ";
            solution[i][j] += speed[i][j];
            if (solution[i][j] < 0)
                solution[i][j] = rand()%cities;
            cout << solution[i][j] << " ";
            // solution[i][j] > (cities + 1) ? solution[i][j] = rand() % cities : solution[i][j] = solution[i][j];
            // solution[i][j] < 0 ? solution[i][j] = rand() % cities : solution[i][j] = solution[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

void psotsp::evaluation()
{
    cout << "___________" << endl;
    e_count++;
    sol2path();
    int length = 0;
    for (int i = 0; i < popsize; i++)
    {
        // calculate the path length to fitness value.
        length = 0;
        for (int j = 0; j < cities - 1; j++)
            length += distance(path[i][j], path[i][j + 1]);
        length += distance(path[i][cities - 1], path[i][0]);
        fitness[i] = length;

        // update gb pb
        if (length < personal_fit[i])
        {
            personal_fit[i] = length;
            personal_best[i] = path[i];
        }
        if (length < global_fit)
        {
            global_fit = length;
            global_best = path[i];
        }
    }
}
