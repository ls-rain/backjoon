#include <string>
#include <vector>
#include <queue>

using namespace std;
priority_queue<int> pq;
int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int, int>> q;
    for(int i = 0; i < priorities.size(); i++){
        q.push({i, priorities[i]});
    }
    for(int i : priorities){
        pq.push(i);
    }
    while(!q.empty()){
        if(q.front().second == pq.top()){
            answer++;
            if(location == q.front().first) break;
            q.pop();
            pq.pop();
        }
        else{
            q.push(q.front());
            q.pop();
        }
    }
    return answer;
}