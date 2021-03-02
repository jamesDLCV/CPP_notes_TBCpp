// ch06.21-1_stdVector.cpp 
//
// 정적 배열을 대체할 수 있는 정적 array에 대해서 살펴 봤었다. 
// 그렇다면 동적 array를 대체할 수 있는 좋은 뭔가는 없을까? 
// std::vector에 대해서 살펴 보자. 동적 array보다 사용하기 편하다. 
// 부담이 엄청나게 줄어든다. 

#include <iostream>
//#include <array>                  // std::array<int, 5> my_arr;
#include <vector>                   // std::vector<int> my_arr; 
using namespace std;

int main()
{
    // std::array<int, 5> my_arr;   <- 정적 array에서는 사이즈를 반드시 적어 줘야 했다.

    std::vector<int> my_arr;        // 동적 할당이 되는 메모리이므로, 
                                    // 사이즈는 처음에 몰라도 된다. 
    // 그때 그때 바뀌므로 적어 주려면 적어 주고, 말라면 말아라는 입장이다. 

    // 초기화를 해 보자. 
    std::vector<int> my_arr2 = { 1, 2, 3, 4, 5 };

    cout << my_arr2.size() << endl;     // 5, .size()를 사용하면, 지금 들어 있는
                                        // 원소의 개수가 몇 개인지 사이즈를 알 수 있다. 
    std::vector<int> my_arr3 = { 1, 2, 3 };

    cout << my_arr3.size() << endl;             // 3

    std::vector<int> my_arr4 { 1, 2, 3 };       // uniform initialization

    cout << my_arr4.size() << endl;             // 3
    cout << sizeof(my_arr4) << endl;            // 16(x86), 32(x64)
    cout << endl;

    // 위와 같이 사이즈가 다양한 것들을 쉽게 할 수 있다. 

    // 더 좋은 것은 사이즈를 그때 그때 바꿀 수가 있다. 

    vector<int> my_arr5 = { 1, 2, 3, 4, 5 };

    for (auto& itr : my_arr5)
        cout << itr << " ";                 // 1 2 3 4 5

    cout << endl;
    cout << endl;

    // 예전에는 for문에서 iterator라는 것을 사용한 적도 있었다. 
    // iterator는 이것보다 훨씬 번거로웠다. 
    // for-each가 훨씬 편하다. 
    // vector도 다음과 같은 것들이 가능하다. 

    cout << my_arr5[1] << endl;             // 2
    cout << my_arr5.at(1) << endl;          // 2
    // 위 두 가지의 차이는 array에서 설명했던 것과 동일하다. 

    // 이 vector의 장점을 메모리를 알아서 지워준다는 것이다. 

    int* my_arr6 = new int[5];  // 이렇게 했으면

    delete[] my_arr6;           // 이렇게 꼭 지워라. 
                                // 이렇게 꼭 지워야 하는 게 고딩할 때는 부담이다. 

    // vector는 다 쓰고 나면, 블럭 밖으로 나가거나 리턴으로 나가거나 할 때, 
    // 자동으로 사라진다. memory leak이 되지 않는다. 
    // 편하다. 프로그래머의 스트레스를 확 줄여 주는 장점이 있다. 
    // 그리고 자신의 길이를 알아서 기억을 해 준다. 
    // 함수에 parameter로 보내면 길이를 자기가 스스로 알고 있다.
    // std::vector<int> my_arr2 = { 1, 2, 3, 4, 5 };    <- 길이를 알아서 기억한다. 
    // 동적 할당에서 int *my_arr = new int[5]; 이렇게 보면 길이가 5라는 것을 알 수 있지만,
    // my_arr만 봐서는 길이를 알 수 없다.
    // 하지만 size()를 쓰면, 지금 들어 있는 원소가 몇 개인지 사이즈를 알 수 있다. 
    // 좀 더 자세히는, 

    cout << my_arr5.size() << endl;     // 5

    // 퍼펙티(?), 리사이즈, 리절브 등등 여러 가지 유용한 기능들을 사용할 수 있다. 
    // 메모리 관리를 훨씬 유용하게 할 수 있다. 
    // 동적 메모리 할당의 장점을 충분히 활용할 수 있는 아주 좋은 기능이다.  
    cout << endl;

    //// resize를 해 보자. 

    vector<int> my_arr7 = { 1, 2, 3, 4, 5 };
    my_arr7.resize(10);

    for (auto& itr : my_arr7)
        cout << itr << " ";                 // 1 2 3 4 5 0 0 0 0 0 
    cout << endl;

    cout << my_arr7.size() << endl;         // 10 
    cout << my_arr7[1] << endl;             // 2
    cout << my_arr7.at(1) << endl;          // 2, array처럼 잘 작동하고 있다. 

    cout << endl;
    cout << endl;

    // 사이즈를 마음대로 바꿀 수 있다. 엄청나게 편하다. 
    
    /*
    다음과 같은 동적 할당을 
    int *my_arr = new int[5];
    직접 코딩해서 만들려면, 원래 있던 메모리 주소, 사용하는 메모리의 길이를 OS에게 물어 봐서,
    더 늘릴 수 있느냐고 물어 본 후에, 된다고 하면, 뒤로 붙이고, 
    안 된다고 하면, 새로 할당을 받아서, 그걸 다시 복사해서 붙이는 과정을 거치는데, 
    이걸 전부 우리가 일일이 코딩을 해서 쓰는 것은 힘들다. 
    --> vector에 전부 구현이 돼 있다. 편하게 쓰면 된다. 
    */

    //// 사이즈를 줄일 수도 있다. 

    vector<int> my_arr8 = { 1, 2, 3, 4, 5 };
    my_arr8.resize(2);

    for (auto& itr : my_arr8)
        cout << itr << " ";                 // 1 2, 뒤의 {3, 4, 5}는 날아가 버린다.  
    cout << endl;

    cout << my_arr8.size() << endl;         // 2 
    cout << my_arr8[1] << endl;             // 2
    cout << my_arr8.at(1) << endl;          // 2, array처럼 잘 작동하고 있다. 

    // 동적 할당 메모리, 배열을 아주 편하게 상용할 수 있는 vector에 대해서 살펴 봤다. 



    return 0;
}

