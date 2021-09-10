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
    for (int x = 0; x < 7; x++) {
        b.set(x);
    }
    //b.set(128);

    z.num = b;
    y.num = b;
    y = z + z + z;

    chrono::steady_clock::time_point begin, end;

    begin = chrono::steady_clock::now();

    end = chrono::steady_clock::now();

    cout << endl << chrono::duration_cast<chrono::nanoseconds>(end - begin).count();

}