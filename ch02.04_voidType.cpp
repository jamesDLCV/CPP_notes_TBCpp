// ch02.04_voidType.cpp
//

#include <iostream>

int main()
{
    using namespace std;

    double d1(100 - 99.99);
    double d2(10 - 9.99);

    cout << d1 << endl;
    cout << d2 << endl;

    if (d1 == d2)
        cout << "equal" << endl;
    else
    {
        cout << "Not equal" << endl;

        if (d1 > d2) cout << "d1 > d2" << endl;
        else
            cout << "d1 < d2" << endl;
    }

    return 0;
}
