#include <iostream>
// #include "psotsp.h"
#include "psotsp.cpp"

using namespace std;

int main()
{
    cout << "?" << endl;
    psotsp test = psotsp(30, 1000, 50, 51, 0.8, 20, 0.7, 0.3, "eil51.txt");
    test.run();
    return 0;
}