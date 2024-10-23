import java.util.*;
import java.io.*;

public class Main {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {
        new Main().solution();
    }

    int n, m;
    int[][] map;
    ArrayList<Integer> arr;
    int[] parent;

    void solution() throws IOException {
        n = Integer.parseInt(br.readLine());
        m = Integer.parseInt(br.readLine());
        map = new int[n + 1][n + 1];
        for (int i = 1; i <= n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 1; j <= n; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        arr = new ArrayList<>();
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < m; i++) arr.add(Integer.parseInt(st.nextToken()));
        parent = new int[n + 1];
        for (int i = 1; i <= n; i++) parent[i] = i;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (map[i][j] == 1) {
                    int a = getParent(i);
                    int b = getParent(j);
                    if (a > b) {
                        parent[j] = a;
                    }
                    else if (b > a) parent[i] = b;
                }
            }
        }
        for (int i = 0; i < m; i++) {
            if (getParent(arr.get(i)) != parent[arr.get(0)]) {
                System.out.println("NO");
                return;
            }
        }
        System.out.println("YES");
    }

    int getParent(int node) {
        if (node == parent[node]) return node;
        return parent[node] = getParent(parent[node]);
    }

}
