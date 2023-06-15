#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
using namespace std;

const int inf = 987654321;
vector<pair<int, int>> car, park;
vector<int> v[101];
int r, c, visited[51][51], dist[101][101], match[101];
bool matched[101];
char area[51][51];
int dy[] = { -1,0,1,0 };
int dx[] = { 0,-1,0,1 };

void bfs(int y, int x, int index) {
	queue<pair<int, int>> q;
	q.push({ y,x });
	visited[y][x] = 0;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
			if (visited[ny][nx] == -1 && area[ny][nx] != 'X') {
				visited[ny][nx] = visited[y][x] + 1;
				q.push({ ny,nx });
			}
		}
	}
	for (int i = 0; i < park.size(); i++) {
		if (visited[park[i].first][park[i].second] == -1) dist[index][i] = inf;
		else {
			dist[index][i] = visited[park[i].first][park[i].second];
			v[index].push_back(i);
		}
	}
}

bool dfs(int here, int time) {
	for (int i : v[here]) {
		if (matched[i] || dist[here][i] > time) continue;
		matched[i] = true;
		if (match[i] == -1 || dfs(match[i], time)) {
			match[i] = here;
			return true;
		}
	}
	return false;
}
int main() {
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < c; j++) {
			area[i][j] = s[j];
			if (area[i][j] == 'C') car.push_back({ i,j });
			else if (area[i][j] == 'P') park.push_back({ i,j });
		}
	}
	if (car.size() > park.size()) {
		cout << -1;
		return 0;
	}
	for (int i = 0; i < car.size(); i++) {
		memset(visited, -1, sizeof(visited));
		bfs(car[i].first, car[i].second, i);
	}
	int res = -1;
	int left = 0;
	int right = 51 * 51;
	while (left <= right) {
		int mid = (left + right) / 2;
		int count = 0;
		fill(match, match + 101, -1);
		for (int i = 0; i < car.size(); i++) {
			fill(matched, matched + 101, false);
			if (dfs(i, mid)) count++;
		}
		if (count == car.size()) {
			res = mid;
			right = mid - 1;
		}
		else left = mid + 1;
	}
	cout << res;

}