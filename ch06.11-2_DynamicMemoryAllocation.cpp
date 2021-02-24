// ch06.11-2_DynamicMemoryAllocation.cpp
//

#include <iostream>
using namespace std;

int main()
{
    // 위에서 본 마와 같이 delete 후 나타나는 문제가 가장 큰 문제이다.
    // visual studio 2019에서는 해결해 준 듯하다.
    // 뒤에서 스마트 포인터를 사용하면 이런 것을 자동으로 해 준다.
    // 또 대부분의 경우 클래스를 직접 만들어서 자동으로 처리하도록 한다.
    // 그럼에도 불구하고 위의 현상을 설명한 이유는 고급 프로그래밍을 하게 되면,
    // 이러한 개념을 알고 있어야 한다.
    // 이것을 방지하는 방식이 몇 가지가 있다.
    cout << endl;
    int* ptr4 = new int{ 15 };

    cout << ptr4 << endl;          // 01157810
    cout << *ptr4 << endl;         // 10

    delete ptr4;
    ptr4 = nullptr;            // delete 후에 ptr4에 0, NULL 혹은 nullptr을 넣어 준다.
                       // nullptr는 이 포인터에는 쓸모 있는 주소가 없다는 것을 나타낸다.

    cout << "After delete" << endl;
    if (ptr4 != nullptr)       // ptr4가 의미가 있을 때만 de-referencing을 하라.
    {
        cout << ptr4 << endl;
        cout << *ptr4 << endl;
    }
}
