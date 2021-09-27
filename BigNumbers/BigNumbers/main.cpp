#include <iostream>
#include <cstdlib>
#include "BigNumbers.h"
#include <ctime>
#include <chrono>

using namespace std;

int main()
{
    UINT1024 x, y, z;
    bitset<1024> b;
    b.reset();
    //b.set(128);
    string str;

    z.num = b;
    y.num = b;
    
    y.reset();

    y.num.set(100);

    chrono::steady_clock::time_point begin, end;

    begin = chrono::steady_clock::now();

    str = y.FastB2DConversion();

    end = chrono::steady_clock::now();

    cout << str << endl << chrono::duration_cast<chrono::nanoseconds>(end - begin).count();

}