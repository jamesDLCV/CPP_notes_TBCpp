// ch06.19-1_이중포인터와동적다차원배열.cpp
//
// 앞에서 정적 배열을 이용해서 다차원 배열을 만드는 방법을 공부했었다.
// 동적 메모리 할당을 통해서 다차원 배열을 만드는 방법을 살펴 보자.
// 이중 포인터를 사용하는 방법과 이중 포인터를 사용하지 않는 방법 모두 살펴 본다.

#include <iostream>
using namespace std;

int main()
{
    int* ptr = nullptr;     // 포인터 변수는 이렇게 선언할 수가 있다.

    // 포인터도 변수다. 그러므로 포인터에 대한 포인터도 만들 수가 있다.
    // 이중 포인터라고 한다.

    int** ptrptr = nullptr; // 이렇게 선언할 수 있다.
    // 포인터에 대한 포인터인데 원래 변수는 int다.
    // 예를 보자.

    int value = 5;

    ptr = &value;
    ptrptr = &ptr;          // ptrptr은 ptr의 주소이다.

    cout << ptr << " " << *ptr << " " << &ptr << endl;
    // 004FFDF0 5 004FFE08
    cout << ptrptr << " " << *ptrptr << " " << &ptrptr << endl;
    // 004FFE08 004FFDF0 004FFDFC
    cout << **ptrptr << endl;
    // 5
    cout << endl;

    // 위 출력 결과가 복잡해 보이지만 개념을 이해하면 그리 어렵지 않다.
    // ptr의 주소, de-referencing했으니까 5, 그리고 ptr 자신의 주소
    // ptrptr에는 ptr의 주소를 넣었으므로 &ptr과 동일한 값
    // ptrptr을 de-referencing하게 되면 ptr 값 즉 주소가 나온다.
    // &ptrptr 자신의 주소는 또 따로 갖고 있다.
    // 별을 두 개 붙인 **ptrptr은 *(*ptrptr) 이렇게 생각할 수 있다.
    // **ptrptr는 원래 value 변수가 가지고 있던 5가 출력됨.
    // 이중 포인터에 대해서 간단히 살펴 봤다.

    //// 삼중 포인터, 다중 포인터
    int*** ppptr, **** pppptr;

    // 되기는 하지만 많이 쓰지 않는다.
    // 이중 포인터까지는 종종 쓴다.
    // 이중 포인터는 교과서적인 2차원 행렬을 구현할 때 많이 사용한다.

    //// 이차원 행렬 구현의 예를 살펴 보자.
    // 앞에서 2차원 배열 정적 배열 구현하는 것 언급했다.

    const int row = 3;
    const int col = 5;              // 5개의 원소를 가진 행이 3개다.

    const int s2da[row][col] =      // static two d array, 두 번째 건 써 줘야 한다.
    {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15}
    };
    // 위 각 행이 5개 짜리 1차원 array이다.
    // 1차원 array가 3개 있는 것으로 구현할 수 있다.

    // 포인터로 array를 구현할 수 있다.

    int* r1 = new int[col] {1, 2, 3, 4, 5};
    int* r2 = new int[col] {6, 7, 8, 9, 10};
    int* r3 = new int[col] {11, 12, 13, 14, 15};

    // 위에서 보면 r1, r2, r3 이렇게 나오는데, row가 몇 개가 나올지 알 수가 없다.
    // row 개수만큼 들어갈 수 있는 것이다.
    // 그래서 int에 pointer의 array를 만든다.
    // int의 array를 만들 때, int에 * 붙여서 int의 pointer를 만들었다.
    // 그럼 int의 pointer의 array를 만들 때는, *을 하나 더 붙이면 된다.

    int** rows = new int* [row] {r1, r2, r3};   // 이렇게 할 수 있다.

    for (int r = 0; r < row; ++r)
    {
        for (int c = 0; c < col; ++c)
            cout << rows[r][c] << " ";
        cout << endl;
    }
    /*
    1 2 3 4 5
    6 7 8 9 10
    11 12 13 14 15
    */
    // 의도한 대로 제대로 작동했다.
    // 이중 포인터를 사용했다. 위와 같은 경우 많이 사용한다.

    // delete도 해야 한다.

    delete[] r1;
    delete[] r2;
    delete[] r3;
    delete[] rows;
    cout << endl;

    // r1, r2, r3, rows를 for문으로 돌릴 수 없을까?
    //

    int** matrix = new int* [row];

    for (int r = 0; r < row; ++r)
        matrix[r] = new int[col];

    for (int r = 0; r < row; ++r)
        for (int c = 0; c < col; ++c)
            matrix[r][c] = s2da[r][c];

    // print all elements
    for (int r = 0; r < row; ++r)
    {
        for (int c = 0; c < col; ++c)
            cout << matrix[r][c] << " ";
        cout << endl;
    }
    /*
    1 2 3 4 5
    6 7 8 9 10
    11 12 13 14 15
    */

    // delete
    for (int r = 0; r < row; ++r)
        delete[] matrix[r];

    delete[] matrix;
    cout << endl;

    // 위 이중 포인터는 말로 설명하기가 좀 어렵다. 스스로 깨달아 봐라.
    // 스스로 그림을 그리면서 생객해 봐라.
    // 2d를 이중 포인터로 구현하는 것을 살펴 봤다.

    //// 이중 포인터를 사용하지 않는 방법도 살펴 보자.
    // 포인터에 포인터를 쓰는 것이 아무래도 부담스럽다.
    // 좀 더 간단한 방법, 쉬운 방법을 보자.

    int* matrix2 = new int[row * col];

    // 1차원 array가 2차원 array인 것처럼 구부려서 사용해야 한다.
    for (int r = 0; r < row; ++r)
        for (int c = 0; c < col; ++c)
            matrix2[c + col * r] = s2da[r][c];      // 왜 이렇게 되는지 따려 봐라.

    // print all elements
    for (int r = 0; r < row; ++r)
    {
        for (int c = 0; c < col; ++c)
            cout << matrix2[c + col * r] << " ";    // col * r는 함수로 만들 수도 있다.
        cout << endl;
    }
    /*
    1 2 3 4 5
    6 7 8 9 10
    11 12 13 14 15
    */

    delete[] matrix2;

    // col * r는 함수로 만들 수도 있지만, 나중에 클래스로 만들면 편해진다.

    // new, delete 하는 것이 좀 번거롭다. 곧 vector 사용법을 배우게 된다.
    // vector를 사용하면 좀 편해진다.

    // 1차원 array를 2차원 array처럼 사용하는 방법은 스스로 고민을 해 봐라.
    // 대부분의 선형대수학 코드들이 col*r 이러한 구조를 많이 쓴다.
    // 3차원은 어떻게 구현할까? 4차원은? tensor는? 도전 욕구를 불러 일으키기를 바란다.

    // 2중 포인터, 다중 포인터에 대해서 살펴 봤다.
    // 2중 포인터를 이용해서 2차원 배열을 동적 메모리 할당으로 만드는 방법도 살펴 봤다.
    // 1차원 동적 배열을 이용해서 2차원 행렬 구현하는 것도 살펴 봤다.


    return 0;
}
