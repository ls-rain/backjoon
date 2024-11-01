import java.util.*;

class Solution {
    
    class Music{
        int idx;
        String genre;
        int play;
        boolean visited;
        Music(int i, String s, int p){
            this.idx = i;
            this.genre = s;
            this.play = p;
        }
    }
    
    public int[] solution(String[] genres, int[] plays) {
        int[] answer = {};
        List<Music> playList = new ArrayList<>();
        Map<String, Integer> m = new HashMap<>();
        for(int i = 0; i < genres.length; i++){
            m.put(genres[i], m.getOrDefault(genres[i], 0) + plays[i]);
            playList.add(new Music(i, genres[i], plays[i]));
        }
        Collections.sort(playList, (a, b) -> b.play - a.play);
        List<Map.Entry<String, Integer>> genreList = new ArrayList<>(m.entrySet());
        Collections.sort(genreList, (o1, o2) -> (o2.getValue() - o1.getValue()));
        List<Integer> res = new ArrayList<>();
        for(int i = 0; i < genreList.size(); i++){
            int cnt = 0;
            for(int j = 0; j < playList.size(); j++){
                if(playList.get(j).genre.equals(genreList.get(i).getKey())){
                    cnt++;
                    res.add(playList.get(j).idx);
                }
                if(cnt == 2) break;
            }
        }
        return res.stream().mapToInt(Integer::intValue).toArray();
    }
}