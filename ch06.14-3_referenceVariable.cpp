// ch06.14-3_referenceVariable.cpp
// reference로 해 보자.

#include <iostream>
using namespace std;

void doSomething(int &n)     // 간단하다. n 앞에 &를 붙여 주면 된다.
{
    cout << &n << endl;      // 주소를 찍어 보자. 00F3F7E0
    n = 10;
    cout << "in doSomething " << n << endl;
}

int main()
{
    int n = 5;

    cout << n << endl;      // 5

    cout << &n << endl;     // 주소를 찍어 보자. 00F3F7E0
                            // void 함수 안의 n과 같은 주소가 됐다.

    doSomething(n);         // in doSomething 10

    cout << n << endl;      // 10
                            // 함수에서 바뀐 n 값이 main() 안에도 그대로 영향을 준다.

    // 포인터를 넘길 때는, 포인터 변수의 주소는 또 다르다.
    // 포인터가 우리가 넘겨 주고자 하는 변수의 주소를 그대로 복사해서 넣어 주는 것이다.
    // 포인터 때 앞에서 설명을 했다. 잘 이해가 안 되면 복습을 해라.

    // 위에서의 함수의 인수 &n처럼 reference를 쓰게 되면,
    // 아예 변수 자체가 넘어 간다. 이런 개념이다. 아주 좋다. 훨씬 편리하다.

    // 퍼포먼스 측면에서도 그냥 n을 넘기면, 밖에는 영향을 못 준다는 단점이 있다. <- 논외!
    // 함수의 인수를 pointer로 넘겼을 때는 변수를 한 번 복사를 해야 한다.
    // 하지만 위와 같이 reference로 넘기면, 변수 자체가 넘어가는 것이기 때문에,
    // 복사를 할 필요가 없다. 주소조차도 복사를 할 필요가 없다.
    // 그래서 효율이 더 높다.

    // 어떤 때는 main() 안의 n이 doSomething(n)에 들어는 가는데,
    // doSomething(n)이 n을 못 바꾸게 막고 싶을 때가 있다. <- 요즘 프로그래밍의 추세다.
    // 예전에는 return 값을 하나만 받을 수 있기 때문에 parameter에다가 return 값의
    // reference나 pointer를 집어 넣는 방식으로 return 값을 여러 개 받는 함수를
    // 간접적으로 구현했다.
    // 최근에는 C++ 17부터는 여러 개의 값을 받는 것도 그리 어렵지 않게 돼서,
    // 코드를 깔끔하게 정리하고자 한다면, 그냥 return 값을 여러 개 받아 버린다.
    // 입력은 순수하게 입력만 받아라. 즉, 입력으로 넣는 것은
    // doSomething(n) 함수 니가 고치지 말아라. 이렇게 짜는 것이 꽤 많아졌다.
    // 그럴 경우는
    // void doSomething(const int &n) <---- 이렇게 const로 막아버릴 수가 있다.
    // const int &n처럼 const로 막아 버리는 순간 doSomething() 함수 내에서
    // n = 10; 으로 바꿀 수 없다는 오류가 뜬다.

    // array를 함수에 넣어 줄 때도 reference를 사용할 수 있다.
    // ch06.14-4_referenceVariable.cpp 에서 다룬다.

    return 0;
}
