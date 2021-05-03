// ch07.04-06_주소에 의한 인수 전달.
// 그럼 포인터를 사용해서 전달하는 것이 쓸모가 없는가?
// 그렇지는 않다. 
// 살펴 보자. 

#include <iostream>
using std::cout;
using std::endl;


// 많이 사용하던 c-style coding이, 이렇게 array를 받고, length도 받고, 
// 그 안에서 뭔가 작업을 하는 방식이다. 
void foo(int* arr, int length)    
{
    for (int i = 0; i < length; ++i)
        cout << arr[i] << endl;

    arr[0] = 1.0;   // 이런 식으로 값을 바꾸면, foo에 입력으로 들어온 array도, 
                    // 값이 같이 변한다. 
                    // 왜냐하면, 메모리 주소를 찾아가서 거기에 있는 값을 바꾸는 것이므로, 
                    // 똑같이 작동을 한다. 
                    // 조금 헤깔릴 수 있지만, 
                    // 참조에 의한 호출을 미리 다뤘으므로 덜 헤깔릴 것이다.

}



int main()
{
    


    return 0;
}




