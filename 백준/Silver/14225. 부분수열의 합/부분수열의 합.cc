#include <iostream>
using namespace std;

int n, arr[21];
bool res[2000001];

void dfs(int idx, int sum) {
    sum += arr[idx];
    res[sum] = 1;
    for (int i = idx + 1; i < n; i++) {
        dfs(i, sum);
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++) {
        dfs(i, 0);
    }
    for (int i = 1; i < 2000001; i++) {
        if (res[i] == 0) {
            cout << i;
            return 0;
        }
    }
}
