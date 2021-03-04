// ch07.12-2_RecursiveFunctionCall.cpp
//
// 0부터 숫자를 더해 나가는 예제를 해 보자.
//


#include <iostream>
using namespace std;

int sumTo(int sumto)
{
    if (sumto <= 0)
        return 0;
    else if (sumto <= 1)
        return 1;
    else
        return sumTo(sumto - 1) + sumto;
    /*
    디버거로 찍을 때는 위 else를 다음과 같이 해 주면 찍히는 게 보인다.
    else
    {
        const int sum_minus_one = sumTo(sumto - 1);
        return sum_minus_one + sumto;
    }
    */
}

int main()
{
    cout << sumTo(10) << endl;


    return 0;
}

// 재귀 함수를 사용하는 아주 흔한 예제가 피보나치 수열 출력이다.
// ch07.02-3_RecursiveFunctionCall.cpp 에서 살펴 본다.
