// ch06.16-1_MemberSelectionOperator.cpp
// 포인터와 참조를 struture 구조체나 클래스에 대해서 사용할 때는,
// 포인터와 참조를 통해서 구조체나 클래스의 멤버에 접근할 수 있다.
// 그때 어떤 연산자를 사용하는지 어떻게 하는 것이 좋을지 살펴 보자.

#include <iostream>
using namespace std;

// struct를 만들었다. 두 개의 member variables를 가지고 있다.
// 뒤에서 member function도 배울 것이다.
// 클래스와 객체지향에 대해서도 배우게 될 것이다.
// 그때 유용하게 사용될 연산자이다.

struct Person
{
    int age;
    double weight;
};

int main()
{
    Person person;

    person.age = 5;         // Person member인 age에 접근할 때는 dot(.) 점을 찍었다.
                            // .은 member selection operator라고 한다.
                            // 멤버를 선택하게 해 주는 연산자다.
    person.weight = 30;     // 이런 식으로 접근할 수 있다.

    // 또 다른 방식은 reference를 쓸 수가 있다.
    Person& ref = person;
    ref.age = 15;
    ref.weight = 50;        // 이런 식으로 ref도 점을 찍어서 age와 weight을 불러올 수 있다.

    // 하지만 포인터는 조금 다르다.
    Person* ptr = &person;  // 주소를 넣어 준다.
    ptr->age = 30;          // 점(dot) 대신 ->을 사용한다.
    (*ptr).age = 20;        // de-referencing operator를 같이 쓸 수 있다.
                            // (*ptr) 이것이 reference가 된다.

    Person& ref2 = *ptr;    // 이렇게 할 수 있다.
    ref2.age = 45;

    cout << &person << endl;    // 0113F8E8
    cout << &ref2 << endl;      // 0113F8E8, 동일한 주소가 나온다.
    // 원래 변수 person이 있었고, 그것을 포인터 *ptr 에 주소를 넣었다가,
    // 그것을 다시 뒤로 레퍼런싱해서 reference에 넣은 것을 주소를 찍어 보니까,
    //  ^- Person& ref2 = *ptr;
    // 원래의 것과 똑같이 나온다.
    // (*ptr).age에서 괄호는 꼭 필요하다.
    // member selection operator가 *보다 우선 순위가 높다.
    // 하지만 (*ptr).age 는 잘 안 쓴다.
    // ptr->age = 30; 이렇게 쓰거나 ref2.age = 45; 이렇게 쓴다.
    // 포인터 쓸 때는 화살표 -> 쓰자, 레퍼런스 쓸 때는 점 찍으면 된다.

    // 포인터나 레퍼런스를 구조체나 클래스에 대해서 사용할 때,
    // 내부의 멤버를 어떻게 선택할 것인가?
    // 선택하는 방법, 연산자에 대해서 살펴 봤다.


    return 0;
}
