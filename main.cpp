#include <iostream>
// #include "psotsp.h"
#include "psotsp.cpp"

using namespace std;

int main()
{
    psotsp test = psotsp(1,1,5,10,2,2,"eil51.txt");
    test.run();

    return 0;    
}