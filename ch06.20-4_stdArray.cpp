// ch06.20-4_stdArray.cpp
//

#include <iostream>
#include <array>
#include <algorithm>        // sort
using namespace std;

void printLength(const array<int, 5>& my_arr)
{
    cout << my_arr.size() << endl;
}


int main()
{
    array<int, 5> my_arr = { 1, 21, 3, 40, 5 }; // 숫자가 뒤죽박죽이게 만든다.

    for (auto &element : my_arr)    // 여기에도 reference를 달아줄 수 있다. 
                                    // 중간 복사 생략. 빨라진다.
        cout << element << " ";     // 1 21 3 40 5
    cout << endl;
    cout << endl;

    std::sort(my_arr.begin(), my_arr.end());

    for (auto& element : my_arr)    // 중간 복사를 안 하므로 빨라진다.
        cout << element << " ";     // 1 3 5 21 40, sorting이 잘 됐다.
    cout << endl;
    cout << endl;

    // 내림차순은 어떻게 하는가?

    std::sort(my_arr.rbegin(), my_arr.rend());  // reversed begin, reversed end

    for (auto& element : my_arr)    // 중간 복사를 안 하므로 빨라진다.
        cout << element << " ";


    return 0;
}

// std::array에 대해서 살펴 봤다.
// 기본적으로 사용하던 built-in array하고 비슷하다.
// 하지만 여러 가지 면에서 훨씬 더 편리하게 사용할 수 있다.
// 용법을 설명했고, sorting하는 방법도 설명했다.
// 이러한 장점은 std library 전반에 걸쳐서 나타난다.
// 뒤로 갈수록 코딩 양은 어떻게 보면 줄어들 수도 있다.
// 앞에서는 귀찬아도 한 번씩 짜 보는 걸 추천한다.
// 너무 어렵다 싶으면 그냥 쭉쭉 가라.
// 그러면 뒤에서 그것들을 자동으로 구현된 상태로 사용하는 방법을 알려 주겠다.
