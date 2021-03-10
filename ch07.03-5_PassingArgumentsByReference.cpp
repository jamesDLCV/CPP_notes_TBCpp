// ch07.03-5_PassingArgumentsByReference.cpp
// 포인터에 대한 reference도 보낼 수가 있다.

#include <iostream>
#include <cmath>        // sin(), cos()
using namespace std;

void foo(int*& ptr)     // 이건 (int*) &ptr로 해석하라.
{
    cout << ptr << " " << &ptr << endl;
}

// 아래처럼 함수의 매개변수를 써 줘도 아무 문제가 없다.
// (int*& ptr)을 이해하기 어렵다면 user defined type처럼 돌려서 생각하라.
// 이건 나중에 사용자 정의 타입, 특히 클래스 정의한 후, 이중 포인터, 삼중 포인터를
// 쓸 일이 있으면, 그때 이중 포인터, 삼중 포인터를 이해할 때도 이렇게 이해하면 된다.
// 이중 포인터를 쓸 일이 있으면 아래처럼 사용자 정의 타입으로 써서 가급적 실수를 줄이자.

typedef int* pint;      // int*와 pint는 같은 것이다.

void foo1(pint& ptr1)   // 포인터지만 그냥 user defined type의 reference로만 보인다.
{
    cout << ptr1 << " " << &ptr1 << endl;
}

int main()
{
    int x = 5;
    int* ptr = &x;

    /*
    void foo(const int& x)
    {
        cout << x << endl;
    }

    foo(ptr);   // <- 이렇게 하면 위와 같은 함수의 매개변수에는 안 들어간다.
    */

    // 포인터 변수를 reference로 받으려면 어떻게 하면 되는가?
    // 함수의 매개변수를 (int *&ptr)로 해 줘야 한다.

    cout << ptr << " " << &ptr << endl;     // 00D7FA68 00D7FA5C

    foo(ptr);                               // 00D7FA68 00D7FA5C

    cout << endl;

    int x1 = 6;
    int* ptr1 = &x1;

    cout << ptr1 << " " << &ptr1 << endl;   // 00D7FA50 00D7FA44

    foo1(ptr1);                             // 00D7FA50 00D7FA44

    cout << endl;

    int x2 = 7;
    pint ptr2 = &x2;    // <- 이렇게 해 줘도 된다. 위에서 pint를 typedef 해 줬다.
                        // pint는 분명 포인터다 하지만 *이 없어서 일반 변수처럼 보인다.


    cout << ptr2 << " " << &ptr2 << endl;   // 00AFFAE0 00AFFAD4

    foo1(ptr2);                             // 00AFFAE0 00AFFAD4

    // 출력을 해 보면 포인터가 argument로 들어갔는데 변수 자체가 넘어갔으므로,
    // 포인터 변수의 주소 자체가 같다.
    // 포인터에 담겨 있는, 저장돼 있는 주소도 물론 같다.

    return 0;
}
