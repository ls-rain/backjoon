import java.util.*;
import java.io.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {
        new Main().solution();

    }
    int n, m, res = 0;
    int[][] map;
    int[] dy = {-1, 0, 1, 0};
    int[] dx = {0, -1, 0, 1};
    static Map<Integer, Integer> group = new HashMap<>();

    void solution() throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        map = new int[n + 1][m + 1];
        for(int i = 0; i < n; i++){
            StringTokenizer s = new StringTokenizer(br.readLine());
            for(int j = 0; j < m; j++){
                map[i][j] = Integer.parseInt(s.nextToken());
            }
        }
        int key = 2;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(map[i][j] == 1){
                    bfs(i, j, key++);
                }
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(map[i][j] == 0){
                    Set<Integer> s = new HashSet<>();
                    int size = 1;
                    for(int k = 0; k < 4; k++){
                        int ny = i + dy[k];
                        int nx = j + dx[k];
                        if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
                        if(map[ny][nx] != 0){
                            s.add(map[ny][nx]);
                        }
                    }
                    for(int cur : s) size += group.get(cur);
                    res = Math.max(res, size);
                }
            }
        }
        System.out.println(res);
    }

    void bfs(int cy, int cx, int key){
        Queue<Pair> q = new LinkedList<>();
        q.add(new Pair(cy, cx));
        int sum  = 1;
        map[cy][cx] = key;
        while(!q.isEmpty()){
            Pair p = q.poll();
            int y = p.y;
            int x = p.x;
            for(int i = 0; i < 4; i++){
                int ny = y + dy[i];
                int nx = x + dx[i];
                if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
                if(map[ny][nx] == 1){
                    q.add(new Pair(ny, nx));
                    map[ny][nx] = key;
                    sum++;
                }
            }
        }
        group.put(key, sum);
    }

    class Pair{
        int y, x;
        Pair(int y, int x){
            this.y = y;
            this.x = x;
        }
    }
}
