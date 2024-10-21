import java.util.*;
class Solution {
    public int solution(String name) {
        int answer = 0;
        int change = 0;
        int move = name.length() - 1;
        for(int i = 0; i < name.length(); i++){
            change += Math.min(name.charAt(i) - 'A', 'Z' - name.charAt(i) + 1);
            int idx = i + 1;
            while(idx < name.length() && name.charAt(idx) =='A') idx++;
            // 순서대로 왔다가 뒤로 돌아감
            move = Math.min(move, 2*i + name.length() - idx);
            // 반대
            move = Math.min(move, (name.length() - idx)*2 + i);
        }
        answer = move + change;
        return answer;
    }
}