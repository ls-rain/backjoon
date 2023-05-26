#include<stdio.h>
#include<vector>
#include <algorithm>
#include<memory.h>
#include<queue>


using namespace std;

vector<pair<int, int>> virus, act_virus;
int n, m, total_cnt;
int c_min = 2147000000;
int map[51][51];
int ch[51][51], ch2[51][51];
int dist[51][51];
int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };
queue<pair<int, int>> q;


void BFS() {
	memset(dist, -1, sizeof(dist));

	//m개의 바이러스 큐에 삽입
	for (int i = 0; i < act_virus.size(); i++) {
		int a = act_virus[i].first;
		int b = act_virus[i].second;
		q.push(make_pair(a, b));
		dist[a][b] = 0;
	}

	int cnt = 0, tmp = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (map[nx][ny] != 1 && dist[nx][ny] == -1) {
				q.push(make_pair(nx, ny));
				dist[nx][ny] = dist[x][y] + 1;
				cnt++;
				tmp = dist[nx][ny];
			}
		}
	}

	if (total_cnt - m == cnt) {
		if (tmp < c_min) c_min = tmp;
	}
}

void DFS(int L, int cnt) {
	//바이러스 중 활성화 시킬 m개의 바이러스 구하기
	if (cnt == m) {
		BFS();
		return;
	}
	else {
		for (int i = L; i < virus.size(); i++) {
			if (ch[virus[i].first][virus[i].second] == 0) {
				ch[virus[i].first][virus[i].second] = 1;
				act_virus.push_back(make_pair(virus[i].first, virus[i].second));
				DFS(i, cnt + 1);
				act_virus.pop_back();
				ch[virus[i].first][virus[i].second] = 0;
			}
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 2) virus.push_back(make_pair(i, j));
			if (map[i][j] != 1) total_cnt++;
		}
	}

	DFS(0, 0);

	if (c_min != 2147000000) printf("%d", c_min);
	else printf("-1");

	return 0;
}