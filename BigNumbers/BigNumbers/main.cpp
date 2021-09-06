#include <iostream>
#include "BigNumbers.h"
#include <ctime>
#include <chrono>

using namespace std;

int main()
{
    UINT1024 x, y, z;

    bitset<1024> b;
    b.reset();

    b.set(1000);

    z.num = b;

    y.num = b;

    chrono::steady_clock::time_point begin, end;
    
    cout << "Inicio" << endl;

    begin = chrono::steady_clock::now();

    cout << z.BitsToDecimal();

    //cout << z.ToString();

    end = chrono::steady_clock::now();

    cout << endl << "Fin" << endl;

    

    cout << endl << chrono::duration_cast<chrono::nanoseconds>(end - begin).count();

}