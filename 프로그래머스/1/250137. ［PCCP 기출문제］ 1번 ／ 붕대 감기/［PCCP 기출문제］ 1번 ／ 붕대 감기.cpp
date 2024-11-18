#include <string>
#include <vector>
#include <map>
using namespace std;
int answer = 0;
int times, x, y, maxH;
map<int ,int> m;

// (시간, x 회복(1초마다), y 회복), (최대 체력), (공격 시간, 피해량, ...)
int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    for(int i = 0; i < attacks.size(); i++) m[attacks[i][0]] = attacks[i][1];
    times = bandage[0];
    x = bandage[1];
    y = bandage[2];
    maxH = health;
    int cur = 0;
    int link = 0;
    while(cur != attacks[attacks.size() - 1][0]){
        cur++;
        if(m[cur]) {
            link = 0;
            health -= m[cur];
            if(health <= 0) return -1;
            continue;
        }
        link++;
        health += x;
        if(link == times) {
            link = 0;
            health += y;
        }
        if(health > maxH) health = maxH;
        
    }
    return health;
}