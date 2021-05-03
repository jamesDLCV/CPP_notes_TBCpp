// ch07.04-07_주소에 의한 인수 전달.

#include <iostream>
using std::cout;
using std::endl;


// const를 넣을 때의 용법에 대해서 살펴 보자. 

void foo(const int* arr, int length)    // const가 들어가면, 아래의 arr[0]에 바로 에러가 뜬다.
{
    for (int i = 0; i < length; ++i)
        cout << arr[i] << endl;

    // arr[0] = 1.0;    // <- 에러가 뜬다. const를 넣었으므로.  
                        // [] 대괄호 기호가 dereferencing 이라는 것을 이제는 알 것이다. 
}

void foo2(int* ptr, int* arr, int length)
{
    for (int i = 0; i < length; ++i)
        cout << arr[i] << endl;

    arr[0] = 1.0;

    *ptr = 1;
}

// const로 막아 버리면, 
void foo3(const int* ptr, int* arr, int length)
{
    for (int i = 0; i < length; ++i)
        cout << arr[i] << endl;

    arr[0] = 1.0;

    // *ptr = 1;    // <- 오류가 뜬다. 이게 안 된다는 게 한 가지가 있고,

    int x = 1;

    // *ptr = &x;   // <- 오류가 뜬다. 주소 자체를 바꿔 버리려고 한 것이다. 
    ptr = &x;       // 이건 된다. 이걸 안 되게 하려면, 
                    // void foo3(const int* const ptr, ...) 이렇게 ptr을
                    // const로 막아 버리면 되지만,
                    // 굳이 그렇게는 안 쓰는 경우가 많다.
    // 왜냐하면, 위 void foo3()의 const int *ptr은 결국 값에 의한 전달이고, 
    // *ptr은 함수의 중괄호 영역에서 local variable인 것처럼 작동을 하기 때문에,
    // *ptr 자체의 값을 바꾸는 것은, 밖에서 foo3 함수를 호출한 곳의 입장에서 봤을 때는,
    // 크게 해 될 것이 없다라고 생각한다. 

    // ptr = &x; 처럼 구현을 하는 중간에 주소를 바꾸는 것은 잘 사용하지 않는다. 
    // 오픈 소스에서는 void foo3(const int * const ptr, ...)과 같이 const가
    // 양쪽으로 붙어 있는 것을 종종 볼 수 있다. 
    // 리터럴이 전달 안 된다는 건 앞에서 언급했다. 

    // 주소를 참조로 보낼 수 있느냐?
    // 바로 앞 강의에서 자세히 설명했다. 

    // 이번 시간에는 주소에 의한 인자 전달에 대해서 설명을 했다. 
    // address로 보내는 것이 쓸모가 없다고 생각할 수도 있지만, 
    // c-style에서 코딩을 할 때는 이게 반드시 필요했고, 
    // array 같은 걸 보낼 때는, 주소 하나가 복사되는 것 정도는, 
    // array에 담겨 있는 수많은 데이터를 복사하는 것보다, 
    // 훨씬 효율이 높다. 
    // 그러므로 그 정도는 감수할 수 있다. 많이 사용이 됐다. 
    // 최근에는 점점 reference로 교체가 되겠다. 
    // c-style 코딩과 c++-style 코딩의 차이이기도 하다. 

    // 여기까지 여러 가지 전달 방법에 대해서 살펴 보았다. 
    // 장단점에 대해서도 설명을 했다. 
    // 기법상 주의해야 할 점 몇 가지도 설명을 했다. 
    // 코딩을 할 때 미묘하게 잘못 쓰거나 실수를 할 수 있는 부분이다. 
    // 기본적인 개념을 깔끔하게 정리하고 넘어가기를 바란다. 
}


int main()
{



    return 0;
}




