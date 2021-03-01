// ch06.20-3_stdArray.cpp
//

#include <iostream>
#include <array>
using namespace std;

void printLength(const array<int, 5>& my_arr)
                                      // my_array가 함수 안에서 변하지 않기를 원하면,
                                      // &my_array와 같이 &를 붙인다. 중간 복사 안 됨(?)
                                      // 그리고 const로 막아 놓는다.
                                      // ch06.20-2와 똑같이 작동한다.
{
    cout << my_arr.size() << endl;
}


int main()
{
    array<int, 5> my_arr = { 1, 2, 3, 4, 5 };

    cout << my_arr.size() << endl;      // 5

    printLength(my_arr);                // 5

    return 0;
}

// array나 vector 같은 표준 라이브러리를 사용하면,
// 레퍼런스를 쓸 건지 포인터를 쓸 건지, 아니면 그냥 넣을 건지를 결정할 때,
// 함수 parameter를 넣을 때 좀 주의를 해야 한다.
// 필요나 용도에 따라 선택하면 된다.
// 함수 paremeter에 const를 붙일지 말지도 그때 그때 결정하면 된다.

// 더 편할 걸 살펴 보자.
// ch06.20-4_stdArray.cpp에서 보자.
