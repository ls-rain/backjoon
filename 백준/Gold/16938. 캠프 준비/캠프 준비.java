import java.util.*;
import java.io.*;

public class Main {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static void main(String[] args) throws IOException {
        new Main().solution();
    }
    int[] arr;
    int n, l, r, x, res;
    void solution() throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        l = Integer.parseInt(st.nextToken());
        r = Integer.parseInt(st.nextToken());
        x = Integer.parseInt(st.nextToken());
        arr = new int[n+1];
        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < n; i++){
            arr[i] = Integer.parseInt(st.nextToken());
        }
        for(int i = 0; i < n; i++) dfs(i, 1, arr[i], arr[i], arr[i]);
        System.out.println(res);
    }
    void dfs(int idx, int cnt, int sum, int min, int max){
        if(sum >= l && sum <= r && cnt <= n){
            if(max - min >= x) res++;
        }
        else if(sum > r && cnt > n) return;
        for(int i = idx + 1; i < n; i++){
            dfs(i, cnt + 1, sum + arr[i], Math.min(arr[i], min), Math.max(arr[i], max));
        }
    }
}
