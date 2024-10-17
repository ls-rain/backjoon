#include <iostream>
#include <queue>
using namespace std;

char map[9][9];
int dy[] = {-1, 0, 1, 0, 1, -1, 1, -1, 0};
int dx[] = {0, 1, 0, -1, 1, 1, -1, -1, 0};

int bfs() {
    queue<pair<int, int> > q;
    q.push({7, 0});
    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            int y = q.front().first;
            int x = q.front().second;
            q.pop();
            if (y == 0) return 1;
            // 캐릭터 이동
            for (int i = 0; i < 9; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if (ny >= 8 || ny < 0 || nx >= 8 || nx < 0) continue;
                if (map[ny][nx] == '#') continue;
                if (ny - 1 >= 0 && map[ny - 1][nx] == '#') continue;
                q.push({ny, nx});
            }
        }
        // 벽 이동
        // for (int i = 7; i >= 1; i--)
        //     for (int j = 0; j < 8; j++) map[i][j] = map[i - 1][j];
        // for (int i = 0; i < 8; i++) map[0][i] = '.';
        bool tag[9][9] = {false,};
        for (int i = 0; i < 8; i++)
            for (int j = 0; j < 8; j++)
                if (map[i][j] == '#') tag[i + 1][j] = true;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (tag[i][j] == true) map[i][j] = '#';
                else map[i][j] = '.';
            }
        }
    }
    return 0;
}


int main() {
    for (int i = 0; i < 8; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < 8; j++) map[i][j] = s[j];
    }
    cout << bfs();
}
