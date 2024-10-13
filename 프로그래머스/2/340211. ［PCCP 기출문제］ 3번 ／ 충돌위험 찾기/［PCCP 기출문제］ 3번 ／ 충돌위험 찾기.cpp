#include <string>
#include <vector>
#include <map>
using namespace std;

//각 포인트의 좌표 저장
map<int, pair<int, int> > m;
vector<map<pair<int, int>, int > > v;

int answer = 0;

void solve(vector<int> route){
    pair<int, int> last;
    int time = 0;
    for(int i = 0; i < route.size() - 1; i++){
        pair<int, int> begin = m[route[i]];
        pair<int, int> end = m[route[i+1]];
        last = end;
        while(begin != end){
            v[time][begin]++;
            if(v[time][begin] == 2) answer++;
            int y = begin.first - end.first;
            int x = begin.second - end.second;
            if(y != 0){
                if(y < 0) begin.first++;
                else begin.first--;
            }
            else if(x != 0){
                if(x < 0) begin.second++;
                else begin.second--;
            }
            time++;
        }
    }
    v[time][last]++;
    if(v[time][last] == 2) answer++;
}

// Y좌표 우선순위 이동
int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    for(int i = 1; i <= points.size(); i++) m[i] = {points[i-1][0], points[i-1][1]};
    v.resize(20001);
    for(auto route : routes) solve(route);
    return answer;
}