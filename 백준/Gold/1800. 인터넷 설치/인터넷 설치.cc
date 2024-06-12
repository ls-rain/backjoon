#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, p, k, dist[1001];
vector<pair<int, int> > edge[1001];

bool dijkstra(int mid){
	priority_queue<pair<int, int> > pq;
	pq.push({0, 1});
	while(!pq.empty()){
		int node = pq.top().second;
		int weight = -1*pq.top().first;
		pq.pop();
		for(int i = 0; i < edge[node].size(); i++){
			int nxt = edge[node][i].first;
			int nweight = edge[node][i].second;
			int w = weight + (nweight > mid);
			if(dist[nxt] > w){
				dist[nxt] = w;
				pq.push({-1*w, nxt});
			}
		}
	}
	return dist[n] <= k;	
}

int main(){
	cin >> n >> p >> k;
	for(int i = 0; i < p; i++){
		int u, v, w;
		cin >> u >> v >> w;
		edge[u].push_back({v,w});
		edge[v].push_back({u,w});
	}
	int right = 987654321;
	int left = 0;
	int res = -1;
	while(left <= right){
		int mid = (left+right) / 2;
		fill(dist, dist+1001, 987654321);
		dist[1] = 0;
		if(dijkstra(mid)){
			right = mid - 1;
			res = mid;
		}
		else left = mid + 1;
		
	}
	cout << res;
}