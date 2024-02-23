#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(vector<int> a, vector<int> b){
    if(a[0] == b[0]) return a[1] < b[1];
    return a[0] < b[0];
}

int solution(vector<vector<int>> targets) {
    int answer = 1;
    sort(targets.begin(), targets.end(), cmp);
    int end = targets[0][1];
    for(int i = 0; i < targets.size(); i++){
        if(targets[i][0] >= end){
            answer++;
            end = targets[i][1];
        }
        else end = min(end, targets[i][1]);
    }
    return answer;
}