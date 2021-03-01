// ch06.20-1_stdArray.cpp 
// std::array 소개
// 지금까지 배열을 사용할 때 많이 불편했다. 
// 여러 가지 반복되는 코딩도 좀 지겹고, 
// 함수 parameter로 넣었을 때, 포인터로 강제 변환돼서 사이즈가 날아가 버린다는 등, 
// 많이 불편했다. 
// 이러한 불편함들을 모두 해소하고 편하게 사용할 수 있도록 구현한 것이
// std에 들어 있는 array이다. 


#include <iostream>
#include <array>        // std::array<int, 5> my_arr
using namespace std;

int main()
{
    int arr[5] = { 1, 2, 3, 4, 5 };   // 이런 식으로 했다. 
                                      // 변수 명을 array로는 하지 않는 게 좋다. 

    std::array<int, 5> my_arr = { 1, 2, 3, 4, 5 };   // 똑같이 작동한다.     

    array<int, 5> my_arr1 = { 1, 2, 3, 4, 5 };       // <- 이렇게 써도 된다. 

    // array를 위와 같이 쓰는 게 편하지만, <int, 5>와 같이 숫자가 꼭 들어와야 한다. 
    // int arr[] = { 1, 2, 3, 4, 5 };와 같이 []에 숫자를 안 넣어도 됐다. 넣어도 좋다. 
    // 함수 parameter로 넘길 때는 array를 쓰는 게 훨씬 편하다. 





    return 0;
}

