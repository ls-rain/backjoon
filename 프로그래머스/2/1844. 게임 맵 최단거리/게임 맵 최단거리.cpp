#include <vector>
#include <queue>
using namespace std;

int answer = -1;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, -1, 0, 1};
int visited[101][101];

void bfs(vector<vector<int> > maps){
    queue<pair<int, int> > q;
    q.push({0,0});
    visited[0][0] = 1;
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= maps.size() || nx >= maps[0].size()) continue;
            if(maps[ny][nx] == 1 && !visited[ny][nx]){
                visited[ny][nx] = visited[y][x] + 1;
                q.push({ny, nx});
            }
        }
    }
}

int solution(vector<vector<int> > maps){
    bfs(maps);
    if(visited[maps.size() - 1][maps[0].size() - 1]){
        return visited[maps.size() - 1][maps[0].size() - 1];
    }
    else return -1;
}