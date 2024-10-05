#include <iostream>
using namespace std;

int n, m, map[502][502], visited[502][502];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int res = 0;

void dfs(int cnt, int sum, int y, int x) {
    if (cnt == 4) {
        res = max(res, sum);
        return;
    }
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (1 > ny || ny > n || 1 > nx || nx > m) continue;
        if (!visited[ny][nx]) {
            visited[ny][nx] = 1;
            dfs(cnt + 1, sum + map[ny][nx], ny, nx);
            visited[ny][nx] = 0;
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> map[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            visited[i][j] = 1;
            dfs(1, map[i][j], i, j);
            visited[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int mid = map[i][j];
            int low = 1001;
            for (int k = 0; k < 4; k++) {
                low = min(low, map[i + dy[k]][j + dx[k]]);
                mid += map[i + dy[k]][j + dx[k]];
            }
            res = max(res, mid - low);
        }
    }

    cout << res << endl;
}
