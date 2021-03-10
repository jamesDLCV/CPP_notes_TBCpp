// ch07.03-1_PassingArgumentsByReference.cpp
// 참조에 의한 인수 전달 Passing Arguments by Reference (Call by Reference)
// 매개변수로 인수를 전달하는 방법 중에서 참조에 의한 인수 전달에 대해서 알아 보겠다.
// 강사께서 가장 선호하고 자주 쓰는 방식이다.
// open sources 볼 때도 많이 등장한다.
//

#include <iostream>
#include <cmath>        // sin(), cos()
using namespace std;

void addOne(int &y)     // y로 매개변수가 전달되면 함수를 벗어나는 순간 y는 사라진다.
{                       // 하지만 &y로 전달되면 함수를 벗어나도 그대로 남게 된다.
    y = y + 1;                          // 여기의 y는 main()의 x와 동일하다.
                                        // 어떻게 동일하냐? 주소가 같다.
    cout << y << " " << &y << endl;     // 5 0073FBE4

    // 값에 의한 호출에서는, 함수 안에서 새롭게 변수를 정의하고 거기에 복사를 한다.
    // 참조에 의한 호출에서는, 그냥 변수 자체를 넘기는 것이므로,
    // 주소가 동일하고, 복사는 일어나지 않는다.
    // 복사가 되는지 않 되는지의 증거는 cap class 학습 후 생성자를 가지고 설명한다.
    // 이러한 성질을 함수의 출력을 갖고 오는 데도 사용한다.
    // ch07.03-2_PassingArgumentsByReference.cpp 에서 보자.
}

int main()
{
    int x = 5;
    cout << x << " " << &x << endl;     // 6 0073FBE4

    addOne(x);                          // x라는 변수 자체가 넘어간 것으로 보면 된다.
                                        // 함수 자체를 인자 argument로서 전달했다.

    cout << x << " " << &x << endl;     // 6 0073FBE4

    // 위 주소를 보면 모두 동일하다.
    // 그냥 변수 x를 함수의 매개변수로 넘긴다는 명확한 증거다.


    return 0;
}
