#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int t, l, dist[301][301];
int chessy, chessx, targety, targetx;
int dy[] = {1, 2, 1, 2, -2, -1, -2, -1};
int dx[] = {2, 1, -2, -1, -1, -2, 1, 2};

void solution() {
    queue<pair<int, int> > q;
    q.push({chessy, chessx});
    dist[chessy][chessx] = 0;
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        if (y == targety && x == targetx) {
            cout << dist[y][x] << '\n';
            return;
        }
        for (int i = 0; i < 8; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny >= l || nx >= l || ny < 0 || nx < 0) continue;
            if (dist[ny][nx]) continue;
            q.push({ny, nx});
            dist[ny][nx] = dist[y][x] + 1;
        }
    }
}

int main() {
    cin >> t;
    while (t--) {
        memset(dist, 0, sizeof(dist));
        cin >> l;
        cin >> chessx >> chessy;
        cin >> targetx >> targety;
        solution();
    }
}
