#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, map[101][101], group[101][101];
int country = 1;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, -1, 0, 1};
struct info{
	int y, x;
	int num;
};
vector<info> edge;

void bfs(int y, int x){
	queue<pair<int, int> > q;
	q.push({y,x});
	group[y][x] = country;
	while(!q.empty()){
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for(int i = 0; i < 4; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];
			if(ny < 0 || ny >=n || nx < 0 || nx >= n) continue;
			if(!group[ny][nx] && map[ny][nx]){
				group[ny][nx] = country;
				q.push({ny,nx});
			}
		}
	}
	country++;
}

int main(){
	cin >> n;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++) cin >> map[i][j];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			if(map[i][j] && !group[i][j]) bfs(i,j);
			
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(group[i][j]){
				bool pos = false;
				for(int k = 0; k < 4; k++){
					int ny = i + dy[k];
					int nx = j + dx[k];
					if(ny <0 || ny >=n || nx <0 || nx >= n) continue;
					if(!map[ny][nx]) pos = true;
				}
				if(pos) edge.push_back({i,j,group[i][j]});
			}
		}
	}
	int res = 987654321;
	for(int i = 0; i < edge.size(); i++){
		for(int j = i + 1; j < edge.size(); j++){
			if(edge[i].num == edge[j].num) continue;
			int dist = abs(edge[i].y - edge[j].y) + abs(edge[i].x - edge[j].x);
			res = min(res, dist);
		}
	}
	cout << res-1;
}