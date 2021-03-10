// ch07.03-6_PassingArgumentsByReference.cpp
// array를 parameter로 전달하는 방법

#include <iostream>
#include <cmath>        // sin(), cos()
#include <vector>
using namespace std;

void printElements(int(&arr)[4])    // [ ] 안에 개수를 반드시 써 줘야 한다.
{
    cout << arr[1] << endl;
}

void priontElements1(const vector<int>& arr1)     // vector 대신 array를 사용해도 된다.
{
    cout << arr1[1] << endl;
}

int main()
{
    int arr[]{ 1,2,3,4 };   // 정적 array를 정의해 줬다.
                            // 실제로는 정적 array를 사용하는 경우는 거의 없다.
                            // 이럴 경우 대부분 동적 array를 사용한다.
                            // 클래스를 별도로 만들어서 보내 버린다.
                            // 그러면 함수에 매개변수에 (int(&arr)[4])와 같은
                            // 구차한 코딩을 안 해도 된다.

    // 지난 강의에서 설명한 std::array나 std::vector를 사용하면,
    // 그냥 데이터 타입을 보내는 것과 똑같으므로 reference로 보내기가 훨씬 쉽다.

    printElements(arr);

    cout << endl;

    // vector로 해 보자.

    vector<int> arr1{ 1, 2, 3, 4, 5 };

    priontElements1(arr1);

    return 0;
}

// 이렇게 참조에 의한 전달, 참조에 의한 함수 호출은
// 값에 의한 인자 전달 혹은 값에 의한 함수 호출과 비교했을 때, 장단점이 분명하다.
// 장단점이 서로 주고 받는 경우가 있는 것 같다.

/*
최근에는 아래와 같이 쓰는 것이 일반적이다.

void priontElements1(vector<int>& arr1)     // const를 붙일 수도 있다.
{

}

*/

// 참조를 이용해서 인자를 전달하는 방법에 대해서 살펴 봤다.
// 가정 선호하는 방식이기도 하고, 효율성도 높고, 덜 골치 아프고, 편리하다.
// 최근에는 이를 사용하는 경향이 더 커질 것이다.
// 참조에 의한 전달을 사용하는 방식으로 코딩 습관을 들이면,
// 대부분의 경우 크게 문제 없이 효율적으로 코딩할 수 있을 것이다. 
