#include <string>
#include <vector>
typedef long long ll;
using namespace std;
int answer = 987654321;

bool judge(int mid,vector<int> diffs, vector<int> times, long long limit){
    ll cnt = 0, prev = 0;
    for(int i = 0; i < diffs.size(); i++){
        if(diffs[i] <= mid){
            cnt += times[i];
            prev = times[i];
        }
        else if(diffs[i] > mid){
            int iter = diffs[i] - mid;
            cnt += iter * (prev + times[i]) + times[i];
            prev = times[i];
        }
        if(cnt > limit) return false;
    }
    return true;
}

int solution(vector<int> diffs, vector<int> times, long long limit) {
    
    int left = 0;
    int right = 200001;
    while(left + 1< right){
        int mid = (left + right) /2;
        if(judge(mid, diffs, times, limit)){
            right = mid;
            answer = min(answer, right);
        }
        else left = mid;
    }
    
    return answer;
}