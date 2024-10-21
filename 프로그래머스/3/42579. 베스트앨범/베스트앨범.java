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
        List<Music> musicList = new ArrayList<>();
        HashMap<String, Integer> m = new HashMap<>();
        for(int i = 0; i < plays.length; i++){
            m.put(genres[i], m.getOrDefault(genres[i], 0) + plays[i]);
            musicList.add(new Music(i, genres[i], plays[i]));
        }
        Collections.sort(musicList, (o1, o2) -> (o2.play - o1.play));
        List<Map.Entry<String, Integer>> genreList = new ArrayList<>(m.entrySet());
        Collections.sort(genreList, (o1, o2) -> (o2.getValue() - o1.getValue()));
        List<Integer> res = new ArrayList<>();
        for(int i = 0; i < genreList.size(); i++){
            int cnt = 0;
            for(int j = 0; j < musicList.size(); j++){
                if(musicList.get(j).visited) continue;
                if(musicList.get(j).genre.equals(genreList.get(i).getKey())){
                    res.add(musicList.get(j).idx);
                    musicList.get(j).visited = true;
                    cnt++;
                }
                if(cnt == 2) break;
            }
        }
        return res.stream().mapToInt(Integer::intValue).toArray();
    }
}