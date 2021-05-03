// ch07.04-05_주소에 의한 인수 전달.
//

#include <iostream>
using namespace std;


void foo(int* ptr)    // const를 안 붙이면,    
{
    cout << *ptr << " " << ptr << " " << &ptr << endl;

    *ptr = 10;   // <- dereferencing하는 값을 바꿀 수 있다. 

}

// 포인터를 사용해서, 함수의 출력인 것처럼 사용하기도 한다.
// 앞의 참조에 의한 전달을 설명하면서 비슷한 예를 살펴 봤다. 
// 앞 강의에서는 reference &를 사용했으나, 
// 포인터를 사용해서 같은 기능을 수행할 수 있다. 

void foo2(double degrees, double* sin_out, double* cos_out)
{
    *sin_out = 1.0;
    *cos_out = 2.0;
}


int main()
{
    int value = 5;

    cout << value << " " << &value << endl;

    int* ptr = &value;
    
    cout << value << endl;

    // foo 함수를 호출한 다음에, 
    foo(ptr);

    cout << value << endl;  // value 변수를 출력하면, 값이 바뀌어 있다. 

    double degrees = 30;
    double sin, cos;

    // foo(degrees, sin, cos);  <- 오류  
    // 위는 sin과 cos가 출력인 것처럼 된다. 
    // 참조에 의한 호출과는 달리 ampersand를 붙여서 주소로 바꾸어서 넣어 줘야 한다. 
    // 조금 더 번거롭다. 
    
    foo2(degrees, &sin, &cos);

    cout << sin << " " << cos << endl;  // foo2에서 넣어준 값이 그대로 출력된다. 
                                        // 1 2
    // <-- 함수에서 바꿔 준 값이 밖에도 영향을 준다. <- 중요한 속성으로 사용된다. 
    // c 프로그래밍할 때 foo2(degrees, &sin, &cos); 이런 형태의 코딩을 아주 많이 
    // 연습한 사람들도 있을 것이다. 
    // 그래서 c++에서 조금 헤깔리는 경우도 있을 것이다. 
    // 실용적인 면에서는 reference를 쓰는 것이 더 편하다. 
    // 주의해야 할 점은, 위가 reference인 것처럼 착각이 들 수도 있다. 
    // 같은 변수가 넘어온 것처럼 착각이 들 수도 있는데, 전혀 아니다. 
    // 위 foo2(degrees, &sin, &cos);에 들어간 포인터의 주소하고, 
    // 위 함수 void foo2(double degrees, double* sin_out, double* cos_out)에 
    // 있는 포인터의 주소는 다르다.
    // 결국 내부적으로는 값에 의한 전달이다. <-- 이것이 결론이다. 
    // 그럼 포인터를 사용해서 전달하는 것이 쓸모가 없는가?
    // 그렇지는 않다. 
    // 초07.04-06에서 살펴 보자. 

    return 0;
}




