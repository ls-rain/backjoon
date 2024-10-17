#include <iostream>

using namespace std;

int t, n, res;

void dfs(int idx, int sum) {
    if (sum >= n) {
        if (sum == n) res++;
        return;
    }
    dfs(idx + 1, sum + 1);
    dfs(idx + 1, sum + 2);
    dfs(idx + 1, sum + 3);
}

int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        dfs(1, 0);
        cout << res << '\n';
        res = 0;
    }
}
