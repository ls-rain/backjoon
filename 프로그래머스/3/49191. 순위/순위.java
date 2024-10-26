import java.util.*;

class Solution {
    int answer = 0;

    public int solution(int n, int[][] results) {
        int[][] graph = new int[n+1][n+1];
        for(int i = 0; i < results.length; i++){
            int w = results[i][0];
            int l = results[i][1];
            graph[w][l] = 1;
            graph[l][w] = -1;
        }
        for(int k = 1; k <= n; k++){
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <=n; j++){
                    if(graph[i][k] == 1 && graph[k][j] == 1){
                        graph[i][j] = 1;
                        graph[j][i] = -1;
                    }
                    if(graph[i][k] == -1 && graph[k][j] == -1){
                        graph[i][j] = -1;
                        graph[j][i] = 1;
                    }
                }
            }
        }
        for(int i = 1; i <= n; i++){
            int cnt = 0;
            for(int j = 1; j <=n; j++){
                if(graph[i][j] == 0) cnt++;
            }
            if(cnt == 1) answer++;
        }
        return answer;
    }
}