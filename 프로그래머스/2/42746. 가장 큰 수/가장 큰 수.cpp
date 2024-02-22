#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool cmp(string a, string b){
    return a+b > b+a;
}
string solution(vector<int> numbers) {
    string answer = "";
    vector<string> input;
    for(int i : numbers) input.push_back(to_string(i));
    
    sort(input.begin(), input.end(), cmp);
    for(string s : input) answer += s;
    if(input[0] == "0") return "0";
    return answer;
}