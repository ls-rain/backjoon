#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int max_w = 0, max_h = 0;
   
    for(int i = 0; i < sizes.size(); i++){
        if(sizes[i][0] > sizes[i][1]){
            max_h = max(max_h, sizes[i][0]);
            max_w = max(max_w, sizes[i][1]);
        }
        else{
            max_h = max(max_h, sizes[i][1]);
            max_w = max(max_w, sizes[i][0]);

        }
    }
    return max_h * max_w;
}