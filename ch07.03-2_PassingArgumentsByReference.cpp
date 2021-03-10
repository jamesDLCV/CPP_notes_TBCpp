// ch07.03-2_PassingArgumentsByReference.cpp
//

#include <iostream>
#include <cmath>        // sin(), cos()
using namespace std;

// 아래의 degrees는 안으로 들어왔다가 밖으로 영향을 못 미치므로 입력이라는 것을 알 수 있다.
// &sin_out과 &cos_out은 reference로 들어왔으니 변수 자체로 들어왔구나를 알 수 있다.
// 함수 안에서 sin_out이라는 변수의 reference와 cos_out이라는 변수의 reference를 건드리면,
// 이 바뀐 값이 함수를 호출한 곳에도 영향을 미치게 된다는 것을 알 수 있다.
// degrees 변수는 함수 내부에서 값이 변하지 않는다. 그러므로 속 편하게 const로 막아 버린다.
void getSinCos(const double degrees, double& sin_out, double& cos_out)
{
    static const double pi = 3.141592;  // static을 쓰면 매번 함수 안에서
                                        // 정의가 되는 것이 아니라,
                                        // 한 번 정의가 된 후 재사용이 된다.
                                        // 이 변수 정의는 헤더로 뽑는다.
    const double radians = degrees * pi / 180.0;  // 이 계산식은 한 번 계산 후 안 바뀐다.
                                                  // const로 박아 놓는다. 박제시킨다.
                                                  // 그래야 실수가 적다.
    // const double radians = degrees * pi / 180.0;의 나누기 180.0은,
    // static const double pi = 3.141592 / 180.0;처럼 위로 보내는 것이 효율이 높아진다.
    // const double pi가 정의될 때 한 번만 이뤄지기 때문이다.

    sin_out = std::sin(degrees);
    cos_out = std::cos(degrees);

    // degrees는 값이 바뀌는 일이 없다.
    // sin_out은 들어와서 값이 바뀐다.
    // cos_out도 들어와서 값이 바뀐다.
}

int main()
{
    double sin(0.0);
    double cos(0.0);

    getSinCos(30.0, sin, cos);

    cout << sin << " " << cos << endl;      // -0.988032 0.154251

    // c/c++에서는 함수의 리턴 값을 하나밖에 줄 수가 없다.
    // 하지만 어떤 경우에는, 함수가 리턴 값을 여러 개 줘야 하는 경우가 꽤 많이 있다.
    // 그래서 위 함수에서처럼 reference를 사용하고,
    // main()에서 위에서처럼 double sin(0.0); double cos(0.0);처럼 변수를 선언하고,
    // getSinCos(30.0, sin, cos);에서 call by reference를 해서,
    // cout << sin << " " << cos << endl; <- 이렇게 마치 output이 나오는 것처럼
    // 구현할 수 있다. 실제로 많이 쓰는 방법이다.
    // 다음에 설명할 주소에 의한 호출, 주소 값에 의한 전달도 비슷한 용도로 사용될 수 있다.

    // c++은 함수에서 출력이, 리턴 값으로 나갈 수 있는 게 하나밖에 없으므로
    // 매개변수를 좀 많이 쓰는 경향이 있다.
    // 위의 함수에서처럼 입력을 앞에 두고 출력으로 나갈 것들을
    // reference로 뒤에 두는 것이 일반적이다.
    // 그래도 조금 헤깔린다. 그래서 이해를 돕기 위해서 입력은 앞에 const를 붙여서 막아 둔다.
    // 그러면 얘는 const니까 입력으로만 쓰이겠구나 하고 알 수 있다.
    // const가 없고 reference만 있으면 얘는 출력이구나 하고 알아차릴 수 있다.
    // 함수 매개변수에서 입력은 const를 박아 놔라.
    // 그리고 입력도 const double &degrees처럼 reference로 만들어 버리면 훨씬 좋다.
    // reference가 실제로 더 좋다. 그러나 단점도 있다.
    //

    return 0;
}
