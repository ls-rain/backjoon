import java.util.*;

class Solution {
    public int solution(int[][] jobs) {
        int answer = 0, i =0;
        int time = 0;
        PriorityQueue<ArrayList<Integer>> pq = new PriorityQueue<>((a, b) -> a.get(1) - b.get(1));
        Arrays.sort(jobs, (a, b) -> a[0] - b[0]);
        while(i < jobs.length || !pq.isEmpty()){
            if(i < jobs.length && time >= jobs[i][0]){
                ArrayList<Integer> l = new ArrayList<>();
                l.add(jobs[i][0]);
                l.add(jobs[i][1]);
                pq.add(l);
                i++;
                continue;
            }
            if(!pq.isEmpty()){
                time += pq.peek().get(1);
                int exec = time - pq.peek().get(0);
                answer += exec;
                pq.poll();
            }
            else time = jobs[i][0];
        }
        return answer/jobs.length;
    }
}