#include <string>
#include <vector>

using namespace std;
int answer = 0;
int visited[51];

void dfs(int cnt, string begin, string target, vector<string> words){
    if(begin == target){
        answer = cnt;
        return;
    }
    for(int i = 0; i < words.size(); i++){
        if(visited[i]) continue;
        int diff = 0;
        for(int j = 0; j < begin.size(); j++){
            if(begin[j] != words[i][j]) diff++;
        }
        
        if(diff == 1) {
            visited[i] = 1;
            dfs(cnt + 1, words[i], target, words);
            visited[i] = 0;
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    dfs(0, begin, target, words);
    return answer;
}