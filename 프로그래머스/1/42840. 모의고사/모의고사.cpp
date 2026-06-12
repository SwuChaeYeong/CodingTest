#include <algorithm>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    
    vector<int> answer, score(3, 0);
    
    int arr1[5] = {1, 2, 3, 4, 5};
    int arr2[8] = {2, 1, 2, 3, 2, 4, 2, 5};
    int arr3[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    for (int i = 0; i < answers.size(); i++)
    {
        if (arr1[i % 5] == answers[i])
            score[0]++;
        
        if (arr2[i % 8] == answers[i])
            score[1]++;
        
        if (arr3[i % 10] == answers[i])
            score[2]++;
    }
    
    int maxScore = *max_element(score.begin(), score.end());
    
    for (int i = 0; i < 3; i++)
    {
        if (maxScore == score[i])
            answer.push_back(i + 1);
    }
    
    return answer;
}