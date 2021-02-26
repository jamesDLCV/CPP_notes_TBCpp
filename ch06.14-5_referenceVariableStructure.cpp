// ch06.14-5_referenceVariableStructure.cpp
// Structure

#include <iostream>
using namespace std;

struct Something    // struct가 있다.
{
    int v1;
    float v2;
};

struct Other        // struct가 또 있다.
{
    Something st;   // struct Something이 안에 있다.

};

int main()
{
    Other ot;       // Other를 하나 정의한다.

    // Something에 들어 있는 v1에 접근을 하겠다.
    ot.st.v1 = 10; // 이렇게 접근했어야 한다. 하지만 이름이 너무 길고,
                    // 안쪽으로 들어가고 들어가고 해야 하면, 타이핑도 힘들고,
                    // 외우기도 힘들고, 사용하기도 힘들어진다. 결국 느려진다.

    // 그때 reference를 쓸 수가 있다.
    int& v1 = ot.st.v1; // 이렇게 reference로 해 놓고,
    v1 = 1;             // 이렇게 사용할 수가 있다.
                        // 실전에서는 이게 쓸모가 정말 많다. 아주 유용하다.
                        // v1이 여러 번 쓰일 때는 referenc를 꼭 쓰는 것이 좋다.
                        // 효율도 좋다. 속도도 떨어지지 않는다.

    //// referenc와 pointer를 비교하는 측면에서 다음도 살펴 보자.
    // 위의 변수들과는 아무런 상관이 없다.
    int value = 5;
    int* const ptr = &value;    // 주소를 못 바꾸는 것이다.
    int& ref = value;           // <- 문제 없이 잘 된다.
    // ref와 ptr이 기능상 동일하다.

    cout << value << endl;      // 5
    cout << ref << endl;        // 5
    cout << endl;

    ref = 10;

    cout << value << endl;      // 10
    cout << ref << endl;        // 10

    cout << *ptr << endl;       // 10
    cout << endl;

    *ptr = 20;

    cout << value << endl;      // 20
    cout << ref << endl;        // 20

    cout << *ptr << endl;       // 20

    // *ptr = 10; 과 ref = 10은 동일하게 작동한다.
    // reference도 내부적으로는 pointer로 구현이 돼 있다.
    // 지금까지 참조에 대해서 살펴 봤다.
    // 참조가 여러 가지로 쓸모가 있고 편한 것이 많다.
    // 객체지향 프로그래밍을 하다 보면 아주 많이 쓰게 될 것이다.
    // 참조 변수에 대해서 살펴 봤다.

    return 0;
}
