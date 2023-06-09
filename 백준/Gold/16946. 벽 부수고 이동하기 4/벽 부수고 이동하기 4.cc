#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, map[1001][1001];
bool visited[1001][1001];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, -1, 0, 1};


void bfs(int y, int x){
	queue<pair<int, int> > q;
	q.push({y,x});
	vector<pair<int, int> > wall;
	visited[y][x] = true;
	int cnt = 1;
	while(!q.empty()){
		int cur_y = q.front().first;
		int cur_x = q.front().second;
		q.pop();
		for(int i = 0; i<4; i++){
			int ny = cur_y + dy[i];
			int nx = cur_x + dx[i];
			if(ny<0 || nx<0 || ny>=n || nx>=m) continue;
			if(map[ny][nx] == 0 &&!visited[ny][nx]){
				cnt++;
				q.push({ny, nx});
				visited[ny][nx] = true;
			}
			else if(map[ny][nx] != 0 && !visited[ny][nx]){
				visited[ny][nx] = true;
				wall.push_back({ny, nx});
			}
		}
	}
	for(int i = 0; i<wall.size(); i++){
		map[wall[i].first][wall[i].second] += cnt;
		visited[wall[i].first][wall[i].second] = false;
	}
}

int main(){
	cin >> n >> m;
	for(int i = 0; i<n; i++){
		string s;
		cin >> s;
		for(int j = 0; j<m; j++){
			map[i][j] = s[j] - '0';			
		}
	}
	for(int i = 0; i<n; i++)
		for(int j = 0; j<m; j++)
			if(map[i][j] == 0 && !visited[i][j]) bfs(i,j);
	for(int i = 0; i<n; i++){
		for(int j = 0; j<m; j++){
			cout << map[i][j]%10;
		}
		cout << '\n';
	}
}