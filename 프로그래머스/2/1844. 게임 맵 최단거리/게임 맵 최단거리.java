import java.util.*;

class Solution {
    int answer = 0;
    int dy[] = {-1, 0, 1, 0};
    int dx[] = {0, -1, 0, 1};
    int[][] visited = new int[101][101];
    int map[][];
    class Pair{
        int y;
        int x;
        Pair(int y, int x){
            this.y = y;
            this.x = x;
        }
    }
    public void bfs(){
        Queue<Pair> q = new LinkedList<>();
        q.add(new Pair(0, 0));
        visited[0][0] = 1;
        while(!q.isEmpty()){
            int y = q.peek().y;
            int x = q.peek().x;
            q.poll();
            for(int i = 0; i < 4; i++){
                int ny = y + dy[i];
                int nx = x + dx[i];
                if(ny < 0 || ny >= map.length || nx < 0 || nx >= map[0].length) continue;
                if(map[ny][nx] == 0 || visited[ny][nx] != -1) continue;
                q.add(new Pair(ny, nx));
                visited[ny][nx] = visited[y][x] + 1;
                
            }
        }
    }
    
    public int solution(int[][] maps) {
        for(int i = 0; i < maps.length; i++){
            for(int j = 0; j < maps[0].length; j++) visited[i][j] = -1;
        }
        map = maps;
        bfs();
        return visited[maps.length - 1][maps[0].length - 1];
    }
}