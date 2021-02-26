// ch06.14-2_referenceVariable.cpp
//

#include <iostream>
using namespace std;

void doSomething(int n)
{
    n = 10;
    cout << "in doSomething " << n << endl;
}

int main()
{
    int n = 5;

    cout << n << endl;      // 5

    doSomething(n);         // in doSomething 10

    cout << n << endl;      // 5, 다시 5가 나온다.

    // 왜 위와 같이 되는가?
    // main()에 있는 int n과 void doSomething() 안에 있는 n은 완전히 다른 n이다.
    // 그러므로 doSomething(n)이 실행될 때만 10이 출력된다.
    // doSomethign(n)에 n이 복사가 될 때는 5가 들어가더라도 10으로 바뀐다.
    // doSomething(n) 실행 후 n 값이 바뀌더라도 main() 안의 n에는 영향을 주지 못한다.
    // 그러므로, doSomething(n) 실행 후에도 main() 내의 n의 10이 아닌 5가 출력된다.

    // 이것을 reference로 해 보자.
    // ch06.14-3_referenceVariable.cpp


    return 0;
}
