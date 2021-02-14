#include <iostream>
using namespace std;

void printArray(int* array)
{
    cout << sizeof(array) << endl;  // 4
    cout << *array << endl;         // 9

    *array = 100;
}

int main()
{
    int array[5] = { 9, 7, 5, 3, 1, };

    cout << array[0] << " " << array[1] << endl;    // 9 7
    cout << array << endl;                          // 00B3F7EC, the same
    cout << &array[0] << endl;                      // 00B3F7EC, the same

    cout << *array << endl;                         // 9

    char name[] = "jackjack";
    
    cout << *name << endl;                          // j
    cout << name << endl;                           // jackjack
    cout << &name << endl;                          // 00B3F7D8

    int* ptr = array;
    cout << ptr << endl;                            // 00B3F7EC, the same
    cout << *ptr << endl;                           // 9 
    cout << &ptr << endl;                           // 00B3F7CC. different address

    printArray(array);                              // 4 9 

    cout << array[0] << " " << *array << endl;      // 100 100 
     
    cout << *ptr << " " << *(ptr + 1) << endl;      // 100 7
    
    return 0;
}
