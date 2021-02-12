#include <iostream>
using namespace std;

int main()
{
    char myString[255];

    cin.getline(myString, 255);

    int ix = -1;
    while (true)
    {
        ++ix;
        cout << myString[ix] << " " << (int)myString[ix] << endl;
        
        if (myString[ix] == '\0') break;
    }       
    
    cout << endl;

    // c-style copy string
    cout << "strcpy_s" << endl;
    char source[] = "Copy this!";
    char dest[50];
    strcpy_s(dest, 50, source);
    cout << source << endl;
    cout << dest << endl;
    cout << endl;

    // c-style strcat
    cout << "strcat_s" << endl;
    strcat_s(dest, source);
    
    cout << "source: " << source << endl;
    cout << "dest: " << dest << endl;

    return 0;
}

