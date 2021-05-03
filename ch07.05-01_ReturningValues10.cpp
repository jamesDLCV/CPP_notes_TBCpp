// ch07.05-01_ReturningValues10.cpp 
// 튜플을 사용하는 경우
// C++17을 사용해 보자. 


#include <iostream>
#include <tuple>
using namespace std;

// 아래 튜플은 사용자 정의처럼 간주된다. 
std::tuple<int, double> getTuple() {
    int a = 10;
    double d = 3.14;
    return std::make_tuple(a, d);
}

int main()
{
    // 받는 쪽에서는 tuple로 받으면 된다. 
    //std::tuple<int, double> my_tp = getTuple();
    //cout << std::get<0>(my_tp) << endl; // a
    //cout << std::get<1>(my_tp) << endl; // d

    // c++17을 사용하면, 다음과 같이 해 줄 수가 있다. 

    auto [a, d] = getTuple; //왜 안 되지? ㅠㅠ 
    cout << a << endl;
    cout << d << endl;

    return 0;
}

// 다양한 방식으로 리턴값을 반환하는 방법을 살펴 보았다. 
// 값으로 받는 방법, 참조로 받는 방법, 
// 주소(포인터)로 받는 방법, 구조체로 받는 방법, 튜플로 받는 받는 방법을
// 살펴 보았다. 
// 클래스를 배우고 나면 return value optimization을 배울 것이다. 