#include <iostream>
using namespace std;

void attachChar(char a[], char b[]);
void compareChar(char a[], char b[]);

int main()
{
    char source[] = "Copy this!";
    char dest[] = "Copy this!";  
       
    attachChar(dest, source);

    compareChar(dest, source);
        
}

void attachChar(char a[], char b[])
{
    cout << a << b << endl;
}

void compareChar(char a[], char b[])
{    
    bool sameChar = true;
    int maxLength = (strlen(a) < strlen(b)) ? strlen(b) : strlen(a);

    for (int i = 0; i < maxLength; ++i)
    {
        if (a[i] == b[i])
        {
            sameChar = true;
        }
        else
        {
            sameChar = false;
            break;
        }
    }
    if (sameChar) cout << "they are the same" << endl;
    else cout << "they are not the same" << endl;
}
