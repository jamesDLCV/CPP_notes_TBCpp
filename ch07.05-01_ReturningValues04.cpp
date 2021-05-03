// ch07.05-01_ReturningValues04.cpp 
//
// return by address

#include <iostream>

int* allocateMemory(int size) {
    return new int[size];       // new int[size]가 주소를 반환하게 된다. 
}

int main()
{
    //int* array = new int[10]; // new int[10]을 함수로 뽑아내고 싶을 때가 생긴다. 
                              // 디자인 패턴 중에서 공장 패턴(factory pattern)에서
                              // 많이 사용한다. 
    int* array = allocateMemory(1024);  // 이런 식으로 사용할 수 있다. 

    delete[] array;

    return 0;
}

// 이렇게 간단한 경우에는 굳이 이렇게 안 쓰지만 
// 뒤로 가면 많이 사용하게 된다. 객체지향 배운 후 설명하겠다. 
// 이것도 위험은 있다. 
// new가 있으면 delete이 있어야 한다. 
// new는 *allocateMemory() 함수에 있고 delete은 main() 함수에 있어야 한다. 
// 좀 정신이 없을 수 있다. 
// 위와 같이 동적 메모리를 할당하는 것은 프로그래머를 힘들게 할 수 있다. 
// 현업에서는 훨씬 더 편한 방법을 사용한다. 