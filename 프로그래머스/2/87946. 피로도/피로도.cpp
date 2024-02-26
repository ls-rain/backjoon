#include <string>
#include <vector>

using namespace std;
int visited[8];
int answer = 0;

void dfs(int k, vector<vector<int>> dungeons, int cnt){
    if(answer < cnt) answer = cnt;
    for(int i = 0; i < dungeons.size(); i++){
        if(dungeons[i][0] <= k && !visited[i]){
            visited[i] = 1;          
            dfs(k- dungeons[i][1], dungeons, cnt+1);
            visited[i] = 0;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    dfs(k, dungeons, 0);
    return answer;
}