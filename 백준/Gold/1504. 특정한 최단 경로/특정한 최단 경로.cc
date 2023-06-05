#include <iostream>
#include <vector>
#include <queue>
#define MAX 801
const int inf = 987654321;
using namespace std;

int n, e, dist[MAX], res;
vector<pair<int, int>> v[MAX];
int V1, V2,V1_V2, V1_n,V2_n;

void dijkstra(int start) {
	for (int i = 0; i <= n; i++) dist[i] = inf;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
	dist[start] = 0;
	pq.push({ 0, start });
	while (!pq.empty()) {
		int cur = pq.top().second;
		int cur_dist = pq.top().first;
		pq.pop();
		if (dist[cur] < cur_dist) continue;
		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i].second;
			int next_dist = v[cur][i].first;
			if (dist[next] > cur_dist + next_dist) {
				dist[next] = cur_dist + next_dist;
				pq.push({ dist[next], next });
			}
		}
	}
}

int main() {
	cin >> n >> e;
	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ c,b });
		v[b].push_back({ c,a });
	}
	int v1, v2;
	cin >> v1 >> v2;
	dijkstra(1);
	V1 = dist[v1];
	V2 = dist[v2];
	dijkstra(v1);
	V1_V2 = dist[v2];
	V1_n = dist[n];
	dijkstra(v2);
	V2_n = dist[n];
	int res = inf;
	res = min(res, V1 + V1_V2 + V2_n);
	res = min(res, V2 + V1_V2 + V1_n);
	if (res == inf || V1_V2 == inf) cout << -1;
	else cout << res;
}