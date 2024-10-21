class Solution {
    int t, res;
    void dfs(int idx, int sum, int[] numbers){
        if(idx == numbers.length - 1){
            if(sum - numbers[idx] == t || sum + numbers[idx] == t) res++;
            return;
        }
        dfs(idx + 1, sum - numbers[idx], numbers);
        dfs(idx + 1, sum + numbers[idx], numbers);
    }
    
    public int solution(int[] numbers, int target) {
        t = target;
        dfs(0, 0, numbers);
        return res;
    }
}