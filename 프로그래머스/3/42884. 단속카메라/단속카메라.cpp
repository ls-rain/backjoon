#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 1;
    sort(routes.begin(), routes.end());;
    int temp = routes[0][1];
    for(int i = 0; i < routes.size(); i++){
        if(temp < routes[i][0]){
            answer++;
            temp = routes[i][1];
        }
        if(temp >= routes[i][1]) temp = routes[i][1];
    }
    return answer;
}