// ch06.18-2_voidPointer.cpp
//

#include <iostream>
using namespace std;

enum Type                   // 이렇게 enum 타입으로 따로 정리를 한다.
{
    INT,
    FLOAT,
    CHAR
};

int main()
{
    int     i = 5;
    float   f = 3.0;
    char    c = 'a';        // int, float, char 하나씩 선언해 놓았다.

    void* ptr = nullptr;    // void pointer를 널 포인터로 초기화했다.

    ptr = &i;               // 이 void pointer에 int type의 주소를 넣었다.
    ptr = &f;               // 이 void pointer에 float type의 주소도 넣었다.
    //ptr = &c;

    Type type = FLOAT;

    if (type == FLOAT)
        cout << *static_cast<float*>(ptr) << endl;
    else if (type == INT)
        cout << *static_cast<int*>(ptr) << endl;
    else
        cout << *static_cast<char*>(ptr) << endl;
    // 이런 식으로까지 하는 경우가 있을 수 있다.
    // 하지만, 최근 최신의 C++ 문법에서는 이렇게까지 안 해도 되는 여러 가지 문법이 생겼다.
    // 좋아진 문법 이야기를 할 때 void pointer도 다룰 것이다.
    // 현실적으로 void pointer를 사용할 일이 그렇게 많지는 않을 것이다.
    // 하지만, 포인터의 특징, 주소라는 특징을 이해하는 데는 도움이 되는 측면이 있다.
    // void pointer도 한 번쯤은 해 보는 것을 권장한다.

    // 여기까지 많이 쓰지는 않겠지만, 알아는 둬야 할 void pointer에 대해서 살펴 봤다.


    return 0;
}
