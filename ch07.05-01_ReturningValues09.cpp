// ch07.05-01_ReturningValues09.cpp 
//
// 튜플을 사용하는 경우
// 


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
    std::tuple<int, double> my_tp = getTuple();
    cout << std::get<0>(my_tp) << endl; // a
    cout << std::get<1>(my_tp) << endl; // d

    return 0;
}

