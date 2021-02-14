#include <iostream>
using namespace std;

struct MyStruct
{
    int array[5] = { 9, 7, 5, 3, 1, };
};

void doSomething(MyStruct* ms)
{
    cout << sizeof((*ms).array) << endl;
}

int main()
{
    MyStruct ms;                            // ms has the array[5]
    cout << ms.array[0] << endl;            // 9
    cout << sizeof(ms.array) << endl;       // 20

    doSomething(&ms);                       // 20

    return 0;
}
