#include <iostream>

using namespace std;

int n, s, arr[21];
int res;

void dfs(int start, int sum) {
    sum += arr[start];
    if (sum == s) {
        res++;
    }
    for (int i = start + 1; i < n; i++) {
        dfs(i, sum);
    }
}


int main() {
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++) {
        dfs(i, 0);
    }
    cout << res;
}
