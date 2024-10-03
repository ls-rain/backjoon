#include <string>
#include <vector>

using namespace std;
int answer = -1;
bool visited[9];

void dfs(int cnt, int k, vector<vector<int>> dungeons){
    if(answer < cnt) answer = cnt;
    for(int i = 0; i < dungeons.size(); i++){
        if(k >= dungeons[i][0] && !visited[i]){
            visited[i] = 1;
            dfs(cnt + 1, k - dungeons[i][1], dungeons);
            visited[i] = 0;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    dfs(0, k, dungeons);
    return answer;
}