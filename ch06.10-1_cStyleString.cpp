// ch06.10-1.c-style string Symbolic literal
// 문자열은 기본적으로 문자의 배열이다.
// 배열은 포인터와 호환이 된다.
// 그런데 컴파일러가 우리를 헤깔리게 하는 부분이 있다.
// 이에 대해 살펴 보자.
// 문자의 기호적 상수에 대해 설명한다.

#include <iostream>
using namespace std;

int main ()
{
    char name[] = "Jack jack";
    cout << name << endl;
    cout << endl;

    // char *name1 = "Jack jack";  // error: conflicting declaration 'char name'
                                   // char name = "Jack jack"
    // char *name1 = "Jack jack"; <- 이렇게는 안 된다.
    // 왜 안 되는지는 지금까지 배운 것으로는 설명이 안 된다.
    // 왼쪽은 포인터이고, 오른쪽은 문자열 리터럴이다.
    // 실제로 Jack jack이 담길 메모리를 어디에서 만들 것인가에 대한 정보가 없다.
    // 포인터 사용할 때 아주 중요한 개념이다.
    // "Jack jack"은 리터럴이다.
    // 위에선 리터럴을 배열에 담는 것도 변수에 담는 것도 아니다.
    // 포인터에는 담을 수가 없다. 포인터는 주소를 가리키기만 할 뿐이다.
    // 실제로 Jack jack이 담길 메모리가 필요하다.
    // 그럼에도 불구하고 Jack jack이라는 리터럴을 기호적 상수처럼 사용할 수가 있다.
    // const를 붙여주면 된다.

    const char *name1 = "Jack jack";
    cout << name1 << endl;
    // 컴파일러가 Jack jack을 꽉 쥐고 있다.
    // 메로리를 없애지 않는다.
    // name1을 통해서 access할 수 있도록 특별히 도와주는 것이다.
    // 다음 name2를 name1과 비교해 보자.

    const char *name2 = "Jack jack";
    cout << (uintptr_t)name1 << endl;   // 4210757
    cout << (uintptr_t)name2 << endl;   // 4210757
    cout << endl;

    // 놀랍게도 두 개의 주소가 같다.
    // 컴파일러 왈, 두 개가 같으니까 메모리 좀 같이 쓰라는 것이다.
    // 한 글자만 바꿔 보자.

    const char *name3 = "Jack jack";
    const char *name4 = "Jack jack2";
    cout << (uintptr_t)name3 << endl;   // 4210757, 주소는 위와 같다.
    cout << (uintptr_t)name4 << endl;   // 4210767, 주소가 달라진다.
    // 다른 값이네 그럼 다른 메모리 주소를 가져라.
    // 주의할 것은 앞에 반드시 const가 붙어야 기호적 상수로 사용할 수 있다는 것이다.

    // 문자 포인터의 특성
    cout << endl;
    int int_arr[5] = {1, 2, 3, 4, 5};   // int array
    char char_arr[] = "Hello, World!";  // char array
    const char *name5 = "Jack jack";    // 포인터니까 array로 볼 수 있다.

    cout << int_arr << endl;            // 0x61fe8c, 주소가 나온다.
    cout << char_arr << endl;           // Hello, World!, 문자열이 나온다.
    cout << name5 << endl;              // Jack jack, 문자열이 나온다.
    cout << *name5 << endl;             // J, 배열의 맨 앞자리만 출력된다.
    cout << *(name5 + 1) << endl;       // a, 배열의 index 1이 출력된다.
    cout << *(name5 + 2) << endl;       // c, 배열의 index 2가 출력된다.
    // 지금까지 배운 것으로는 설명이 안 된다.
    // cout에서 문자열은 특별히 처리한다라고 정리하라.
    // cout은, 문자의 포인터가 들어오면 문자열이 아닐까 하고 일단 가정하는 것이다.
    // 포인터 자체를 cout하는 경우가 많지는 않다.
    // 실전에서는 포인터 주소는 아무런 의미가 없으므로 찍는 일이 거의 없다.
    // cout에서는, 문자의 포인터가 들어오면 c-style의 문자열일 가능성이 높다고 보고
    // 즉 문자의 배열일 가능성이 높다고 생각하고 주소를 출력하는 것이 아니라
    // null character를 만날 때까지 array를 쭉 출력한다.
    // 왜 주소가 안 나오고 문자열이 출력되지 하고 의심을 한다면 제대로 공부하고 있음.
    // 위 char_arr와 name5의 출력 결과는 봐 둬라.

    cout << endl;
    char d = 'Q';            // Q@, Q는 제대로 나오지만 뒤에 이상한 글자가 붙는다.
    cout << &d << endl;      // 여기에서는 위에서 char에 무엇인가가 들어 있어서
                             // 그것을 출력했다.
    // cout에 메모리 주소가 들어가니까 이것은 문자열인가 보다라고 생각한 것이다.
    // 문자열은 null character가 나올 때까지 계속 출력을 한다.
    // c가 문자열이라고 가정하고 널 캐릭터가 나올 때까지 쭉 출력을 한 것이다.
    // null character가 어디에 있는지 우리는 모른다.
    // Q 다음에 무엇이 있을지 우리는 알 수가 없는 것이다.
    // 그래서 위험성이 있다.
    cout << *&d << endl;        // Q, 정상적으로 출력이 된다.

    // 문자열의 기호적 상수를 문자열로 어떻게 사용하는지 살펴봤다.
    // 우리가 이론적으로 배운 것과 좀 맞지 않는 게 있다.
    // 컴파일러가 이렇게 하면 프로그래머가 편하겠지하고 구현해 놓은 것이다.
    // 원칙을 배워서 공부해 나가는 입장에서 보면 이상하고 생각할 수 있다.
    // 이런 것들은 예외적인 것들이다.
    // standard library의 string이라든지 std array라든지 std vector 같은 것을
    // 배우면 이런 세세한 것들을 신경 안 쓰고 편하게 사용할 수 있다.
    // 하지만 아직은 포인터에 대해서 더 공부할 필요가 있어서 더 설명을 하겠다.

    // 아래와 같이 char 문자열을 포인터 초기화하는 것은 안 된다.
    // char name2[] = "Jack jack";
    // char *name2;
    // name2 = &name2;
    // 아래와 같이도 안 된다.
    // char name2[] = "Jack jack";
    // char *name2 =  &name2;

    return 0;
}
