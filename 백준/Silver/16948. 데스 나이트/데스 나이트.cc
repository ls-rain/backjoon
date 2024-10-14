#include <iostream>
#include <queue>
using namespace std;

int dy[] = {-2, -2, 0, 0, 2, 2};
int dx[] = {-1, 1, -2, 2, -1, 1};
int n, r1, c1, r2, c2, dist[201][201];
const int INF = 987654321;

void bfs(int r1, int c1, int r2, int c2) {
    queue<pair<int, int> > q;
    q.push({r1, c1});
    dist[r1][c1] = 0;
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for (int i = 0; i < 6; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
            if (dist[ny][nx] > dist[y][x] + 1) {
                dist[ny][nx] = dist[y][x] + 1;
                q.push({ny, nx});
            }
        }
    }
}

int main() {
    cin >> n;
    cin >> r1 >> c1 >> r2 >> c2;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) dist[i][j] = INF;
    bfs(r1, c1, r2, c2);
    if (dist[r2][c2] == INF) cout << -1;
    else cout << dist[r2][c2];
}
