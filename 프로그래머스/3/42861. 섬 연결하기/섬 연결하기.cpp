#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 101
using namespace std;
int parent[MAX];

int getParent(int node){
    if(node == parent[node]) return node;
    return parent[node] = getParent(parent[node]);
}

bool cmp(vector<int> a, vector<int> b){
    return a[2] < b[2];
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    sort(costs.begin(), costs.end(), cmp);
    for(int i = 0; i < n; i++) parent[i] = i;
    for(int i = 0; i < costs.size(); i++){
        int v1 = getParent(costs[i][0]);
        int v2 = getParent(costs[i][1]);
        if(v1 != v2){
            answer += costs[i][2];
            parent[v2] = v1;
        }        
    }
    return answer;
}