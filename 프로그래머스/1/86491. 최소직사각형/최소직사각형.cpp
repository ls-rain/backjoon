#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int w = 0, h = 0;
    for(auto i : sizes){
        if(i[0] > i[1]){
            w = max(w,i[0]);
            h = max(h,i[1]);
        }
        else{
            w = max(w, i[1]);
            h = max(h, i[0]);
        }
    }
    answer = w*h;
    return answer;
}