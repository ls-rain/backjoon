import java.util.*;
import java.io.*;

public class Main {

    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static void main(String[] args) throws IOException {
        new Main().solution();
    }

    int n, x, res, cnt;
    int[] arr;
    void solution() throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        x = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        arr = new int[n + 1];
        for(int i = 0; i < n; i++) arr[i] = Integer.parseInt(st.nextToken());
        ArrayList<Integer> list = new ArrayList<>();
        int s = 0, e = 0;
        int sum = arr[0];
        while(e < n){
            if(e - s == x - 1){
                res = Math.max(res, sum);
                list.add(sum);
                sum -= arr[s];
                s++;
            }
            else if(e - s < x - 1){
                e++;
                sum += arr[e];
            }
        }
        Collections.reverse(list);
        for(int i = 0; i < list.size(); i++){
            if(res == list.get(i)) cnt++;
        }
        if(res == 0) System.out.println("SAD");
        else {
            System.out.println(res);
            System.out.println(cnt);
        }
    }
}
