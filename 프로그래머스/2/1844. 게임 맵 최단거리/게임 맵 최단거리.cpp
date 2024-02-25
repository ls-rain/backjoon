#include<vector>
#include <queue>
using namespace std;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, -1, 0, 1};
int visited[101][101];
int map[101][101];
int answer = 0;

void bfs(vector<vector<int> > maps){
    queue<pair<int, int>> q;
    q.push({0,0});
    map[0][0] = 1;
    while(!q.empty()){       
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if(ny < 0 || ny >= maps.size() || nx < 0 || nx >= maps[0].size()) continue;
            if(!maps[ny][nx] || visited[ny][nx]) continue;
            visited[ny][nx] = 1;
            q.push({ny, nx});
            map[ny][nx] = map[y][x] + 1;
        }
    }
    if(!map[maps.size()-1][maps[0].size()-1]) answer = -1;
    else answer = map[maps.size()-1][maps[0].size()-1];
}

int solution(vector<vector<int> > maps)
{
    bfs(maps);
    return answer;
}