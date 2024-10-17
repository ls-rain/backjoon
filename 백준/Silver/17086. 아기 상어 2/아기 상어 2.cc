#include <iostream>
#include <queue>
using namespace std;

int n, m, map[51][51];
int dy[] = {-1, 0, 1, 0, -1, -1, 1, 1};
int dx[] = {0, 1, 0, -1, 1, -1, 1, -1};

int res;

int bfs(int cy, int cx) {
    queue<pair<int, int> > q;
    q.push({cy, cx});
    int dist[51][51] = {0};
    dist[cy][cx] = 0;
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        if (map[y][x] == 1) return dist[y][x];
        for (int i = 0; i < 8; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny > n || ny < 0 || nx > m || nx < 0) continue;
            if (dist[ny][nx]) continue;
            dist[ny][nx] = dist[y][x] + 1;
            q.push({ny, nx});
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 1) continue;
            res = max(res, bfs(i, j));
        }
    }
    cout << res;
}
