#include <string>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;
long long answer = 0;

bool judge(ll mid, int n , vector<int> times){
    ll cnt = 0;
    for(int i = 0; i < times.size(); i++){
        cnt += mid / times[i];
    }
    return cnt < n;
}

long long solution(int n, vector<int> times) {
    sort(times.begin(), times.end());
    ll left = 1, right = (ll)times[times.size() - 1] * n;
    while(left <= right){
        ll mid = (left + right) / 2;
        if(judge(mid, n, times)){
            left = mid + 1;
        }
        else{
            if(mid <= right) answer = mid;
            right = mid - 1;
        }
    }
    
    return answer;
}