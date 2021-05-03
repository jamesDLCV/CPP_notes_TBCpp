// ch07.04_주소에 의한 인수 전달.cpp 
//
// 매개 변수로 인수를 전달하는 방법들 중에서, 
// 주소, 그러니까 포인터를 사용하는 방법을 살펴 보자. 
// 함수를 호출하는 입장에서는 call by address가 된다.


#include <iostream>
using namespace std;

void foo(int* ptr)      // parameter가 포인터이다. 
{
    cout << *ptr << " " << ptr << " " << &*ptr << endl;
}



int main()
{
    int value = 5;

    cout << value << " " << &value << endl;

    // foo(value);  <- 오류가 뜬다. 함수의 parameter가 포인터이기 때문이다. 
    //              <- 주소를 보내 줘야 한다. 

    // 포인터를 하나 선언하는 방법이 있다. 
    int* ptr = &value;

    cout << &ptr << endl;       // 포인터 변수도 변수다. 

    foo(ptr);       // <- 포인터를 선언한 후 ptr를 넣어 준다. 


    foo(&value);    // <- 이렇게 바로 주소를 넣는 방법도 있다. 

    //foo(5); <- 이건 안 된다. literal이라서 주소가 없으므로 안 된다. 
    //        <- foo methode 매개변수를 const int *ptr로 바꿔도 안 된다. 
    //           void foo(const int *ptr) 
    //        <- foo methode 매개변수를 int const *ptr로 바꿔도 안 된다.
    //           void foo(int const *ptr) 
    //        <-                     를 inst * const ptr로 바꿔도 안 된다. 
    //           void foo(int * const ptr) 
    // 그냥 주소만 넣어 줘야 되는 것이다. 
    // 시작하자마자 단점이 나오고 있다. 

    return 0;
}