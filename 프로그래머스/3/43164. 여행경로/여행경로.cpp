#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<string> answer;
int visited[100001][2];
bool pos;

void dfs(int cnt, string start, vector<vector<string>> tickets){
    if(cnt == tickets.size()){
        pos = 1;
    }
    answer.push_back(start);
    for(int i = 0; i < tickets.size(); i++){
        if(visited[i][1]) continue;
        if(tickets[i][0] == start){
            visited[i][1] = 1;
            dfs(cnt + 1, tickets[i][1], tickets);
            if(!pos){
                answer.pop_back();
                visited[i][1] = 0;
            }
        }        
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(), tickets.end());
    dfs(0, "ICN", tickets);
    return answer;
}