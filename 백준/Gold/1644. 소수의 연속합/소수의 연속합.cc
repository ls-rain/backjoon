#include <iostream>
#include <vector>
#define MAX 4000001
using namespace std;

int n;
bool prime[MAX];
vector<long long> v;
int res;

void isPrime() {
    for (int i = 2; i < MAX; i++) prime[i] = true;
    for (int i = 2; i * i < MAX; i++) {
        if (prime[i] == false) continue;
        for (int j = i * i; j < MAX; j += i) prime[j] = false;
    }
}

int main() {
    cin >> n;
    isPrime();
    for (int i = 2; i <= n; i++) {
        if (prime[i]) v.push_back(i);
    }
    int s = 0, e = 0;
    while (e < v.size()) {
        long long sum = 0;
        for (int i = s; i <= e; i++) sum += v[i];
        if (sum < n) e++;
        else if (sum == n) {
            res++;
            s++;
        } else s++;
    }
    cout << res << endl;
}
