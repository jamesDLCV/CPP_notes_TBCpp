// ch07.05-01_ReturningValues02.cpp 
//
// 주소 값으로 돌려받는 것을 살펴보자. 
//

#include <iostream>
using namespace std;

int* getValue(int x) {
    int value = x * 2;
    return &value;
}

int main()
{
    // 포인터 함수를 받는 방법은 두 가지가 있다. 
    // 하나는 아래처럼 주소로 받는 방법이다. 
    // 아래를 실행해 보라. 
    //int* value = getValue(3);
    //cout << *value << endl;

    // 또 다른 방법은, 변수는 값을 받고, dereferencing으로 받는 방법이 있다. 
    // 
    int value = *getValue(5);  // 이렇게 받는 것은 크게 문제가 없다. 
                                // 하지만 권장하지 않는다. 
                                // value2가 중괄호를 벗어남과 동시에 사라져 버린다.
    // 사라질 변수를 dereferencing하는 것이 안전하지는 않다. 
    // 실행하면 값은 잘 나온다. 10. 
    // 하지만 다음의 warning 메시지에서처럼 좀 위험하다. 
    // warning C4172: returning address of local variable or temporary: value
    // 당장은 결괏값을 출력하는 데 문제가 없지만, 이런 코딩은 안 하는 것이 좋다. 
    // 다른 많은 방법이 있으므로 굳이 이렇게 할 필요는 없다. 
    std::cout << value << std::endl;       

    //int* value = getValue(7);  // 이렇게 주소로 직접 받는 방법은 더 위험하다. 
    // 왜냐하면, 함수 안의 변수 value 주소를 받고 있는데, 
    // value는 함수를 벗어나면서 이미 사라졌다. 
    // 변수는 사라졌는데 메모리 주소만 남아 있다? 이사를 간 건지, 남아 있는 건지
    // 알 수는 없고 이렇게 주소만 주고 있는 것이다. 
    // 이는 아주 위험하다. 
    //std::cout << *value << std::endl; //

    return 0;
}