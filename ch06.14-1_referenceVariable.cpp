// ch06.14-1_referenceVariable.cpp
//
// 포인터를 이해하고 나면, 포인터가 이렇게 작동하는구나, 컴퓨터 내부 구조를 이해할 수 있어서
// 도움이 되는 것 같다. 그리고 이러 이러한 경우에 일반 변수로는 안 되는 게 되기 때문에
// 편리하다. 이렇게 생각하게 될 것이다.
// 그런데 조금 더 사용하다 보면 *을 붙여 주는 게 조금 귀찮아질 수 있다.
// de-referencing 할 때 *을 붙여 줘야 한다. 이런 게 조금 불편한다.
// 특정한 경우에 포인터보다 조금 더 사용하기 편한 게 있다.
// 그것이 참조 변수이다. Referenct Variable.
// 참조에 대해서 살펴 보자.

#include <iostream>
using namespace std;

int main()
{
    //// reference의 특성
    int value = 5;          // 이후 포인터를 사용해 보자.

    int* ptr = nullptr;     // int *ptr = &value; 이렇게 할 수 있다.
                            // 하지만 이렇게 nullptr을 먼저 넣을 수도 있다.
                            // 왜냐하면, 메모리 값이니까,
                            // 메모리 값에 0을 넣는 것은 가능하다.
                            // 실제로는 사용할 수 없는 주소지만 주소는 주소다.
                            // 가짜 전화 번호를 적어 주는 것과 비슷하다.
    ptr = &value;           // 그 다음 이렇게 &value, value의 주소를 넣어줄 수 있다.
    // 이런 것이 가능하다는 것을 알아 두라.

    // 지금부터 설명하는 참조와 비교를 해 보자.
    // 참조는 다음과 같이 쓴다.

    int& ref = value;       // 이렇게 &를 붙여주고 value 변수를 넣어 준다.
                            // 이렇게 하면 내부적으로 ref가 value와 같은 변수처럼 작동한다.
    // 마치 같은 메모리(value가 꽉 잡고 있는 메모리)를 사용하는 것처럼 작동한다.

    cout << ref << endl;                    // 5

    ref = 10;

    cout << value << " " << ref << endl;    // 10 10
    // ref의 값만 바꾸었는데 value의 값도 바뀌었다.
    // 마치 포인터에서 *ptr = 10; 이라고 써 준 것과 똑같이 작동하고 있다.
    // 그런데 ref는 앞에다가 *를 붙여 줄 필요도 없고 문법적으로 깔끔해 보인다.
    // 강사 님은 참조를 많이 쓴다고 한다. 참조가 더 좋은 점이 있다.
    // 일단 참조는 별명처럼 사용될 수 있다.
    // 위에서는, value라는 변수의 별명, 또 다른 이름인 것처럼 ref를 사용할 수 있다. <- 기억!
    // 다음은 주소를 찍어 보자.
    cout << endl;
    cout << "&value: " << &value << endl;
    cout << "  &ref: " << &ref << endl;
    cout << "   ptr: " << ptr << endl;
    cout << "  &ptr: " << &ptr << endl;     // 포인터 자체의 주소를 찍으면 다르다.
    /*
    &value: 0074F7C0    <- os가 준 것이다.
      &ref: 0074F7C0    <- ref는 주소가 된다. 한 변수의 또 다른 이름이다. 이름만 다르다.
       ptr: 0074F7C0    <- 포인터 변수에 담고 있는 주소는 &value의 주소가 맞다.
      &ptr: 008FFD10    <- 포인터 변수 자체의 주소를 출력해 보면, 다른 값이 나온다.
    */
    // 위에서 알 수 있는 것은 포인터 변수도 변수의 성질을 그대로 가지고 있다.
    // 포인터 변수도 변수다.
    // 위의 예제에서는 &value와 &ref의 주소 값이 같은 값이 나온다는 것을 기억해 둬라.
    // ref 자기 자신이 별도의 주소를 가지고 있는 것이 아니고,
    // value의 주소를 공유한다고 봐라.
    // 포인터는 포인터 변수 자체가 다른 주소를 갖고 있다.

    //// reference의 특징을 조금 더 살펴 보자.
    //int& ref1;   <- 이렇게는 안 된다.
    // reference variable 'ref1' requires an initializer.
    // reference 변수 반드시 초기화를 해야 한다.
    // 별명이니까, 원래 이름이 있어야 별명을 지을 수 있는 것이다. 원래 이름은 꼭 있어야 한다.
    int& ref1 = value;  // <- 이렇게 반드시 초기화 해야 한다. 원래 이름이 있어야 한다.

    //int &ref1 = 104;  <- 이렇게 오른쪽에 literal이 못 들어간다.
                        // 왜냐하면, literal은 메모리에 주소를 갖지 못하기 때문이다.
                        // r-value, 즉 변수만 들어갈 수 있다.
    cout << endl;

    //// const를 해 보자.
    int x = 5;
    int& ref2 = x;       // 변수 x의 다른 이름(별명)은 ref이다.
                         // 이렇게 하면 된다는 것은 이미 학습했다.

    // 그럼 const를 붙이면 어떻게 되는가?
    const int y = 8;
    //int& ref = y;     //<- 안 된다. 허용할 경우 ref에서 y를 마음대로 바꿀 수 있기 때문에
    //                       문법이 허용을 안 한다. y를 바꿀 수 없도록 하기 위하여.
    //                       컴파일러가 막아 버리고 있다.
    //qualifiers dropped in binding reference of type "int &"
    //to initializer of type "const int"
    // 마우스를 갖다 대면 위와 같은 메시지가 뜬다. 그러면 const를 해 주면 되겠구나.

    const int& ref3 = y; // <- 이렇게 const를 붙이면 된다.
    // 이전에 설명한 포인터와 const 문제를 이해한다면 이것은 어렵지 않다.

    //// reference가 reassign이 되는가??
    int value4 = 5;
    int value5 = 10;

    int& ref4 = value4;     // ref4는 value4의 또 다른 이름(별명)이 되었다.

    cout << ref4 << endl;   // 5, value4의 값이 할당됐다.

    ref4 = value5;          // 이렇게 다시 ref4에 다른 변수의 별명을 붙일 수 있는가?

    cout << ref4 << endl;   // 10, value5의 값이 할당됐다. <-- 된다.
                            // ref4는 이미 value4의 별명이었지만,
                            // 다시 value4의 별명이 됐다. 새 별명을 할당받는 것이 된다.

    //// 지금부터 설명하는 것이 중요하다.
    // 함수를 사용하므로 다른 파일에서 다루겠다.
    // ch06.14-1_referenceVariable.cpp 에서 다룬다.

    return 0;
}
