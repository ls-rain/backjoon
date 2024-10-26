import java.util.*;

// 이익의 10% -> 추천인   /   90% -> 자신
// (자신의 이익의 90%) + 추천하여 가입시킨 판매원의 10%

class Solution {
    Map<String, String> m = new HashMap<>();
    Map<String, Integer> res = new HashMap<>();
    public int[] solution(String[] enroll, String[] referral, String[] seller, int[] amount) {
        int[] answer = new int[enroll.length];
        
        for(int i = 0; i < enroll.length; i++){
            m.put(enroll[i], referral[i]);
        }
        for(int i = 0; i < seller.length; i++){
            sell(seller[i], amount[i] * 100);
        }
        for(int i = 0; i < enroll.length; i++){
            answer[i] = res.getOrDefault(enroll[i], 0);
        }
        return answer;
    }
    
    void sell(String person, int won){
        int nxt = won / 10;
        res.put(person, res.getOrDefault(person, 0) + won - nxt);
        if(nxt > 0 && m.containsKey(person)) sell(m.get(person), nxt);
    }
}