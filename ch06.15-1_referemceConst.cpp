// ch06.15-1_referemceConst.cpp
// Reference와 const
// 앞서 포인터와 const에 대해서 살펴 봤다.
// 세 가지 정도의 경우가 있었다. 조급 복잡했다.
// 참조는 훨씬 더 간단하고 편하게 사용할 수 있다.
// 특히 함수의 parameter로 참조를 사용할 때, 아주 편해진다.
// 참조와 const에 대해서 살펴 보자.

#include <iostream>
using namespace std;

int main()
{
    int x = 5;
    int &ref_x = x;     // &는 연산자는 아니다. 자판 키의 한계로 동일한 키가
                        // 여기 저기 사용된다.

    int x1 = 5;
    const int &ref_x1 = x1;     // const도 문제 없이 붙일 수 있다.

    /*
    const int x = 5;        <-- 이렇게 위에만 붙이는 건 안 된다.
    int &ref_x = x;             // 위에만 붙이고 아래에는 안 붙이면 안 된다.
    */

    const int x2 = 5;           // <- const
    const int &ref_x2 = x2;     // <- const, 둘 다 붙이면 된다.
    cout << ref_x2 << endl;     // 5

    const int &ref_2 = ref_x2;  // 가능하다.
    cout << ref_2 << endl;      // 5, x2와 ref_x2와 동일한 값.

    /*
    int x2 = 5;                 // <- const를 빼도 된다.
    const int &ref_x2 = x2;     // <- const

    const int &ref_2 = ref_x2;  // 가능하다. 위에서 살펴본 내용이다.
    */

    /*
    int x2 = 5;                 // <- const를 빼도 된다.
    int &ref_x2 = x2;           // <- const를 빼도 된다.

    const int &ref_2 = ref_x2;  // 가능하다.
    */

    // reference를 선언할 때, 메모리 주소가 있어야지만 선언을 할 수 있다.
    // 다음처럼은 안 된다.
    /*
    int &ref_x3 = 5;     <- 안 된다. 리터럴은 안 된다.
    */
    // 그런데, const를 쓰면 된다.
    const &ref_x3 = 5;          // <- 된다. 리터럴도 된다.
    const &ref_x4 = 3 + 4;      // <- 된다.

    cout << ref_x4 << endl;     // 7
    cout << &ref_x4 << endl;    // 0x61fef4, 주소도 출력된다.
                                // 주소 생성도 된다. 아주 편하다.
    // 그러면
    const int ref_x5 = 3 + 4;   // const int &ref_x4 = 3 + 4; 와 다른 것이 뭐냐?
    // 이 둘의 차이는 뭔가?
    // 함수 parameter로 넣을 때 아주 유용하다.
    // ch06.15-2_referemceConst.cpp 에서 살펴 보자.


    return 0;
}
