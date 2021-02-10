#include <iostream>
using namespace std;

int main()
{
    //const int num_students = 5;
    int scores[] = { 84, 92, 76, 81, 56 };
    const int num_students = sizeof(scores) / sizeof(int);               // can do it like this. 
    int total_score = 0;
    int max_score = 0;

    for (int i = 0; i < num_students; ++i)
    {
        total_score += scores[i];
        max_score = ((max_score < scores[i]) ? scores[i] : max_score);
    }
        
    double avg_score = static_cast<double>(total_score) / num_students;  // 77.8
    double avg_score2 = (double)(total_score / num_students);            // 77. it is different from avg_score

    cout << avg_score << endl;
    cout << avg_score2 << endl;

    cout << max_score << endl;                                           // 92

    return 0;
}
