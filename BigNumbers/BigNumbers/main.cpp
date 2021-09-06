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
<<<<<<< Updated upstream
    b.set(100);
=======

    b.set(1019);
>>>>>>> Stashed changes


    z.num = b;

    //z = 8;

<<<<<<< Updated upstream
    b.reset();
    b.set(100);

=======
>>>>>>> Stashed changes
    y.num = b;

    //y = 4;

    chrono::steady_clock::time_point begin, end;
    
    cout << "Inicio" << endl;

    begin = chrono::steady_clock::now();
    auto a = y + z;
    //x = y + z;
    for (int i = 0; i < 24; i++) {
        x = x + a;
    }
    

    end = chrono::steady_clock::now();

    cout << x.ToString();

    cout << endl << "Fin" << endl;

    

    cout << endl << chrono::duration_cast<chrono::nanoseconds>(end - begin).count();

}