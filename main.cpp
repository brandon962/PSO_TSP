#include <iostream>
// #include "psotsp.h"
#include "psotsp.cpp"

using namespace std;

int main()
{
    psotsp test = psotsp(1, 10, 5, 51, 0.5, 0.7, 0.7, "eil51.txt");
    test.run();

    return 0;
}