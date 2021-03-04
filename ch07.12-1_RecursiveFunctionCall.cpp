// ch07.12-1_RecursiveFunctionCall.cpp
//
// 재귀적 함수 호출은 자신과 이름이 똑같은 함수를 다시 호출하는 것이다.
// 말로는 조금 어렵지만 코드를 보면 쉽게 이해할 수 있을 것이다.
// 숫자를 하나씩 내려가면서 출력하는 함수를 하나 만들어 보겠다.
// 이것을 recursion으로 짜 보겠다.
// for문으로 짜면 되는 것 아니냐고 할 수도 있겠지만 다음 예제를 보자.

#include <iostream>
using namespace std;

void countDown(int count)
{
    cout << count << endl;

    if (count >0)
        countDown(count - 1);   // 자기가 자기를 호출하는 것이다.
                                // 종료하는 조건을 반드시 만들어 줘야 한다.
                                // recursion을 너무 많이 하면 stack overflow가 난다.
                                // 다른 함수보다 stack이 쌓일 가능성은 엄청 크다.
                                // 이 재귀 호출 말고는 구현이 어려운 알고리즘이 있다.
                                // 그럴 때는 재귀 호출을 써야 하므로 주의점을 알고 있어라.
    // stack overflow가 너무 두렵다면,
    // 전 강의의 std::vector를 stack처럼 써서 막는 방법도 있다.




}

int main()
{
    countDown(5);       // 디버거를 찍어 보자.


    return 0;
}
