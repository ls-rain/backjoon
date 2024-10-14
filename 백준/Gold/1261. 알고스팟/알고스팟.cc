#include <iostream>
#include <queue>
using namespace std;

int m, n, map[101][101], visited[101][101];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, -1, 0, 1};

void bfs() {
    queue<pair<int, int> > q;
    q.push(make_pair(1, 1));
    visited[1][1] = 0;
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (0 >= ny || ny > n || 0 >= nx || nx > m) continue;
            if (!map[ny][nx]) {
                if (visited[ny][nx] > visited[y][x]) {
                    visited[ny][nx] = visited[y][x];
                    q.push(make_pair(ny, nx));
                }
            } else {
                if (visited[ny][nx] > visited[y][x] + 1) {
                    visited[ny][nx] = visited[y][x] + 1;
                    q.push(make_pair(ny, nx));
                }
            }
        }
    }
}

int main() {
    cin >> m >> n;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= m; j++) {
            map[i][j] = s[j - 1] - '0';
            visited[i][j] = 987654321;
        }
    }
    bfs();
    cout << visited[n][m];
}
