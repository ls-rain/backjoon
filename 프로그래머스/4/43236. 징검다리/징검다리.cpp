#include <string>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
int answer = 0;

bool judge(int mid, int distance, vector<int> rocks, int n){
    int prev = 0;   //이전 바위의 위치
    int cnt = 0;    //없앤 바위 수
    for(int i = 0; i < rocks.size(); i++){
        if(rocks[i] - prev < mid){
            cnt++;
        }
        else{
            prev = rocks[i];
        }
    }
    if(distance - prev < mid) cnt++;
    
    return cnt > n;
}

int solution(int distance, vector<int> rocks, int n) {
    sort(rocks.begin(), rocks.end());
    int left = 1, right = distance;
    while(left <= right){
        // mid로 돌사이의 거리의 최솟값을 만족시킬수 있는가?
        int mid = (left + right) / 2;
        if(judge(mid, distance, rocks, n)){
            right = mid - 1;
        }
        else{
            answer = max(answer, mid);
            left = mid + 1;
        }
    }
    return answer;
}