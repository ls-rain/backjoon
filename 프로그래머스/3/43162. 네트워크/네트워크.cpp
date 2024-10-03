#include <string>
#include <vector>

using namespace std;

int answer = 0;
bool visited[201];

void dfs(int idx, int n, vector<vector<int>> computers){
    visited[idx] = 1;
    for(int i = 0; i < n; i++){
        if(!visited[i] && computers[idx][i]) dfs(i, n, computers);
    }
}

int solution(int n, vector<vector<int>> computers) {
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            dfs(i ,n, computers);
            answer++;
        }
    }
    
    return answer;
}