// ch06.15-2_referemceConst.cpp
// 그러면
// const int ref_x5 = 3 + 4; 와 const &ref_x4 = 3 + 4; 의 차이는 뭐냐?
// 위 둘의 차이는 뭔가?
// 함수 parameter로 넣을 때 아주 유용하다.

#include <iostream>
using namespace std;

void doSomething(const int &x)  // const로 하고 &로 넣었다. 장점은 복사가 안 일어남.
{
    cout << x << endl;
}

int main()
{
    int a = 1;

    doSomething(a);      // 1, 함수를 호출하고 싶은데 반드시 변수가 있어야 하나?
                         // 변수가 있으면 함수 인수에 const가 있어도 없어도 다 된다.

    // 함수 parameter에 const가 있으면 아래처럼 직접 리터럴을 넣을 수 있다.
    // 함수의 parameter에 const가 없으면 리터럴을 넣을 수 없다.
    doSomething(10);     // 10  <- 출력된다.

    doSomething(a + 3);  // 4   <-- 이런 것도 가능하다.
    doSomething(3 * 4);  // 12  <-- 이것도 가능.

    // reference를 함수 parameter로 쓰면 정말 편해진다.
    // const하고 reference가 같이 사용될 때,
    // 어떻게 사용되고 어떤 장점이 있는지 살펴 봤다.

    return 0;
}
