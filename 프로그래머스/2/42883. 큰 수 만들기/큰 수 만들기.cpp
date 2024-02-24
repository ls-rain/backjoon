#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string number, int k) {
    string answer = "";
    vector<int> num;
    for(char c : number) num.push_back(c - '0');
    int start = 0;
    for(int i = 0; i < num.size() - k; i++){
        int maxNum = num[start];
        int maxIdx = start;
        for(int j = start; j <= k+i; j++){
            if(num[j] > maxNum){
                maxNum = num[j];
                maxIdx = j;
            }
        }
        start = maxIdx + 1;
        answer += to_string(maxNum);
    }
    return answer;
}