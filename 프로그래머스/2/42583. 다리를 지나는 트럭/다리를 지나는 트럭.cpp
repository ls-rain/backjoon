#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<int> q;

    int idx = 0;
    int sum = 0;
    while(true){
        int now = truck_weights[idx];
        if(idx == truck_weights.size()){
            answer += bridge_length;
            break;
        }
        if(q.size() >= bridge_length){
            sum -= q.front();
            q.pop();
        }
        if(sum + now <= weight){
            sum += now;
            q.push(now);
            idx++;
        }
        else q.push(0);
        answer++;
        
    }
    return answer;
}