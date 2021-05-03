// ch07.05-01_ReturningValues05.cpp 
//
// return by reference

#include <iostream>
using namespace std;

int& getValue(int x) {
    int value = x * 2;
    return value;
}

int main()
{
    int value = getValue(5);    // getValue(5)가 레퍼런스를 반환해서
                                // 래퍼런스가 잠깐 남아 있는 상태에서
                                // 그 래퍼런스가 가리키고 있는 변수의 실제 값이 
                                // 이 value로 복사해서 들어온다. 
    cout << value << endl;      // 비교적 안전하게 나온다.    

    return 0;
}


