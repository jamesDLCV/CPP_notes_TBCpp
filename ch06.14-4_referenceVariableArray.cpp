// ch06.14-4_referenceVariableArray.cpp
// array를 함수에 넣어 줄 때도 reference를 사용할 수 있다.
// 아래와 같이 &array도 사용할 수 있다.
// array의 개수를 반드시 넣어 줘야 한다. 조금 불편하다.
// 하지만 어차피 나중에 다른 라이브러리를 사용할 것이다.
// 그때는 sdt::vector 같은 것을 reference로 넘겨 버리면 아주 편해진다.



#include <iostream>
using namespace std;

void printElements(int (&array)[5])  // reference 기호 &가 붙어 있다. 원소 수 반드시 입력.
{
    for (int i = 0; i < 5; ++i)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}


int main()
{
    const int length = 5;
    int array[length] = { 1, 2, 3, 4, 5 };

    printElements(array);

    return 0;
}

// void printElements(const int (&array)[5])
// 이렇게 const도 붙여 줄 수 있다. 필요하면 붙여라.
// ch06.14 - 5_referenceVariableStructure.cpp
