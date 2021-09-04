#include <iostream>
#include "BigNumbers.h"
#include <ctime>
#include <chrono>

using namespace std;

int main()
{
    UINT1024 x, y, z;

    bitset<1000000> b;
    b.reset();
    b.set(200000);

    z.num = b;

    b.reset();
    b.set(200001);

    y.num = b;

    chrono::steady_clock::time_point begin, end;
    
    cout << "Inicio" << endl;

    begin = chrono::steady_clock::now();

    x = y + z;

    end = chrono::steady_clock::now();

    cout << "Fin" << endl;

    //x.ToString();

    

    cout << endl << chrono::duration_cast<chrono::microseconds>(end - begin).count();

}