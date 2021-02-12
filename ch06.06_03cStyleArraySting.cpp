#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char source[] = "Copy this!";
    char dest[50];
    strcpy_s(dest, 50, source);      

    cout << strcmp(dest, source) << endl;  // same string returns 0, not same returns 1

    if (strcmp(source, dest) == 0)         // need to add '0' comparision
    {
        cout << "the same" << endl;
    }
    else
    {
        cout << "not the same" << endl;
    }

    return 0;
}

