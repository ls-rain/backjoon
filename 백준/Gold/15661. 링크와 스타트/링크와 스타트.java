import java.util.*;
import java.io.*;


public class Main {

    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static void main(String[] args) throws IOException {
        new Main().solution();
    }

    int N, res = 987654321;
    int[][] map;
    boolean[] check;
    void dfs(int idx, int n){
        int score1 = 0, score2 = 0;
        if(n >= 1 && n <=  N/2){
            for(int i = 0; i < N; i++){
                for(int j = i + 1; j < N; j++){
                    if(check[i] && check[j]) score1 += map[i][j] + map[j][i];
                    else if(!check[i] && !check[j]) score2 += map[i][j] + map[j][i];
                }
            }
            res = Math.min(res, Math.abs(score1 - score2));
        }
        for(int i = idx; i < N; i++){
            check[i] = true;
            dfs(i + 1, n + 1);
            check[i] = false;
        }
    }

    void solution() throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        map = new int[N + 1][N + 1];
        check = new boolean[N + 1];
        for(int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j < N; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        dfs(0,0);
        System.out.println(res);
    }

}
