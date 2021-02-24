#include <iostream>
using namespace std;

// const char은 리턴 타입으로도 쓸 수 있다.
const char *getName()
{
    return "Jack jack";
}

int main()
{
    const char *name = getName();
    const char *name2 = getName();

    cout << (uintptr_t)name << endl;   // 4210757
    cout << (uintptr_t)name2 << endl;  // 4210757
    // 동일한 주소 값을 가진다.
    // 이렇게 리턴 타입에도 넣어 줄 수 있다. 


    return 0;
}
