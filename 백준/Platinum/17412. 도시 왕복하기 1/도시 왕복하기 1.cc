#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, p, cap[401][401], flow[401][401];
int res;
int edmonds(){
	while(1){
		vector<int> path(n+1, -1);
		queue<int> q;
		q.push(1);
		while(!q.empty()){
			int cur = q.front();
			q.pop();
			for(int i = 1; i <= n; i++){
				if(cap[cur][i] - flow[cur][i] > 0 && path[i] == -1){
					path[i] = cur;
					q.push(i);
				}
			}
		}
		if(path[2] == -1) break;
		int remain = 987654321;
		for(int p = 2; p != 1; p = path[p]) remain = min(remain, cap[path[p]][p] - flow[path[p]][p]);
		for(int p = 2; p != 1; p = path[p]){
			flow[path[p]][p] += remain;
			flow[p][path[p]] -= remain;
		}
		res += remain;
	}
	return res;
}

int main(){
	cin >> n >> p;
	for(int i = 0; i < p; i++){
		int v1, v2;
		cin >> v1 >> v2;
		cap[v1][v2] = 1;
	}
	cout << edmonds();
}