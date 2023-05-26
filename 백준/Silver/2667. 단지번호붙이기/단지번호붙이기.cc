#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, cnt, map[26][26];
bool visited[26][26];
int dy[] = {-1, 0 , 1, 0};
int dx[] = {0, -1, 0, 1};
vector<int> group;

void dfs(int y, int x) {
	for (int i = 0; i < 4; i++) {
		int next_y = y + dy[i];
		int next_x = x + dx[i];
		if(next_y>=n || next_y <0 || next_x >=n || next_x<0) continue;
		if (map[next_y][next_x] == 1 && visited[next_y][next_x] == false) {
			visited[next_y][next_x] = true;
			cnt++;
			dfs(next_y, next_x);
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < s.length(); j++) map[i][j] = s[j] - '0';
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (visited[i][j] == false && map[i][j] == 1) {
				visited[i][j] = true;
				cnt = 1;
				dfs(i, j);
				group.push_back(cnt);
			}
		}
	sort(group.begin(), group.end());
	cout << group.size() << '\n';
	for (auto i : group) cout << i << '\n';
}