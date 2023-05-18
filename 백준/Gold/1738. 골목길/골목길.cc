#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string.h>
#define MAX 20001
using namespace std;
const int inf = 200010;
int n, m, dist[101], path[101];
pair<int, pair<int,int>> edge[MAX];
bool cycle;
bool visit[101];

void bellmanford() {
	dist[1] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int from = edge[j].second.first;
			int to = edge[j].second.second;
			int cost = edge[j].first;
			if (dist[from] == -inf) continue;
			if (dist[from] + cost > dist[to]) {
				if (i == n && visit[from]) cycle = true;
				dist[to] = dist[from] + cost;
				path[to] = from;
		 	}
		}
	}
	//한번 전부 탐색해서 최대값 구한다.
}

void trace(int n) {
	if (n == 1) {
		cout << 1 << " ";
		return;
	}
	trace(path[n]);
	cout << n << " ";
	return;
}

int main() {
	cin >> n >> m;
	vector<int> reverse[101];
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		edge[i] = { w,{ u,v} };	//{가중치, 다음노드}
		reverse[v].push_back(u);
	}
	memset(dist, -inf, sizeof(dist));
	memset(path, -1, sizeof(path));
	queue<int> q;
	q.push(n);
	visit[n] = true;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < reverse[cur].size(); i++) {
			int next = reverse[cur][i];
			if (!visit[next]) {
				visit[next] = true;
				q.push(next);
			}
		}
	}
	bellmanford();
	if (cycle) cout << -1;
	else trace(n);
}