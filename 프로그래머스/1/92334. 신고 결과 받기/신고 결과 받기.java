import java.util.*;

class Solution {
    // 이용자아이디 신고한아이디

    public int[] solution(String[] id_list, String[] report, int k) {
        int[] answer = new int[id_list.length];
        Map<String, Integer> bad = new HashMap<>();
        Map<String, Set<String>> pair = new HashMap<>();
        for(int i = 0; i < id_list.length; i++){
            bad.put(id_list[i], 0);
            pair.put(id_list[i], new HashSet<>());
        }
        for(int i = 0; i < report.length; i++){
            StringTokenizer st = new StringTokenizer(report[i]);
            String a = st.nextToken();
            String b = st.nextToken();
            if(pair.get(a).add(b)){
                bad.put(b, bad.get(b) + 1);
            }
        }
        for(int i = 0; i < report.length; i++){
            StringTokenizer st = new StringTokenizer(report[i]);
            String a = st.nextToken();
            String b = st.nextToken();
            if(bad.get(b) < k){
                pair.get(a).remove(b);
            }
        }
        for(int i = 0; i < id_list.length; i++){
            answer[i] = pair.get(id_list[i]).size();
        }
        return answer;
    }
}