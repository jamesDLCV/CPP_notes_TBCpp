// ch07.03-4_PassingArgumentsByReference.cpp
//
// 매개변수로 reference를 쓸 때의 단점. 일반적으로는 더 좋으나...


#include <iostream>
#include <cmath>        // sin(), cos()
using namespace std;

void foo(int& x)
{
    cout << x << endl;
}

void foo1(const int& x1)    // x1의 값이 내부에서 변경되지 않을 때만 const를 붙일 수 있다.
{
    cout << x1 << endl;

    // 요즘에는 코딩하는 스타일이 조금 변하고 있다.
    // 입력으로 들어올 것은 const int &x;와 같이 const reference, 이렇게 집어 넣는다.
    // 출력은 입력 뒤에 reference로 넣는 것이 전통적인 코딩 방법이었다.
    // 모던 c++에서 return value optimization이라는 기술이 아주 잘 도입이 됐다.
    // 여러 개의 return type을 구현하는 것이 그리 복잡하지 않게 되었다.
    // 여러 개의 return type을 구현하는 방법은 앞쪽의 강의에서 소개했다. 참조해라.
    // 매개변수 들어가는 것은 위와 같이 (const int& x1) 이렇게 들어가는 것이 일반적이다.
    // 함수를 선언하고 괄호를 치는 순간 const로 바로 손이 간다. 버릇이 돼 버린다.
    // 교과서에서는, 이처럼 매개변수를 reference로 써 주는 것이 좋다는 걸 늦게 가르친다.
    // 그래서 실무에 들어가서 open source를 읽기 시작하면서 이것을 처음 보는 경우가 많다.
}

int main()
{
    /*
    foo(6);     // 코드 구조로만 보면 value 6이 함수로 넘어가면, x가 출력이 되지 않겠는가
                // 하고 생각할 수 있다.
                // 하지만 compile error가 뜬다.
    */

    // 위처럼은 왜 안 되는가?
    // 왜냐하면, 받는 쪽에서는 reference로 받아야 하는데 value 6은 주소가 없다.
    // 리터럴이다. 문제가 발생한다.
    // 그럼 어떻게 해결할 것인가? 간단하게는 함수의 매개변수에서 &를 떼어 버리면 된다.
    // 두 번째 해결 방법은 함수의 매개변수 reference 앞에 const를 붙이면 된다.
    // 물론 매개변수의 값이 함수 내부에서 변경이 되지 않을 때만 const를 붙이는 것이 가능하다.

    foo1(6);    // 아무 문제 없다. ㅋㅋ

    return 0;
}
