// ch07.05-01_ReturningValues07.cpp
//
// return by reference


#include <iostream>
#include <array>

int& get(std::array<int, 100>& my_array, int ix) {
    return my_array[ix];
}

int main()
{
    std::array<int, 100> my_array;      // 이 경우에는 이것이 메모리에 명확하게
                                        // 잡혀 있다. 
    // 여기에 메모리가 잡혀 있는 상태에서 이것을 위 함수의 매개변수로 받아주고, 
    // 그 중에서 한 element의 레퍼런스를 리턴해 준다. 

    my_array[30] = 10;

    get(my_array, 30) = 1024;           // 마치 왼쪽에 있는 것이 변수인 것처럼
                                        // 값을 업데이트해 주고 있다. 
    // 결국 get(my_array, 30)이  my_array[30]와 같은 형태가 돼 버리는 것이다. 
    // 이런 패턴으로 사용하는 경우가 아주 많다. 

    std::cout << my_array[30] << std::endl;     // 1024
                                                // 바뀐 값이 출력된다. 
    get(my_array, 30) *= 10;

    std::cout << my_array[30] << std::endl;     // 10240

    // 수학 라이브러리를 구현할 때 이런 형태를 사용할 수 있다.
    // 이런 타입은 많이 사용한다. 뒤에서 다시 다룰 것이다. 

    return 0;
}

