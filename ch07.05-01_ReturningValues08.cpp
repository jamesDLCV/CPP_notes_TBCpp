// ch07.05-01_ReturningValues08.cpp 
// 
// return 값을 여러 개를 리턴하고 싶을 때가 있다. 
// 예를 들어 정수 세 개를 리턴받고 싶다면 structure로 받는 게 일반적인 방법이었다. 
// 

#include <iostream>
using namespace std;

struct S {
    int a, b, c, d;
};

S getStruct() {
    S my_s{ 1, 2, 3, 4 };
    return my_s;
}


int main()
{
    S my_s = getStruct();
    my_s.b;

    return 0;
}

// 이 방식의 단점은 명확하다. 
// 함수 하나를 만들 때마다 구조체를 하나씩 만들어줘야 한다면, 
// 구현 오버로드가 꽤 크게 된다. 
// 옛날 라이브러리는 이렇게 돼 있는 게 많다. 예) directX
// directX는 내부에 구조체가 엄청나게 많다. 
// 함수 호출할 때에도 구조체에 포인터를 넣고, 
// 받을 때도 구조체로 받거나, 구조체의 포인터로 받는 경우가 많다. 
// c++-style을 사용할 수 없는 경우, c-style을 사용해야만 하는 경우에는 
// 위와 같이 사용해야 한다. 대신에 c니까 속도는 더 빠를 것이다. 
