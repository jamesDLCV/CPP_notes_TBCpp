#include <iostream>
using namespace std;

unsigned int PRNG() // Pseudo Random Number
{
    static unsigned int seed = 5523; // seed number
    seed = 8253729 * seed + 2396403;

    return seed % 32768;
}

int main()
{
    for (int count = 1; count <= 100; ++count)
    {
        cout << PRNG() << "\t";
        if (count % 5 == 0) cout << endl;
    }

    return 0;
}
