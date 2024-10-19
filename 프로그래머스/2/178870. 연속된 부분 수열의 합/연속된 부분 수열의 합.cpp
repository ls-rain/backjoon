#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer(0, sequence.size() - 1);
    int s = 0, e = 1;
    int sum = sequence[0];
    int diff = 1000000;
    while(e < sequence.size() + 1){
        if(sum == k){
            if(e - 1 - s < diff){
                answer.clear();
                answer.push_back(s);
                answer.push_back(e - 1);
                diff = e - 1 - s;
            }
            sum -= sequence[s];
            s++;
        }
        else if(sum > k){
            sum -= sequence[s];
            s++;
        }
        else{
            sum += sequence[e];
            e++;
        }
    }
    return answer;
}