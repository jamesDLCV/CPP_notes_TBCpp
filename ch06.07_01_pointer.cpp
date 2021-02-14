#include <iostream>
#include <typeinfo>
using namespace std;

int main()
{
    int x = 5, y = 6;
    int* ptr_x = &x, * ptr_y = &y;  // initialization, both variables need *

    cout << ptr_x << endl;          // address
    cout << *ptr_x << endl;         // 5, value
    cout << endl;

    double d = 1.0;
    double* ptr_d;
    ptr_d = &d;                     // initialization

    cout << ptr_d << endl;
    cout << *ptr_d << endl;
    cout << endl;

    cout << typeid(*ptr_x).name() << endl;
    cout << typeid(*ptr_d).name() << endl;
    cout << endl;

    return 0;
}
