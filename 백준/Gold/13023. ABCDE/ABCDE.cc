#include <iostream>
#include <vector>
#define MAX 2001
using namespace std;

int n, m, visited[MAX];
vector<int> v[MAX];
bool pos;

void dfs(int cur, int cnt) {
    if (cnt == 5) {
        pos = true;
        return;
    }
    visited[cur] = 1;
    for (int i: v[cur]) {
        if (visited[i]) continue;
        dfs(i, cnt + 1);
    }
    visited[cur] = 0;

}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for (int i = 0; i < n; i++) {
        dfs(i, 1);
        if (pos == true) {
            cout << 1;
            return 0;
        }
    }
    cout << 0;
}
