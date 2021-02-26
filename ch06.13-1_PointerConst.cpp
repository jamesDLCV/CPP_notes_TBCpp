// ch06.13-1_PointerConst.cpp
// 포인터와 const

// 일반 변수에 const를 붙여서 상수를 만들 수 있듯이 포인터에도 const를 사용할 수 있다.
// 하지만 일반 변수와는 조금 다르다. 포인터와 const가 어떻게 사용되는지 살펴 본다.
// 포인터의 간단한 용례부터 살펴 보자.

#include <iostream>
using namespace std;

int main()
{
    int value = 5;
    int* ptr = &value;      // value의 주소를 ptr에 넣어 줬다.
    *ptr = 6;               // de-referencing으로 value를 바꿀 수 있다.

    //// value에 const를 걸어 보자.
    /*
    const int value1 = 5;
    int* ptr1 = &value1;    // 에러가 발생한다. value가 const면 value를 못 만드나?
    *ptr1 = 6;              // 그렇지는 않다. 만들 수 있다.
    */

    const int value2 = 5;
    const int* ptr2 = &value2;  // 포인터도 const면 된다.
    //*ptr2 = 6;  <- 오류 발생   // 대신에 de-referencing을 못 한다.
                                // 그러니까 value의 값을 못 바꾸는 것이다.
                                // value를 assingment 하는 것은 안 된다.
                                // *ptr2 = 6;이 안 되는 이유는 value2 = 6;이 안 되기 때문.
                                // value2 = 6;이 안 되는 이유는 const가 있기 때문이다.
    // value의 값을 못 바꾼다고 해서 value 변수의 주소를 못 갖고 올 이유는 없다.
    // 주소를 갖고 올 수 있고 포인터를 통해서 이 주소를 읽을 수는 있다.

    cout << *ptr2 << endl;         // 5, 이렇게 주소를 읽을 수는 있다.
                                   // de-referencing 해서 출력하는 것은 문제가 없다.
    cout << endl;

    int value3 = 5;                // value는 const가 아니지만,
    const int* ptr3 = &value3;     // 포인터는 const를 쓸 수 있다.
    //*ptr3 = 6;  <- 오류 발생      // value는 const가 아니지만,
    // ptr3 포인터가 가리키고 있는 주소의 값을 바꾸지는 않겠다는 뜻이 된다.

    value3 = 6;                    // 이건 된다. value는 바꿀 수가 있다.
                                   // 역참조는 바꿀 수 없지만 value는 바꿀 수 있다.
    cout << *ptr3 << endl;         // 포인터를 출력하면 어떤 값이 나올까?
                                   // 6이 나온다.
    // 자기는 못 바꾸지만, 바꾼 값은 가지고 올 수가 있다.

    //// 변수가 두 가지가 있는 경우를 보자.
    int value4 = 7;
    const int* ptr4 = &value4; // ptr4가 가리키고 있는 주소에 있는 값을 안 바꾸겠다는 뜻이지
                               // ptr4에 저장된 주소 값을 바꾸지 않겠다는 뜻은 아니다.
    // 이것이 이해가 되면 포인터에 대한 이해는 끝났다고 보면 된다.
    //*ptr4 = 8;    <== 이렇게는 안 된다. 역참조를 했을 때 값을 바꿀 수는 없다.

    int value5 = 8;
    ptr4 = &value5;                // <- 된다. 포인터에다가 다른 변수를 넣는 것은 된다.
    //*ptr4 = 8;                   // <- 안 된다. 다른 변수의 값을 바꾸는 것은 또 안 된다.
                                   // 왜냐하면, 앞에 const가 붙었기 때문이다.
    // 이런 것 때문에 포인터가 어렵다고 생각하는 것이다.
    // const value에 대한 포인터에 대해서 알아 봤다.
    cout << endl;

    //// 포인터 자체가 상수인 경우를 살펴 보자.
    int value6 = 5;
    int* const ptr6 = &value6;      // <- 이것이 진정 포인터를 상수로 만드는 것이다.
                                    // 진짜 변수로서 포인터에 const가 붙는 것이다.
    // 포인터 안에 어떤 메모리 주소 값이 붙어 있을 텐데, 그 값은 못 바꾼다.
    // const int *ptr6 = &value6; 이렇게 앞에 const가 붙는 것은, 포인팅하는 변수,
    // 참조해 주는 존재로서 const가 붙는 기능적인 문제다.

    *ptr = 10;                      // 이번에는 역참조가 된다.
                                    // 역참조에 뭘 넣는 것도 된다.
    cout << *ptr << endl;           // 10

    // 그럼 뭐가 안 되는 걸까?
    int value7 = 15;
    //ptr6 = &value7;   <- 이것이 안 된다. 포인터에 있는 주소 값을 못 바꾸는 것이다.

    //// 다음 예제도 살펴 보자.
    int value8 = 5;
    const int* const ptr8 = &value8;    // 이렇게도 된다. 이때는 포인터 자체가 상수다.
                                        // 그러므로 반드시 초기화를 해 줘야 한다.
                                        // 반드시 어떤 주소를 넣어 줘야 하는 것이다.
                                        // 이후에는 바꿀 수가 없기 때문이다.
    //const int *const ptr8;   <- 이렇게는 안 된다. 초기화를 꼭 해 줘야 한다.
                                        // const variable ptr8 requires an initializer.
    //ptr8 = 10;               <- 이것도 안 된다. 값을 바꿀 수도 없다.
                                        // 앞에 또 const가 붙어 있기 때문이다.

    //// 정리를 해 보자.
    int value11 = 5;
    const int* ptr11 = &value11;
    int* const ptr12 = &value11;    // 하나의 변수에 대해 포인터가 여러 개 붙을 수도 있다.
                                    // 주소를 갖고 오는 게 다르므로 상관이 없다.
    const int* const ptr13 = &value11;
    // 포인터에 const가 붙는 것은 위 세 가지 경우가 있다.
    // 이렇게 변수 앞에 붙는 경우, const 앞에 붙는 경우, const가 두 개 다 붙는 경우가 있다.
    // 이것은 어디에 쓰나?
    // 함수 parameter로 들어갈 때, int *const ptr12 = &value11; 이것이 주로 들어가고
    //  이것도 간혹 들어간다.
    // 함수 parameter로 array를 집어 넣을 때, 결국은 포인터로 들어가는 것이다.
    // 이때 값을 바꾸지 말고, 주소 값도 바꾸지 말아라는 뜻으로 아주 안전하게
    // const int *const ptr13 = &value11; 이런 식으로 사용하기도 한다.
    // array 말고도 다른 경우에도 포인터가 필요한 경우가 있다. 종종 보게 된다.
    // 위 세 가지 모두 숙지하고 있어라.
    // 좀 더 실용적인 것은 뒤에 포인터 참조를 배울 것이다.
    // 참조를 쓰면 타이핑하는 것도 좀 더 편해지고 깔끔해 진다.

    // 포인터와 const를 같이 사용할 때, 어떠한 조합으로 사용이 되는지
    // 경우에 따라서 되는 것과 안 되는 것을 살펴 보았다.
    // 다시 복습하면서 꼼꼼히 따져 보고 아! 이런 거구나라는 느낌을 갖기 바란다.

    return 0;
}
