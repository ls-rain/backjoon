#include <iostream>
using namespace std;

int n, m, visited1[25][25], visited2[25][25];
char board[21][21];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int dfs(int cnt, int y1, int x1, int y2, int x2) {
    if (cnt > 10) return -1;
    bool flag1 = false, flag2 = false;
    if (y1 < 1 || y1 > n || x1 < 1 || x1 > m) flag1 = true;
    if (y2 < 1 || y2 > n || x2 < 1 || x2 > m) flag2 = true;

    if (flag1 && flag2) return -1;
    if (flag1 || flag2) return cnt;
    int ans = -1;
    for (int i = 0; i < 4; i++) {
        int ny1 = y1 + dy[i];
        int nx1 = x1 + dx[i];
        int ny2 = y2 + dy[i];
        int nx2 = x2 + dx[i];
        if (board[ny1][nx1] == '#') {
            ny1 = y1;
            nx1 = x1;
        }
        if (board[ny2][nx2] == '#') {
            ny2 = y2;
            nx2 = x2;
        }
        int tmp = dfs(cnt + 1, ny1, nx1, ny2, nx2);
        if (tmp == -1) continue;
        if (ans == -1 || ans > tmp) ans = tmp;
    }
    return ans;
}

int main() {
    cin >> n >> m;
    int idx = 0;
    int y1, y2, x1, x2;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> board[i][j];
            if (board[i][j] == 'o') {
                if (idx == 0) {
                    y1 = i;
                    x1 = j;
                    idx += 1;
                } else {
                    y2 = i;
                    x2 = j;
                }
            }
        }
    }

    cout << dfs(0, y1, x1, y2, x2);
}
