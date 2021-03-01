// ch06.20-2_stdArray.cpp
//

#include <iostream>
#include <array>
using namespace std;

void printLength(array<int, 5> my_arr)  // 일반 변수도 parameter로 집어 넣으면 복사가 됨.
                                        // array도 복사가 된다.
                                        // array가 클 경우 복사하는 데 시간이 걸린다.
{
    cout << my_arr.size() << endl;
}


int main()
{
    array<int, 5> my_arr = { 1, 2, 3, 4, 5 };



    cout << my_arr.size() << endl;      // 5

    printLength(my_arr);                // 5, 똑같이 작동한다.

    return 0;
}
