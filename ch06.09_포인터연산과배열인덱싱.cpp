// ch06.09 포인터 연산과 배열 인덱싱

// 포인터는 메모리에 주소를 저장하는 변수다.
// 포인터를 가지고 연산을 할 수 있는가?
// 301호의 옆 집, 301호의 앞 집, 이렇게 얘기하면 302를 쉽게 찾을 수 있다.
// 포인터 연산에 대해서 설명을 하고, 배열에 인덱싱을 할 때, 배열의 값을 가지고 올 때
// 몇 번째 위치에서 가지고 오는지, 어떻게 연결이 되는지 살펴보자.

#include <iostream>
using namespace std;

int main()
{
    //// int type의 포인터 연산을 해 보자.
    int value = 7;        // value를 하나 넣어줬다.
    int *ptr = &value;    // value의 주소를 ptr에 넣어줬다.

    cout << uintptr_t(ptr) << endl;         // 6422132
    cout << uintptr_t(ptr) + 1 << endl;     // 6422133
    cout << uintptr_t(ptr + 1) << endl;     // 6422136

    cout << uintptr_t(ptr - 1) << endl;     // 6422128
    cout << uintptr_t(ptr) << endl;         // 6422132
                          // (int)ptr 이렇게 했었는데 uintptr_t가 더 좋다.
    cout << uintptr_t(ptr + 1) << endl;     // 6422136
    cout << uintptr_t(ptr + 2) << endl;     // 6422140
    cout << endl;
    // data type의 사이즈에 맞춰서 옆으로 한 칸씩 간다.
    // int가 4bytes이므로 4씩 옆으로 간 것이다.

    //// 그럼 double은 어떻게 될까?
    double value1 = 7.0;         // value1을 하나 넣어줬다.
    double *ptr1 = &value1;      // value1의 주소를 ptr에 넣어줬다.

    cout << uintptr_t(ptr1 - 1) << endl;   // 6422176
    cout << uintptr_t(ptr1) << endl;       // 6422184
                          // (int)ptr1 이렇게 했었는데 unintptr_t가 더 좋다.
    cout << uintptr_t(ptr1 + 1) << endl;   // 6422192
    cout << uintptr_t(ptr1 + 2) << endl;   // 6422200
    cout << endl;
    // data type의 사이즈에 맞춰서 옆으로 한 칸씩 간다.
    // double이 8bytes이므로 8씩 옆으로 간 것이다.

    // 포인터는 주소고, 주소는 data type과 관계 없이 결정되는 우편 번호 같은 것이다.
    // 우편 번호 사이즈는 고정돼 있다.
    // 그런데 왜 포인터도 data type을 적어 줄까?
    // 1. de-referencing할 때 어떤 data type의 값으로 가지고 올지 알아야 하기 때문에
    // 2. pointer 연산을 할 때, +1이 몇 bytes인지 알아야 하기 때문이다.
    // void pointer를 설명하면, data type이 필요 없을 수도 있겠다고 생각할 수 있다.
    // 점점 포인터에 대해서 깊이 들어가고 있다.

    //// short type도 해 보자.
    short value2 = 7;         // value2를 하나 넣어줬다.
    short *ptr2 = &value2;      // value2의 주소를 ptr에 넣어줬다.

    cout << uintptr_t(ptr2 - 1) << endl;   // 6422180
    cout << uintptr_t(ptr2) << endl;       // 6422182
    cout << uintptr_t(ptr2 + 1) << endl;   // 6422184
    cout << uintptr_t(ptr2 + 2) << endl;   // 6422186
    cout << endl;
    // data type의 사이즈에 맞춰서 옆으로 한 칸씩 간다.
    // short가 2bytes이므로 2씩 옆으로 간 것이다.
    // data type과 메모리 주소는  관 관계가 있다.

    // 이것을 array에 사용해 보자.
    int array[] = {9, 7, 5, 3, 1, };

    cout << array[0] << " " << (uintptr_t)&array[0] << endl;  // 9 6422160
    cout << array[1] << " " << (uintptr_t)&array[1] << endl;  // 7 6422164
    cout << array[2] << " " << (uintptr_t)&array[2] << endl;  // 5 6422168
    cout << array[3] << " " << (uintptr_t)&array[3] << endl;  // 3 6422172
    cout << array[4] << " " << (uintptr_t)&array[4] << endl;  // 1 6422176
    cout << endl;
    // array에서도 주소가 4씩 증가하고 있다.
    // int 사이즈가 하나씩 쭉 나열돼 있는 구조가 int array[]이다.
    // 위에서는 5개가 쭉 나열돼 있다. 이웃해 있다.
    // 그래서 for문으로 사용하는 것이 용이하다.
    //// for문으로도 해 보자.
    for (int i = 0; i < 5; ++i)
        cout << array[i] << " " << (uintptr_t)&array[i] << endl;
    cout << endl;
    // 출력 값은 위 array[]에서의 출력 값과 동일하다.

    //// 같은 작업을 포인터 연산을 이용해서 해 보자.
    //
    int *ptr3 = array; // pointer array는 이렇게 초기화한다. array가 주소이므로.

    for (int i = 0; i < 5; ++i)
    {
      cout << *(ptr3 + i) << " " << (uintptr_t)(ptr3 + i) << endl;
    }
    cout << endl;
    // 포인터 연산을 통해 알아 봐도, 동일한 값이 출력된다.
    // 나란히 4씩 차이가 나고 있다.

    //// long으로도 해 보자
    long array1[] = {9, 7, 5, 3, 1, };
    long *ptr4 = array1;

    for (int i = 0; i < 5; ++i)
    {
      cout << *(ptr4 + i) << " " << (uintptr_t)(ptr4 + i) << endl;
    }
    cout << endl;
    // long도 나란히 4씩 차이가 나고 있다.

    // long long으로 해 보자
    // long으로도 해 보자
    long long array2[] = {9, 7, 5, 3, 1, };
    long long *ptr5 = array2;

    for (int i = 0; i < 5; ++i)
    {
      cout << *(ptr5 + i) << " " << (uintptr_t)(ptr5 + i) << endl;
    }
    cout << endl;
    // long long은 8씩 차이가 난다.
    // 포인터 연산에 대한 기본적인 사항을 살펴 봤다.

    //// 문자열을 해 보자.

    char name[] = "Jack jack";  // 정적 array, 내부적으로는 pointer이다.
    const int n_name = sizeof(name) / sizeof(name[0]); // sizeof(char)

    for (int i = 0; i < n_name; ++i)
    {
        cout << *(name + i);        // name을 바로 포인터 연산을 해 보자.
    }
    cout << "is there a white space?" << endl;
    cout << endl;
    // 출력) Jack jack is there a white space?
    // 출력을 보면, jack 다음에 null character까지 출력이 되었다.

    // 조금 더 보수적으로 코딩한다면 위 char는 다음과 같이 할 수 있다.
    char name1[] = "Jack1 jack1";  // 정적 array, 내부적으로는 pointer이다.
    const int n_name1 = sizeof(name1) / sizeof(name1[0]); // sizeof(char)

    char *ptr6 = name1;      // 이렇게 casting해 준다.

    for (int i = 0; i < n_name1; ++i)
    {
        cout << *(ptr6 + i);        // name을 바로 포인터 연산을 해 보자.
    }
    cout << "is there a white space?" << endl;
    cout << endl;
    // 동일하게 null character까지 출력된다.
    // 포인터 연산이 array indexing에 사용되는 것을 살펴 봤다.
    // array 안의 내용 물을 한 바뀌 쭉 돌면서 출력을 하거나 사용할 때,
    // 위와 같이 포인터 연산 사용할 수 있다는 것도 살펴 봤다.

    //// 연습 문제) while문과 break를 사용해서 Jack jack을 출력하되,
    ////           null character는 출력을 하지 말아라. ++ptr을 사용하라.
    {
        char name[] = "Jack jack";  // 정적 array, 내부적으로는 pointer이다.
        const int n_name = sizeof(name) / sizeof(name[0]); // sizeof(char)

        char *ptr = name;      // 이렇게 casting해 준다.
        int i = 0;

        while (true)
        {
            cout << *(++ptr - 1);

            if (i >= n_name - 2)    // null character 제외를 위해 -2를 함. 
            {                       // i = 0부터이므로 8까지만 반복돼야 한다.
                break;
            }
            ++i;
        }
        cout << "There is no white space." << endl;
        cout << endl;
    }
    // char name[] = "Jack jack"; 의 index와, 개수, sizeof를 써 보라. 
    // index는 index0 ~ index8까지, 총 9개
    // sizeof는 10개다. 문자 9개 + null character 1개. 
    // null character를 출력하지 않기 위해서는 sizeof에서 -1을 해야 한다. 

    // 포인터 연산에 대해서 살펴 봤고,
    // 포인터 연산을 통해서 array 속에 들어 있는 elements에 접근하는 방법도
    // 살펴 봤다.
    return 0;
}
