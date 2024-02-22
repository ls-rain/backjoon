#include <string>
#include <vector>
#include <cmath>
using namespace std;
//가로 >= 세로
vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    for(int h = 3; h <= sqrt(brown+yellow); h++){
        if((brown+yellow) % h == 0){
            int w = (brown+yellow)/h;
            if(((w+h)*2-4) == brown){
                answer.push_back(w);
                answer.push_back(h);
            }
        }
    }
    
    return answer;
}