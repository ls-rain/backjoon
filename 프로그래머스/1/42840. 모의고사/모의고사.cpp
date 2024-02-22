#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int one[] = {1, 2, 3, 4, 5};
    int two[] = {2,1,2,3,2,4,2,5};
    int three[] = {3,3,1,1,2,2,4,4,5,5};
    int cnt1 = 0, cnt2 = 0, cnt3 = 0;
    for(int i = 0; i < answers.size(); i++){        
        if(one[i%5] == answers[i]) cnt1++;
        if(two[i%8] == answers[i]) cnt2++;
        if(three[i%10] == answers[i]) cnt3++;
    }
    int max_ans = max(cnt1, cnt2);
    max_ans = max(max_ans, cnt3);

    if(max_ans == cnt1) answer.push_back(1);
    
    if(max_ans == cnt2) answer.push_back(2);
    
    if(max_ans == cnt3) answer.push_back(3);
    return answer;       
}