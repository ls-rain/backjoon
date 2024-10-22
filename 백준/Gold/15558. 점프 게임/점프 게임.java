import java.io.*;
import java.util.*;

public class Main {


    static int n, k;
    static boolean[][] arr;
    static class Pair{
        int y, x, time;
        Pair(int y, int x, int time){
            this.y = y;
            this.x = x;
            this.time = time;
        }
    }

    static int bfs(){
        Queue<Pair> q = new LinkedList<>();
        q.add(new Pair(0, 0, 0));
        while(!q.isEmpty()){
            int y = q.peek().y;
            int x = q.peek().x;
            int time = q.peek().time;
            q.poll();
            if(x >= n) return 1;
            if(!arr[y][x + 1]){
                arr[y][x + 1] = true;
                q.add(new Pair(y, x + 1, time+1));
            }
            if(x - 1 > time && !arr[y][x - 1]){
                arr[y][x - 1] = true;
                q.add(new Pair(y, x - 1, time+1));
            }
            if(!arr[1 - y][x + k]){
                arr[1 - y][x + k] = true;
                q.add(new Pair(1 - y, x + k, time+1));
            }
        }
        return 0;
    }

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        arr = new boolean[2][n + 1 + k];
        for(int i = 0; i < 2; i++){
            String str = br.readLine();
            for(int j = 0; j < n; j++){
                if(str.charAt(j) == '0'){
                    arr[i][j] = true;
                }
            }
        }
        System.out.println(bfs());

    }
}