#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//최대한 많은 사람 보트에 태우기 -> 중앙값 생각!
int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end());
    int idx = 0;
    while(people.size() > idx){
        int back = people.back();
        people.pop_back();
        if(people[idx] + back <= limit){
            idx++;
            answer++;
        }
        else answer++;
    }
    return answer;
}