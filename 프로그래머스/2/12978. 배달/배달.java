import java.util.*;

class Solution {
    int answer = 0;
    int[][] roads;
    int[] dist;
    ArrayList<Info>[] graph;
    class Info{
        int cost, v;
        Info(int cost, int v){
            this.cost = cost;
            this.v = v;
        }
    }
    void dijkstra(){
        PriorityQueue<Info> pq = new PriorityQueue<>((o1, o2) -> o1.cost - o2.cost);
        // 탐색 시작 {최소거리, 도착위치}
        pq.add(new Info(0, 1));
        dist[1] = 0;
        while(!pq.isEmpty()){
            Info info = pq.poll();
            int cost = info.cost;
            int v = info.v;
            if(cost > dist[v]) continue;
            for(int i = 0; i < graph[v].size(); i++){
                Info nxt = graph[v].get(i);
                int ncost = nxt.cost;
                int nxtNode = nxt.v;
                if(dist[nxtNode] > cost + ncost){
                    dist[nxtNode] = cost + ncost;
                    pq.add(new Info(dist[nxtNode], nxtNode));
                }
            }
        }
    }
    public int solution(int n, int[][] road, int K) {
        roads = road;
        dist = new int[n+1];
        graph = new ArrayList[n+1];
        // 분리 집합으로 초기화
        for(int i = 1; i <= n; i++){
            graph[i] = new ArrayList<>();
            dist[i] = 500001;
        }
        for(int i = 0; i < road.length; i++){
            int a = road[i][0];
            int b = road[i][1];
            int c = road[i][2];
            graph[a].add(new Info(c, b));
            graph[b].add(new Info(c, a));
        }

        
        dijkstra();
        for(int i = 1; i <= n; i++){
            if(dist[i] <= K) answer++;
        }
        
        return answer;
    }
}