#include <string>
#include <vector>

using namespace std;
bool check;
int answer = 100;
int visited[51];

void dfs(string begin, string target, vector<string> words, int change){
    for(int i = 0; i < words.size(); i++){
        int cnt = 0;
        for(int j = 0; j < words[i].length(); j++){
            if(!visited[i] && begin[j] != words[i][j]) cnt++;
        }
        if(cnt == 1){
            if(target == words[i] && answer > change + 1){
                answer = change + 1;
                return;
            }
            visited[i] = 1;
            dfs(words[i], target, words, change+1);
            visited[i] = 0;
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    for(int i = 0; i < words.size(); i++){
        if(target == words[i]) check = 1;
    }
    dfs(begin, target, words, 0);
    if(!check) answer = 0;
    return answer;
}