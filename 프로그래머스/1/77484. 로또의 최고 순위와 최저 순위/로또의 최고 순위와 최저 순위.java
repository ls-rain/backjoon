import java.util.*;

class Solution {
    int[] answer = new int[2];

    public int[] solution(int[] lottos, int[] win_nums) {
        Set<Integer> s = new HashSet<>();
        for(int i = 0; i < win_nums.length; i++){
            s.add(win_nums[i]);
        }
        int maxV = 6;
        int minV = 1;
        int cnt = 0;
        for(int i = 0; i < lottos.length; i++){
            if(lottos[i] == 0) cnt++;
            s.remove(lottos[i]);
        }
        answer[0] = s.size() + 1 - cnt;
        answer[1] = s.size() + 1;
        if(answer[0] > 6) answer[0] = 6;
        if(answer[1] > 6) answer[1] = 6;
        return answer;
    }
}