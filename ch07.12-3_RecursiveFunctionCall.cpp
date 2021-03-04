// ch07.12-3_RecursiveFunctionCall.cpp
// 피보나치 수열이란?
// 0 1 1 2 3 5 8 13 21 ...
// 이것을 재귀 함수로 만들어 봐라.


#include <iostream>
using namespace std;

void pibonacci(int sum)
{
    cout << sum << " ";
    cout << pibonacci(sum) + sum << " ";
    sum += 1;
}

int main()
{

    pibonacci(0);

    return 0;
}

// iterative가 있다. 반복하는 것이 있다.
// 원소들을 다 돌면서 작업을 하는 것이다.  <- iteration이라고 한다.
// recursion은 이 강의에서 보여 준 재귀 함수다.
// 두 가지가 비슷한 듯하면서 명확하게 다르다.
// recursion은 구현하기는 더 쉽다.
// 가끔 recursion으로 짜고 싶다고 느끼기도 하지만 recursion은 iteration과 다르게
// stack을 사용하기 때문에, depth가 한계가 있다.
// 또 기계마다 다르다.
// 가급적 iteration으로 바꿔서 사용하는 편이다.
// recursion은 performance가 중요한 코드에서는 사용하지 않는 것이 좋다.
// 다른 과목에서 정밀하게 배우게 될 것이다.
//
