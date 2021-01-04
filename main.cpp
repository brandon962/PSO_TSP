#include <iostream>
// #include "psotsp.h"
#include "psotsp.cpp"

using namespace std;

int main(int argc, char *argv[])
{
    cout << "?" << endl;
    if (argc < 5)
    {
        psotsp test = psotsp(30, 5000, 50, 51, 0.8, 40, 0.7, 0.3, "eil51.txt");
        test.run();
    }
    else
    {
        psotsp test = psotsp(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), atoi(argv[4]), atof(argv[5]), atoi(argv[6]), atof(argv[7]), atof(argv[8]), argv[9]);
        test.run();
    }

    return 0;
}