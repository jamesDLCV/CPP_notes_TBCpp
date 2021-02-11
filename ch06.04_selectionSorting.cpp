#include <iostream>
using namespace std;

int main()
{
    // const int num_students = 5;
    int scores[] = { 84, 92, 76, 81, 56, 34, 16, 96, 79 };
    const int num_students = sizeof(scores) / sizeof(int);
    int total_score = 0;
    int max_score = 0;    

    for (int i = 0; i < num_students - 1; ++i)
    {
        //total_score += scores[i];
        //max_score = ((max_score < scores[i]) ? scores[i] : max_score);
        
        for (int j = i + 1; j < num_students; ++j)
        {                
            if (scores[i] < scores[j])
            {
                int temp = scores[i];
                scores[i] = scores[j]; 
                scores[j] = temp;
            }             
        }
        
    }

    for (int i = 0; i < num_students; ++i)
    {
        total_score += scores[i];
        max_score = ((max_score < scores[i]) ? scores[i] : max_score);
    }

    double avg_score = static_cast<double>(total_score) / num_students;
    double avg_score2 = (double)(total_score / num_students);

    cout << avg_score << endl;
    cout << avg_score2 << endl;

    cout << max_score << endl;

    for (int i = 0; i < num_students; ++i)
    {
        cout << scores[i] << " ";
    }

    return 0;
}