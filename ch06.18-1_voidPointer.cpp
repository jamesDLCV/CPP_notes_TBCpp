// ch06.18-1_voidPointer.cpp
//
// 포인터는 주소다.
// 집이 크든 작든 주소의 길이는 똑같다.
// 규격화돼 있는 주소를 사용해서, 모든 데이터 타입의 주소를 저장하는 것이 포인터다.
// 그렇다면, 자료형과 상관 없이 포인터를 저장할 수도 있을까?
// void pointer에 대해서 살펴 보자.
// void pointer는 generic pointer라고도 한다.
// 모든 데이터 타입을 다 포괄적으로 다룰 수 있기 때문에 generic pointer라고도 한다.

#include <iostream>
using namespace std;

int main()
{
    int     i = 5;
    float   f = 3.0;
    char    c = 'a';        // int, float, char 하나씩 선언해 놓았다.

    void* ptr = nullptr;    // void pointer를 널 포인터로 초기화했다.

    ptr = &i;               // 이 void pointer에 int type의 주소를 넣었다.
    ptr = &f;               // 이 void pointer에 float type의 주소도 넣었다.
    ptr = &c;               // 이 void pointer에 char type의 주소도 넣었다.
                            // 전부 문제가 없다.
    // 신기하다.
    // 주소기 때문에, 주소는 주소 자체기 때문에,
    // void pointer에도 주소를 넣는 것은 문제가 안 된다.
    // 하지만 한계는 있다.
    // voit pointer로 포인터를 넣는 순간, 이것이 int인지, float인지, char인지 알 길이 없다.

    int* ptr_i = &i;                // int에 pointer type을 선언을 하면,
    // 아래와 같이 pointer 연산을 사용할 수가 있다.
    cout << ptr_i << endl;          // 00EFF7BC
    cout << ptr_i + 1 << endl;      // 00EFF7C0

    // 하지만, void pointer는 연산을 할 수가 없다.
    /*
    cout << ptr + 1 << endl;    <- 안 된다.
    */

    // 왜 안 되는가? + 1을 할 때, 몇 bytes인지 모르기 때문이다.
    // int pointer, float pointer는 4bytes. char pointer는 1byte.
    // void pointer는 이렇게 몇 bytes인지 알 수가 없기 때문에 연산을 할 수가 없다.

    // 주솟값은 제대로 들어가는가?
    // 위에서 ptr에 마지막으로 들어간 것은 &c이므로 &c와 void pointer의 값을 찍어 보자.

    cout << &c << " " << ptr << endl;   // a 0115FC77
    // 강좌에서는 &c의 출력이 앞에서와 같이 a 다음에 알 수 없는 문자가 덧붙여졌다.
    // a 출력 후 null character가 나올 때까지 계속 출력되었다.
    // 하지만 내 컴에서는 a가 문제 없이 출력되었다.
    // &f 를 출력해 보면 주소는 제대로 출력이 된다.
    // 하지만 void pointer일 때는 type을 알 수가 없어서 뭔가를 할 수가 없는 것이다.
    cout << endl;

    // de-referencing을 해 보자.
    /*
    cout << *ptr << endl;     <-- de-referencing이 안 된다.

    메모리에 2진수로 나열돼 있는 건 알겠는데,
    int인지, float인지 등은 알 수가 없다.

    그러면 이것을 가지고 오려면 어떻게 해야 하는가?
    */
    // 강제로 캐스팅을 해야 한다.

    float f2 = 3.0;

    void* ptr2 = nullptr;
    ptr2 = &f;

    cout << &f << " " << ptr2 << endl;             // 00F3F958 00F3F958
    cout << *static_cast<float*>(ptr2) << endl;    // 3

    // 그럼 이런 의문이 들 것이다.
    // *static_cast<float*>(ptr2) 이걸 이렇게까지 써서 void pointer를 써야 하는가?
    // 너무 하는 거 아닌가.
    // 다형성 구현을 하다 보면 부득이하게 이렇게 써야 하는 경우가 있다.

    // void pointer의 다른 예를 보자.
    // ch06.18-2_voidPointer.cpp 에서 살펴 본다.


    return 0;
}
