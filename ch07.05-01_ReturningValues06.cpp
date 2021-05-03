// ch07.05-01_ReturningValues06.cpp  
//
// return by reference

#include <iostream>
using namespace std;

int& getValue(int x) {
    int value = x * 2;          // 이렇게 메모리가 일시적으로 생겼다가 사라지는
                                // 지역변수일 경우에는, 
    return value;               // <-- 이렇게 리턴을 하면 안 된다. 
                                // 리턴할 때, 이것이 레퍼런스인지 value인지 
                                // 구분하기도 힘들다. 
                                // 위 리턴 타입 정의하는 부분에서 확인해야 한다. 
                                // 그러므로 실수할 가능성이 조금 더 크다. 
}

int main()
{
    //int value = getValue(5);  // getValue(5)가 레퍼런스를 반환해서
                                // 래퍼런스가 잠깐 남아 있는 상태에서
                                // 그 래퍼런스가 가리키고 있는 변수의 실제 값이 
                                // 이 value로 복사해서 들어온다. 
    //cout << value << endl;    // 비교적 안전하게 나온다. 

    int& value = getValue(5);   // <-- 이렇게 하는 것은 문제가 발생한다. 

    // 값은 출력이 되지만, 아래와 같이 두 번 출력을 하면 두 번째 값에 이상한 값이 찍힌다.
    cout << value << endl;      // 10
    cout << value << endl;      // -858993460
                                // 두 번째 출력할 때, 
                                // 함수의 value 메모리가 사라진 것이다.
    // 리턴 값 받는 동안만 임시로 잡아주고 있다가, 받으면 할 일을 다 했으므로, 
    // 함수 안의 value는 사라진 것이다. 메모리가 OS로 돌아간 것이다. 
    // 그러나 레퍼런스는 살아 있으므로 값을 dereferencing하려고 시도는 하고, 
    // 메모리가 죽어 버렸으므로 쓰레기 값이 나오는 비극적인 사태가 발생한다. 
    // 위와 같이 사용하는 것은 매우 안 좋다. 
    // 이처럼 두 번째 출력값에서 이상한 값이 나오는 문제는, 
    // return by address에서도 똑같이 발생할 수 있다. 

    // 그러면 return by reference는 쓸모가 없느냐? 
    // 그렇지는 않다. 더 편하게 사용하는 경우가 있다. 

    return 0;
}


