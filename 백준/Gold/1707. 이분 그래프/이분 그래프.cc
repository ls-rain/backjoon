#include <iostream>
#include <vector>
using namespace std;

int k, v, e;
vector<int> edge[20001];
int check[20001];

bool dfs(int vertex, int vs) {
    check[vertex] = vs;
    for (int i: edge[vertex]) {
        if (check[i] == 0) {
            if (!dfs(i, 3 - vs)) return false;
        } else if (check[vertex] == check[i]) return false;
    }
    return true;
}

void solution() {
    bool res = true;
    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    for (int i = 1; i <= v; i++) {
        if (check[i] == 0) {
            if (!dfs(i, 1)) {
                res = false;
                break;
            }
        }
    }
    if (res == true) cout << "YES" << '\n';
    else cout << "NO" << '\n';
}

int main() {
    cin >> k;
    while (k--) {
        for (int i = 0; i < 20001; i++) {
            edge[i].clear();
            check[i] = 0;
        }
        cin >> v >> e;
        solution();
    }
}
