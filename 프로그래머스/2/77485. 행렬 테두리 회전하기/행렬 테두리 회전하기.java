import java.util.*;

class Solution {
    ArrayList<Integer> res = new ArrayList<>();
    public int[] solution(int rows, int columns, int[][] queries) {
        int[][] map = new int[rows+1][columns+1];
        for(int i = 1; i <= rows; i++){
            for(int j = 1; j <= columns; j++){
                map[i][j] = (i-1)*columns + j;
            }
        }
        for(int i = 0; i < queries.length; i++){
            int y1 = queries[i][0];
            int x1 = queries[i][1];
            int y2 = queries[i][2];
            int x2 = queries[i][3];
            int tmp = map[y2][x1];
            int minV = rows * columns;
            for(int x = x1; x < x2; x++){
                map[y2][x] = map[y2][x + 1];
                minV = Math.min(minV, map[y2][x]);
            }
            for(int y = y2; y > y1; y--){
                map[y][x2] = map[y-1][x2];
                minV = Math.min(minV, map[y][x2]);
            }
            for(int x = x2; x > x1; x--){
                map[y1][x] = map[y1][x-1];
                minV = Math.min(minV, map[y1][x]);
            }
            for(int y = y1; y < y2; y++){
                map[y][x1] = map[y + 1][x1];
                minV = Math.min(minV, map[y][x1]);
            }
            map[y2-1][x1] = tmp;
            minV = Math.min(minV, map[y2 -1][x1]);
            res.add(minV);
        }
        
        return res.stream().mapToInt(Integer::intValue).toArray();
    }
}