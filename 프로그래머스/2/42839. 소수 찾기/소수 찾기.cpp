#include <string>
#include <vector>
#include <algorithm>
#include <set>
#define MAX 9999999
using namespace std;
bool prime[MAX];

void isPrime(){
    for(int i = 2; i <= MAX; i++) prime[i] = true;
    for(int i = 2; i*i <= MAX; i++){
        if(!prime[i]) continue;
        for(int j = i*i; j <= MAX; j+=i){
            prime[j] = false;
        }
    }
}

int solution(string numbers) {
    int answer = 0;
    isPrime();
    set<int> s;
    sort(numbers.begin(), numbers.end());
    do{
        string ans;
        for(int i = 0; i < numbers.size(); i++){
            ans += numbers[i];
            if(prime[stoi(ans)]) s.insert(stoi(ans));
        }
    }while(next_permutation(numbers.begin(), numbers.end()));

    return s.size();
}