// ch06.17-1_C++11ForEachLoop.cpp
//
// array를 for문으로 돌릴 때, 그러니까 iterate 할 때, 구현할 양이 좀 많아서 불편했다.
// 훨씬 간단해진 for-each 반복문을 살펴 보자.
//

#include <iostream>
#include <limits>       // std::numeric_limits<int>::lowest();
#include <algorithm>    // std::max_align_t(); std::max(max_number, n);
#include <vector>       // int array 대신 vector를 사용할 수 있다.
using namespace std;

int main()
{
    // 아래와 같은 array가 있다. 이를 for문으로 돌려야 한다.
    // 이전의 for문은 많이 구현해 봤다.
    // for-each문으로 해 보자.
    const int fibonacci[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 };

    for (int number : fibonacci)
    {
        cout << number << " ";
    }
    cout << endl;
    // 0 1 1 2 3 5 8 13 21 34 55 89
    // 아주 간단해졌다.
    cout << endl;

    //// change array values
    for (int number : fibonacci)
    {
        number = 10;                // 값을 모두 10으로 해 보자. 될까?
    }
    // output
    for (int number : fibonacci)
    {
        cout << number << " ";
    }
    cout << endl;
    // 0 1 1 2 3 5 8 13 21 34 55 89, <- 값이 10으로 바뀌지 않았다.
    // 안타깝다.
    // 이건 함수의 parameter로 들어가는 것과 비슷하다.
    cout << endl;

    //// 그럼 어떻게 number의 값을 바꿀 수 있는가?
    // reference를 쓰면 된다.

    // &number를 쓸 때 array에 const를 쓰면 안 된다.
    int fibonacci2[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 };

    for (int & number : fibonacci2) // &를 붙여 줬다.
    {
        number = 10;                // 값을 모두 10으로 해 보자. 될까?
    }
    // output
    for (int number : fibonacci2)
    {
        cout << number << " ";
    }
    cout << endl;
    // 10 10 10 10 10 10 10 10 10 10 10 10, array의 값이 모두 바뀌었다.
    // reference를 싸용하니까 바뀐 것이다.
    cout << endl;

    //// 보통 더 흔하게 사용하는 방식은 아래와 같이 auto를 넣는다.
    int fibonacci3[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 };

    for (auto& number : fibonacci3) // auto를 넣어 주면, int가 자동으로 들어온다.
    {
        number = 10;
    }
    // output
    for (auto number : fibonacci3)  // 여기에도 auto를 넣어 준다.
    {
        cout << number << " ";
    }
    cout << endl;
    cout << endl;

    // auto를 넣어준 후 const도 사용한다.
    int fibonacci4[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 };

    // change array values
    for (auto& number : fibonacci4) // const를 넣지 않는다. 값을 변경할 것이므로
    {
        number *= 10;
    }
    // output
    for (const auto number : fibonacci4)    // const를 넣는다. 값을 변경하지 않으므로
    {
        cout << number << " ";
    }
    cout << endl;
    // 0 10 10 20 30 50 80 130 210 340 550 890
    cout << endl;

    //// 주어진 숫자 중 가장 큰 숫자를 찾아라.
    // std::numeric_limits<int>::lowest();를 사용할 수 있다.
    // 음수 중 큰 값을 구할 수도 있으므로 std::numeric_limits<int>::lowest();를 사용.
    // 따라서 inclue <limits>를 해 줘야 한다.

    int fibonacci5[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 };

    int max_number = std::numeric_limits<int>::lowest();

    for (const auto& n : fibonacci5)
    {
        max_number = std::max(max_number, n);    // inclue <algorithm>
    }
    cout << max_number << endl;
    // 89, 가장 큰 숫자인 89 출력.
    // 가장 큰 숫자 찾는 프로그램을 이전 강의에서 다뤘었다. 프로그램이 조금 길었다.
    // modern C++을 사용하기 시작하면서 코드가 많이 깔끔해지고 있다.
    cout << endl;

    //// vector를 사용해 보자.
    // array를 동적 할당을 하면, for-each를 사용할 수가 없다.
    // 단점이다 혹은 한계라고 생각할 수 있지만 더 좋은 걸 사용할 수 있다.
    // vector를 사용할 수 있다. include <vector>를 해 줘야 한다.
    // fibonacci6를 vector로 선언한다.
    vector<int> fibonacci6 = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 };

    int max_number2 = std::numeric_limits<int>::lowest();

    for (const auto& n : fibonacci6)
    {
        max_number2 = std::max(max_number, n);    // inclue <algorithm>
    }
    cout << max_number2 << endl;
    // 89
    // vector는 우리가 동적 할당 배열을 아주 편하게 사용할 수 있도록,
    // std::에 들어 있는 것이다.
    // 예전에는 array에 관한 것은 다 만들어서 썼으나 이젠 vector를 사용하면 된다.
    // 이외에도 std::에 들어 있는 함수를 그대로 사용하면 된다.
    // 작업 속도가 훨씬 빨라졌다.
    // 동적 할당 배열 대신에 vector를 사용할 수 있다. 훨씬 편해진다.
    // vector는 다시 다른 강의에서 다룬다.
    // 점점 더 효율적으로 프로그래밍하는 방법들이 소개되고 있다.


    return 0;
}
