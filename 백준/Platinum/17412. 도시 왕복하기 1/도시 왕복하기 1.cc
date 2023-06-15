#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

int n, p, cap[401][401], flow[401][401];

int edmonds(int s, int e){
	memset(flow, 0, sizeof(flow));
	int res = 0;
	while(true){
		vector<int> path(n+1, -1);
		queue<int> q;
		q.push(s);
		while(!q.empty()){
			int cur = q.front();
			q.pop();
			for(int nxt = 1; nxt<=n; nxt++){
				if(cap[cur][nxt]-flow[cur][nxt]>0 && path[nxt]==-1){
					q.push(nxt);
					path[nxt] = cur;
					if(nxt == e) break;
				}
			}
		}
		if(path[e] == -1) break;
		int remain = 987654321;
		for(int p = e; p != s; p = path[p]) remain = min(remain, cap[path[p]][p]-flow[path[p]][p]);
		for(int p = e; p != s; p = path[p]){
			flow[path[p]][p] += remain;
			flow[p][path[p]] -= remain;
		}
		res += remain;
	}
	return res;
}


int main(){
	cin >> n >> p;
	for(int i = 0; i<p; i++){
		int v1, v2;
		cin >> v1 >> v2;
		cap[v1][v2] = 1;
	}
	cout << edmonds(1, 2);
}