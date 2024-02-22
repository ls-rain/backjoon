#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(vector<int> i : commands){
        vector<int> input;
        int start = i[0] - 1;
        int end = i[1];
        for(int j = start; j < end; j++) input.push_back(array[j]);
        sort(input.begin(),  input.end());
        answer.push_back(input[i[2] - 1]);
    }
    return answer;
}