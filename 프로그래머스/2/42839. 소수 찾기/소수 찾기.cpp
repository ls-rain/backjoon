#include <string>
#include <vector>
#include <algorithm>
#include <set>
#define MAX 10000001
using namespace std;
bool judge[MAX];
void isPrime(){
    for(int i = 2; i <= MAX; i++) judge[i] = true;
    for(int i = 2; i*i <= MAX; i++){
        if(!judge[i]) continue;
        for(int j = i*i; j <= MAX; j+=i){
            judge[j] = false;
        }
    }
}

int solution(string numbers) {
    int answer = 0;
    isPrime();
    set<int> ans{};
    sort(numbers.begin(), numbers.end());
    do{
        string tmp;
        for(int i = 0; i < numbers.size(); i++){
            tmp += numbers[i];
            if(judge[stoi(tmp)]) ans.insert(stoi(tmp));
        }
    }while(next_permutation(numbers.begin(), numbers.end()));
    return ans.size();
}