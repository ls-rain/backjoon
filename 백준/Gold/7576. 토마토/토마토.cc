#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int m, n, res, map[1001][1001];

struct node {
    int y, x, cnt;
};

queue<node> q;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, -1, 0, 1};


void bfs() {
    while (!q.empty()) {
        int y = q.front().y;
        int x = q.front().x;
        int cnt = q.front().cnt;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny >= n || ny < 0 || nx >= m || nx < 0) continue;
            if (map[ny][nx] != 0) continue;
            map[ny][nx] = cnt + 1;
            q.push({ny, nx, cnt + 1});
        }
    }
}

int main() {
    cin >> m >> n;
    bool pos = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            if (map[i][j] == 0) pos = false;
            if (map[i][j] == 1) {
                q.push({i, j, 0});
            }
        }
    }
    if (pos == true) {
        cout << 0;
        return 0;
    }
    bfs();
    pos = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            res = max(res, map[i][j]);
            if (map[i][j] == 0) {
                pos = false;
                break;
            }
        }
        if (pos == false) break;
    }
    if (pos == true) cout << res;
    else cout << -1;
}
