#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

int n, m, area;
int block[51][51];
bool visited[51][51];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int bfs(int y, int x) {
	queue<pair<int, int>> q;
	q.push({ y,x });
	visited[y][x] = true;
	int cnt = 1;

	while (!q.empty()) {
		int Y = q.front().first;
		int X = q.front().second;
		q.pop();
		int bit = 1;
		for (int i = 0; i < 4; i++) {
			if (!(block[Y][X] & bit)) {
				int next_y = Y + dy[i];
				int next_x = X + dx[i];
				if (!(0 <= next_y && next_y < m && 0 <= next_x && next_x < n)) continue;
				if (!visited[next_y][next_x]) {
					cnt++;
					visited[next_y][next_x] = true;
					q.push({ next_y, next_x });
				}				
			}
			bit <<= 1;
		}
	}
	return cnt;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> block[i][j];
		}
	}
	int cnt = 0;
	for (int i = 0; i < m; i++) 
		for(int j = 0; j<n; j++)
			if (!visited[i][j]) {
				area = max(area, bfs(i,j));
				cnt++;
			}
	cout << cnt << "\n" << area << "\n";

	for(int i = 0; i<m; i++)
		for(int j = 0; j<n; j++)
			for(int k = 1; k<=8; k<<=1)
				if (block[i][j] & k) {
					memset(visited, false, sizeof(visited));
					block[i][j] -= k;
					area = max(area, bfs(i, j));
					block[i][j] += k;
				}
	cout << area;
}