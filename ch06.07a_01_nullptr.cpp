#include <iostream>
using namespace std;

void doSomething(double* ptr)
{
    cout << "address of pointer variable in doSomething() " << &ptr << endl; //00CFF9E4

    if (ptr != nullptr)
    {
        cout << *ptr << endl;
    }
    else
    {
        cout << "Null ptr, do nothing" << endl;
    }
}

int main()
{
    //double* ptr{ nullptr };   

    double* ptr;
    ptr = nullptr;          // double *ptr = nullptr;

    doSomething(ptr);       // Null ptr, do nothing
    doSomething(nullptr);   // Null ptr, do nothing
    
    double d = 123.4;
    doSomething(&d);        // 123.4
    
    ptr = &d;
    doSomething(ptr);       // 123.4

    cout << "address of pointer variable in main() " << &ptr << endl;   // 00CFFAC8
    
    return 0;
}

